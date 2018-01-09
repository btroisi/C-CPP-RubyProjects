#include<iostream>
using namespace std; 


int calculate(int a, int b){
    //Returns sum of two integers
    return a+b;
}

double calculate(double a, double b){
    //Returns product of two doubles
    return a*b;
}

//Create Parent class with show method
class Parent{
public:
    void show(){
        //Print "I am a parent"
        cout<<"I am a parent"<<endl;
    }
};
//Create Child class that is child class of Parent class
class Child: public Parent{
public:
    void show(){
        //Print "I am a child" this overrides show funciton from parent class
        cout<<"I am a child"<<endl;
    }
};

int main(){

    int a=4, b=5;
    double c=6, d=9.6;
    cout<<"Calculate (4,5): "<<calculate(a,b)<<endl;
    cout<<"Calculate (6.0,9.6): "<<calculate(c,d)<<endl;
    Child child = Child();
    child.show();
    return 0; 

}