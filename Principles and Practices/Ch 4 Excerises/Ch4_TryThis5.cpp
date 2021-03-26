#include<iostream>
using namespace std;


int square(int x){
  int val = 0;
  for(int i = 0; i < x; i ++){
    val += x;
  }
  return val;
}


int main(){
  cout << square(6) << endl;
  cout << square(8) << endl;
}
