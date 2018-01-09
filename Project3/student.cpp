#include <iostream>
using namespace std;

struct Student
{
    string name;
    int classyear;
    string major;
    float gpa;
};

int main()
{
    Student s1;
    s1.name="Brandon";
    s1.classyear=2019;
    s1.major="CS/Math";
    s1.gpa=3.70;

    Student s2; 
    s2.name="Kate";
    s2.classyear=2019;
    s2.major="CS/Econ";
    s2.gpa=3.40; 
 
    
    cout << "\nDisplaying Information for student 1" << endl;
    cout << "Name: " << s1.name << endl;
    cout <<"Class year: " << s1.classyear << endl;
    cout << "Major: " << s1.major << endl;
    cout << "GPA: " <<s1.gpa << endl; 
    
    cout << "\nDisplaying Information for student 2" << endl;
    cout << "Name: " << s2.name << endl;
    cout <<"Class year: " << s2.classyear << endl;
    cout << "Major: " << s2.major << endl;
    cout << "GPA: " <<s2.gpa << endl; 

    return 0;
}