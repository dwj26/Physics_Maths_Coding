#include <iostream>
using namespace std;

int main(){
	int f=0, a=0, b=1, total=0;  	cout << "How many terms of the Fibonacci sequence do you wish to see? "; 	cin >> f; 

	for(int i = 0; i < f; i++){
	cout << total << endl; 	total = a + b; 	a = b;
	b = total; 	}
return 0;
}
