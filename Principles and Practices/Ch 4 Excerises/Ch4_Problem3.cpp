#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  vector<double> distances;
  double temp = 0;
  double min = 0;
  double max = 0;
  double totalDist = 0;
  double mean = 0;
  cout << "Please enter the distances between cities: ";
  while(cin >> temp){
    distances.push_back(temp);
  }
  for(int i = 0; i < distances.size(); i++){
    totalDist += distances[i];
    mean += distances[i];
  }
  min = *min_element(begin(distances), end(distances));
  max = *max_element(begin(distances), end(distances));
  mean = mean/distances.size();
  cout << "\nThe total distance is: " << totalDist << endl;
  cout << "The smallest distance is: " << min << endl;
  cout << "The largest distance is: " << max << endl;
  cout << "The mean of all of the distances is: " << mean << endl;
}
