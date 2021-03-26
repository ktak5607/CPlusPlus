#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

void error(string s){
  throw runtime_error(s);
}

vector<double> QuadraticSolver(double a, double b, double c){
  if((pow(b, 2) - 4 * a *c) < 0){
    error("The numbers entered result in the square root of a negative number. Try again.");
  }
  double negBNumor = sqrt(pow(b, 2) - 4 * a * c) - b;
  double posBNumor = sqrt(pow(b, 2) - 4 * a * c) + b;
  vector<double> quad;
  quad.push_back(negBNumor/(2 * a));
  quad.push_back(posBNumor/(2 * a));
  return quad;
}
int main(){
  double a = 0;
  double b = 0;
  double c = 0;
  double answer = 0;
  cout << "Please enter the three numbers to put into the quadratic equation. ";
  cin >> a >> b >> c;
  try{
    vector<double> answer = QuadraticSolver(a, b, c);
    cout << "The possible answers are: " << answer[0] << ", " << answer[1] << endl;
    return 0;
  }
  catch(runtime_error &e){
    cout << e.what() << endl;
    return -1;
  }
  catch(exception &e){
    cerr << e.what()<< endl;
    //keep_window_open();
    return -1;
  }
}
