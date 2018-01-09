#include <iostream>

int main(){

	int i=5;
	int j=0;
	int outervar=700;
	int g=20;

	for(int i=0,j=10;i<j;i++,j--){

		int innervar=699; 
		int g=19; 
		std::cout << "Inner Scope i= " <<i << " j=" << j << "\n";
		std::cout << "Printing the inner var..." <<innervar <<"\n";
		std::cout << "Printing the outer var..." <<outervar <<"\n";
		std::cout << "g: " << g << "\n";

	}
	std::cout << "Outer Scope i= "<<i << " j=" << j <<"\n";
	//std::cout << "Printing the inner var..." <<innervar;
	std::cout << "Printing the outer var..." <<outervar <<"\n";
	std::cout << "g: " << g << "\n";
	

	return 0;


}