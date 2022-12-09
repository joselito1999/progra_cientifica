//Marco V. Bayas. Julio 2022
//Programa para resolver la ecuacion del movimiento de un oscilador armónico.
//Métodos: euler-cromer, pc, rk2, rk4.
//Ecuación: x"+wo^2*x=0
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2 y1

//compilación: $g++ algoritmos_osc.cpp

#include <iostream>
#include <fstream>
#include <math.h>
#define pi 3.14159265359

using namespace std;

double x1,v1,x2,v2,x3,v3,x4,v4,x5,v5,xo,vo,wo,b,w,a,t,dt;

double g2 (double y1)
{
 double f;
 
 f=-wo*wo*y1;
 return f;
}

void eulercrommer (double & x, double & v)
{
 v = v+g2(x)*dt;
 x = x+v*dt;
}

/*void pc (double & x, double & v)
{
 double xi,vi,dv1, dv2;

 xi=x;
 vi=v;
 dv1=g2(x);
 x = x+v*dt;
 v = v+dv1*dt;

 dv2=g2(x);
 x=xi+0.5*(vi+v)*dt;
 v=vi+0.5*(dv1+dv2)*dt;
}

void rk2 (double & x, double & v)
{
 double xi,vi,dvi,dv1;

 xi=x;
 vi=v;
 dvi=g2(xi);

 x = xi+3*vi*dt/4;
 v = vi+3*dvi*dt/4;
 dv1=g2(x);

 x=xi+(vi+2*v)*dt/3;
 v=vi+(dvi+2*dv1)*dt/3;
}

void rk4 (double & x, double & v)
{
 double xx[5],vv[5],dv[5];

 xx[1]=x;
 vv[1]=v;
 dv[1]=g2(xx[1]);

 xx[2] = xx[1]+vv[1]*dt/2;
 vv[2] = vv[1]+dv[1]*dt/2;
 dv[2]=g2(xx[2]);
 
 xx[3] = xx[1]+vv[2]*dt/2;
 vv[3] = vv[1]+dv[2]*dt/2;
 dv[3]=g2(xx[3]);
 
 xx[4] = xx[1]+vv[3]*dt;
 vv[4] = vv[1]+dv[3]*dt;
 dv[4]=g2(xx[4]);

 x=xx[1]+(vv[1]+2*vv[2]+2*vv[3]+vv[4])*dt/6;
 v=vv[1]+(dv[1]+2*dv[2]+2*dv[3]+dv[4])*dt/6;
}*/

void parametros ()
{
 cout << "Posición inicial: \n";
 cin >> xo;
 cout << "Velocidad inicial: \n";
 cin >> vo;
 cout << "Frecuencia natural \n";
 cin >> wo;
}

int main ()
{
 double T,r[10];;
 int Nr,n;
 ofstream file ("oscilador.dat" );
 parametros ();
 n=1000;
 T=2*pi/wo;
 dt=2*pi*0.01;
 Nr=10*n;
 x1=xo;
 v1=vo;
 /*x2=xo;
 v2=vo;
 x3=xo;
 v3=vo;
 x4=xo;
 v4=vo;*/
 for ( int i=0; i<4; i++) r[i]=0;
 
 for ( int i = 1; i < 1000; i++ ) {
  t=i*dt;
  eulercrommer(x1,v1);
  r[0]=r[0]+(sin(t)-x1)*(sin(t)-x1)/Nr;
  /*pc(x2,v2);
  r[1]=r[1]+(xo*cos(t)-x2)*(xo*cos(t)-x2)/Nr;
  rk2(x3,v3);
  r[2]=r[2]+(xo*cos(t)-x3)*(xo*cos(t)-x3)/Nr;
  rk4(x4,v4);
  r[3]=r[3]+(xo*cos(t)-x4)*(xo*cos(t)-x4)/Nr;*/
  file<< t << " "<<sin(t)<<" "<<x1<</*" "<<x2<<" "<<x3<<" "<<x4<<*/endl;
 }
 for ( int i=0; i<4; i++)
  {
   cout<<sqrt(r[i])<<" ";
  }
  cout<<endl;
}		   
