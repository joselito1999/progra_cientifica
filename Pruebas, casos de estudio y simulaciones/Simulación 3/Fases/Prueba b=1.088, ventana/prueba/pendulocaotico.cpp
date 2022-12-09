//Marco V. Bayas.   Agosto 2022
//Estudio del movimiento de un  pendulo ideal de masa m y longitud l 
//sujeto a una fuerza externa F=fcos(wt)
//Ecuación del movimiento: x"=-sin(x)-q*x'+b*cos(wt)
//q=r/m, r coeficiente de viscosidad
//b=f/ml 

//compilación: $g++ [program_name].cpp

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double x,v,q,b,w,t,dt;

double a (double x, double v, double t)
{
 double f; 
 f=-sin(x)-q*v+b*cos(w*t); //d^2theta/dt^2
 return f;
}

void rk4 (double & x, double & v, double t)
{
 double xx[5],vv[5],dv[5];

 xx[1]=x;
 vv[1]=v;
 dv[1]=a(xx[1],vv[1],t);

 xx[2] = xx[1]+vv[1]*dt/2;
 vv[2] = vv[1]+dv[1]*dt/2;
 dv[2]=a(xx[2],vv[2],t);
 
 xx[3] = xx[1]+vv[2]*dt/2;
 vv[3] = vv[1]+dv[2]*dt/2;
 dv[3]=a(xx[3],vv[3],t);
 
 xx[4] = xx[1]+vv[3]*dt;
 vv[4] = vv[1]+dv[3]*dt;
 dv[4]=a(xx[4],vv[4],t);

 x=xx[1]+(vv[1]+2*vv[2]+2*vv[3]+vv[4])*dt/6;
 v=vv[1]+(dv[1]+2*dv[2]+2*dv[3]+dv[4])*dt/6;

/* int d= int (x/M_PI);
 x=x-2*M_PI*d;*/
}

void parametros ()
{//Solo los parámetros
 w=2.0/3.0;
 q=0.5;
 x=1;
 v=0;
}

int main (int argc, char *argv[])
{
 double T;
 int Nr,n,d,aux;

 std::string ch = argv[1];
 ofstream file ("pendulo_"+ch+".dat" );
 //ofstream filep ("poincare_"+ch+".dat");
 b=std::stod(&ch[0],0);
  
 parametros ();
 
 n=500;
 T=2*M_PI/w;
 dt=T/n;
 Nr=100*n;
 for ( int i =1; i <= Nr; i++ ) {
  t=i*dt;
  rk4(x,v,t);
  if(i>60*n){file<< i/((double) n) <<" "<<x<<" "<<v<<" "<<endl;}
  
  /*if ((i>60*n) && (i % n==0))
  {
  filep<<x<<" "<<v<<" "<<endl;
  }*/
 }
}		   
