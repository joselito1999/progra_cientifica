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
 f=u-0.2;
 return f;
}

void print (ofstream & file, double a, bool b) //Almacenamos la solución en un archivo. Usamos el b para imprimir dos espacios e ilustrar la evolución de la solución
{
 u=0;
 v=a;
 file<< 0 << " "<< u <<endl; //Valor en la frontera
 for ( int i = 0; i < N; i++ ) {
  eulercromer(u,v);
  file<< (i+1)*dx << " "<< u <<endl;
 }
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
 h=0.001; //Paso para la derivada
 a=0.1; //Valor inicial del alpha, es la derivada de la función que queremos en el punto cero.
 do
 {//Algoritmo de Newton Raphson para la raíz
  print(file,a,1); //Imprimo en el archivo con el valor de a que se va calculando en cada iteración. Esto solo para animar la evolución de la solución
  u1=fa(0,a); //Siempre para el punto cero, porque desde ahí se empieza
  u2=fa(0,a+h); //Para el siguiente paso de h
  a=a-h*u1/(u2-u1);
  c++;
 } while (abs(u1)>0.000001 and c<100); //Detengo la búsqueda cuando el u1 sea aproximadamente cero, porque son las condiciones de frontera.
 cout<<endl;
 
 cout <<"Listo! \n";
 cout <<c<<" iteraciones"<<endl;
 cout <<"a= "<<a<<endl; //El valor final de la pendiente
 print(file,a,0);
 return 0;
}
