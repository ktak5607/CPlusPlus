#include<iostream>
using namespace std;

int main(){
  int i = 0;
  while(i < 26){
    cout << char('a' + i) << "\t" << int('a' + i) << endl;
    i++;
  }
  return 0;
}
