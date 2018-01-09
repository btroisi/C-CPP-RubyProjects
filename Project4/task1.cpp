//Control statements in C++
#include <iostream>
using namespace std;

int main(){


	cout << "For loop with if statments" <<endl;
	//For loop with if statements
	//Prints values 0-9 in ascending order
	//Also prints whether value is less than 5 based on conditionals in loop
	for(int i=0;i<10;i++){

		if(i<5){

			cout << i << " is less than 5" << endl; //If i is less than 5 print value of i is less than 5
		}

		else if(i==5){

			cout << i << " is equal to 5" << endl; //If i is equal to 5 print 5 is equal to 5
		}

		else{

			cout << i << " is greater than 5" << endl;  //If i is greater than 5 print value of i is less than 5
		}
	}

	cout << "While loop with continue and break statement" <<endl;
	//While loop with break statement
	//Prints values 4-10 in descending order because loop breaks when n=4
	int n=10;
	while(n>0){
		n--;
		cout << n << ", ";

		if(n==4){

			cout << "Breaking point" << endl; 
			break; 
		}
	}

	cout<<"Do while statement with continue statement"<<endl;
	int r=0;
	//Do while statement is similar to while loop, prints before the continue once
	//Then prints after the continue, shouldn't print above statement
	do{
		r++;
		cout<<"Before the continue"<<endl;
		continue;
		cout<<("After the continue, shouldn't print above statement")<<endl;
	}while(r<5);

	cout<<"After the do while loop"<<endl;
	cout << "Switch statement" << endl; 
	
	//Demonstration of switch cases with a guessing game
	//In this case the correct number to guess is 6

	//Takes in user input from command line for their guess between 1 and 10
	int guess;
	cout << "Guess a number between 1 and 10: ";
	cin >> guess;
	
	switch (guess){

		//If the user enters a value that between 1-10 but not equal to 6
		//Program prints "Sorry you guessed incorrectly" \n The correct number was 6.
		//Break out of switch statement
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 7:
		case 8:
		case 9:
		case 10:
			cout<<"Sorry you guessed incorrectly"<<endl;
			cout<<"The correct number was 6"<<endl;
			break;
		//If the user guesses 6, program prints "Good job, you guessed correctly!" and we break out of switch statement
		case 6:
			cout<<"Good job, you guessed correctly!"<<endl;
			break;
		
		//If the user inputs anything (number that is not between 1-10 or a string) 
		//Program prints you did not enter a number between 1 and 10 and we break out of switch statemtnt
		default:
			cout<<"You did not enter a number between 1 and 10"<<endl;
			break;
		
	}

	return 0; 
}

