//Marco V. Bayas Noviembre, 2022.
//Programa para encontrar la raiz de una función
//Método: Secante.

#include <iostream>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;

 f=exp(x)*log(x)-x*x;
 return f;
}

int main()
{
 int count;
 double a,b,x,dx,del;
 del=1e-6;
 
 cout << "Valores de a b" << endl;
 cin >> a >> b;

 dx=-(b-a)*fx(a)/(fx(b)-fx(a));
 count=0;
 while( dx> del ) {
  x=x+dx;
  if (fx(x)*fx(a)<0)
   {
    b=x;
   }
   else {
    a=x;
   }
   dx=-(b-a)*fx(a)/(fx(b)-fx(a));
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<dx<<endl;
  return 0;
}
