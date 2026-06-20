# Calculator Project

This is a small C study project built to practice the core parts of C programming in a simple, hands-on way.

## What this project is for

The goal is to learn and practice:

- functions and header files
- loops and `switch` statements
- input validation with `scanf`
- basic file handling for history storage
- simple state handling with memory functions like `M+`, `MR`, and `MC`
- writing code in a clean multi-file C project structure

## Why this project exists

I made this project as a practice calculator so I can understand C better by building something useful instead of only reading theory.

It helps show how small C programs are organized and how features can be split into separate files:

- `main.c` handles the menu and user interaction
- `operations.c` contains the math and history functions
- `calculator.h` stores the shared function declarations

## Features

- Addition
- Subtraction
- Multiplication
- Division
- Modulus
- Power
- Square root
- Memory storage:
  - `M+`
  - `MR`
  - `MC`
- Input validation for menu choices and numbers
- Saved calculation history in `history.txt`

## Project files

- `main.c` - program entry point and menu logic
- `operations.c` - calculator operations and history handling
- `calculator.h` - function declarations shared between files

## How to run

Use a C compiler such as GCC:

```bash
gcc main.c operations.c -o calculator.exe -lm
```

Then run:

```bash
calculator.exe 
```

or 

```powershell
.\main
```

