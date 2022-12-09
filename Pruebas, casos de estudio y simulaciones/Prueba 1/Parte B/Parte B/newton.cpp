//Marco V. Bayas Mayo-2022.
//Raiz de una función
//Método: Newton-Raphson.

#include <iostream>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;

 f=tan(sqrt(3-x))+sqrt(3/x-1);
 return f;
}

double dfx (double x)
{
 double f,h=1e-6;

 f=(fx(x+h)-fx(x))/h;
 return f;
}

int main()
{
 int count;
 double a,x,xm,dx,f,fm,del,aux;
 del=1e-6;
 
 cout << "Estimación inicial: " << endl;
 cin >> a;
 
 count=0;
 dx=1;
 while( abs(dx) > del ) {
  x=a-fx(a)/dfx(a);
  dx=x-a;
  a=x;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<abs(dx)<<endl;
  return 0;
}
