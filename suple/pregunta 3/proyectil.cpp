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
bool flag;

void eulerm (double & x, double & vx, double & y, double & vy,int i)
{
 double a1, a2;
 double bm, g;
 
 bm=0.5;
 g=9.81;
 
 x = x+vx*dt;
 y = y+vy*dt;
 
 a1= -bm*vx;
 vx = vx+a1*dt;
 a2= -g-bm*vy;
 vy = vy+a2*dt;
 
}

void parametros ()
{
 cout << "Condiciones iniciales: \n";
 x=0;
 cout <<"vx: ";
 cin >> vx;
 y=0;
 vy=vx;
}
void alcance(bool & flag,double x1, double x2,double & max)
{
 if(flag)
 {
  if(x1*x2<=0)
  {
    flag=false;
    max=(x2-x1)/2; //una mejor estimacion para el alcance, es el punto medio entre los puntos
  }
 }
}
int main ()
{
 double T,xoff,xmax;
 xmax=0;
 int Nr,n;
 flag=true;

 ofstream file1 ("pos.dat");
 
 parametros();
 n=100;
 T=2*M_PI;
 dt=1.0/n;
 Nr=100*n;
 
 file1<<0<<" "<<x<<" "<<y<<endl;
 
 for ( int i = 1; i <= Nr; i++ ) {
  t=i*dt;
  xoff=x;
  eulerm(x,vx,y,vy,i);
  alcance(flag,xoff,x,xmax);
  file1<<t<<" "<< x << " "<< y <<endl;
 }
 cout<<xmax<<endl;
}		   
