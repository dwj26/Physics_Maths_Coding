//recursive twos

#include <iostream>

using namespace std;

int twos(int number, int count);

int main()
{
    int number;
    int count = 0;  //this needed to be declared outside the function so the count doesn't begin again each recursion step
    cout << "Enter a number to find the number of factors of two: " << endl;  //function for input of number
    cin >> number;
    cout << "The number of factors of two are " << twos(number, count) << endl;  //output of comma'd number
    return 0;
}

int twos(int number,int count)
{
    if(number%2 == 0){  //if there is no remainder (i.e even number) increment count by one
	count +=1;
	twos(number/2, count);  //recursive step with the number divided by 2
    }
    else
        return count;
}



    
    


