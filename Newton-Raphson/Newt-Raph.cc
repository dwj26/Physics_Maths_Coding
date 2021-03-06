#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

//Function prototype
double MyFunction(double number);
double f(double x, double number);


//main body of code
int main()
{
    double c;

    cout << "Input a real number between 1 and 100:" << endl;	
    cin >> c;

    cout << "The solution by Newton-Raphson is..." << endl;
    double solution = MyFunction(c);	
    cout << solution << endl;
    return 0;
}

double MyFunction(double number)
{
    double a=0.1,b=10.1,root, sign;
    for(int i=0; i<=20; i++){
	root = (a+b) / 2.0;
	sign = f(a, number)*f(root, number);
	if(sign<0){
	    b = root;
	}
	else{
	    a = root;
	}
    }
    return root;
}


//put in the function after root = ...
double f(double x, double number)
{
    double sol;
    sol = number - x*x;
    return sol;
}
	
