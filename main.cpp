#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include <filesystem>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;
namespace fs = std::filesystem;

HWND hConsoleWnd = ::GetConsoleWindow();
HMONITOR hMonitor = ::MonitorFromWindow(hConsoleWnd, MONITOR_DEFAULTTONEAREST);

/*//////////////////////////////    FUNCTIONS    //////////////////////////////*/



////////////////FUNCTION TO CHECK IF X ENDS WITH Y ////////////////
inline bool ends_with(const string &value, const string &ending){
    if (ending.size() > value.size()) return false;
    
    return equal(ending.rbegin(), ending.rend(), value.rbegin(),
    [](char a, char b) { return tolower(a) == tolower(b); });
}

////////////////FUNCTION TO REPLACE FILE EXTENSION////////////////
inline void replExt(string &filename, const string &oldExt, const string &newExt) {
    if (ends_with(filename, oldExt)) {
        filename.replace(filename.size() - oldExt.size(), oldExt.size(), newExt);
    }
}


////////////////FUNCTION TO CHECK IF CPP EXISTS////////////////
bool checkCPP(const string& cppPath) {
    ifstream file(cppPath);
    fs::path filePath = cppPath;
    if (!file.is_open() || filePath.extension() != ".cpp") {
        system("title ERR: CPP_NOT_FOUND");
        return false;
    }
    
    return true;
}


