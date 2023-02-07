//Marco V. Bayas, Agosto 2022

//Programa para encontrar la forma de un cable suspendido en sus extremos.
//Ecuación: d^2u/dx^2=r*sqrt(1+(du/dx)^2); u(0)=u(1)=0
//Método la relajación

#include <iostream>
#include <fstream>
#include <math.h>

#define pi 3.14159265359
//Necesitamos conocer todos los puntos de todos los nodos. Por eso se define el vector u[101] porque tengo 100 partes del intervalo
using namespace std;

double r,dx,p,d,u[101],ep; 
int N;

double f0(int i)
{
 double f;
 
 f=r*sqrt(1+(u[i+1]-u[i])*(u[i+1]-u[i])/dx*dx);  //Parte correspondiente a la segunda derivada. Es la aproximación numérica de eso.
 return f;
}

void parametros ()
{
 cout << "Parámetro r: \n";
 cin >> r;
 cout << "valor del parámetro p [0-2]:  ";
 cin >> p;
 N=100;
 dx=1.0/N;
 ep=1e-6; //tolerancia para la convergencia del método
}

int main ()
{
 int m,k;
 double uu,f[101],de,des; 
 ofstream file ("cabler.dat");

 parametros ();
 for (int i = 0; i <= N; i++ )
 {
  u[i]=(i*dx)*((i*dx)-1); //Forma inicial. En este caso es un -sin(pi*x). Esta solución es cero en las fronteras. Esa es la única condición
  file  << i*dx << " "<<u[i]<<endl;
 }
 for ( int i = 1; i < N; i++ ) //Se gan los valores de f a los nodos/
  {
    f[i]=dx*dx*f0(i);
  }
 file << endl;
 file << endl;

 k=0;
 m=10000;
 do 
  {
   de=0;
   for ( int i = 1; i < N; i++ ) {
    des=u[i]; 
    uu=0.5*(u[i+1]+u[i-1]-f[i]); //Es el valor correspondiente al algoritmo de la ec de diferencias.
    u[i]=(1-p)*u[i]+p*uu; //actualización de la curva de acuerdo a la ecuación.
    des=des-u[i];//Para ver si converge
    de=de+des*des/N;
   }
   for ( int i = 1; i < N; i++ ) {
    f[i]=dx*dx*f0(i);
   }
   de=sqrt(de); //desviación entre las curvas
   k++;
   if (k%100==0){
    for ( int i = 0; i <= N; i++ ) {
     file  << i*dx << " "<<u[i]<<endl;
    }
    file << endl; 
    file << endl;
   }
  } while (de>ep && k<m);
 cout<<k<<" iteraciones"<<endl;

 //última actualización
 for ( int i = 0; i <= N; i++ ) {
    file  << i*dx << " "<<u[i]<<endl;
 }
 return 0;
}

