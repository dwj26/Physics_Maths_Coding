//recursive commas

#include <iostream>

using namespace std;

void commas(int number){
    if(number < 1000){  //for the last recursion step and if number is less than 1000
        cout << number; //just print the number
    }
    else{
	commas(number/1000);  //recursion step
        cout << "," << number%1000;  //comma is in front of the remainder of the number divided by 1000
    }
    return;
}

int main(){
    int number;
    cout << "What number would you like to convert to commas: " << endl;
    cin >> number;
    commas(number); //get an input of the number and call the number
    cout << endl;  //end the line of text that comes out of the function
    return 0;
}