////////////////FUNCTION TO CHECK IF THE ALL REQUIRED FILES ARE THERE////////////////
string readFile(const string& filePath) {
    ifstream file(filePath);
        if (!file.is_open()) {
        	system("title FILE_PATH_NOT_FOUND");
            cerr << "Cannot open '" << filePath << "', please check it's path again";
            system("pause>nul");
            exit(EXIT_FAILURE);
}
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


////////////////FUNCTION TO SEARCH FOR CPPCONF.JSON VALUES////////////////
string extractJsonValue(const string& jsonContent, const string& key) {
    size_t keyPos = jsonContent.find("\"" + key + "\"");
    if (keyPos == string::npos) {
        system("title MISSING VALUE");
        cerr << "KEY '" << key << "' not found on cppConf.json";
        system("pause>nul");
        exit(EXIT_FAILURE);
    }
    size_t valueStart = jsonContent.find(":", keyPos) + 1;
    size_t valueEnd = jsonContent.find("\"", valueStart + 1);
    return jsonContent.substr(valueStart + 1, valueEnd - valueStart - 1);
}

////////////////FUNCTION TO SEARCH FOR ARGUMENTS FOR COMPILATION ON CPPCONF.JSON ////////////////
vector<string> extractArguments(const string& jsonContent, const string& key) {
    vector<string> values;
    size_t keyPos = jsonContent.find("\"" + key + "\"");
    if (keyPos == string::npos) {
        system("title MISSING VALUE");
        cerr << "KEY '" << key << "' not found in cppConf.json";
        system("pause>nul");
        exit(EXIT_FAILURE);
    }
    
    size_t arrayStart = jsonContent.find("[", keyPos);
    size_t arrayEnd = jsonContent.find("]", arrayStart);
    if (arrayStart == string::npos || arrayEnd == string::npos) {
        system("title INVALID ARGUMENT FORMATTING");
        cerr << "Invalid format for '" << key << "'";
        system("pause>nul");
        exit(EXIT_FAILURE);
    }

    size_t currentPos = arrayStart + 1;
    while (currentPos < arrayEnd) {
        size_t quoteStart = jsonContent.find("\"", currentPos);
        if (quoteStart == string::npos || quoteStart >= arrayEnd) break;

        size_t quoteEnd = jsonContent.find("\"", quoteStart + 1);
        if (quoteEnd == string::npos || quoteEnd >= arrayEnd) break;

        values.push_back(jsonContent.substr(quoteStart + 1, quoteEnd - quoteStart - 1));

        currentPos = quoteEnd + 1;
    }

    return values;
}


////////////////FUNCTION TO COMPILE YOUR PROGRAM (now its more accessible for editing)////////////////
string compileANDshow(const string& ruteCPP, const string& program_name, const string& arguments, const string& cpp_name, const string& boolR, const string& customCompile, const string& autorun){
    string compileCMD;
    string endMSG;
    string cdCmd = "@echo off && cd "+ruteCPP+" && ";

    if(boolR == "true"){
        if(autorun == "true"){

            system("echo WARNING: Autorun not supported with customCompile, please add: && echo ^&^& your_program_name.exe && echo to the end of your customCompile to autorun && echo: && echo:");

        }
            
        compileCMD = cdCmd+customCompile;
        endMSG = "@echo off && echo: && echo: && echo [Command Terminated] && pause>nul";

    } else if(boolR == "false"){

        cdCmd = "";

        if(autorun == "true"){

            compileCMD = "@echo off && cd "+ruteCPP+" && title " + program_name + " && cls && g++ "+arguments+" -o " +'"'+program_name +'"'+ " "+cpp_name+" && "+'"'+program_name+".exe"+'"';
            endMSG = "@echo off && echo: && echo: && echo [Launcher Terminated] && pause>nul";

        } else {

            compileCMD = "@echo off && cd "+ruteCPP+" && title " + program_name + " && cls && g++ "+arguments+" -o " +'"'+program_name +'"'+ " "+cpp_name+"";
            endMSG = "@echo off && echo [Done compiling] && pause>nul";

        }
    }

    system(compileCMD.c_str());
    system(endMSG.c_str());

    return " ";
}

////////////////LOAD ICON FROM JSON VALUE////////////////
HICON LoadIconFromFile(const std::string& iconPath) {
    return reinterpret_cast<HICON>(
        LoadImageA(
            nullptr, 
            iconPath.c_str(), 
            IMAGE_ICON, 
            0, 
            0, 
            LR_LOADFROMFILE | LR_DEFAULTSIZE
        ));
}



int main() { /*//////////////////////////////    MAIN    //////////////////////////////*/


////////////////WIN RESIZE////////////////
if (hMonitor) {
   MONITORINFO info{sizeof(info)};
    if (::GetMonitorInfo(hMonitor, &info)) {
        int width = 500;
        int height = 200;
        int x = (info.rcWork.left + info.rcWork.right) - width + 10;
        int y = (info.rcWork.top + info.rcWork.bottom) - height + 6;
        ::SetWindowPos(hConsoleWnd, nullptr, x, y, width, height, SWP_NOZORDER | SWP_NOOWNERZORDER);
    }	
}


////////////////GET VALUES FROM CPPCONF.JSON////////////////
    string jsonContent = readFile("cppConf.json");
    string program_name = extractJsonValue(jsonContent, "program_name");
    string cpp_name = extractJsonValue(jsonContent, "cpp_name");
    string ruteCPP = extractJsonValue(jsonContent, "ruteCPP");
    string icon = extractJsonValue(jsonContent, "icon");
    string autorunRaw = extractJsonValue(jsonContent, "autorun");
    vector<string> customCompileRaw = extractArguments(jsonContent, "customCompile");
    vector<string> argumentsRaw = extractArguments(jsonContent, "arguments");
    

////////////////AUTORUN TOLOWERCASE////////////////
    transform(autorunRaw.begin(), autorunRaw.end(), autorunRaw.begin(), [](unsigned char c) { return std::tolower(c); });
    string autorun = autorunRaw;


////////////////CHECK IF CUSTOM COMPILING ITS ENABLED////////////////
string customCompile, boolR;
bool isFirst = true;

for (const string& cmpl : customCompileRaw) {
        if (isFirst) {

            boolR = cmpl;
            transform(boolR.begin(), boolR.end(), boolR.begin(), 
                [](unsigned char c) { return tolower(c); });
            isFirst = false;

        } else {

            if (!customCompile.empty()) {
                customCompile += " ";
            }
            customCompile += cmpl;
        }
    }

    if(boolR == "true"){
    cout << customCompile << "\n\n";
    }

    string arguments;
    for (const string& arg : argumentsRaw) {
        if (!arguments.empty()) {
            arguments += " ";
        }
        arguments += arg;
}


////////////////DEFAULT ICON IF NOTHING SPECIFIED ON 'ICON' VALUE////////////////
if(icon == "" || icon == " " || icon == "./icons/"){
    icon = "./icons/default.ico";
}


////////////////CUSTOM CONSOLE WIN ICON////////////////
if (hMonitor) {
    HICON hIcon = LoadIconFromFile(icon);
    if (hIcon) {
        ::SendMessage(hConsoleWnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(hIcon));
        ::SendMessage(hConsoleWnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(hIcon));
    } else {
    	system("title ICON_PATH_NOT_FOUND");
        cerr << "Cannot find path '" << icon << "' to specified icon in cppConf.json:4:10";
		system("pause>nul");
		exit(EXIT_FAILURE);
    }
}


////////////////CHECK IF 'RUTE' HAS ENDS WITH '/' ////////////////
 if (ruteCPP.empty()) {
    ruteCPP += "./";
//true
    } else if (ruteCPP.back() == '/') {
//true
    } else if(ruteCPP == " "){
        ruteCPP = "./";
//true
    } else {
    ruteCPP += "/";
 //false
}


////////////////IF CUSTOM COMPILING ENABLED RUN INSTANTLY SKIPPING VERIFICATIONS////////////////
if(boolR == "true"){

    if(ruteCPP == "" || ruteCPP == " "){
    
    compileANDshow(ruteCPP, program_name, arguments, cpp_name, boolR, customCompile, autorun);

    } else {

    compileANDshow(ruteCPP, program_name, arguments, cpp_name, boolR, customCompile, autorun);
    
        }



} else if(boolR == "false"){



////////////////CHECK IF CPP ENDS WITH THE CPP EXTENSION////////////////
string path; 
if(ends_with(ruteCPP+cpp_name, ".cpp") == true){

    replExt(cpp_name, ".cpp", ".cpp");
    path = ruteCPP+cpp_name;

} else {

    cpp_name += ".cpp";
    path = ruteCPP+cpp_name;

}

////////////////CHECK IF CPP EXISTS////////////////
if (checkCPP(path)) { 
        
        } else {

        cout << cpp_name+" not found on '" << ruteCPP << "'\n\nPlease check it's path again and make sure that your C++ file\nit's on the path specified in cppConf.json:3:10";
        system("pause>nul");
        exit(EXIT_FAILURE);
} 

////////////////PROGRAM NAME////////////////
if(program_name == "" || program_name == " "){
    program_name = "Program Name";
}

////////////////CPP_NAME////////////////
if(cpp_name == "" || cpp_name == " "){
    //throw invalid_argument("No value found on 'cpp_name' on cppConf.json:3:17");
    cout << "No value found on 'cpp_name' on cppConf.json:3:17";
}

////////////////RUN CPP////////////////
if(ruteCPP == "./" || ruteCPP == " "){

    compileANDshow(ruteCPP, program_name, arguments, cpp_name, boolR, customCompile, autorun);

    } else {

    compileANDshow(ruteCPP, program_name, arguments, cpp_name, boolR, customCompile, autorun);

        }
    }
}