#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double f(double x,double tau){

 double f;
 //Defino condiciones iniciales y constantes
 double vxo=5, vyo=10, m=1, g=10;
 
 f=((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau)));
 return f;
}

double df(double x,double tau){

 double df, h=1e-6;
 
 df = (f(x+h,tau)-f(x,tau))/h;
 
 return df;
}

void raiz(double xo, double tau){
 int i=0;
 double x, del=1e-6, error;
 
 do{
  x=xo-f(xo,tau)/df(xo,tau);
  error = abs(xo-x);
  xo=x;//Obtención de la raíz
  i++;
 }while(error>del);
 cout<<i<<endl;
 cout<<x<<endl;
}

int main(){

 double xo;
 ofstream file("datos.dat");
 cout<<"x0"<<endl;
 cin>>xo;
 //Estimación inicial para tau=1
 raiz(xo,10);

 
 return 0;
}
