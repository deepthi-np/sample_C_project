Problem statement
--------------------
Implement pushd and popd Linux commands in C programming.

Conditions:
- Program must be compiled and executed in Linux environment
- Program should accept command-line arguments only
- Pre-build Linux applications such as ls, mkdir, etc, and pre-build functions like
system(), popen() should not be used in your application

Code Overview
---------------------
This code implemnents the basic functionality of pushd and popd without using external commands or library functions
The user can define the maximum size of the directory stack at runtime, which is used to store the maximum number of directories the user wants to store in the stack.
Cli option select option for push or pop operation
The current directory change is done using chdir
If the user selects "Push", the program prompts for a directory path, and changes the current directory. It then pushes the previous directory to the stack and updates the current directory.
If the user selects "Pop", the program pops the top directory from the stack, changes the current directory and frees the memory allocated for the popped directory. 
The program also prints the current stack size.

Steps to Run
-------------
gcc code.c -o testrun
./testrun
