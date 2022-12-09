//Marco V. Bayas Mayo-2022.
//Raiz de una función
//Método: Newton-Raphson.

#include <iostream>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;

 f=-0.0411/x+exp(-x);
 return f;
}

double dfx (double x)
{
 double df;

 df=0.0411/pow(x,2)-exp(-x);
 return df;
}

double ddfx (double x)
{
 double ddf;

 ddf=-2*0.0411/pow(x,3)+exp(-x);
 return ddf;
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
  x=a-dfx(a)/ddfx(a);
  dx=x-a;
  a=x;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<abs(dx)<<endl;
  return 0;
}
