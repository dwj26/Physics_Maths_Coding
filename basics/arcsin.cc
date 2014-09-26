#include <iostream>
#include <cmath>
using namespace std;

//declare function
float MyArcSin(float num);

int main()
{
//Runs the function for users input	
float arcsin, N=0, arcsin1, arcsin2;
cout << "Input a number between -1 and 1 to evaluate the arcsin of the number: " << endl;
cin >> N;
arcsin = MyArcSin(N);
cout << "Arcsin of your number = " << arcsin << endl;

//Runs function for common values stated
cout << "Here are two common values for arcisn, that of arcisn(1/2) and arcsin(root(3)/2) " << endl;
float a =0.5;
arcsin1 = MyArcSin(a);
float b = sqrt(3)/2;
arcsin2 = MyArcSin(b);
cout << arcsin1 << ", " << arcsin2 << endl;


return 0;
}

//define function

float MyArcSin(float num){
float lower = -3.14159265/2, upper = 3.14159265/2, arc, sign, one, two;

for(int i=1; i<=10000; i++){

arc = (lower + upper)/2;

one = num - sin(arc);
two = num - sin(lower);

sign = one*two;

if(sign<=0) {
upper = arc;
lower = lower;
} else{
upper = upper;
lower = arc;
}
}
return arc;
}
