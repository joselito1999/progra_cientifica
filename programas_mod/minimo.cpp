//Marco V. Bayas Noviembre 2022.
//Mínimo de una función de dos variables
//Método: "Steepest descend"

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;
double fxy (double x, double y)
{
 double f;
 f=2/sqrt(x*x+y*y)+1/sqrt((0.5-x)*(0.5-x)+(0.866-y)*(0.866-y))+2/sqrt((1-x)*(1-x)+y*y);
 return f;
}
int main()
{
 int count;
 double a,xo,yo,x,y,df,dfx,dfy,error,h,del;
 del=1e-6;
 h=1e-6;
 a=0.1;
 cout << "Valor de xo" << endl;
 cin >> xo;
 cout << "Valor de yo" << endl;
 cin >> yo;
 error=1;
 count=0;
 while( error > del && count<1000) {
  dfx=(fxy(xo+h,yo)-fxy(xo,yo))/h;
  dfy=(fxy(xo,yo+h)-fxy(xo,yo))/h;
  df=sqrt(dfx*dfx+dfy*dfy);
  x=xo-a*dfx/df;
  y=yo-a*dfy/df;
  error=sqrt((x-xo)*(x-xo)+(y-yo)*(y-yo));
  if(fxy(x,y)>fxy(xo,yo)){
    a=a/5;
  }else{
  xo=x;
  yo=y;
  }
  count++;
 }
  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<xo<<" "<<yo<<endl;
  cout << "Error: "<<error<<endl;
  cout << "a: " << a<< endl;
  return 0;
}
