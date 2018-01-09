Brandon Troisi
11/13/17
CS 333 Fall 2017 Project 7

Directory Layout:
Project7

|haiku.cp
|memmanage.c
|memmanage.cpp
|memmanage.rb
|my_timing.h

Compilation environment: 

Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.7.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin


Overall Purpose:

The purpose of this week's project was to examine memory management in Ruby. We did this by
answering two main questions, what is the average time per call to allocate a certain amount of memory,
and does the time of a memory management call change with the number of allocation and free operations the program has executed.


memmanage.c:


    We investegated the average time per call to allocate a certain amount of memory by 
    by allocating a small (1 byte), medium (100000 bytes) and large (100000000 bytes) amounts
    of memory for an int array 10000 times. From there, we calculated the average time it took to
    allocate and deallocate the memory for the different amounts of memory.
    
    Then we looked at how the time of a memory management call changes with the number of allocation and free 
    operations the program has executed. We did this by calculating the amount of time it takes to call 
    the memory every 1000th iteration memory is allocated and deallocated. So, this calculation
    was performed 10 times given that we allocated and deallocated memory 100000 times. 

    The output is organized by size of memory allocated and within each size of memory
    the amount of time it takes to allocate and deallocate memory at each 1000th iteration
    is performed. Then at the bottom shows the average time it takes to allocate memory 
    10000 times

Output: 


Small

Time for section call: 0.0005249977

Time for section call: 0.0000000000

Time for section call: 0.0000009537

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Time for section call: 0.0000000000

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Average time per call to allocate memory: 0.0000001843

Medium

Time for section call: 0.0000278950

Time for section call: 0.0000009537

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Time for section call: 0.0000000000

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Time for section call: 0.0000009537

Time for section call: 0.0000009537

Time for section call: 0.0000000000

Average time per call to allocate memory: 0.0000004996

Large

Time for section call: 0.0000171661

Time for section call: 0.0000009537

Time for section call: 0.0000019073

Time for section call: 0.0000019073

Time for section call: 0.0000021458

Time for section call: 0.0000021458

Time for section call: 0.0000009537

Time for section call: 0.0000019073

Time for section call: 0.0000019073

Time for section call: 0.0000019073

Average time per call to allocate memory: 0.0000020070


Meaning of output: It turns out that overall, the more memory you allocate, the longer it's 
going to take to allocate that memory. Another interesting observation was that no matter
how much memory you allocate, it takes a lot more to initially allocate that memory as opposed
to allocating that memory several times. Then, after initially allocating that memory, the amount
of time it takes to allocate memory more times stays nearly the same, no matter
how much memory you allocate. 

Extensions

I decided to make a plot of how long it took to allocate memory at every 1000th iteration
for each size of memory allocation. Each of these plots supports the pattern described 
in the Meaning of Output section. 

Small

 

Here it is for Medium

 

Here it is for Large

 
