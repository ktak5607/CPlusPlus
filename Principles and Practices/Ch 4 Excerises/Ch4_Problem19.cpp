#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
  vector<string> names;
  vector<int> scores;
  string n;
  int s = 0;
  cout << "Enter the names and scores for the people. To exit enter \"NoMore\"" << endl;
  while(cin >> n >> s){
    if(n == "NoMore"){
      break;
    }
      for(int i = 0; i < names.size(); i++){
        if(names[i] == n){
          cout << "\nError: The name you entered already exists." << endl;
          return 1;
        }//end check to see if name exists
      }//end loop through names list
      names.push_back(n);
      scores.push_back(s);
  }
  for(int i = 0; i < names.size(); i++){
    cout << names[i] << "\t" << scores[i] << endl;
  }
  return 0;
}
