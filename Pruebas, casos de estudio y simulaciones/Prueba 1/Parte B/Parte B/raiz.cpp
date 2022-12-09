#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double f(double x,double tau){

 double f;
 //Defino condiciones iniciales y constantes
 double vxo=10, vyo=10, m=1, g=9.81;
 
 f=((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau)));
 return f;
}

double df(double x,double tau){

 double df, h=1e-6;
 
 df = (f(x+h,tau)-f(x,tau))/h;
 
 return df;
}

void raiz(double *xo, double tau){

 double x, del=1e-6, error;
 
 do{
  x=*xo-f(*xo,tau)/df(*xo,tau);
  error = abs(*xo-x);
  *xo=x;
 }while(error>del);
 
}

int main(){

 double xo;
 ofstream file("datos.dat");
 
 //Estimación inicial para tau=1
 xo=8.05;
  for(int tau=1; tau<11; tau++){
   raiz(&xo,tau);
   file<<tau<<" "<<xo<<endl;
   file<<endl;
   file<<endl;
  }
 
 return 0;
}
