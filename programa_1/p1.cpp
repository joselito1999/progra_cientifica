#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#define pi 3.14159265359

using namespace std;

double xo,vo,wo,b,w,a,t,dt,q;
int num,n; //Para facilitar la evaluación simultanea

double g2 (double y1,double y2) //Se define la aceleración como una función.
{
 double f;
 
 f=-wo*wo*sin(y1)-q*y2;
 return f;
}

void rk4 (double & x, double & v)
{ //Runge Kutta 4 para el caso visto en clase
 double xx[5],vv[5],dv[5];
//A nuestro intervalo grande lo divido en 4 intervalos y realizo 4 cálculos intermedios
 xx[1]=x; //Almaceno los valores xk. Porque los usamos al final
 vv[1]=v;
 dv[1]=g2(xx[1],vv[1]);

 xx[2] = xx[1]+vv[1]*dt/2; //Primera actualización en un subintervalo
 vv[2] = vv[1]+dv[1]*dt/2;
 dv[2]=g2(xx[2],vv[2]); //Calculo la aceleración
 
 xx[3] = xx[1]+vv[2]*dt/2;
 vv[3] = vv[1]+dv[2]*dt/2;
 dv[3]=g2(xx[3],vv[3]);
 
 xx[4] = xx[1]+vv[3]*dt;
 vv[4] = vv[1]+dv[3]*dt;
 dv[4]=g2(xx[4],vv[4]);

 x=xx[1]+(vv[1]+2*vv[2]+2*vv[3]+vv[4])*dt/6; //Se suma algo más al xk. Lo que se suma son los coeficientes del runge kutta 4. g1 es la velocidad
 v=vv[1]+(dv[1]+2*dv[2]+2*dv[3]+dv[4])*dt/6; //g2 es la aceleración
}

void parametros ()
{
 cout << "periodos \n";
 cin >> num;
 cout << "divisiones (typ n=100) \n";
 cin >> n;
 cout << "amplitud \n";
 cin >> xo;
 vo=0;
 cout << "Coef rozamiento \n";
 cin >> q;
 int q1=q*10;
 int x_1=xo*10;
}

void resolucion()
{
 double T,r;
 int Nr;
 parametros ();
 string s="pen_q_"+to_string(q1)+"_A_"+to_string(x_1)+"_N_"+to_string(num)+"_n_"+to_string(n)+".dat";
 ofstream file (s);
 wo=1;
 T=2*pi/wo;
 dt=T/n;
 Nr=num*n;
 for ( int i = 1; i < Nr; i++ ) 
  {
  t=i*dt;
  rk4(xo,vo);
  r=r+(xo*cos(t)-x4)*(xo*cos(t)-x4)/Nr;
  file<< t <<" "<<x4<<endl;
  }
  cout<<sqrt(r)<<" ";
}


int main ()
{
 

 

}		   

