//recursive factorial calculator

#include <iostream>

using namespace std;

int factorial(int a)
{
    if(a>1)
        return(a*factorial(a-1));  //recursion means a*(a-1)*(a-2)*... all the way down to one
    else
        return(1);  //makes sure something is returned for the last step of recursion
}

int main()
{
    int number;
    cout << "Please type a number: ";  //main function to get an inout number
    cin >> number;
    cout << number << "! = " << factorial(number) << endl;  //output factorial
    return 0;
}
