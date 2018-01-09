#include <iostream>
using namespace std;

//Dynamically create and destroy int array of size 10
int main(){
    int *arr = new int[10]; //Dynamically create int array of size 10
    if(!arr){
        //Check if allocation failed
        cout<< "Allocation of memory failed"<<endl; 
    }
    else{
        //Put integers 0-9 into each slot of int array
        for(int i=0; i<10;i++){
            arr[i]=i;
        }
        //Print all values of array
        cout<<"Value stored in memory"<<endl;
        for(int i=0; i<10;i++){
            cout<<arr[i]<<endl;
        }
    }
    delete[] arr; //Destroy array
    return 0; 
}


