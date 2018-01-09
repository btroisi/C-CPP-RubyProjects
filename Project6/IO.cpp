#include<iostream>
#include<fstream>
using namespace std; 

//Reads content from file and prints to terminal
void readFromFile(){
    string line;
    string filename;
    cout<<"Enter the file name to read data from: "<< endl; //Prompt user to enter filename
    getline(cin,filename); //Stores user input 
    ifstream inputfile (filename); //User input is filename from which to retrieve data from
    if(inputfile.is_open()){
        while(getline(inputfile,line)){
            cout<<line<<endl;  //If file exists go through file and print each line in file
        }
        inputfile.close();
    }
    else{ 
        cout << "Cannot open the file"<<endl; //If file doesn't exist print "Cannot open the file"
    }
}

//Reads content from file and writes content to another file
void writeToFile(){
    string infname;
    string lines; 
    ofstream outputfile;
    outputfile.open("IOoutputcpp.txt"); //Initializes output file to IOoutput.txt
    cout<<"Enter the file name to read data from: "<< endl; //Prompt user to enter filename
    getline(cin,infname); //Store command line input
    ifstream inputfile (infname); //User input is filename from which to retrieve data from
    if(inputfile.is_open()){
        while(getline(inputfile,lines)){
            outputfile<<lines<<endl; //If input file exists go through file and print each line in file in IOoutput.txt
        }
        inputfile.close();
        cout<<"Data written to IOoutputcpp.txt"<<endl; 
        outputfile.close();
    }
    else{
        cout << "Cannot open the file"; //If file doesn't exist
    } 
}

//Read binary file called BinaryFile.bin and print contents to terminal
void readBinaryFile(){
    string line1;
    ifstream binputfile; 
    binputfile.open("BinaryFile.bin", ios::in | ios::binary );
    if(binputfile.is_open()){
         while(getline(binputfile,line1)){
            cout<<line1<<endl;
        }
        binputfile.close();
    }     
    else{
        cout << "Cannot open the file";
    }
}
int main(){
    //Test all of the functions defined aboce
    cout<<"Reading from text file"<<endl; 
    readFromFile();
    cout<<"\nWriting to text file"<<endl;
    writeToFile();
    cout<<"\nReading from binary file"<<endl; 
    readBinaryFile();
    return 0;
}