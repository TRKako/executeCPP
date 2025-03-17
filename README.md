###### note: this script assumes that you have installed on your system MSYS2 and MinGW, if not, you can get it by following the [Vscode tutorial to get MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain), also, this program will only work with command line if you have "autorun" enabled, to compile programs without this error you have to set autorun to false
# executeCPP
Execute and compile your cpp file on small console window at the same time

# How to use it?
Just download the rar binary from the [Releases tab](https://github.com/TRKako/executeCPP/releases), decompress it and throw it on your project, something like this:
```
Example Project/
│
├───test.cpp //This is your cpp file that you want to test
│
└───executeCPP/    //This is the folder that the rar drops, throw it inside the folder in which your cpp file is
    ├───ExecuteCPP.exe
    ├───cppConf.json
    │
    └───Icons/
        └───default.ico
```
Then you just run `ExecuteCPP.exe` and your program will show up there.

# Can I customize this?
Yes!, you can customize:
> - The Window Title
> - The path to your cpp file if you want to put this thing somewhere else
> - The path to the Icon that you wanna use on your Window (Make sure it's an ICO file, I recommend [This website](https://redketchup.io/icon-converter) to convert whatever picture to ICO)
  
On `cppConf.json`.

<br>

# Basic use explanation
```JSON
{
	"program_name":"Test Window",
  // The name of the output program.exe (you can specify the extension if you want, it's not neccesary tho)

  	"cpp_name":"test",
     // The name of your cpp file, it must not have the .cpp extension or it's not going to work

	"rute":"C:/Users/<your_username_here>/Desktop/Example Project/",
   // The path to the folder where your cpp file is located

	"icon":"C:/Users/<your_username_here>/Desktop/Example Project/cute icon I really like/griffith.ico",
  // The path to your ICO file

	"arguments": [
		"-static",
		"-static-libstdc++"
	],
  // Optional arguments, in this case I put by default those two, you can use as much arguments as you want, even replace this two, you can also set nothing there, like this

  // "arguments": []

	"customCompile":[
		"false",
    // you can turn ON and OFF this option by setting this to "true" or "false"  
		"g++ -static -static-libstdc++ -o YOUR_EXE_PROGRAM_NAME_HERE.exe YOUR_FILE_NAME_HERE.cpp && YOUR_EXE_PROGRAM_NAME_HERE.exe"
	],
  // CustomCompile it's in case you don't want to use the default settings of the program and you want to run your own command, using this will ignore all the other options but "rute", "icon" and "autorun"; Only one line of command its allowed, tho you can add more and more commands by just typing &&

	"autorun":"true"
  // This option it's for running your program on the console or not, set this to false if you are using customCompile or if you are not compiling a command line program
}

```

<p align="center"><sub><sup>note: you can also use relatives paths like "../desktop/some folder here/" or "./my project folder/src/"</sup></sub></p>

<p align="center">and it would look like this:</p>

<p align="center">
  <img src="https://i.imgur.com/UOvQ79X.png" title="Example"/>
</p><br>


# Detailed json documentation
<p align="center"><sub><sup>this is the first time I do one</sup></sub></p>

| Parameter | Description                       | Type     |Required| 
| :-------- | :-------------------------------- | :------- |:--------|
| `program_name`        |  Name of the output executable | `string` |False|
| `cpp_name`            |  Name of the CPP file you're compiling / running | `string`|**Required**|
| `ruteCPP`             |  Path to your CPP file | `string` |False|
| `icon`                |  Path to your ICO file (this parameter must have **.ico** in the end)| `string`|False|
| `arguments`           |  Arguments for compiling| `string` |False|
| `customCompile`       |  One line custom command| `boolean & string` |**Boolean Required**|
| `autorun`             |  Run program on compiling| `boolean` | **Required**|

<br>
<br>

#### program_name
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `program_name` |`YOUR_EXE_PROGRAM_NAME_HERE` | False |

The parameter "`program_name`" it's the name of the executable of your cpp, if for example this parameter is set to "helloWorld" or "byeWold.exe" the output file will be that name

In this parameter, typing .exe in the end it's completly optional and it will work either way; This parameter can be omitted but it will output your file with the name "`program name.exe`".

<br>
<br>

#### cpp_name
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `cpp_name` |`YOUR_FILE_NAME_HERE` | **True** |

The parameter "`cpp_name`" it's the name of your cpp file

In this parameter, typing .cpp in the end it's completly optional and it will work either way; This parameter can NOT be omitted.

<br>
<br>

#### ruteCPP
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `ruteCPP` |   `../` | False |

The parameter "`ruteCPP`" it's the path to the cpp file you're working on

In this parameter, typing a path it's completly optional, if this parameter it's left on blank it will use the path of the folder "ExecuteCPP", it's recommended to use a relative path or the default path for more comfort but you can change it as much as you want; This parameter can be omitted.

<br>
<br>

#### icon
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `icon` |    | False |

The parameter "`icon`" it's the path to the icon you want to use

In this parameter, typing a path it's completly optional, if this parameter it's left on blank it will use the default path to it's icon on "**`./ExecuteCPP/Icons/default.ico`**", if you do put your icon on this parameter, you have to make sure it does end with **`your_ico_name.ico`**, if it doesn't ends with ".ico" it will fail.

If you want to use your own icon make sure it's a proper ICO file, I suggest [redketchup.io](https://redketchup.io/icon-converter) to convert your images to a good ICO file

The icon setted for this will be only so it displays on the console window, it does not set an Icon to the executable, for that I suggest using [Resource Hacker](https://www.google.com/search?q=resource+hacker)

This parameter can be omitted.

<br>
<br>

#### arguments
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `arguments` | `-static`, `-static-libstdc++`   | False |

The parameter "`arguments`" is the arguments used for compiling your cpp file

In this parameter, typing an arguments it's completly optional, if this parameter it's left on blank nothing will happend and it will compile without any arguments. if you do type arguments this parameter, you have to make a new row for each one, like this:
```json
"arguments": [
		"-static",
		"-static-libstdc++",
        "XXXXXXXXXX",
        "YYYYYYYYYY",
        "ZZZZZZZZZZ",
        "you_get_the_idea..."
	],
```
if you want to leave this on blank it has to be like this
```json
"arguments": [],
```

This parameter can be omitted.

<br>
<br>

#### customCompile
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `customCompile` |boolean: **`false`**, string: **`g++ -static -static-libstdc++ -o YOUR_EXE_PROGRAM_NAME_HERE.exe YOUR_FILE_NAME_HERE.cpp && YOUR_EXE_PROGRAM_NAME_HERE.exe`** | **Boolean Required** / False |

The parameter "`customCompile`" it's both a boolean and string, you can enable this option by setting the boolean of `customCompile` from false to "`True`", once you enable this parameter you can use whatever command you like

by default the command there it's a compile one, but you can actually use whatever you want, try using the command "`ping google.com`" on it, it would look like this
```json
"customCompile":[
		"true",
		"ping google.com"
	],
```

Enabling the parameter `customCompile` will make the program ignore these previous parameters:
- `program_name`
- `cpp_name`
- `arguments`
- `autorun`

The `ruteCPP` argument will define on which directory the command will execute, `icon` stays being optional, and `autorun` will be ignored, but it if it's enabled it will pop up a warning on the console;

This parameter can be omitted.

<br>
<br>

#### autorun
| Parameter | default state                | Required     |
| :-------- | :------------------------- | :--------|
| `autorun` |   `true` | **True** |

The parameter "`autorun`" it's a boolean switch that allows you to run your output executable on the same console window at the same moment it ends compiling, useful for debugging purposes

if you set this parameter to false, ExecuteCPP will just compile your cpp and then it will end there;

This parameter can NOT be omitted.



<br>

---------------------------------------------
---------------------------------------------
---------------------------------------------

# How is this better than just compile c++ the normal way?
Well, this is more for people that don't like using the compile button everytime, or if you are using Vscode and you don't want to set up everything there just to compile "hello world", this is just an alternative

<br>

# I have to enter the folder everytime I want to compile?

No, you don't, in fact I did this with the idea in mind of using it with the taskbar since you only have to do "Windows key + number" to run it, something like this 

<p align="center">
  <img src="https://i.imgur.com/JnWoxvP.png" title="Taskbar Example"/>
</p><br>

In this example you have to do "Windows key + 2" to compile the file, that's all

<br>

# Can I get rid of the whole folder and just use the program alone?

Yes, you can, but you need to have "`var.json`" on the same folder as "`ExecuteCPP.exe`" and a path to an icon, if you don't want to put one, then bring the folder "`Icons`" into the same folder as "`ExecuteCPP.exe`" and let the value of the icon on "`var.json`" in blank 


----
  <p align="center">-Kako</sup></sub></p>

<p align="center">
    <img src="https://raw.githubusercontent.com/TRKako/TRKako/main/files/Marina.svg" title="Evil Kako"/>
  <img src="https://raw.githubusercontent.com/TRKako/TRKako/main/files/Arusu2.svg" title="Kako"/>
</p>
