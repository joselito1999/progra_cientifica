//Marco V. Bayas Noviembre, 2022.
//Programa para encontrar la raiz de una función
//Método: Bisección.

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
 double a,b,x,error,del;
 del=1e-6;
 
 cout << "Valores de a b" << endl;
 cin >> a >> b;

 error=b-a;
 count=0;
 while( error > del ) {
  x=(a+b)/2;
  if (fx(x)*fx(a)<0)
   {
    b= x;
   }
   else {
    a=x;
   }
  error=b-a;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Raiz: "<<x<<endl;
  cout << "Error estimado: "<<error<<endl;
  return 0;
}
