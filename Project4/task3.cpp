/**
 * Given an array of any type, use quicksort to sort it in ascending order

 */


#include <iostream>
#include <cstdlib>
using namespace std;

//quicksort method takes in array of any tpy constant address onf int leftarg and righarg
template<class T> void quicksort(T a[], const int& leftarg, const int& rightarg)
{
  //This function takes first element as pivot, places
  //the pivot element at its correct position in sorted
  //array, and places all smaller (smaller than pivot)
  //to left of pivot and all greater elements to right
  //of pivot
  if (leftarg < rightarg) {

    T pivotvalue = a[leftarg];
    int left = leftarg - 1;
    int right = rightarg + 1;

  for(;;) {

    //While traversing, if we find a smaller element to right of current element, 
    //we swap current element with the larger element. Otherwise we ignore current element.
    while (a[--right] > pivotvalue);
    while (a[++left] < pivotvalue);

    if (left >= right) break;

    T temp = a[right];
    a[right] = a[left];
    a[left] = temp;
  }

  int pivot = right;
  quicksort(a, leftarg, pivot);
  quicksort(a, pivot + 1, rightarg);
  }
}

//We test this method on a list of ints and chars. 
int main(void) {
  int list[10];

  //Creates random list of numbers between 0 and 100
  cout << "unsorted int list" << endl;
  for (int i = 0; i <10; i++) {
    list[i] = rand() % 100;
    cout << list[i] << " ";
  };
  cout << endl;

  //Use quicksort to sort that list of ints in ascending order
  quicksort<int>(list, 0, 10 - 1);

  cout << "sorted int list" << endl;
  for (int i = 0; i < 10; i++){
    cout << list[i] << " ";
  } 
  cout << endl;

  //Creates list of chars
  char mystring [] = {'d','o','e','s','t','h','i','s','w','o','r','k'};

  cout << "unsorted char list" << endl;
  for (int i = 0; i < sizeof(mystring)/sizeof(char); i++){
    cout << mystring[i] << " ";
  } 
  cout << endl;

  cout << "sorted char list" << endl;
  //Use quicksort to sort list of chars in alphabetical order
  quicksort<char>(mystring, 0,sizeof(mystring)-1);
  for (int i = 0; i < sizeof(mystring)/sizeof(char); i++){
    cout << mystring[i] << " ";
  } 
  cout << endl;


 
  return 0;
}