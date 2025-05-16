/*
Here are some commonly used gdb commands to debug your pokergame program:
run                # Start the program
break <location>   # Set a breakpoint at the specified location
continue           # Continue execution until the next breakpoint
step               # Step into the next function call
next               # Step over the next function call
print <variable>   # Print the value of a variable
quit               # Exit gdb

/////////////////////////////////////////////////
1. Start gdb
Run gdb with your compiled program:

./gdb ./pokergame

2. Run the Program
Run the program with arguments (e.g., number of simulations):

run 10

3. Set Breakpoints
Breakpoints allow you to pause execution at specific lines or functions.

Set a breakpoint at the start of the main function:

break main

Set a breakpoint at a specific line:

break pokergame.c:50

Set a breakpoint at a specific function:

break player_init

List all breakpoints:

info breakpoints

Delete a breakpoint:

delete <breakpoint_number>

4. Step Through Code
Step through the program line by line or function by function.

Step into a function:

step

Step over a function (execute it without stepping into it):

next

Continue execution until the next breakpoint:

continue

Finish the current function and return to the caller:

finish

5. Inspect Variables
Check the values of variables during execution.

Print the value of a variable:

print <variable_name>

Example:

print <variable_name>

Print the value of a pointer:

print *<pointer_name>

Example:

print *players[0]

Display a variable continuously after each step:

display <variable_name>

Stop displaying a variable:

undisplay <display_number>

6. Backtrace
View the call stack to see how the program reached the current point.

Show the call stack:

backtrace

Move up or down the stack:

up
down

7. Watchpoints
Watchpoints pause execution when a variable's value changes.

Set a watchpoint on a variable:

watch <variable_name>

Example:
watch pool

Set a conditional watchpoint:

watch <variable_name> if <condition>

Example:

watch <variable_name> if <condition>

Example:
watch pool if pool > 100

Examine memory at an address:

x/<format> <address>

Example:

x/4xw &players[0]

Formats:

x: Hexadecimal
d: Decimal
s: String
w: Word (4 bytes)

9. Debugging Tips
Check for Segmentation Faults: If your program crashes, run it in gdb and use backtrace to find the cause:

run
backtrace

Inspect Function Arguments: Use info args to view the arguments passed to the current function.

List Source Code: Display the source code around the current line:

list

10. Exit gdb
To quit the debugger:

quit
*/
