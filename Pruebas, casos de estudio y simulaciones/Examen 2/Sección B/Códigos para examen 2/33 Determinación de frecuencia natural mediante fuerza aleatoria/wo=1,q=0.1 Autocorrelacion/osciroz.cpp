//Marco V. Bayas. Agosto 2022

//Programa para resolver la ecuacion del movimiento de un péndulo simple con rozamiento proporcional a la velocidad. 
//x"=-wo^2*sen(x)-q*x'
//Método: Piccard.
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2 sen(x)-q*x'

//Run: ./exe q

//Péndulo con rozamiento

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double xo,x,v,vo,wo,q,w,a,t,dt;

void piccard (double & x,double & v)
{
 double xo,vo,ao,a, aux1, aux2;
 
 aux1=2*(double) rand() / (RAND_MAX)-1;
 aux2=10*(double) rand() / (RAND_MAX);
 
 vo=v;
 xo=x;
 ao =-wo*wo*x-q*v+aux1*aux2; //g2
 v = v+ao*dt;  //y2
 x = x+vo*dt;  //y1
 a =-wo*wo*x-q*v+aux1*aux2;
 x = xo+0.5*(vo+v)*dt;  //y1
 v = vo+0.5*(ao+a)*dt; //y2
}

void parametros ()//Solo parámetros iniciales
{
 x=0.0;
 v=0.1;
 wo=1;
}

int main (int argc, char *argv[])
{
 double T;
 int Nr,n;

 std::string ch = argv[1];
 std::string ch1 = argv[2];
 std::string ch2 = argv[3];
 ofstream file ("pendulo_"+ch+".dat" );
 q=std::stod(&ch[0],0);
 n=std::stod(&ch1[0],0);
 Nr=std::stod(&ch2[0],0);
 
 srand(time(NULL));
 
 parametros ();
 
 T=2*M_PI/wo;
 dt=1.0/n;
 Nr=100*n;

 file<< 0 << " "<< x << endl; //Almaceno desde el t=0
 for ( int i = 1; i <= Nr; i++ ) {//Resuelve la edo
  t=i*dt;
  piccard(x,v);
  file<< t << " "<< x << endl;
 }
}		   
