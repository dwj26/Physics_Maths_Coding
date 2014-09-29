//@Dan
#include <iostream>
#include <cmath>
#include <fstream>
#define D 2
using namespace std;

struct particle{
    float x[D];
    float v[D];
    float mass;
    float A;
};

void ForcesEuler(particle &Earth, float time, float deltat, int N);

int main()
{
    particle Earth;
    float t=0, deltat =0.0001;
    Earth.A = 1.0;
    Earth.mass = 1.0;
    int number;
    
    cout << "Enter x and y coordinates of initial position" << endl;
    cin >> Earth.x[0] >> Earth.x[1];

    cout << "Enter x and y components of initial velocity" << endl;
    cin >> Earth.v[0] >> Earth.v[1];

    cout << "How many iterations" << endl;
    cin >> number;

    ForcesEuler(Earth , t, deltat, number);

    
    return 0;
}


void ForcesEuler(particle &Earth, float time, float dt, int N)
{
    float f[2];
    float modulus, kinetic, potential;
    ofstream fout;
    fout.open("output.dat");

    for(int i = 0; i < N; i++){
	modulus = 0;
	for(int i = 0; i < D; i++){
             modulus += sqrt(Earth.x[i]*Earth.x[i]);
        }

        for(int i = 0; i < D; i++){
	    f[i] = (-Earth.A*Earth.x[i])/(modulus*modulus*modulus);
	}
        
	for(int i = 0; i < D; i++){
            Earth.x[i] += Earth.v[i]*dt;
        }

        for(int i = 0; i<D; i++){
	    Earth.v[i] += (f[i]*dt)/Earth.mass;
        }
        
        for(int i = 0; i < D; i++){
            kinetic = 0.5*Earth.mass*Earth.v[i]*Earth.v[i];
        }

        for(int i = 0; i < D; i++){
            potential = -Earth.A/modulus;
	}

        time += dt;
    	
        fout << Earth.x[0] << "  " << Earth.x[1] << "   " << modulus << "   " << kinetic << "   " << potential << "   " << time << endl;
        
    }
    
}





    	
	

