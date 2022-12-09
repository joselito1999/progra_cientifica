//Marco V. Bayas May-2022A.
//Mínimo de una función
//Método: Sección dorada 
//Resultados almacenados para animación.

#include <iostream>
#include <fstream>
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

 ofstream file("extremos.dat");
 
 cout << "Valor de a" << endl;
 cin >> a;
 cout << "Valor de b" << endl;
 cin >> b;
 cout << "Valor de c" << endl;
 cin >> c;
 
 count=0;
 do {
  file<<a<<" "<<fx(a)<<endl;
  file<<b<<" "<<fx(b)<<endl;
  file<<c<<" "<<fx(c)<<endl;
  file<<endl;
  file<<endl;
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
     if (fx(x)>fx(b))
      {
       c=x;
      } else {
       a=b;
       b=x;
      }
    }
  error=(c-a)/2;
  count++;
 } while( error > del);

  file<<a<<" "<<fx(a)<<endl;
  file<<b<<" "<<fx(b)<<endl;
  file<<c<<" "<<fx(c)<<endl;

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<x<<endl;
  cout << "Error estimado: "<<error<<endl;
  return 0;
}
