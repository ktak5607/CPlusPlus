#include<iostream>
#include<string>

using namespace std;

enum currencyType{yen, euros, pounds, kroner, yuan};

int main(){

  string currency;
  double inAmount = 0;
  double dollars = 0;
  int cType = 0;
  const double yenToDollars = 0.0089; //conversion rates at time program was made
  const double euroToDollars = 1.17;
  const double poundsToDollars = 1.31;
  const double kronerToDollars = 0.16;
  const double yuanToDollars = 0.15;
  cout << "Enter the amount and currency (yen, euros, pounds, kroner, or yuan) separted by a space you wish to convert to dollars: ";
  while(cin >> inAmount >> currency){
    if(currency == "yen") cType = 0;
    else if (currency == "euros") cType = 1;
    else if (currency == "pounds") cType = 2;
    else if (currency == "kroner") cType = 3;
    else if (currency == "yuan") cType = 4;
    else cType = 5;
    switch(cType){

      case 0:
      dollars = inAmount * yenToDollars; //convert yen
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
      break;

      case 1:
      dollars = inAmount * euroToDollars; //convert euros
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
      break;

      case 2:
      dollars = inAmount * poundsToDollars; //convert pounds
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
      break;

      case 3:
      dollars = inAmount * kronerToDollars; //convert kroner
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
      break;

      case 4:
      dollars = inAmount * yuanToDollars; //convert yuan
      cout << inAmount << " " << currency << " is equal to " << dollars << " dollars" << endl;
      cout <<"Enter your next amount and currency: ";
      break;

      default:
      cout << "You entered an invalid currnecy. Please try again: ";
      break;
    }
  }
  cout << "\nGoodbye" << endl;
  return 0;
}
