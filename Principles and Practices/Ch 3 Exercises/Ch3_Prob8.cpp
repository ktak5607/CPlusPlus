#include<iostream>
using namespace std;

int main(){
  int val = 0;
  cout << "Please enter an integer value. ";
  cin >> val;
  if(val%2 == 0){
    cout << "The number " << val << " is even." << endl;
  }
  else{
    cout << "The number " << val << " is odd." << endl;
  }
  return 0;
}
