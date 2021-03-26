#include<iostream>//need to include iostream and namespace std inorder to use cin/cout
using namespace std;

double ctok(double c){ // converts Celsius to Kelvin
  int k = c + 273.15;
  return k; //change return from int to k and add semicolon
}


int main(){
  double c = 0; // declare input variable
  cout << "Enter the temperature in celsius that you want to conver to Kelvins. ";
  cin >> c ; // retrieve temperature to input variable (change variable from d to c)
  double k = ctok(c); // convert temperature (change bracket to parenthise and send c not as string)
  cout << c << " degrees celsius is " << k << " degrees Kelvin."<< endl; // print out temperature (change capitol c to lower case)
}
