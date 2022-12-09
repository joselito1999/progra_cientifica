//Marco V. Bayas, Agosto 2022

//Simulación de las ondas en una cuerda sujeta en sus extremos. 
//Ecuación d^2 u(x,t)/dt^2 =  v^2 d^2 u(x,t) /dx^2
//Condiciones iniciales: 
//u(x,0)=(h/xo)*x para 0<x<xo; u(x,0)=(h/(L-xo))*(L-x) para xo<x<L
//u'(x,0)=0;
//Condiciones de frontera:
//u(0,t)=u(L,t)=0
//L=1
//Método: Evaluación numérica de la solución geneal

//Ejecución: ./exe xo
//

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;

double h,xo,t,dt,dx;
double u1,u2,v,ao,a,x;
double u[1001],bn[10001];
int N;

void inicio (ostream& fileout)//Forma inicial de la cuerda
{
 int m;
  m=ceil(xo/dx);
 //segmento 1
 for ( int i = 0; i < m; i++ ) {
  u[i]=h*dx*i/xo;
  fileout<<i*dx<<" "<<u[i]<<endl; //Almaceno la forma enun archivo
 }
 //segmento 2
 for ( int i = m; i <=1000 ; i++ ) {
  u[i]=h*(1-dx*i)/(1-xo);
  fileout<<i*dx<<" "<<u[i]<<endl;
 }
}

double funcion (double x, int n, double p) //Integrando involucrado en el cálculo del coeficiente bn. Por eso está multiplicado por el sin
{
 double f;

 if (x <= p) {
  f=h*x*sin(n*pi*x)/p; //Calculo de coeficiente de serie de Fourier
 } else {
  f=h*(1-x)*sin(n*pi*x)/(1-p);
 }
 return f;
}

double fbn (int n, double p)//Calculo bn. Por las condiciones iniciales solo unos es diferente de cero
{
 int nn;
 double h,f;

 nn=10000;
 h=1.0/nn;

 f=0;
 for ( int i = 0; i <= nn/2-1; i++ ) {
  f=f+funcion(2*i*h,n,p)+4*funcion((2*i+1)*h,n,p)+funcion((2*i+2)*h,n,p);
 }
 f=2*h*f/3;
 return f;
}

void parametros ()
{
 h=0.01; //Levanto la cuerda una centesima parte de la long de la cuerda
 N=2000; //2000 puntos en la serie temporal. 2000 puntos temporales.
 dt=0.005; //El tiempo total es 10.
 dx=1.0/1000; //El dx es el tamaño del intervalo en la parte espacial
}//La frecuencia máxima es el inverso del dt

int main (int argc, char *argv[])//Como argumento es el xo
{
 double T;
 string line;

 std::string ch1 = argv[1];

 ofstream file ("cuerda"+ch1+".dat" ); //
 ofstream file2 ("fuerza"+ch1+".dat" ); //
 xo=std::stod(&ch1[1],0);

 parametros ();
 inicio(file); //Determina el perfil inicial de la cuerda

 //Cálculo de los coeficientes bn. Para cada punto se tiene un valor de bn
 for ( int i = 1; i <=1000 ; i++ ) {
   bn[i]=fbn(i,xo);
 }

 //Evolucion temporal
 cout<<"Evaluando la evolución temporal"<<endl;
 for ( int it = 1; it <=N ; it++ ) {//Inicia la serie hasta N, que son  los 2000. Para cada instante se tiene un perfil, es decir y(x).
  for ( int ix = 1; ix <= 1000; ix++ ) {
   u[ix]=0;//Inicio la variable para calcular la suma
   for ( int i = 1; i <=1000 ; i++ ) {
    u[ix]=u[ix]+bn[i]*cos(i*pi*it*dt)*sin(i*pi*ix*dx); //Esta es la serie. Calculo 1000 términos de la suma, en sí son infinitos pero solo sumamos bastantes
   }
  }
  file2<<it*dt<<" "<<1000*u[1]<<endl;
   //Almacenamiento de perfiles
   if (it<=200) { //Cada 200 datos guardo
    file<<endl;
    file<<endl; 
    for ( int i = 0; i <=1000 ; i++ ) {
     file<<i*dx<<" "<<u[i]<<endl;//Guardo valores del desplazamiento de cada x
    }
   }
   if (it%200==0) cout<<"it: "<<it<<endl;
 }
}		   
