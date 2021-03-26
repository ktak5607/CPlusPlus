#include<iostream>
using namespace std;
int main ()
{
   cout << "Welcome to the miles to kilometers converter.\n\nPlease enter the number of miles. ";
   double miles = 0;
   double kilometers = 0;
   while(cin >> miles){
   kilometers = miles * 1.609;
   cout << kilometers << " Kilometers" << "\n\nPlease enter the number of miles. ";
   }
    return 0;
}
