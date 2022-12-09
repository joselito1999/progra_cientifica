//Marco V. Bayas. Julio 2022
//Programa para resolver las ecuaciones del movimiento de dos osciladores armónicos acoplados
//x1"=-(w1^2+w2^2)x1"+w2^2*x2i
//x2"=-w2^2x1+(w2^2+w3^2)x2
//w1^2=k1/m, w2^2=k2/m, w3^2=k3/m
//Método: Euler
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2 y1
//Las constantes serán 1 1 1 1

//compilación: $g++ pendulo.cpp

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double x, y, vx, vy, wo,b,w,a,t,dt;

void eulerm (double & x, double & vx, double & y, double & vy,int i)
{
 double a1, a2;
 double bm, g;
 
 bm=0.2;
 g=9.81;
 
 x = x+vx*dt;
 y = y+vy*dt;
 
 a1= -bm*vx;
 vx = vx+a1*dt;
 a2= -g-bm*vy;
 vy = vy+a2*dt;
 
 if(i<100){
 cout<<"ax: "<<a1<<endl;
 cout<<"x: "<<x<<endl;
 cout<<"vx: "<<vx<<endl;
 cout<<"ay: "<<a2<<endl;
 cout<<"y: "<<y<<endl;
 cout<<"vy: "<<vy<<endl<<endl<<endl;
 }
 
}

void parametros ()
{
 cout << "Condiciones iniciales: \n";
 cout << "x: ";
 cin >> x;
 cout <<"vx: ";
 cin >> vx;
 cout <<"y: ";
 cin >> y;
 cout << "vy: ";
 cin >> vy;
}

int main ()
{
 double T;
 int Nr,n;

 ofstream file1 ("pos.dat");
 
 parametros();
 n=100;
 T=2*M_PI;
 dt=1.0/n;
 Nr=100*n;
 
 file1<<0<<" "<<x<<" "<<y<<endl;
 
 for ( int i = 1; i <= Nr; i++ ) {
  t=i*dt;
  eulerm(x,vx,y,vy,i);
  file1<<t<<" "<< x << " "<< y <<endl;
 }
}		   
