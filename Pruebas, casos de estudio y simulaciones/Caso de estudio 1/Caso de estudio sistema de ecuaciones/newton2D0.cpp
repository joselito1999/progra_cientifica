//Marco V. Bayas May-2022
//Sistema de dos ecuaciones no lineales
//Método: Newton-Raphson

#include <iostream>
#include <math.h>

using namespace std;

double fxy (double x, double y)
{
 double f;
 f=x/exp(5*log(x**2+y**2)/2)+(x-1)/exp(5*log((x-1)**2+y**2)/2)+(x-0.5)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2);
 return f;
}

double gxy (double x, double y)
{
 double f;
 
 g=y/exp(5*log(x**2+y**2)/2)+y/exp(5*log((x-1)**2+y**2)/2)+(y-0.866)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2);
 return f;
}

double dfx (double x,double y)
{
 double f;
 
 f=exp(x);
 return f;
}

double dfy (double x,double y)
{
 double f;
 
 f=-3;
 return f;
}

double dgx (double x,double y)
{
 double f;
 
 f=2*x;
 return f;
}

double dgy (double x,double y)
{
 double f;
      
 f=2*y;
 return f;
}

int main()
{
 int count;
 double x,dx,y,dy,del;
 del=1e-6;
 
 cout << "Valor de x0" << endl;
 cin >> x;
 cout << "Valor de y0" << endl;
 cin >> y;

 count=0;
 
 do {
  dx=(fxy(x,y)*dgy(x,y)-gxy(x,y)*dfy(x,y))/(dfx(x,y)*dgy(x,y)-dgx(x,y)*dfy(x,y));
  dy=(gxy(x,y)*dfx(x,y)-fxy(x,y)*dgx(x,y))/(dfx(x,y)*dgy(x,y)-dgx(x,y)*dfy(x,y)); 
  x=x-dx;
  y=y-dy;
  count++;
  
  cout<<"Raiz "<<count<<": "<<x<<","<<y<<endl;
  cout<<endl;
 } while( abs(dx)+abs(dy) > del );

 cout << "Número de iteraciones: " <<count<< endl;
 cout << "Raiz: "<<x<<","<<y<<endl;
 cout << "Error estimado para x: "<<abs(dx)<<endl;
 cout << "Error estimado para y: "<<abs(dy)<<endl;
 return 0;
}
