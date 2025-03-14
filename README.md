###### note: this script assumes that you have installed on your system MSYS2 and MinGW, if not, you can get it by following the [Vscode tutorial to get MinGW](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain), also, this program will only work with command line programs, programs that creates windows will fail, I will fix this problem in future updates
# executeCPP
Execute your cpp file on small console window

# How to use it?
Just download the rar binary from the [Releases tab](https://github.com/TRKako/executeCPP/releases), decompress it and throw it on your project, something like this:
```
Example Project/
│
├───test.cpp //This is your cpp file that you want to test
│
└───executeCPP/    //This is the folder that the rar drops, throw it inside the folder in which your cpp file is
    ├───ExecuteCPP.exe
    ├───var.json
    │
    └───Icons/
        └───default.ico
```
Then you just run `ExecuteCPP.exe` and your program will show up there.

# Can I customize this?
Yes!, you can customize:
> - The Window Title
> - The path to your cpp file if you want to put this thing somewhere else
> - The path to the Icon that you wanna use on your Window (Make sure it's a ICO file, I recommend [This website](https://redketchup.io/icon-converter) to convert whatever picture to ICO)
  
On `var.json`.

For example:
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
	]
  // Optional arguments, in this case I put by default those two, you can use as much arguments as you want, even replace this two, you can also set nothing there, like this

  // "arguments": []
}
```

<p align="center"><sub><sup>note: you can also use relatives paths like "../desktop/some folder here/" or "./my project folder/src/"</sup></sub></p>

<p align="center">and it would look like this:</p>

<p align="center">
  <img src="https://i.imgur.com/UOvQ79X.png" title="Example"/>
</p><br>

<br>

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
