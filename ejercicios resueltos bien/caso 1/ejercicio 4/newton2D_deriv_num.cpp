//Marco V. Bayas May-2022
//Sistema de dos ecuaciones no lineales
//Método: Newton-Raphson con evaluación numérica de la derivada.

#include <iostream>
#include <math.h>

using namespace std;

//Definición de ecuaciones a resolver

double fxy (double x, double y)
{
 double f;
 f=x/exp(5*log(pow(x,2)+pow(y,2))/2)+(x-1)/exp(5*log(pow(x-1,2)+pow(y,2))/2)+pow(x-0.5,2)/exp(5*log(pow(x-0.5,2)+pow(y-.866,2))/2);
 return f;
}

double gxy (double x, double y)
{
 double f;
 
 f=y/exp(5*log(pow(x,2)+pow(y,2))/2)+y/exp(5*log(pow(x-1,2)+pow(y,2))/2)+(y-0.866)/exp(5*log(pow(x-0.5,2)+pow(y-.866,2))/2);
 return f;
}

double dfx (double x, double y)
{
 double f,h;

 h=1e-6; 
 f=(fxy(x+h,y)-fxy(x,y))/h;
 return f;
}

double dfy (double x, double y)
{
 double f,h;
 
 h=1e-6;
 f=(fxy(x,y+h)-fxy(x,y))/h;
 return f;
}

double dgx (double x, double y)
{
 double f,h;
 
 h=1e-6; 
 f=(gxy(x+h,y)-gxy(x,y))/h;
 return f;
}

double dgy (double x, double y)
{
 double f,h;
      
 h=1e-6;
 f=(gxy(x,y+h)-gxy(x,y))/h;
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
 } while( abs(dx)+abs(dy) > del );

 cout << "Número de iteraciones: " <<count<< endl;
 cout << "Raiz: "<<x<<","<<y<<endl;
 cout << "Error estimado para x: "<<abs(dx)<<endl;
 cout << "Error estimado para y: "<<abs(dy)<<endl;
 return 0;
}

