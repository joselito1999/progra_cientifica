//x"+wo^2*x+q*sgn(x')*x'^2=0
//Métodos: Picard.
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2*x-q*sgn(x')*x'^2

//compilación: $g++ pendulo.cpp

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double xo,x,v,vo,wo=1,q=1,a,t,dt;

void picard (double & x,double & v)
{
 double xo,vo,ao,a;
 
 //Valores en k
 xo=x;
 vo=v;
 if(v!=0){
  ao =-pow(wo,2)*xo-q*(vo/abs(vo))*pow(vo,2);
 }else{
  ao =-pow(wo,2)*xo;
 }
 
 //Valores en k+1 con el método de Euler
 x = x+vo*dt; //x no es una pendiente de ningún lado, es por eso que lo calculo al inicio sin repercusión alguna.
 v = v+ao*dt;
 if(v!=0){
  a =-pow(wo,2)*x-q*(v/abs(v))*pow(v,2);
 }else{
  a =-pow(wo,2)*x;
 }

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

 ofstream file ("pen_pic.dat" );
 
 ofstream file2 ("amp.dat");
 
 parametros ();
 n=1000;
 T=2*M_PI/wo; //Calculo T
 dt=T/n; //Calculo el dt en fracciones del periodo
 Nr=5*n;

 for ( int i = 0; i < Nr; i++ ) {
  picard(x,v);
  file<< i/((double) n) << " "<< x <<endl;
  if(abs(v)<1e-3){
   file2<<i/((double) n)<<" "<<abs(x)<<endl;
  }
 }
}		   
