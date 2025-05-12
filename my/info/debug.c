/*To debug pokergame.c, you can follow these steps:

1. Compile with Debugging Information
Use the -g flag when compiling the program to include debugging symbols. This allows you to use 
a debugger like gdb.

2. Run the Debugger
Start the debugger with the compiled program. For example:
gdb ./pokergame

3. Set Breakpoints
Set breakpoints in the code where you want to pause execution and inspect variables. For example:
break main

4. Run the Program
Run the program within the debugger:
run

5. Inspect Variables
When the program hits a breakpoint, you can inspect variables using the print command:
print variable_name

6. Step Through the Code
Use the step command to execute the code line by line:
step

7. Continue Execution
Use the continue command to resume execution until the next breakpoint:
continue

8. Exit the Debugger
When you are done debugging, you can exit the debugger with:
quit*/
//////////////////////////////////////////////
/*1. Compile with Debugging Information
Use the -g flag when compiling the program to include debugging symbols. This allows you to use 
a debugger like gdb.
*/
gcc -g -o pokergame pokergame.c card.c deck.c -lm
/*2. Use a Debugger (e.g., gdb)
Start debugging with gdb:*/
 gdb ./pokergame
 /*Common gdb Commands:
Run the program*/
run <arguments>
//Example:
run 10
//Set breakpoints:
break main
break <line_number>
break <function_name>
//Step through code:
next: Step over a function call.
step: Step into a function call.