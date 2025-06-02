create launch.json for debug pokergame in Visual Studo code

GitHub Copilot
To create a launch.json file for debugging pokergame in Visual Studio Code, follow these steps:

1. Create the .vscode Folder
If it doesn't already exist, create a .vscode folder in your project directory:

mkdir .vscode

2. Create the launch.json File
Inside the .vscode folder, create a file named launch.json and add the following configuration:




If it doesn't already exist, create a .vscode folder in your project directory:
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug Pokergame",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/pokergame", // Path to the compiled executable
            "args": ["10"], // Replace with any arguments your program needs
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb", // Path to gdb (default on Linux)
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}

3. Explanation of Fields
program: Path to your compiled pokergame executable. Ensure it matches the output of your Makefile.
args: Command-line arguments passed to your program (e.g., 10 for the number of simulations).
cwd: The working directory for the debugger (usually your project folder).
miDebuggerPath: Path to the gdb debugger (default is gdb on Linux).
setupCommands: Enables pretty-printing for better variable inspection in gdb.
4. Debugging Steps in Visual Studio Code
Open the Run and Debug tab in Visual Studio Code (Ctrl+Shift+D).
Select Debug Pokergame from the dropdown menu.
Click the green Start Debugging button or press F5.
5. Add a Pre-Build Task (Optional)
To ensure the program is compiled before debugging, you can add a preLaunchTask to the launch.json:

"preLaunchTask": "build"

Then, define the build task in a tasks.json file:
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "make",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}

This will automatically run make before starting the debugger.

