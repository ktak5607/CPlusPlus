#include<iostream>
using namespace std;

int main(){
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int min = 0;
  int mid = 0;
  int max = 0;
  cout << "Please enter the first integer number. " << endl;
  cin >> val1;
  cout << "Please enter the second integer number. " << endl;
  cin >> val2;
  cout << "Please enter the third integer number. " << endl;
  cin >> val3;

  if(val1 < val2){
    if(val1 < val3){
      min = val1;
      if(val2 < val3){
        mid = val2;
        max = val3;
      }//end val2 less than val3
      else{
        mid = val3;
        max = val2;
      }//end val2 bigger than 3

    }//end val1 less than val3
    else{
      min = val3;
      mid = val1;
      max = val2;
    }//end val1 is mid
  }//end main val1 test


  else if(val2 < val1){
    if(val2 < val3){
      min = val2;
      if(val1 < val3){
        mid = val1;
        max = val3;
      }//end val1 smaller than val3
      else{
        mid = val3;
        max = val1;
      }//end val1 bigger than val3
    }
    else{
      min = val3;
      mid = val2;
      max = val1;
    }//end val2 is mid
  }//end val2 test


  else if(val3 < val1){
    if(val3 < val2){
      min = val3;
      if(val2 < val1){
        mid = val2;
        max = val1;
      }//end val2 smaller than val1
      else{
        mid = val1;
        max = val2;
      }//end val2 bigger than val1
    }//end val3 smaller than val2
    else{
      min = val2;
      mid = val3;
      max = val1;
    }//end val3 is mid
  }//end val3 test


  cout << min << "," << mid << "," << max << endl;
  return 0;
}
