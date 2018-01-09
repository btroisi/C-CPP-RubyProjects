Brandon Troisi
10/3/17
CS 333 Fall 2017 Project 3

Compilation environment: 

Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.7.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin


Overall Purpose:

The purpose of this week's project was to understand the usage of .h and .c files, the keyword extern, and prototype in C. We did this by implementing a stack with an array. 



c/h Files in this directory: 

The files in this directory include cstk.h, cstk.c, cstktest.c, and cstktestext.

cstk.h:

	Description: This program implemented the member functions declared in the
	
	Member functions:

		Stack *stk_create(int):
			This creates a stack with the size specified by the int value
		void stk_destroy (Stack*):
			This recycles a stack
		void stk_push(Stack*, int):
			This adds a new value to the top of the stack
		int stk_pop(Stack*):
			This removes a value from the top of the stack
		void stk_display(Stack*, int): 
			This prints out the list in the reverse order if the int value is 1, otherwise, prints out in the original order

		As an extension I created a few other member functions including:

		int get_size(Stack* stk):
			This returns size of the stack

		int peek(Stack* stk):
			This returns top value of the stack

		int is_empty(Stack* stk):	
			This returns 1 if the stack is empty, otherwise return 0


	
	
cstk.c:

	Description: This program implemented the member functions declared in the variable. We also specified the capacity of our stack as a global variable int CSTK_MAX=50. We used extern in the h file so that it could be accessed in the two test files, cstktest.c and cstktestext.c.
	


cstktest.c:

	Description: This is a test file that tested the stk_create,stk_destroy,stk_push,stk_push, stk_pop,and stk_display methods that were implemented in the cstk.c file.

	How to compile and run: 
	gcc -o cstktest cstktest.c cstk.c
	./cstktest

	Output: 
	The original list: 0 1 2 3 4 5 6 7 8 9 
	The reversed list: 9 8 7 6 5 4 3 2 1 0 

cstktestext.c: 

	Description: This is another test file that test the get_size, peek, and is_empty methods that I created as an extension in my cstk.c file.

	How to compile and run: 
	gcc -o cstktestext cstktestext.c cstk.c
	./cstktestext

	Output: 

	The list: 0 1 2 3 4 5 6 7 8 9 
	Size of the list: 10
	The list is empty: 0
	The value of the top of the stack is: 9
	The stack has been destroyed...The list is empty: 1

Extensions in C: 

	Creating additional member methods in my stack 

I recieved help from Jackie Hang.