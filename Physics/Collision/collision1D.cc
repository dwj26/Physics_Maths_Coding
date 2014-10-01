#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct particle{   //create a structure for a particle
    double x;      //position
    double im;     //inverse mass
    double v;      //velocity
    double mom;    //momentum
    double energy; //energy
};

void momenergy(particle &one);               //declare function prototypes
void collision(particle &one, particle &two);

int main(){
    particle one;   //declare particles
    particle two;
    int tests;
    double mass1, mass2;

    ofstream fout;   //open file output.dat and write to it
    fout.open("output.dat");
    fout << "Mass1  " << "Mass2  " << " Vel1  " << "Vel2  " << "MomBefore  " << "EnergyBefore  " << "MomAfter  " << "EnergyAfter  " << "%ChangeMom1  ";
    fout << "%ChangeEne1  " << "%ChangeMom2  " << "%ChangeEne2  " << endl;

    cout << "How many tests do you want to run?" << endl;
    cin >> tests;  //input the number of tests to run
    
    for(int i = 0; i < tests; i++){    //iterate test for number of particles
        cout << "Enter mass of both particles" << endl;
        cin >> mass1;
        cin >> mass2;
	one.im = 1.0/mass1;   //turn masses into inverse masses
        two.im = 1.0/mass2;

        cout << "Enter velocity for both particles" << endl;
        cin >> one.v; 
        cin >> two.v;


        momenergy(one);  //run the functions
        momenergy(two);

        float MomBefore = one.mom + two.mom;  //declare total momentum before
        float EnergyBefore = one.energy + two.energy;  //declare total energy before
        float onebeforem = one.mom;  //declare momentum of each particle before
        float onebeforee = one.energy;  //declare energy of each particel before
        float twobeforem = two.mom;
        float twobeforee = two.energy;

        fout << 1.0/one.im << "  " << 1.0/two.im << "  " << one.v << "  " << two.v << "  " << MomBefore << "  " << EnergyBefore << "  ";
        
	collision(one,two);
	
 	float MomAfter = one.mom + two.mom;  //decalre total momentum after
	float EnergyAfter = one.energy + two.energy;  //declare total energy after
        float oneafterm = one.mom;  //declare momentum of each particle after
        float oneaftere = one.energy; //declare energy of each particle after
        float twoafterm = two.mom;
        float twoaftere = two.energy;

	fout << MomAfter << "  " << EnergyBefore << "  " << 100*(onebeforem - oneafterm)/onebeforem << "  " << 100*(onebeforee - oneaftere)/onebeforee << "  ";
        fout << 100*(twobeforem - twoafterm)/twobeforem << "  " << 100*(twobeforee - twoaftere)/twoaftere << endl;  //write all data to file
    }
    return 0;
}

void momenergy(particle &one){  //main body of function
    if(one.im > 0.0)
	one.mom = one.v / one.im;  //input momentum
    }
    else
        one.mom = 0.0;  //if infinte particle it wont move

    one.energy = 0.5*one.v*one.mom;  //declare energy
}

void collision(particle &one, particle &two){  //main body of function
    float velocity = one.v - two.v;  //declare differences in velocity
    float massfractionone = one.im/(one.im + two.im);  //declare mass fractions
    float massfractiontwo = two.im/(one.im + two.im);
    //carry out collision
    one.v -= 2.0*massfractionone*velocity;  
    two.v += 2.0* massfractiontwo*velocity;
    //store momentum and energy after collision
    momenergy(one);
    momenergy(two);
}
	
	
        
