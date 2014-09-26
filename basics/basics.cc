// Here begins file teacher.cc
#include <iostream>
using namespace std;
int main()
{
for (int i=1; i<=20; i++) {
if ( i%2 == 0 ) {
cout << i << " is an even number!" << endl ;
} else {
cout << i << " is an odd number!" << endl ;
}
}
int n;
cout << "Now I've taught you, enter a number that is even." << endl ;
cin >> n ;
if ( n%2 == 0){
	cout << "Well Done, I must be a good teacher!" << endl ;
} else {
	cout << "You really need to practice!" << endl ;
}
int j ;
cout << "Let's really test you, give me an odd number." << endl;
cin >> j ;
if ( j%2 != 0){
	cout << "Well done, you do understand!" << endl;
} else{
	cout << "DID I TEACH YOU NOTHING!" << endl;
}
}
