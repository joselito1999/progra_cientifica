//Marco V. Bayas   Agosto 2022
//Programa para calcular la transformada discreta de Fourier 
//Algoritmo: transformada rápida simple. 
//Ejecución: exe name
//Hace solo una divsion entre pares e impares

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,T;

void dft (int N, istream& filein, ostream& fileout) 
{
 double a,x,f,re,im,xre,xim,yre,yim;
 int aux;
 
 string s;
 ofstream filet ("temp"); //Almacena los valores de xj y yj porque los usa para la transformada. Luego ya no me sirven entonces lo borro al final

 for ( int j = 0; j < N/20; j++ ) //Iteramos la mitad de valores, entre pares e impares.
 {
  xre=xim=0;//Son lo valores de la suma. Los inicializo
  yre=yim=0;
  filein.clear(); //Cada vez que voy a calcular me voy al inicio del archivo
  filein.seekg(0, ios::beg);

  for ( int k = 0; k < N/2; k++ ) //Primer cælculo de lox xj y yj
  {
   a=2*pi*j*(2*k)/N; //Argumento de lazs funciones seno y coseno
   filein>>x>>f;   //elementos pares
   xre=xre+f*cos(a);
   xim=xim-f*sin(a);
   filein>>x>>f;   //elementos impares
   yre=yre+f*cos(a);
   yim=yim-f*sin(a);
  }
  a=2*pi*j/N;
  re=(xre+yre*cos(a)+yim*sin(a))/sqrt(N); //Actualizo los valores complejos de re e im
  im=(xim+yim*cos(a)-yre*sin(a))/sqrt(N);
  fileout<<2*pi*j/T<<" "<<re<<" "<<im<<endl; //Guardo Parte real e imaginaria
  aux=j+N/2;
  re=(xre-yre*cos(a)-yim*sin(a))/sqrt(N);
  im=(xim-yim*cos(a)+yre*sin(a))/sqrt(N);
  filet<<2*pi*aux/T<<" "<<re<<" "<<im<<endl; //Los guardo en el temporal
 }

 filet.close();
 ifstream file ("temp"); //Abro el arcchivo temporal
 while (getline(file,s)) {
  fileout<<s<<endl;  //lo pongo en el archivo de salida.
 }
 //Los gj se calcula con los xj y yj. Los xj y yj son complejos en general. 
//hago esto de cerrar y volver a abrir el archivo para que no me salkgan los datos alternados sino en orden
 file.close();
 remove("temp");
}

void idft (int N, istream& filein, ostream& fileout)
{
 double x,gr,gi,re,im;

 for ( int k = 0; k < N; k++ )
 {
  re=0;
  im=0;
  filein.clear();
  filein.seekg(0, ios::beg);
  for ( int j = 0; j < N; j++ )
  {
   filein>>x>>gr>>gi;
   re=re+gr*cos(2*pi*j*k/N)-gi*sin(2*pi*j*k/N);
   im=im+gr*sin(2*pi*j*k/N)+gi*cos(2*pi*j*k/N);
  }
  re=re/sqrt(N);
  im=im/sqrt(N);
  fileout<<k*d<<" "<<re<<" "<<im<<endl;
 }
}

int main(int argc, char *argv[]) {

 int N;
 string line;
 
 std::string ch1 = argv[1];
 ifstream fx (ch1+".dat");
 ofstream gw (ch1+"w.dat");

 double time=clock();

 N=0;
 while(getline(fx,line) )
 {
  N++;
  fx>>T;
 }
 d=T/(N-1);
 cout<<N<<" datos"<<endl;
 N=2*(N/2);
 T=d*(N-1);
 cout<<N<<" datos considerados"<<endl;
 cout<<"Intervalo: "<<T<<endl;

 dft(N,fx,gw);
 fx.close();
 gw.close();

 /*ifstream gww (ch1+"w.dat");
 ofstream fxx (ch1+"t.dat");
 cout<<"Transformación inversa"<<endl;

 idft(N,gww,fxx); 
 gww.close();
 fxx.close();*/
 
 time=clock()-time;
 cout<<"Tiempo de ejecución: " << (float) time/CLOCKS_PER_SEC<<endl;
 return 0;
}

