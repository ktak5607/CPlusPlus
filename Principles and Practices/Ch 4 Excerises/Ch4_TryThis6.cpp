#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
  string dislike = "tomatoes";
  vector<string> words;
  string temp;
  cout << "Please enter a few words to test: ";
  while(cin >> temp){
    words.push_back(temp);
  }
  for(int i = 0; i < words.size(); i++){
    if(words[i] == dislike) words[i] = "BLEEP";
    cout << words[i] << " ";
  }
  cout << "\n";
  return 0;
}
