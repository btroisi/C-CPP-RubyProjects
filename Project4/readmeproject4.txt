Brandon Troisi
10/9/17
CS 333 Fall 2017 Project 4

Compilation environment: 

Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.7.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin


Overall Purpose:

The purpose of this week's project was to understand the function handler of C. We practiced this by using the library function quicksort.



c files in this directory: The only c file for this week's project is quicksort.c

quicksort.c:

	Description: Given an array of random integers sort the array sort a that the even numbers apper first and the odd numbers apper later. From there, the even numbers should be sorted in descending order and the odd numbers should be sorted in ascending order.

	How the code worked: C's quicksort algorithm takes in a void pointer to an array, the low and high bounds for using the quicksort algorithm, and a comparator function, which we had to write ourselves so the array would be sorted as defined in the description. The comparator funciton took in two const int pointers as its parameters In our comparator we had four cases that compared the values in the array in the following way:

		Case 1: If both values of the pointers are are odd put lesser value first

		Case 2: If both values of the pointers are even, put greater value first

		Case 3: If the first pointer value is odd and the second pointer value is even put the second piointer value first first 

		Case 4: If the first pointer value is even, put that even value first.

	These cases allowed us to apply the quicksort algorithm to any array of integers so that the values were sorted as defined in the description.

	Array to be sorted: The array that we were given to sort was [10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12]

	Output: The sorted array is: 12 10 8 6 4 2 0 1 3 5 7 9 11 13 

Extensions in C: In doing this task, I implicityly created the most efficient quicksort algorithm I could make as I minimize the number of operations that the comparator has to perform. This is because I have only 3 conditional statements handle 4 cases. The code to handle each of the cases is as follows: 

	//If m and n are odd put lesser value first
	if ((m&1) && (n&1)){
		return (m-n);
	}

	//If m and n are even, put greater value first
	if (!(m&1) && !(n&1)){
		return (n-m);
	}

	//If m is odd and n is even put n first 
	if((m&1)){

		return 1;
	}

	//m is even put m first
	return -1; 

In this code, m and n are the values of the pointers passed into the parameters of the comparator.
I could have designed this program so that it would handle the 4 cases separately by performing mod operations when each pointer m and n was odd or even. However, I thought that performing bitwise operations was more efficient as you only need to check the least significant bit for each value instead of performing mathematical calculations on them. 

C forums was helpful for this project