# Example Technical Questions and Things to Know
<p style="color: rgb(80, 130, 200);">Answers written in blue</p>

## What is the Volatile keyword in C?
<p style="color: rgb(80, 130, 200);">
The volatile keyword tells the compiler that the value of the variable being decalred may change at any time. This stops the compiler from optimizing out re-reads of a variable from its memory address. This is important for embedded applications where a peripheral may change the value written to a register at any moment. 
</p>

### Differences between Const and Volatile?
<p style="color: rgb(80, 130, 200);">
Const and volatile are essentially oposites. Const (constant) tells the compiler that the variable will never change and declares it as read-only. Const can be used to ensure correctness in the system for variables and arguments to ensure that they are not altered during a function. It also allows the compiler to make some optimizations like constant replacement.
</p>

## What is an ISR used for?
<p style="color: rgb(80, 130, 200);">
An interupt service routine is used when an interupt is triggered from some hardware. It will service a request that requires immediate response.
</p>

### What is Interrupt Service Latency?
<p style="color: rgb(80, 130, 200);">
ISL is the amount of time it takes for an ISR to complete. The latency of an interupt service routine should be as short as possible so another interupt does not fire while the first is being dealt with.
</p>

### Can you pass or return variables from an Interrupt Service Handler?
<p style="color: rgb(80, 130, 200);">
No and ISR cannot directly be transfered or return any variables. It can however manipulate data stored in a pointer somewhere for another process to read at a later time.
</p>

## How do you share variables between source files in C?
<p style="color: rgb(80, 130, 200);">
Using the extern ketword in the header file allows you to initialize it in the corresponding C file and then access it from other C files. Another method is to initialize the variables in the header file itself, however this will mean copies of the variable are stored in any C file to include it.
</p>

## What is a segmentation fault?
<p style="color: rgb(80, 130, 200);">
A segmentation fault is what happens when a program tries to access a memory address it does not have access to or is unmapped. It stops the program from accessing memory outside of its virtual memory space which could potential lead to security and corruption issues. The operating system will terminate the program if a segfault occurs.
</p>

### What are some reasons it might occur in C?
<p style="color: rgb(80, 130, 200);">
In C you could be accessing memory off the end of an array (accessing an out of bounds element), dereferencing a null pointer or if you overflow the stack with variables and/or function calls.
</p>

## Whats the difference between Inline and Macro function?

## Can a variable be both volatile and const?
<p style="color: rgb(80, 130, 200);">
Surprisingly, yes. Declaring a variable as const means the source code cannot alter its value, however also declaring it as a volatile means that the underlying value might change at any time. An example of this may be a system clock. The clock value in the register may be incremented by some hardware, but the program itself should only ever be able to read the value.
</p>

## Can you declare a static variable in header file?
### Whats the implications of doing so?

## What is a null pointer in C?

## What do each of these declarations mean?
1. `const int x;`
2. `int const x;`
3. `const int *x;`
4. `int * const x;`
5. `int const *x const;`

## What is virtual memory in embedded C and how can it be implemented?

## What is the __interupt keyword in C and what does it do?

## What is a wild pointer?

## What is a memory leak and how does it occur?

## What is endianness?
### What is the point to endianness?

## What is an ELF file?
### What are the seperate sections of an ELF file?


## How are decimal numbers represented in the computer?
### What is fixed point?
### What is floating point?
