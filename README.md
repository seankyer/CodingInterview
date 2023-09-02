# CodingInterview

My prep material and practice questions for an embedded or low-level systems technical interview.  

This repository will contain notes on embedded-systems related topics, definitions, as well as some coding problems involving low-level data structures, with a slight touch on dynamic programming (just in case).

## Target Job Description

(Culmunation of desired qualifications from Apple, Tesla, Amazon and Meta)  

- Software development experience using C and assembly for ARM CPUs  
- Proficiency in C
- Experience in SW development and testing FPGAs  
- Familiarity with control loop or PID controllers  
- Experience working with RTOS  
- Familiar with communication protcols: UART, SPI, I2C  
- Experience coding a MicroController

## Syllabus

1. Systems Concepts:
    1. Basic Embedded Definitions
    2. Booting
    3. Interrupts
    4. RTOS
    5. PID and System Control
    6. Peripherals
    7. Programming Workflows
2. Communication Protocols:
    1. UART
    2. SPI
    3. I2C
    4. TCP
    5. UDP
3. Language and Syntax:
    1. C
    2. Python
    3. GCC
4. Coding
    1. Linked List Traversal
    2. Bitwise Operations
    3. Microntroller - Blinky
    4. Communication Protocol Implementation
    5. Multithreading
    6. Implementation of stack and queue
    7. and a whole lotta leetcode...
5. Dynamic Programming (TBD)

## Running Code

To run the code in this repostiory you must have `GNU Make >= 4.2.1` and `GCC >= 9.4.0` (Ubuntu packaged).  

Navigate to the directory containing the given topic and run `make`. The executables will be generated as `.bin` files in the topics root directory.
