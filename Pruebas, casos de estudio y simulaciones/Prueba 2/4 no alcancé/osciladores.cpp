//Marco V. Bayas. Julio 2022
//Programa para resolver las ecuaciones del movimiento de dos osciladores armónicos acoplados
//x1"=-(w1^2+w2^2)x1"+w2^2*x2i
//x2"=-w2^2x1+(w2^2+w3^2)x2
//w1^2=k1/m, w2^2=k2/m, w3^2=k3/m
//Método: Euler
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2 y1
//

//compilación: $g++ pendulo.cpp

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double x1, x2, x3, v1, v2, v3, wo,b,w,a,t,dt;

void eulerm (double & x1, double & v1, double & x2, double & v2, double & x3, double & v3, double & t)
{
 double a1, a2, a3;

 x1 = x1+v1*dt;
 x2 = x2+v2*dt;
 x3 = x3+v3*dt;
 a1=-2*wo*wo*x1+wo*wo*x2;
 v1 = v1+a1*dt;
 a2= wo*wo*x1-2*wo*wo*x2+wo*wo*x3;
 v2 = v2+a2*dt;
 a3 = 0.5*wo*wo*x2-0.5*wo*wo*x3;
 v3 = v3+a3*dt;
}
void parametros ()
{
 cout << "Condiciones iniciales: \n";
 cout << "x1: ";
 cin >> x1;
 cout <<"v1: ";
 cin >> v1;
 cout <<"x2: ";
 cin >> x2;
 cout << "v2: ";
 cin >> v2;
 cout <<"x3: ";
 cin >> x3;
 cout << "v3: ";
 cin >> v3;
 
 wo=1;
}

int main ()
{
 double T;
 int Nr,n;

 ofstream file ("osciladores.dat" );

 parametros ();
 n=1000;
 T=2*M_PI;
 dt=T/n;
 Nr=10*n;
 for ( int i = 1; i < Nr; i++ ) {
  t=i*dt;
  eulerm(x1,v1,x2,v2,x3,v3,t);
  file<< t/T << " "<< x1 <<" "<<x2<<" "<<x3<<endl;
 }
}		   
