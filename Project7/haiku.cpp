
//Compilable haiku that describes dynamic memory allocation
//Creates and deletes array of size 10
int main(){
    
    "Make/delete array";
    int *arraynow = new int[10];
    delete[] arraynow;

    return 0;
}