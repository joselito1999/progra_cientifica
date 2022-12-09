//x"-(w^2*cos(x)-g/R)sin(x)=0
//Métodos: Picard.
//y1=x, y2=dx/dt, g1= y2, g2= (w^2*cos(x)-g/R)sin(x)

//compilación: $g++ pendulo.cpp

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double xo,x,v,vo,g=1,R=1,dt,ww=2; //Se pone ww=w^2

void picard (double & x,double & v)
{
 double xo,vo,ao,a;
 
 //Valores en k
 xo=x;
 vo=v;
 ao =(ww*cos(xo)-g/R)*sin(xo);
 
 //Valores en k+1 con el método de Euler
 x = x+vo*dt; //x no es una pendiente de ningún lado, es por eso que lo calculo al inicio sin repercusión alguna.
 v = v+ao*dt;
 a =(ww*cos(x)-g/R)*sin(x);

 x = xo+0.5*(vo+v)*dt;
 v = vo+0.5*(ao+a)*dt;
}

void parametros ()
{
 cout << "Posición inicial: \n";
 cin >> x;
 cout << "Velocidad inicial: \n";
 cin >> v;
}

int main ()
{
 double T;
 int Nr,n;

 ofstream file ("pic_can.dat" );
 
 ofstream file2 ("per.dat");
 
 parametros ();
 n=1000;
 dt=1/((double)n); //Calculo el dt en fracciones de 1 segundo
 Nr=10*n;

 file2<<0<<" "<<x<<endl;

 for ( int i = 0; i < Nr; i++ ) {
  picard(x,v);
  file<< i*dt << " "<< x <<endl; //Calculo todo en unidades de segundos
  if(abs(v)<1e-3){
   file2<<i*dt<<" "<<x<<endl;
  }
 }
}		   
