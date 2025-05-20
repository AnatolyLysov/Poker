You are getting two errors:

Implicit declaration of function ‘getch’:
The compiler does not know about the getch() function because its declaration is missing or the required header is not included.

Undefined reference to ‘getch’:
The linker cannot find the implementation of getch(). On Linux, getch() is not part of the standard C library. It is available in conio.h (which is for DOS/Windows), but not on Linux.

Solution:
On Linux, you can use getchar() instead of getch(), or use libraries like ncurses for similar functionality.

To use getchar(), replace getch() with getchar() in your code.

If you need getch()-like behavior (no Enter key required), install and use ncurses:

Replace getch() with getch() from ncurses and include <ncurses.h> in your code.

Text to replace:

{getch}: Replace with getchar() or use ncurses's getch()
{#include <conio.h>}: Replace with #include <ncurses.h> if using ncurses
// #include <conio.h> // This is for Windows, not Linux
// #include <ncurses.h> // Uncomment this if using ncurses
// #include <stdio.h>
// #include <stdlib.h>