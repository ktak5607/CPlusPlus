#include<string>
#include<fstream>
#include<iostream>
using namespace std;

int main(){
    int num = 0;
    //create try catch statements very basic example
    try{
        if(num !=0){
        cout<<2/num<<endl;
        }
        else throw(num);
    }
    //don't have to catch a variable but useful sometimes
    catch(int num){
        cout<<"number isn't valid: "<<num<<endl;
    }

    return 0;
}
