#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct particle{
    double x;
    double im;
    double v;
    double mom;
    double energy;
};

void momenergy(particle &one);
void collision(particle &one, particle &two);

int main(){
    particle one;
    particle two;
    int tests;
    double mass1, mass2;

    ofstream fout;
    fout.open("output.dat");
    fout << "Mass1  " << "Mass2  " << " Vel1  " << "Vel2  " << "MomBefore  " << "EnergyBefore  " << "MomAfter  " << "EnergyAfter  " << "%ChangeMom1  ";
    fout << "%ChangeEne1  " << "%ChangeMom2  " << "%ChangeEne2  " << endl;

    cout << "How many tests do you want to run?" << endl;
    cin >> tests;
    
    for(int i = 0; i < tests; i++){
        cout << "Enter mass of both particles" << endl;
        cin >> mass1;
        cin >> mass2;
	one.im = 1.0/mass1;
        two.im = 1.0/mass2;

        cout << "Enter velocity for both particles" << endl;
        cin >> one.v; 
        cin >> two.v;


        momenergy(one);
        momenergy(two);

        float MomBefore = one.mom + two.mom;
        float EnergyBefore = one.energy + two.energy;
        float onebeforem = one.mom;
        float onebeforee = one.energy;
        float twobeforem = two.mom;
        float twobeforee = two.energy;

        fout << 1.0/one.im << "  " << 1.0/two.im << "  " << one.v << "  " << two.v << "  " << MomBefore << "  " << EnergyBefore << "  ";
        
	collision(one,two);
	
 	float MomAfter = one.mom + two.mom;
	float EnergyAfter = one.energy + two.energy;
        float oneafterm = one.mom;
        float oneaftere = one.energy;
        float twoafterm = two.mom;
        float twoaftere = two.energy;

	fout << MomAfter << "  " << EnergyBefore << "  " << 100*(onebeforem - oneafterm)/onebeforem << "  " << 100*(onebeforee - oneaftere)/onebeforee << "  ";
        fout << 100*(twobeforem - twoafterm)/twobeforem << "  " << 100*(twobeforee - twoaftere)/twoaftere << endl;
    }
    return 0;
}

void momenergy(particle &one){
    if(one.im > 0.0){
	one.mom = one.v / one.im;
    }
    else
        one.mom = 0.0;

    one.energy = 0.5*one.v*one.mom;
}

void collision(particle &one, particle &two){
    float velocity = one.v - two.v;
    float massfractionone = one.im/(one.im + two.im);
    float massfractiontwo = two.im/(one.im + two.im);
    
    one.v -= 2.0*massfractionone*velocity;
    two.v += 2.0* massfractiontwo*velocity;

    momenergy(one);
    momenergy(two);
}
	

 
	
        
