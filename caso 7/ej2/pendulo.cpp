//Marco V. Bayas. Julio 2022
//Programa para resolver la ecuacion del movimiento de un oscilador armónico.
//Métodos: euler-cromer, pc, rk2, rk4.
//Ecuación: x"+wo^2*x=0
//y1=x, y2=dx/dt, g1= y2, g2= -wo^2 y1

//compilación: $g++ algoritmos_osc.cpp

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#define pi 3.14159265359

using namespace std;

double x1,v1,x2,v2,x3,v3,x4,v4,x5,v5,xo,vo,wo,b,w,a,t,dt,q;
int num,n; //Para facilitar la evaluación simultanea

double g2 (double y1,double y2) //Se define la aceleración como una función.
{
 double f;
 
 f=-wo*wo*sin(y1)-q*y2;
 return f;
}

void eulercrommer (double & x, double & v)
{
 v = v+g2(x,v)*dt; //Se evalua la velocidad con g2
 x = x+v*dt; //Luego se evalua el x
}

void pc (double & x, double & v) //Picard. Es básicamente un método de predicción corrección
{
 double xi,vi,dv1, dv2;

 xi=x;
 vi=v;
 dv1=g2(x,v);
 x = x+v*dt; //Calculamos x y v al tiempo intermedio con el algoritmo de euler
 v = v+dv1*dt;//Primero se calcula x y luego v, es la predicción

 dv2=g2(x,v); //Es la corrección. Ahora es la nueva aceleración
 x=xi+0.5*(vi+v)*dt; //Cálculo de x y v con el promedio de las pendientes
 v=vi+0.5*(dv1+dv2)*dt;
}

void rk2 (double & x, double & v) //Runge Kutta 2. En un caso particular se reduce al picard
{//En este caso alfa 2 es 2/3
 double xi,vi,dvi,dv1;

 xi=x;
 vi=v;
 dvi=g2(xi,vi);

 x = xi+3*vi*dt/4; //Se actualiza el intervalo en 3/4 del delta
 v = vi+3*dvi*dt/4;
 dv1=g2(x,v);

 x=xi+(vi+2*v)*dt/3; //Se calcula los x y v con el algoritmo de runge kutta
 v=vi+(dvi+2*dv1)*dt/3;
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
}

int main ()
{
 double T,r[10];
 int Nr;
 parametros ();
 int q1=q*10;
 int x_1=xo*10;
 string s="pen_q_"+to_string(q1)+"_A_"+to_string(x_1)+"_N_"+to_string(num)+"_n_"+to_string(n)+".dat";
 ofstream file (s);
 //ofstream file2 ("per.dat");
 //ofstream file3 ("amp.dat");
 
 wo=1;
 T=2*pi/wo;
 dt=T/n;
 Nr=num*n;
 x1=xo;
 v1=vo;
 x2=xo;
 v2=vo;
 x3=xo;
 v3=vo;
 x4=xo;
 v4=vo;
 for ( int i=0; i<4; i++) r[i]=0;  //Inicializa el vector r que va a contener los mrsd
 for ( int i = 1; i < Nr; i++ ) {
  t=i*dt;
  eulercrommer(x1,v1);
  r[0]=r[0]+(xo*cos(t)-x1)*(xo*cos(t)-x1)/Nr;
  pc(x2,v2);
  r[1]=r[1]+(xo*cos(t)-x2)*(xo*cos(t)-x2)/Nr;
  rk2(x3,v3);
  r[2]=r[2]+(xo*cos(t)-x3)*(xo*cos(t)-x3)/Nr;
  rk4(x4,v4);
  r[3]=r[3]+(xo*cos(t)-x4)*(xo*cos(t)-x4)/Nr;
  //file<< t << " "<<xo*cos(t)<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<endl; //Para sacar la velocidad solo se sacar con vi
  file<< t <<" "<<x4<<endl;
  if(abs(v4)<1e-3 && x1>0){
   //file2<<t/T<<" "<<x4<<endl;
  }
  if(abs(v4)<3e-3){
   //file3<<t/T<<" "<<abs(x4)<<endl;
  }
  
 }
 for ( int i=0; i<4; i++)
  {
   cout<<sqrt(r[i])<<" ";
  }
  cout<<endl;
}	
