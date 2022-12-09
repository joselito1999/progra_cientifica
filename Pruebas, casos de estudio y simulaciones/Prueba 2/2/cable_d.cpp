//Marco V. Bayas.   Agosto, 2022
//Programa para encontrar la forma de un cable suspendido en sus extremos.
//Ecuación: d^2u/dx^2=r*sqrt(1+(du/dx)^2); u(0)=u(1)=0
//Método: método del disparo

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

double u,v,r,a,dx;
int N;

void eulercromer (double & u, double & v) //Algoritmode euler cromer
{
 double a;

 a=r*sqrt(1+v*v); //f. Calcula la segunda derivada, d^2u/dx^2
 v = v+a*dx;      //y2. Calcula du/dx
 u = u+v*dx;      //y1. Calcula u con el valor de y2 calculado
}

double fa(double uo, double a)
{
 double x,dx,f;

 u=uo;
 v=a;
 for ( int i = 0; i < N; i++ ) {
  eulercromer(u,v);
 }
 f=u;
 return f;
}

void print (ofstream & file, double a, bool b)
{
 u=0.2;
 v=a;
 file<< 0 << " "<< u <<endl;
 for ( int i = 0; i < N; i++ ) {
  eulercromer(u,v);
  file<< (i+1)*dx << " "<< u <<endl;
  if(i==0||i==N-1){
  cout<<"pend"<<v<<endl;}
 }
 
 cout<<endl<<endl;
 
 if (b) {
  file<<endl;
  file<<endl;
 } 
}

void parametros ()
{
 cout << "Parámetro r: \n";
 cin >> r;
 N=100; //Número de intervalos
 dx=1.0/N; //Paso en el intervalo
}

int main()
{
 int n,c;
 double u1,u2,a,h;

 ofstream file ("cabled.dat");

 parametros();
 
 c=0;
 h=0.001;
 a=0.1;
 do
 {
  print(file,a,1);
  u1=fa(0.2,a);
  u2=fa(0.2,a+h);
  a=a-h*u1/(u2-u1);
  c++;
 } while (abs(u1)>0.00000001 and c<10000);
 cout<<endl;
 
 cout <<"Listo! \n";
 cout <<c<<" iteraciones"<<endl;
 cout <<"a= "<<a<<endl; //El valor final de la pendiente
 print(file,a,0);
 return 0;
}
