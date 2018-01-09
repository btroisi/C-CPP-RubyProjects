#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std; 

 
template<class T>
struct Node
{
	/*Defines struct for node*/
	T data; //Represents word
    Node<T> *next; //Next pointer 
    int count; //Shows how many times word appears
    int printed; //Shows whether word has been printed 
};

template<class T>
class LinkedList
{
	/*Defines class for linked list*/
	public:
	Node<T> *head, *tail;
    int size;
    //Initialize linked list
	LinkedList(){
		head=NULL;
		tail=NULL;
		size=0;
	}

/*Adds new word to list if we haven't encountered word yet
Otherwise, increases count by 1 of word we have seen*/
	void push(T newword){
        if(head==NULL){
        //If there is no word in the list
		//Create a new node to represent that set its count to 1 and printed to 0
            Node<T> *new_node = new Node<T>;
            new_node->data=newword;
            new_node->count=1;
            new_node->printed=0;
            new_node->next=NULL;
            head=new_node; 
            size++;
		
        }
        else{
            //Otherwise if there are one or more words on the list
            Node <T> *cur = head;
            while(cur!=NULL){
                if(cur->data!=newword){
                //If the word we are adding to the list is not already there
				//Keep traversing through the list until we reach the end
                    cur=cur->next;
                }
                
                else {
                //Otherwise if the word we are adding to the list is already there
				//Increment the count of the word already in the list by 1
				//Do not create a new node for the word
                    cur->count++;
                    return;
                }
                
            }
            
            //For a new word in the list
		    //Create a new node to represent the word and set count to 1
            Node<T> *new_node = new Node<T>;
            new_node->count=1;
            new_node->printed=0;
            new_node->data=newword;
            new_node->next=head;
            head=new_node; 
            size++;

        }
 
    }

    /*Returns a unique word associated with a particular frequncy */
    T mapfreqtouniqueword(int freq){
        
        //If head is null return null
        if(head==NULL){
            return NULL;
        }
        
        Node<T> *cur=head; 
        T retval; 
        
       //While the current node is not null get the count associated with that word and the reference to that count
        int curwordfreq=cur->count;
        int *current=&curwordfreq;
        while(cur != NULL){
            curwordfreq=cur->count;
            if((curwordfreq==freq && cur->printed == 0 )){
            //If we are at the word we are looking for according to its count and it hasn't been printed yet
			//Return this word
			//and set its printed value to 1 to show that it's been printed 
			//so we return a unique word every time this function is called
                retval=cur->data;
                cur->printed=1;
                return retval; 
            }
            
            else{
                //Otherwise keep traversing through the list to see if that frequency appears in the list
                cur =cur->next;
            }
            
        }
        return NULL;
    }
	int get_size(){
	//Returns size of list
		return size;
	}

};

int compFreq(const void *i, const void *j) {
    //Compare funciton that returns the difference between the first and second frequency
	//Returns values in descending order
    int a = *(const int *)i;
    int b = *(const int *)j;
    return b-a;  
}


int main(){
    
    string word;
    string filename;
    LinkedList<string> wordlist; //Initialize wordlist that holds strings, a linked list

    //Prompts user to put in file name for which to run word counter program on and reads it in
    cout<<"Enter the file name to test your word counter on: "<< endl;
    getline(cin,filename);
    ifstream inputfile (filename);

    if(!inputfile.is_open()){ cout<<"Cannot open the file"<<endl; exit(1); } //If file does not exist print "cannot open the file" and exit the program

    while(inputfile >> word){
        //Read each word in file while there is a word to be read
        ::transform(word.begin(), word.end(), word.begin(), ::tolower); //Change all characters in each word to lowercase
        word.erase(::remove_if(word.begin(), word.end(), ::ispunct), word.end() ); //Removes punctuation marks from each word
        wordlist.push(word); //Pushes this lowercase, stripped word  onto list,
    }

    //Create array to put frequencies of each word in wordlist into
    int freq[wordlist.get_size()]; 
	int i=0;
	Node<string> *cur = wordlist.head; 
	while (cur != NULL) {
		freq[i]=cur->count; 
		cur = cur->next;
		i++; 
	}
    
    //Sort array of frequencies using qsort
	qsort((void*)freq, wordlist.get_size(), sizeof(int),
	 compFreq);

    //Print top 20 words in descending order with word and frequency
	for(int i=0;i<20;i++){
		cout<< wordlist.mapfreqtouniqueword(freq[i]) << " : " << freq[i]<<endl;
		//printf("%s : %d\n", ll_return_word(wordlist,i), freq[i]);
		
	}
    inputfile.close(); //Close the file
	return(0);
}



