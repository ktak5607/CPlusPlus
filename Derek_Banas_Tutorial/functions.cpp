#include <iostream>
using namespace std;

functions are useful for reusing code and organizing

//create function to add numbers
//secondNum is given default value, variables that are given
//default values have to be listed last
int addNums (int firstNum, int secondNum = 0){

return firstNum + secondNum;
}

//function overloading, just have to have diff input vars
int addNums (int firstNum, int secondNum, int thirdNum){

return firstNum + secondNum + thirdNum;
}

//example of recursive function
int getFactorial(int num){
    int sum;
    if(num == 1)sum = 1;
    //call function from itself, passing num -1 till get to 1
    else sum = getFactorial(num -1) * num;

    return sum;
}

int main()
{

    cout<<addNums(1)<<endl;
    cout<<addNums(1,2,3)<<endl;
    //prints 6
    cout<<getFactorial(3)<<endl;
    return 0;
}
