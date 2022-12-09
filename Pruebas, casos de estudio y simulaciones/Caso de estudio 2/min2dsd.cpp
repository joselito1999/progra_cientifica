//Marco V. Bayas May-2022.
//Mínimo de una función de dos variables
//Método: "Steepest descend"

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double fxy (double x, double y)
{
 double f;

 f=(x-1)*(x-1)*exp(-y*y)+y*(y+2)*exp(-2*x*x);
 return f;
}

int main()
{
 int count;
 double a,xo,yo,x,y,df,dfx,dfy,error,h,del;
 del=1e-1;
 h=1e-6;
 a=0.01;
 
 ofstream file("minimo2d.dat");
 
 cout << "Valor de xo" << endl;
 cin >> xo;
 cout << "Valor de yo" << endl;
 cin >> yo;
 
 error=1;
 count=0;
 do {
 file<<xo<<" "<<yo<<endl;
 file<<endl;
 file<<endl;
  dfx=(fxy(xo+h,yo)-fxy(xo,yo))/h;
  dfy=(fxy(xo,yo+h)-fxy(xo,yo))/h;
  df=sqrt(dfx*dfx+dfy*dfy);
  x=xo-a*dfx/df;
  y=yo-a*dfy/df;
  error=sqrt((x-xo)*(x-xo)+(y-yo)*(y-yo));
  
  xo=x;
  yo=y;
  count++;
  
 }while( df > del && count<1000);
 
 file<<xo<<" "<<yo<<endl;
 file<<endl;
 file<<endl;
 
  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<x<<" "<<y<<endl;
  cout << "Error: "<<error<<endl;
  return 0;
}
