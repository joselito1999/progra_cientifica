//Marco V. Bayas Mayo-2022.
//Programa para encontrar la raiz de una función
//Método: Newton-Raphson.

#include <iostream>
#include <math.h>

using namespace std;
double b;
double fx (double x,double a)
{
 double f;
 f=1-1/(x*x)-exp(-x)/(x*a);
 return f;
}

double dfx (double x)
{
 double f;
 double h = 1e-6;
 f=(fx(x+h,b)-fx(x,b))/h;
 return f;
}

int main()
{
 int count;
 double a,x,dx,del;
 del=1e-6; 
 cout << "Estimación inicial: " << endl;
 cin >> a;
 cout << "Energia: " << endl;
 cin >> b;
 
 count=0;
 dx=1;
 while( abs(dx) > del ) {
  dx=-fx(a,b)/dfx(a);
  x=a+dx;
  a=x;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<abs(dx)<<endl;
  return 0;
}
