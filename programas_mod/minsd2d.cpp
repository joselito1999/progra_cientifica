//Marco V. Bayas Noviembre 2022.
//Mínimo de una función de dos variables
//Método: "Steepest descend"
//Programa vinculado con Grafico08.plt

#include <iostream>
#include <assert.h>
#include <math.h>
#include <fstream>


using namespace std;

double fxy (double x, double y)
{
 double f;

 f=(x-1)*(x-1)*exp(-y*y)+y*(y+2)*exp(-2*x*x);
 return f;
}

int main()
{
 int count;
 double a,xo,yo,x,y,df,dfx,dfy,error,h,del;
 del=1e-6;
 h=1e-6;
 a=0.1; //le cambiamos de 0.1 a 0.001 para una mejor precisión
 
 ofstream file("minimo2d.dat"); //creamos el archivo del min consistente con Grafico08.plt
 
 cout << "Valor de xo" << endl;
 cin >> xo;
 cout << "Valor de yo" << endl;
 cin >> yo;
 
 error=1;
 count=0;
 
 do { //cambiamos el while por el do while para que se vayan guardando los valores
	 
  file<<xo<<" "<<yo<<" "<<0<<endl; //le agrego el cero puesto que estamos graficando en 3D y teniamos solamente dos columnas
  file<<endl;
  file<<endl;
  
  dfx=(fxy(xo+h,yo)-fxy(xo,yo))/h;
  dfy=(fxy(xo,yo+h)-fxy(xo,yo))/h;
  df=sqrt(dfx*dfx+dfy*dfy);
  x=xo-a*dfx/df;
  y=yo-a*dfy/df;
  error=sqrt((x-xo)*(x-xo)+(y-yo)*(y-yo));

  if(fxy(x,y) > fxy(xo,yo)){
  a = a/5;
  }else{
  xo = x;
  yo = y;
  }
  
  count++;
 }
 while(error > del && count<1000); //le cambiamos el numero de iteraciones de 1000 a 1500 puesto que el a le hicimos más pequeño (de 0.1 a 0.001)
 //Como solucion efectiva podremos cambiar el valor de a, inicialmente grande y luego más pequeño. }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<xo<<" "<<yo<<endl;
  cout << "Error: "<<error<<endl;
  return 0;
}
