###### note: this script assumes that you have installed on your system MSYS2 and MinGW, if not, you can get it by following the [Vscode tutorial to get MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain)
# executeCPP
Execute your cpp file on small console window

# How to use it?
Just clone this whole repository on your project folder, something like this:
```
Example Project/
│
├───example.cpp //This is your cpp file
│
└───executeCPP/    //just throw this repo inside the folder in which your cpp file is
    ├───launcher.cpp
    ├───launcher.exe
    ├───var.json
    │
    └───Icons/
        └───default.ico
```
Then you just run the `Launcher.exe` and it will work.

# Can I customize this?
Yes!, you can customize:
> - The Window Title
> - The path to your cpp file if you want to put this thing somewhere else
> - The path to the Icon that you wanna use on your Window (Make sure it's a ICO file, I recommend [This website](https://redketchup.io/icon-converter) to convert whatever picture to ICO)
  
On `var.json`.

For example:
```JSON
{
	"program_name":"Test Window", // The name of the output program.exe
  	"cpp_name":"test", // The name of your cpp file, it musn't have the .cpp extension or it's not going to work
	"rute":"C:/Users/<your_username_here>/Desktop/Example Project/", // The path to the folder where your cpp file is located
	"icon":"C:/Users/<your_username_here>/Desktop/Example Project/cute icon I really like/griffith.ico" // The path to your ICO file
}
```

<p align="center"><sub><sup>note: you can also use relatives paths like "../desktop/some folder here/" or "./my project folder/src/"</sup></sub></p>

<p align="center">and it would look like this:</p>

<p align="center">
  <img src="https://i.imgur.com/UOvQ79X.png" title="Example"/>
</p>

----
  <p align="center">-Kako</sup></sub></p>

<p align="center">
    <img src="https://raw.githubusercontent.com/TRKako/TRKako/main/files/Marina.svg" title="Evil Kako"/>
  <img src="https://raw.githubusercontent.com/TRKako/TRKako/main/files/Arusu2.svg" title="Kako"/>
</p>
