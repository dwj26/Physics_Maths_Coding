//@Dan
#include <iostream>
#include <cmath>
#include <fstream>   //import cmath for sqrt and fstream to write to output.dat
#define D 3  //replace any instance of D with the number of dimensions

using namespace std;

struct particle{
    float x[D];  //declare position for particle
    float v[D];  //declare velocity for particle
    float mass;
    float A;  //declare GMm or -Qq/4pi(epsilon)
};

void ForcesEuler(particle &Earth, float time, float deltat, int N); //declare function prototype


int main()
{
    particle Earth;  //declare particle Earth
    float t=0, deltat =0.0001;  //keep deltat small as Euler method best when small
    Earth.A = 1.0;
    Earth.mass = 1.0;
    int number;
    cout << "Enter x and y (and z if 3D) coordinates of initial position" << endl;
    for(int i = 0; i <D; i++){
        cin >> Earth.x[i];  //enter position components
    }
    cout << "Enter x and y (and z if 3D) components of initial velocity" << endl;
    for(int i = 0; i <D; i++){
    cin >> Earth.v[i];  //enter velocity components
    }
    cout << "How many iterations" << endl;
    cin >> number;  //enter the number of data rows
    
    ForcesEuler(Earth , t, deltat, number);  //declare function

    return 0;
}

void ForcesEuler(particle &Earth, float time, float dt, int N) //main body of Euler function (http://tutorial.math.lamar.edu/Classes/DE/EulersMethod.aspx)
{
    float f[2];  //declare the force vector
    float modulus, kinetic, potential;
    ofstream fout;
    fout.open("output.dat");  //open file output.dat to write to
    for(int i = 0; i < N; i++){
        modulus = 0;
	for(int i = 0; i < D; i++){
	    modulus += sqrt(Earth.x[i]*Earth.x[i]);  //declare modulus
	}
	for(int i = 0; i < D; i++){
	    f[i] = (-Earth.A*Earth.x[i])/(modulus*modulus*modulus); //declare force components
	}
	for(int i = 0; i < D; i++){
	    Earth.x[i] += Earth.v[i]*dt;  //carry out Euler steps
	}
	for(int i = 0; i<D; i++){
	    Earth.v[i] += (f[i]*dt)/Earth.mass;
	}
	for(int i = 0; i < D; i++){
	    kinetic = 0.5*Earth.mass*Earth.v[i]*Earth.v[i];  //declare kinetic energy
	}
	for(int i = 0; i < D; i++){
	    potential = -Earth.A/modulus;  //declare potential
	    fout << Earth.x[i] << " ";  //write each position dimension
	}

	time += dt;  //increment time

	fout << modulus << " " << kinetic << " " << potential << " " << time << endl;  //write all info
    }
}


    	
	

