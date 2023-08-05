//Read this README_MUST if you want to setup graphics.h in your compiler.

# Graphics library setup

## Quick setup

```bash
git clone https://github.com/ullaskunder3/graphics.h-project-template.git
```

Detail setup can be found on my other repo [solution-to-graphics.h](https://github.com/ullaskunder3/Solution-to-graphics.h)

## My directory looks like

```cmd
  D:.
├───.vscode
└───Home
    ├───build
    └───src
```

- Just `Ctrl+Shift+B` to run the build task you will get the executable file in build folder
- To run the program, right click on the exe file, then press Run executable to run the graphics program.

Also very very important, src folder must contain source code and also create build folder where the compiler itself will generate exe file.

## !mportant

- Folder `src` contains source code

- Folder `build` where compiler generate .exe

- .vscode contains c_cpp_properties.json and task require modification according to your environment and types compiler

Reference video: Setting up graphics.h in VS Code 2023 | C/C++
https://www.youtube.com/watch?v=FHhP7wcX5uQ

To download graphics compiler from scratch:

1. Download mingw - minimalist gnu for windows download
2. Run the mingw setup .exe and do as told
3. Mark for installation 3 packages as shown in video
4. From the given github links in the video, move the libbgi.a to lib folder of mingw, move the graphics.h and winbgim.h folder into include folder of mingw folder in c.
5. Set the path in environment variables: for user and admin as you need.
6. Very important to do ctrl+shift+b, right click run executable and have the source code inside src code and also make build folder to store output file.
7. Sabai lekhna alxi lagyo, if doesn't work, then watch video in given above link.
