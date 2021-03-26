#include<iostream>
#include<string>

using namespace std;


int main(){
  string currency;
  double inAmount = 0;
  double dollars = 0;
  const double yenToDollars = 0.0089; //conversion rates at time program was made
  const double euroToDollars = 1.17;
  const double poundsToDollars = 1.31;
  cout << "Enter the amount and currency (yen, euros, or pounds) separted by a space you wish to convert to dollars: ";
  while(cin >> inAmount >> currency){

    if(currency == "yen"){
      dollars = inAmount * yenToDollars; //convert yen
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
    }
    else if (currency == "euros"){
      dollars = inAmount * euroToDollars; //convert euros
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
    }
    else if (currency == "pounds"){
      dollars = inAmount * poundsToDollars; //convert pounds
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
    }
    else{
      cout << "You entered an invalid currnecy. Please try again: ";
    }
  }
  cout << "Goodbye" << endl;
  return 0;
}
