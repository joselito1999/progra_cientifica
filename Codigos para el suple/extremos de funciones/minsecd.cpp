//Marco V. Bayas,  Noviembre 2022.
//Búsqueda del mínimo de una función
//Método: Sección dorada 

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

double fx (double x)
{
 double f;

 f=-exp(5*log(x))/(exp(x)-1);
 return f;
}

int main()
{
 int count;
 double a,b,c,x,error,del,w;
 del=1e-6;
 
 cout << "Límite inferior (a)" << endl;
 cin >> a;
 cout << "Límite superior (c)" << endl;
 cin >> c;
 w=0.38197;
 b=a+w*(c-a);

 error=c-a;
 count=0;
 while( error > del) {
  if (abs(a-b)<abs(b-c))
   {
    x=a+(1-w)*(c-a);
    if (fx(x)>fx(b))
     {
      c=x;
     } else {
       a=b;
       b=x;
      }
   } else {
     x=a+w*(c-a);
     if (fx(x)>fx(b))
      {
       a=x;
      } else {
       c=b;
       b=x;
      }
    }
   error=c-a;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<x<<endl;
  cout << "Error estimado: "<<error<<endl;
  return 0;
}
