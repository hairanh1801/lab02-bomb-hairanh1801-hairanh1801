[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=21040955)
# Bomb lab

## Introduction

This lab is about defusing a binary bomb. The bomb is a program that takes a string as input. If you run it with the wrong input, it will blow up. You have to figure out what the right input is. Unlike most labs, this one is not about writing code. Instead, you will be figuring out what the code is supposed to do, and then finding the right input to set it off.

## Getting started

Download the [bomb](http://csapp.cs.cmu.edu/3e/bomb.tar) and extract it. You can run it from the command line like this:

```
$ ./bomb
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
```

## Defusing the bomb

The bomb has six phases. Each phase expects you to type a particular string on stdin. If you type the right string, then the phase is defused and the bomb proceeds to the next phase. Otherwise, the bomb explodes by calling the `explode_bomb` function. When the bomb explodes, it prints an error message and dumps core.

```
$ ./bomb
Welcome to my fiendish little bomb. You have 6 phases with
which to blow yourself up. Have a nice day!
Phase 1 defused. How about the next one?
```

Your job is to figure out what string to type for each phase.

## Dumping the bomb

If you run the bomb under gdb, you can single-step through the assembly code and watch what it does. This is a good way to figure out what it's doing, but a bad way to defuse the bomb. If you single-step through the code, you will eventually get to the end of the phase and the bomb will blow up. To defuse the bomb, you have to figure out what the code is supposed to do without actually running it.

## Using gdb in vscode

If you are using vscode, you can debug the bomb by adding the following configuration to your `launch.json` file:

```
{
    "name": "gdb",
    "type": "cppdbg",
    "request": "launch",
    "program": "${workspaceFolder}/bomb",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${workspaceFolder}",
    "environment": [],
    "externalConsole": false,
    "MIMode": "gdb",
    "miDebuggerPath": "/usr/bin/gdb"
}
```
## Documents about X86-64

You should read the following documents before you start the lab:

- [X86-64 Assembly Language Programming with Ubuntu](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
- [Standford CS107](https://web.stanford.edu/class/cs107/guide/x86-64.html)

## submit your lab

Write the string for each phase in a file named `solution.txt`. For example:

```
$ cat solution.txt
1 2 3 4 5 6
```

Then commit and push your solution to github. The autograder will run your solution against the bomb and give you a score.

## Hints

- You can use `objdump -d bomb` to disassemble the bomb.
- You can use `gdb bomb` to debug the bomb.
- You can use `x/s <address>` to print the string at the given address.
- You can use `x <address>` to print the value at the given address.
- You can use `x/10i <address>` to print the 10 instructions at the given address.
- You can use `x/10i $rip` to print the 10 instructions at the current instruction pointer.