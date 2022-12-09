//Marco V. Bayas Mayo-2022.
//Raiz de una función
//Método: Newton-Raphson.

#include <iostream>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;
 //Defino condiciones iniciales y constantes
 double vxo=10, vyo=10, tau=1, m=1, b=m/tau, g=9.81;
 double vy=m*g/b;
 
 f=((vyo+vy)/(vxo))*x+vy*tau*log(1-(x/(vxo*tau)));
 return f;
}

double dfx (double x)
{
 double df;
 
 double h=1e-6;
 
 df=(fx(x+h)-fx(x))/h;
 return df;
}

int main()
{
 double a,x,xm,dx,f,fm,del,aux;
 del=1e-6;
 
 cout << "Estimación inicial: " << endl;
 cin >> a;

 dx=1;
 while( abs(dx) > del ) {
  x=a-fx(a)/dfx(a);
  dx=x-a;
  a=x;
 }

  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<abs(dx)<<endl;
  return 0;
}
