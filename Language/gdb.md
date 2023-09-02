# Commands for using GDB

## Compiling  
You must compile using gcc with the `-g` flag so the binary include debug information.

## Commands  
- `gdb ./filename` - to launch gdb  
- `br filename.c:function_name/line_number` - to set a breakpoint  
    - `info br` - gives you info on currently set breakpoints
    - `delete x` - (where x is the br id) deletes the breakpoint
- `r` - to start running the file
- `c` - to continue running until next breakpoint  
- `n` - to go to the next instruction (will skip over any function calls)  
- `s` - to step into a function call or go to the next instruction  
- `list` - prints code around your current execution point
- `frame` - prints the current instruction you're on
- `bt` - prints the current backtrace (callstack)