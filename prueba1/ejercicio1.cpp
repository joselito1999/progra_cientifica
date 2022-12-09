//Marco V. Bayas, Noviembre 2022.
//Búsqueda del mínimo de una función
//Método: Newton 

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;

 f=-0.0411/x+1090*exp(-x);
 return f;
}

double dfx (double x)
{
 double f,h;
 h=1e-6;
 f=(fx(x+h)-fx(x))/h;
 return f;
}

double ddfx (double x)
{
 double f,h;
 h=1e-6;
 f=(fx(x+h)-2*fx(x)+fx(x-h))/(h*h);
 return f;
}

int main()
{
 int count;
 double xo,x,error,del;
 del=1e-6;
 
 cout << "Estimación inicial" << endl;
 cin >> xo;

 error=1;
 count=0;
 while( error > del) {
  x=xo-dfx(xo)/ddfx(xo);
  error=abs(x-xo);
  xo=x;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<x<<endl;
  cout << "Error estimado: "<<error<<endl;
  return 0;
}
