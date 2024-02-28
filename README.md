Description

This is an ALX Africa Software Engineering milestone peer project, using C programming language to write a Unix command line interpreter which exhibit the features/capabilities of a simple shell.

Compilation

As instructed, the shell should be compiled by using the gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh. After compilation the shell program should be able to operate in both interactive mode and non-interactive mode.

 Interactive mode

There is direct interaction between the shell program and the user where the shell displays prompt to the user and awaits (command) input through the keyboard

($) exit
$ 
the program can be exited by typing the 'exit' command or ctrl+D

 Non interactive mode

In this mode of interaction, programs execute commands without displaying prompt or awaits the user input, it reads command from a script or from other programs.

$ echo "/bin/ls" | ./hsh


Credits
codes written by: Goodness Atunde and Isah Bashir
# The Simple Shell Project at ALX-SE
