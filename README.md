# The Simple Shell Project at ALX-SE

![Alt Text](https://camo.githubusercontent.com/de922f3a0aec73d3c30c0af58c5a8e8a24c4bd1193e43ec4a27be56a7c7d3a94/68747470733a2f2f73332e616d617a6f6e6177732e636f6d2f696e7472616e65742d70726f6a656374732d66696c65732f686f6c626572746f6e7363686f6f6c2d6c6f775f6c6576656c5f70726f6772616d6d696e672f3233352f7368656c6c2e6a706567)


# Description

This is an ALX Africa Software Engineering milestone peer project, using C programming language to write a Unix command line interpreter which exhibit the features/capabilities of a simple shell.

# Compilation

As instructed, the shell should be compiled by using the gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh. After compilation the shell program should be able to operate in both interactive mode and non-interactive mode.

## Interactive mode

There is direct interaction between the shell program and the user where the shell displays prompt to the user and awaits (command) input through the keyboard

($) exit
 $
 
the program can be exited by typing the 'exit' command or ctrl+D

## Non interactive mode

In this mode of interaction, programs execute commands without displaying prompt or awaits the user input, it reads command from a script or from other programs.

$ echo "/bin/ls" | ./hsh


# Credits

codes written by: Goodness Atunde and Isah Bashir
