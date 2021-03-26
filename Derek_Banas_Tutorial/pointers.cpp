#include<string>
#include<fstream>
#include<iostream>
using namespace std;
/*use pointers if don't want to initialize at declaration
  creating a ref need to initailze at creation, pointers don't
  so ageRef had to be initialized when created, agePtr didn't

  use pointers if want to change pointer value later
  references can only be assigned a value one time, can't change later
*/

void getYoung(int* age){
    //remember to use * to get age's value
    cout<<"my age is "<<*age<<endl;
    //changes myAge in main to 23
    *age = 23;
}

void actYourAge(int& age){
    age = 75;
}
int main(){
    int myAge = 29;
    char letter = 'Q';

    //sizeof tells number of bytes variable takes up
    cout<<"size of an int: "<<sizeof(myAge)<<endl;
    cout<<"size of a char: "<<sizeof(letter)<<endl;
    int* agePtr = &myAge;
    //using agePtr is just like using &myAge (is just an address)
    cout<<"address of myAge: "<<agePtr<<endl;
    //to get value at address pointer is pointing to use *agePtr
    cout<<"data at that address: "<<*agePtr<<endl;

    int numArray[5] = {4, 13, 14, 24, 34};
    //remeber that arrays are just ptrs pointing to first address in the array
    int* numPtr = numArray;
    cout<<"address of numArray 0 is "<<numPtr<<" and it's value is "<<*numPtr<<endl;
    //moves the pointer to the next values address in the array
    numPtr++;
    cout<<"address of numArray 1 is "<<numPtr<<" and it's value is "<<*numPtr<<endl;
    //shows an array is just a pointer
    cout<<"address of numArray 0 is "<<numArray<<" and it's value is "<<*numArray<<endl;
    //need to pass address of variable
    getYoung(&myAge);
    cout<<"and now my age is "<<myAge<<endl;
    //called variable reference, used more than pointers
    int& ageRef = myAge;
    cout<<"my age is "<<myAge<<endl;
    //increments myAge by 1
    ageRef++;
    cout<<"my age is now "<<myAge<<endl;
    //pass value by reference
    actYourAge(ageRef);
    cout<<"myAge: "<<myAge<<endl;
    return 0;
}
