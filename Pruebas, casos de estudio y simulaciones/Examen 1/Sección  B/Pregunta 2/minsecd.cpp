//Marco V. Bayas May-2022.
//Mínimo de una función
//Método: Sección dorada 

#include <iostream>
#include <math.h>

using namespace std;

double fx(double x){

 double f;
 //Defino condiciones iniciales y constantes
 double vxo=10, vyo=10, m=1, g=9.81, tau=10;
 
 f=-(((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau))));
 return f;
}

int main()
{
 int count;
 double a,b,c,x,error,del;
 del=1e-6;
 
 cout << "Valor de a" << endl;
 cin >> a;
 cout << "Valor de b" << endl;
 cin >> b; 
 cout << "Valor de c" << endl;
 cin >> c;

 error=c-a;
 count=0;
 while( error > del) {
  if (abs(a-b)>abs(b-c))
   {
    x=a+0.38197*(c-a);
    if (fx(x)>fx(b))
     {
       a=x;
      } else {
       c=b;
       b=x;
      }
   } else {
     x=b+0.23606*(c-a);
     if (fx(x)<fx(b))
      {
       c=x;
      } else {
       a=b;
       b=x;
      }
    }
   error=c-a;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del máximo: "<<x<<endl;
  cout<<"Altura máxima: "<<fx(x)<<endl;
  cout << "Error estimado: "<<error<<endl;
  return 0;
}
