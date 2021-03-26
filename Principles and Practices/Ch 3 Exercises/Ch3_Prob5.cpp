#include<iostream>
#include<string>
#include<cmath>
 using namespace std;

int main(){
  double val1 = 0;
  double val2 = 0;
  cout << "Enter the first floating point number. ";
  cin >> val1;
  cout << "Enter the second floating point number. ";
  cin >> val2;
  if(val1 < val2){
    cout << "The min value is value 1." << endl;
    cout << "The max value is value 2." << endl;
  }
  else{
    cout << "The min value is value 2." << endl;
    cout << "The max value is value 1." << endl;
  }
  double ratio = val1/val2;
  cout << "The sum of the two numbers is " << val1 + val2 << endl;
  cout << "The difference between the two numbers is " << abs(val1 - val2) << endl;
  cout << "The product is " << val1*val2 << endl;
  cout << "The ratio of value 1 to value 2 is " << ratio << endl;

  return 0;
}
