//Function types in C++
#include <iostream>
using namespace std;

//Function B returns x*2.0 as a double
double B(int x){

	return x*2.0;
}

//Function A passes in a reference to a function that returns a double 
//but takes in an int as its parameter
void A(double (*f)(int)){

	//Prints result of calling reference to function *f on integers 0-9
	for(int i=0;i<10;i++){
		cout<<f(i)<<endl;
	}
}

int main(){

	//Passing in function as a parameter
	//In this case we call A and pass in B as the parameter
	//The result is doubling all of the integers between 0 and 9
	A(B);
}