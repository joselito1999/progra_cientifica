//Marco V. Bayas.   Agosto, 2022
//Programa para encontrar la forma de un cable suspendido en sus extremos.
//Ecuación: d^2u/dx^2=r*sqrt(1+(du/dx)^2); u(0)=u(1)=0
//Método: método del disparo

//compilation $g++ [program name].cpp

//f(x)=cosh(r*(x-0.5))/r-cosh(0.5*r)/r

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;
double izquierda, derecha;

double u,v,r,a,dx,rmsd=0;
int N;

void eulercromer (double & u, double & v) //Algoritmode euler cromer
{
 double a;

 a=r*sqrt(1+v*v); //f. Calcula la segunda derivada, d^2u/dx^2
 v = v+a*dx;      //y2. Calcula du/dx
 u = u+v*dx;      //y1. Calcula u con el valor de y2 calculado
}

double fa(double uo, double a) //Funcion de la pendiente cuya raíz vamos a encontrar
{
 double x,dx,f;

 u=uo;
 v=a;
 for ( int i = 0; i < N; i++ ) {
  eulercromer(u,v);
 }
 f=u-derecha;
 return f;
}

void print (ofstream & file, double a, bool b)
{
 u=izquierda;
 v=a;
 
 rmsd=0;
 file<< 0 << " "<< u <<endl;
 for ( int i = 0; i < N; i++ ) {
  eulercromer(u,v);
  
  rmsd=rmsd+pow((cosh(r*((i+1)*dx-0.5))-cosh(r*0.5))/r-u,2)/N;
  //f(x)=cosh(r*(x-0.5))/r-cosh(0.5*r)/r
  file<< (i+1)*dx << " "<< u <<endl;
 }
 
 rmsd=sqrt(rmsd);
 
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
 
 cout<<"Condicion u(0): "; cin>>izquierda;
 cout<<"Condicion u(1): "; cin>>derecha;
 
 parametros();
 //f(x)=cosh(r*(x-0.5))/r-cosh(0.5*r)/r
 c=0;
 h=0.001; //Paso para la derivada
 a=0.1; //Valor inicial del alpha, es la derivada de la función que queremos en el punto cero.
 do
 {//Algoritmo de Newton Raphson para la raíz
  print(file,a,1); //Imprimo en el archivo con el valor de a que se va calculando en cada iteración. Esto solo para animar la evolución de la solución
  u1=fa(izquierda,a); //Siempre para el punto cero, porque desde ahí se empieza
  u2=fa(izquierda,a+h); //Para el siguiente paso de h
  a=a-h*u1/(u2-u1);
  c++;
 } while (abs(u1)>0.000001 and c<100); //Detengo la búsqueda cuando el u1 sea aproximadamente cero, porque son las condiciones de frontera.
 cout<<endl;
 
 print(file,a,1);
 
 cout <<"Listo! \n";
 cout <<c<<" iteraciones"<<endl;
 cout <<"Valor de la pendiente encontrado a= "<<a<<endl; //El valor final de la pendiente
 cout <<"rmsd= "<<rmsd<<endl;
 print(file,a,0);
 return 0;
}
