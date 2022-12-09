//Marco V. Bayas   Agosto 2022
// Programa para generar un archivo texto con los puntos
// correspondientes a una función 

//compilación $g++ [program name].cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
 
double funcion(double x)
{
 double b,f,w;
 
 b=2;
 w=2;

 f=b*cos(w*x);
 return f;
}

int main() {

 int n,Nr;
 double t,dt,f,T;
 ofstream file ("funcion.dat" );
 n=100;
 T=2*M_PI;
 dt=T/n;
 Nr=10*n;

 for (int i = 0; i < Nr; i ++)
 {
  t=i*dt;
  f=funcion(t);
  file<<t<<" "<<f<<endl;
 }
 return 0;
}

