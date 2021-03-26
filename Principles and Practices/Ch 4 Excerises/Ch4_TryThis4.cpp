#include<iostream>
using namespace std;

int main(){
  for(int i = 0; i < 26; i++){
    cout << char('a' + i) << "\t" << int('a' + i) << endl;
  }

  for(int i = -32; i < -6; i++){
    cout << char('a' + i) << "\t" << int('a' + i) << endl;
  }
  return 0;
}
