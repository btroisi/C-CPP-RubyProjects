#include <iostream>
using namespace std; 

 
template<class T>
struct Node
{
	/*Defines struct for node*/
	T data;
	Node<T> *next;
};

template<class T>
class LinkedList
{
	/*Defines class for linked list*/
	public:
	Node<T> *head, *tail;
	int size;
	LinkedList(){

		head=NULL;
		tail=NULL;
		size=0;
	}



	void push(T data){
		// adds a node to the front of the list, storing the given data in the node.
		Node<T> *new_node=new Node<T>;
		new_node->data=data;
		if (size ==0){
			head = new_node;
			tail = new_node;
			tail->next= NULL;
			size ++;
			return;
		}
		
		new_node->next=head;
		head = new_node;
		size++;
 
	}

	T pop(){
		//removes the node at the front of the list and returns the associated data.
		if(head==NULL){
			return 0;
		}
		T retval = head->data;
		Node<T> *removed_node = head;
		head=removed_node->next;
		size--;
		return retval;
	}

	void append(T data){
		//adds a node to the end of the list, storing the given data in the node.
		if(head==NULL){
			Node<T> *new_node=new Node<T>;
			new_node->data=data;
			new_node->next=NULL;

			head=new_node;
			tail=new_node;
		}

		else{

			Node<T> *cur = head;
			while(cur->next!=NULL){
				cur=cur->next;
			}

			Node<T> *new_node=new Node<T>;
			new_node->data=data;
			new_node->next=NULL;
			cur->next=new_node;
			tail=new_node;
			tail->next=NULL; 
		}
		size++;
	}
	T remove(T target){
	//removes the first node in the list whose data matches target

		//If head is null
		if(head==NULL){
			return NULL;
		}

		Node<T> *cur=head;
		T retval=NULL;

		//If the first node in the list whose data matches target given the comparison function is the head.
		//Free and return data at the head
		if(cur->data==target){
			retval=cur->data;
			head=cur->next;
			size--;
			return retval; 
		}

		Node<T> * next_node=cur->next;
		//while we are not at the node before the one we are looking for
		while(next_node->data!=target){
			if(next_node->next != NULL){
			//If next node from node we want to delete is not null
			//Keep traversing through list 
				cur=cur->next;
				next_node = next_node -> next; 	
			}
			else{
				//If data we are looking for is not in list return null
				return NULL;
			}
		}
		retval=next_node->data;
		//If the node we are looking for is in the middle of the list
		if(next_node->next!=NULL){
			cur->next=next_node->next;
			size--;
			return retval;

		}
		//If the node we are looking for is at the end of the list
		else if(next_node->next==NULL){
			cur->next=NULL;
			size--; 
			return retval; 
		}
	return retval; 


	}

	int get_size(){
	//Returns size of list
		return size;
	}

	void clear(){
	//Removes all nodes from list
		head = NULL;
		tail = NULL;
		size = 0;

		return; 
	}

	void map(LinkedList<T> l,void (*mapfunc)(T thing)){
	// traverses the list and applies the given function to the data at each node.
		if(l.head!=NULL){
	
			Node<T> * cur=l.head;
			while(cur!=NULL){
				mapfunc(cur->data);
				if(cur->next!=NULL){
					cur=cur->next;
				}
				else{
		
					return; 
				}
			}
		}
		return; 
	}

	T deleteAtIndex(int index){
	//Deletes node at a particular index of a list and returns data at that node

		//If head is null return null
		if(head==NULL){
			return NULL;
		}

		Node<T> * cur=head; 
		T retval=NULL; 

		//If index we want to delete is first index
		//Delete and return data associated with node at this index 
		if(index==0){
			retval=cur->data;
			head=cur->next;
			size--;
			return retval; 
		}

		Node<T> *next_node=cur->next;

		//Otherwise keep traversing through list until you get to node
		//before the node at the index which you would like to delete
		for(int i=0;i<index-1;i++){
			if(next_node->next != NULL){
				cur=cur->next;
				next_node = next_node -> next; 	
			}
			else{
				return NULL;
			}
		}
		retval=next_node->data;

		//If the node we are looking for is in the middle of the list
		if(next_node->next!=NULL){
			cur->next=next_node->next; 
			size--;
			return retval;

		}
		//If the node we are looking for is at the end of the list
		else if(next_node->next==NULL){

			cur->next=NULL;
			size--; 
			return retval; 
		}
		return retval; 
	}

};

template<class T>
void printval(T val){
	//Function outside of linked list class that prints the value of the list
	cout<< "Value: " << val <<endl; 
}

int main(){
	// test function for the various linked list functions
	// tests linked list functions for ints and char types
	cout << "Initializing a list of integers by pushing" << endl;
	LinkedList<int> llint;
	for(int i=0;i<10;i++){
		llint.push(i);

	}
	
	llint.map(llint,printval);
	
	cout << "Popping from the list" << endl; 
	llint.pop();
	llint.map(llint,printval);


	cout << "After Removing from index 4" << endl;
	llint.deleteAtIndex(4);
	llint.map(llint,printval);

	cout << "Removing 6 from the list" <<endl;
	llint.remove(6);
	llint.map(llint,printval);

	cout << "Trying to remove 12 from the list" <<endl;
	llint.remove(12);
	llint.map(llint,printval);
	
	cout << "Done with the int list..time to clear" <<endl;
	llint.clear();
	llint.map(llint,printval);

	LinkedList<char> llchar;

	cout << "Initializing a list of char by appending" << endl;
	llchar.append('c');
	llchar.append('s');
	llchar.append('i');
	llchar.append('p');
	llchar.map(llchar,printval);
	cout << "Size of list: " << llchar.get_size()<<endl;


	cout << "After removing value at index 1 from the list" <<endl;
	llchar.deleteAtIndex(1);
	llchar.map(llchar,printval);


	cout << "Removing p from the list" <<endl;
	llchar.remove('p');
	llchar.map(llchar,printval);

	cout << "Removing b from the list" <<endl;
	llchar.remove('b');
	llchar.map(llchar,printval);

	cout << "Done with the test..time to clear" <<endl;
	llchar.clear();
	llchar.map(llchar,printval);


	return(0);
}



