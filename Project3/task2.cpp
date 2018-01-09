/*
* searches for a value in sorted array
*   arr is an array to search in
*   value is searched value
*   left is an index of left boundary
*   right is an index of right boundary
* returns position of searched value, if it presents in the array
* or -1, if it is absent
*/

#include <iostream>
int binarySearch(int arr[], int value) {
      int left=1;
      int right=sizeof(arr);
      while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] == value)
                  return middle;
            else if (arr[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;

}

int main (void) {

  int arr[]={1,2,3,4,5,6,7};
  std::cout << "List for executing binary search: ";
  for(int i=0;i<(sizeof(arr)/sizeof(*arr));i++){
      std::cout << arr[i];
  }
  std::cout << "\n"<<"Executing binary search on 5... " << binarySearch(arr,5) <<"\n";
  std::cout << "Exectuing binary search on 10..." << binarySearch(arr,10)<<"\n";
  return 0;
}