---
title: thinkos
layout: post
author: hooticambo
permalink: /thinkos/
source-id: 1N94bLc8d5xonjde4h3QlUbFcyWgjH7vGY3D3tsy7Hpo
published: true
---
## Chapter 1

### **Compilation**

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

* Dynamic typing

2) Name two advantages of static typing over dynamic typing.

* Errors can be found in parts of the program that haven't been run.

* Save space - dynamic language variable names are saved in memory. Compiled languages simply refer to a memory address.

3) Give an example of a static semantic error.

* Calling a function with the wrong number of arguments.

4) What are two reasons you might want to turn off code optimization?

* Longer compilation times.

* New bug might appear.

5) When you run gcc with -S, why might the results look different on different computers?

* gcc is configured to generate assembly code for the machine you are using. A laptop using an x86 processor will probably look different than a mobile phone processor.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different. Why?

* Often times the compiler will spit out a whole bunch of error messages when you misspell a variable name. Only the first error message will be the relevant one.

7) What is a segmentation fault?

* Segmentation fault occurs when you try to read or write memory in such a way that isn't "allowed".

## Chapter 2

### **Processes**

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

* Virtual private network.

2) What is the difference between a program and a process?

* Processes are the software object that isolates programs. Programs are usually isolated from each other so they don't negatively affect each other.

3) What is the primary purpose of the process abstraction? What illusion does the process abstraction create?

* The operating system uses process abstraction to make sure that the processes don't interfere with each other. For example, in a 32 bit system, each program has virtual memory addresses from 0x0000000 to 0xfffffff. This virtual memory allows both processes to use memory address 0x0000000 as they are different physical memory addresses. Process abstraction also make sure that processes don't write data to the same storage location.

4) What is the kernel?

* The kernel is responsible for the core parts of the operating system, such as creating threads.

5) What is a daemon?

* A daemon is a process that runs in the background. A commonly used daemon is the "cron daemon" used to run other programs at specified times.

## Chapter 3

### **Virtual memory**

1) The Georgian alphabet has 33 letters. How many bit are needed to specify a letter?

* b >= log2(33)

* b = 6

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.

Ignoring the details of the encoding scheme, how many different characters can be represented?

* 2^32 = 4294967296

* 4294967296 different characters

3) What is the difference between "memory" and "storage" as defined in Think OS?

* "memory" refers to volatile memory such as RAM.

* "storage" refers to non-volatile memory such as an SSD or HDD.

4) What is the difference between a GiB and a GB? What is the percentage difference in their sizes?

* GB is 10^9 bytes

* GiB is 10^9 bits

* 1 byte = 8 bits

* 12.5% of 1 GB = 1 GiB

5) How does the virtual memory system help isolate processes from each other?

* In a 32 bit system, each program has virtual memory addresses from 0x0000000 to 0xfffffff. This virtual memory allows both processes to use memory address 0x0000000 as they are different physical memory addresses

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

* It is unknown how much data the stack and heap are going to use. We start them at opposite ends of the memory address space to make sure that they don't interfere with one other.

7) What Python data structure would you use to represent a sparse array?

* !

* Dictionary of Keys based sparse matrix.

8) What is a context switch?

* A context switch is when the operating system interrupts a running process, saves its state, and then switches to another process.

In this directory, you should find a subdirectory named aspace that contains aspace.c. Run it on your computer and compare your results to mine.

1) Add a second call to malloc and check whether the heap on your system grows up (toward larger addresses).

2) Add a function that prints the address of a local variable, and check whether the stack grows down.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.

How much space is there between them? Hint: Google knows how to subtract hexadecimal numbers.

## Chapter 4

### **Files and file systems**

1) What abstractions do file systems provide? Give an example of something that is logically true about files systems but not true of their implementations.

* File systems give the illusion that files are stored in a nice tree like structure. In reality, operating systems store files in locations, and then record where the file was stored.

2) What information do you imagine is stored in an OpenFileTableEntry?

* A position in the file that keeps track of where it was read. A starting address for the first byte in the file.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

* Block transfers - the difference between loading a single byte and the additional time to load an 8KiB is almost zero. So the operating system can sometimes to additional work on the remaining 8KiB of data. Prefecting - if the operating system can predict that it needs to read a block, it will prefetch the block before the program has actually requested it. Buffering - if many changes are made to the same byte of memory, the operating system will wait until the final change before it writes it to the disk. Caching - the operating system keeps around blocks that it has recent used in faster memory such as RAM.

4) Suppose your program writes a file and prints a message indicating that it is done writing.

Then a power cut crashes your computer. After you restore power and reboot the computer, you find that the file you wrote is not there. What happened?

* The IO is buffered. fprintf will only write to a file when you close the file. You can use fflush(fp) to clear the buffer and write to the file.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode? Or an advantage of a inode over a FAT?

* It can be easier to do data recovery with a File Allocation Table. For example, if you want to recover jpgs off of an SD card, the bytes that make up the jpgs will be stored contiguously across blocks. This allows for much easier data recovery.

* Inodes are better at storing large files. Since inodes can be filled with pointers to more inodes, the maximum file size is extremely large.

6) What is overhead? What is fragmentation?

* Overhead - storage taken by the data structure

* Fragmentation - unused space in a block.

7) Why is the "everything is a file" principle a good idea? Why might it be a bad idea?

* Standardization is a powerful.

* Subtle errors in file systems can lead to powerful exploits.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.

Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then [Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).

Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).

## Chapter 5

### **Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number. What happens if you convert it to a 16-bit number and accidentally apply sign extension?

* 0b1000 0000

* 0b0000 0000 1000 0000

* 0b1111 1111 0111 1111 + 0b0000 0000 0000 0001

* 0b1111 1111 1000 0000

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. Try it out and confirm that the result is interpreted as -12.

* I get -2147483635 which isn't all that unexpected.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision IEEE floating-point. What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.

As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one character at a time. This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

## Chapter 6

### **Memory management**

1) Which memory management functions would you expect to take constant time? Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.

3) Run

ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical memory a process has. Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks? What can you do to mitigate the problem?

If you want to know more about how malloc works, read [Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)

## Chapter 7

### **Caching**

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average access time of a program with hit rate 50%? How about 90%?

4) The book gives several examples of programming language features, like loops, that tend to improve locality in the access pattern of instructions and/or data. Can you think of other examples?

Or counter-examples that might decrease locality?

5) If you refactor a program to improve locality, would you say the program is "cache aware"? Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.

If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named cache that contains cache.c and supporting files. Read cache.c, then run make and ./cache.

2) Run python graph_data.py to see the results. What can you infer about the cache structure on your computer?

## Chapter 8

### **Multitasking**

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices. But my griddle only has room for 8 slices. Each piece of toast has to cook for 5 minutes on each side. How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices? (Note: this question is not hypothetical; this is really how I make French toast.)

## Chapter 9

### **POSIX threads and mutexes**

As you read Chapter 9, you should compile and run the example code. By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the gcc flag -lpthread do?

3) What does the argument of pthread_exit do?

4) Normally the same thread that created a thread also waits to join it. What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?

## Chapter 10

### **Condition variables**

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue n-1, if n is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true? What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?

## Chapter 11

### **Semaphores in C**

