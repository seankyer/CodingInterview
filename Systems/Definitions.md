# Definition of Terms Related to Embedded Systems
<p style="color: rgb(80, 130, 200);">Answers written in blue</p>

## Generic Terms
### Embedded C Programming
<p style="color: rgb(80, 130, 200);">
Embedded C programming is the process of writing C code for an embedded electronic (obviously). In general, the languages are the same, however the usage differs from traditional C. Specific toolchains and interactions may differ.
</p>  

1. <p style="color: rgb(80, 130, 200);">Embedded C will interact directly with hardware components such as sensors, peripherals or GPIO.</p>
2. <p style="color: rgb(80, 130, 200);">Sometimes in an embedded system (microcontroller for example) you don't have an OS, so certain OS library functions wont wont like malloc() for example.</p>
3. <p style="color: rgb(80, 130, 200);">The compiler used may differ from your typical gcc. Depending on your platform, the vendor may supply a compiler to you or you will have to consider the architecture of the target CPU.</p>

### Embedded System
<p style="color: rgb(80, 130, 200);">
An embedded system is essentially a computer that is designed for some specific task in mind. It may be a part of a larger electronic device and will tailor its needs specifically. It differs from a general purpose computer in that the system will be min-maxed to suit the needs of the greater electronic system or product goal. That means it may be missing subsystems like RAM or a UI if it's not required for the task. 
</p>

<p style="color: rgb(80, 130, 200);">
'Embedded Systems' is a broad term and the specifics usually come down to the task at hand. But in general, I'd describe it as dealing with low-level programming for an electronic system.
</p>

### Firmware
<p style="color: rgb(80, 130, 200);">
Type of software for lowlevel control over a system. Typically the firmware, unlike software, is permament to the system once deployed and may reside in some read-only memory. Usually used to refer to the control software of an embedded deveice which may also control some hardware compoenents (servos, shutters, peripherals).
</p>

### Microcontroller
<p style="color: rgb(80, 130, 200);">
A microcontroller is a type of integrated circuit that would combine a processor, some memory and GPIO. It is lighter weight than an SoC. It has no memory management unit and is typically used for low-level tasks such as controlling some hardware or performing a subroutine.
</p>

### Microprocessor
<p style="color: rgb(80, 130, 200);">
A microprocessor is the CPU (central processing unit) of a computer or device. is a type of integrated circuit that would contain all of the components to be the central processing unit of a computer. A microprocessor may have multiple processing cores on it, allowing for mutli-core execution of a program.
</p>

### SoC
<p style="color: rgb(80, 130, 200);">
An SoC, or 'System on Chip' is a type of integrated circuit that combines all the periphals and hardware needed to be a fully functional computer. It would contain a processor, RAM, MMU, some ROM potentially, GPIO, etc. The SoC, having an MMU is capable of running an operating system and supporting multi-processing. The SoC is essentially the entire conventional computer rolled into a single chip.
</p>

### RTOS
<p style="color: rgb(80, 130, 200);">
An RTOS (real-time operating system) is a type of operating system that can operate in 'real-time'. Meaning that when a task is running on a given core, it cannot be interrupted or stopped by any abstraction layers in a typical operating system. In a conventional operating system, the OS would share CPU resources with different processing, and if done correctly, provides the user with a seamless experience as if each process has total computing power. However, in an embedded system, where precise timing may be critical (monitoring a sensor for example), there can be no gaps in processing time for certain processes. But if the engineer still wants the benefits of an OS (networking abstractions, multi-threading, IPC, etc) then an RTOS may be appropriate over a dedicated microcontroller.
</p>

### RTOS Scheduler
<p style="color: rgb(80, 130, 200);">
The RTOS scheduler is what determines which tasks get hold of which processing cores. There are many different implementation of the RTOS scheduler. Typically, a process may be given a priority level and depending on the OS configuration, when a process of high priority is set to run, it will have uninterrupted access to the CPU core.
</p>

### Cross Compilation
<p style="color: rgb(80, 130, 200);">
Cross compiling is where you program the code for a device using a separate device which's CPU architecture may differ. When you cross-compile the code, it would not run on your host system and would instead need to be transported to the target device before it could be executed. It depends on which compiler you use at build-time. It also required cross-compiling any libraries you used when writing the code. Everything needs to be compatible with the architecture of your target CPU.
</p>

### Hardware Abstraction Layer (HAL)
<p style="color: rgb(80, 130, 200);">
The hardware abstaction layer is as it sounds. It allows a program or OS to interact with the hardware of the baremetal in an abstracted way. For example, you may be able to 'turn off/on' a periphals such as an LED using some function. What is not known to the host program is how the driver of the LED is written and in what manner it is communicated to the LED that it must change its state. This concept can be extended to any piece of hardware that could be interacted with. Providing a HAL allows for more general software writing and then the hardware interface can be swapped interchangably (given it has the same features and drivers written).
</p>

### ELF
<p style="color: rgb(80, 130, 200);">
A file format for executable files. The ELF file has roughly the following structure:
</p>  

1. <p style="color: rgb(80, 130, 200);">Header: contains information on ELF type (object, executable, library)</p>
2. <p style="color: rgb(80, 130, 200);">Text: machine code to be ran on CPU</p>
3. <p style="color: rgb(80, 130, 200);">Data: initialized variables from the code ex: int y = 3; (read/write)</p>
4. <p style="color: rgb(80, 130, 200);">BSS: Uninitliazed variables from the code ex: int y; (read/write)</p>


## Peripherals

### Board Support Package (BSP)
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### DMA
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### GPIO
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### Flash Memory
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### RAM
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### EEPROM
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### Clock Speed
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### Watchdog Timer
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### JTAG
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### SPI Flash Programming
<p style="color: rgb(80, 130, 200);">
TODO
</p>


## Processes

### Bootloader
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### Startup Code
<p style="color: rgb(80, 130, 200);">
TODO
</p>

### Interupt Service Routine (ISR)
<p style="color: rgb(80, 130, 200);">
TODO
</p>
