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
<p style="color: rgb(80, 130, 200);">
Yes, this would be considered a global static variable for the .C file that the header is included in.
</p>

### Whats the implications of doing so?
<p style="color: rgb(80, 130, 200);">
Each file that includes the header will get its own copy of the static variable. Can't be used for sharing variables between files. Each time a file within that C function alters the static variable, it will of course maintain its state between function calls. It will restrict the scope of the variable to the entire C file, as opposed to if it were declared within a specific function, to that function.
</p>

## What is a null pointer in C?
<p style="color: rgb(80, 130, 200);">
A null pointer is a pointer that points to nothing, or the null address. If using an OS this would trigger a segfault. If you create a pointer but do not initialize where it is pointing to, it probably points to null.
</p>

## What do each of these declarations mean?
1. `const int x;`
<p style="color: rgb(80, 130, 200);">
Declared a constant integer x, but did not initialize it to any value, so it is stuck that way now.
</p>

2. `int const x;`
<p style="color: rgb(80, 130, 200);">
Same meaning as the previous. C allows you to declare a constant variable in either way.
</p>

3. `const int *x;`
<p style="color: rgb(80, 130, 200);">
Is declaring that x is a pointer that points to a constant integer. The integer it points to cannot change. However, x could point to any address.
</p>

4. `int * const x;`
<p style="color: rgb(80, 130, 200);">
A constant pointer to an integer. In this scenario the address of which x points to cannot change. The value of the integer is allowed to be change however.
</p>

5. `int const *x const;`
<p style="color: rgb(80, 130, 200);">
A combination of the previous points. Here we declare a constant pointer that points to a constant integer. So the pointer cannot be used to changed the value of the int and the pointer itself cannot point to anything else but that int.
</p>

## What is virtual memory in embedded C and how can it be implemented?
<p style="color: rgb(80, 130, 200);">
Virtual memory is the concept of creating an execution space for a process which believes it has full control over the comuter hardware. However, in reality, typically an OS is mediating allocation and readings of memory values. To provide virtual memory, an MMU is required so that physical memory can be segmented per process. Virtual memory is typically used in OS's, however some forms of virtual memory can technically exist is the case of memory mappable IO for example, where an SoC may have some GPIO mapped to given memory values.
</p>

## What is a wild pointer?
<p style="color: rgb(80, 130, 200);">
A wild pointer is a pointer which is not initialized or who's memory region it originally referenced has since been freed. If you attempt to dereference the pointer, you may encounter undefined behavior. Typically you would call free() and then ptr = null; to reset a pointer completely.
</p>

## What is a memory leak and how does it occur?
<p style="color: rgb(80, 130, 200);">
A memory leak is when some process or function acquires some memory (maybe through malloc()) and then after it is done using that memory region, does not call free(). If the function exits without calling free, the region of memory stays reserved for the rest of the processes lifetime however the code has no way of retrieving the address of it (since presumably the pointer has now been popped off the stack). In a long running program this can cause the machine to run out of memory for the process, causing a crash.
</p>

## What is endianness?
<p style="color: rgb(80, 130, 200);">
Endianness is the byte-order of which variables are stored in memory for a given system. This is defined by the hardware (CPU archiecture) of the system. Little endian means that the first address of the first byte of a memory object will contain the least signficiant bit (LSB) of the object. Big endian is the reverse where things read more chronologically. Network order is big endian when transporting packets.
</p>

### What is the point to endianness?
<p style="color: rgb(80, 130, 200);">
For the case of little endian, it can speed up memory access and typical use of access data stored in memory. For big endian, it is somtimes important to read the header of an incoming data packet before the rest of the information arrives over the channel.
</p>

## How are decimal numbers represented in the computer?
### What is fixed point?
### What is floating point?

## Explain a Mutex
<p style="color: rgb(80, 130, 200);">
A mutex is a method of ensuring that multi-threaded programs have controlled access to a variable, to eliminate race conditions. In a mutex lock situation, to access or write to a variable, the process must first acquire a mutex lock. If another process has the lock, the second process needs to wait for the other to release the lock. It is usually implemented by having a structure that contains a boolean value that the processes try to acquire. The risk of this approach is that if a process does not ever release the lock, no other processes can continue.
</p>

## Explain a Semaphore
<p style="color: rgb(80, 130, 200);">
In a semaphore, there may be more than one worker accessing the control structure. In this case, you may implement a counting semaphore. For a sempahore to be incremented, the process does not need to have 'acquired' it. It can be used to dispatch jobs so long as the counter is >0. If the counter reaches 0, then the worker threads would block.
</p>

## Explain the differnces between a semaphore and a mutex
<p style="color: rgb(80, 130, 200);">
Whereas a mutex is more 'ownership' based, a sempahore is not. A mutex may be considered simpler, but is less flexible as it can basically only be used for a single resource or variable. A semaphore, although more complex, may be considered more flexible since you can declare many resources within a single object.
</p>
