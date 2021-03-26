#include <iostream>
#include<vector>
using namespace std;

int main()
{
    /*vectors
    */
    //create a vector
    vector<int> lotteryNumVect(10);
    int lotteryNumArray[5] = {4, 13, 14, 24, 34};
    //insert first three numbers from lotterNumArray into lotterNumVect
    lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray + 3);

    //prints 14
    cout << lotteryNumVect.at(2) << endl;
    //put 44 in fifth spot of lotteryNumVect
    lotteryNumVect.insert(lotteryNumVect.begin() + 5, 44);

    //puts 64 at end of array
    lotteryNumVect.push_back(64);
    //print last number in vector
    cout << lotteryNumVect.back() << endl;
    //remove last value in the vector
    lotteryNumVect.pop_back();
    //print first value
    cout << lotteryNumVect.front() << endl;
    //returns 0 (false) if it isn't empty or 1 (true) if it is
    cout << lotteryNumVect.empty() << endl;
    //print the size of the vector
    cout << lotteryNumVect.size() << endl;
    return 0;
}
