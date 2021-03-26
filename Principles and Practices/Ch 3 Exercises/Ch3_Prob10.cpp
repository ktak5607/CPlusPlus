#include<iostream>
#include<string>
using namespace std;

int main(){
  double val1 = 0;
  double val2 = 0;
  string operation;
  cout << "Enter a mathmatical operation (+, -, *, /, plus, minus, mul, div) followed by 2 floating point numbers seperated by a space. ";
  while(cin >> operation >> val1 >> val2){
    double res = 0;
    if(operation == "+" || operation == "plus"){
       res = val1 + val2;
     }
    else if (operation == "-" || operation == "minus"){
      res = val1 - val2;
    }
    else if (operation == "*" || operation == "mul"){
      res = val1 * val2;
    }
    else if (operation == "/" || operation == "div"){
      if (val2 == 0) {
        cout << "You can't divide by zero" << endl;
        cout<< "Please try again. ";
        continue;
      }
      res = val1 / val2;
    }
    cout << val1 << " " << operation << " " << val2 << " = " << res <<endl;
    cout << "Please try again. ";
  }
  return 0;
}
