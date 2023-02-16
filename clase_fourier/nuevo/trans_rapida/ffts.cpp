//Marco V. Bayas   Febrero 2023
//Programa para calcular la transformada discreta de Fourier 
//Algoritmo: transformada rápida simple. 
//Ejecución: exe name

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime> 
#define pi M_PI

using namespace std;
 
double d,T;
unsigned t0, t1;

void dft (int N, istream& filein, ostream& fileout) 
{
 double a,x,f,re,im,xre,xim,yre,yim;
 int aux;
 
 string s;
 ofstream filet ("temp");

 for ( int j = 0; j < N/2; j++ )
 {
  xre=xim=0;
  yre=yim=0;
  filein.clear();
  filein.seekg(0, ios::beg);

  for ( int k = 0; k < N/2; k++ )
  {
   a=2*pi*j*(2*k)/N;
   filein>>x>>f;   //elementos pares
   xre=xre+f*cos(a);
   xim=xim-f*sin(a);
   filein>>x>>f;   //elementos impares
   yre=yre+f*cos(a);
   yim=yim-f*sin(a);
  }
  a=2*pi*j/N;
  re=(xre+yre*cos(a)+yim*sin(a))/sqrt(N);
  im=(xim+yim*cos(a)-yre*sin(a))/sqrt(N);
  fileout<<2*pi*j/T<<" "<<re<<" "<<im<<endl;
  aux=j+N/2;
  re=(xre-yre*cos(a)-yim*sin(a))/sqrt(N);
  im=(xim-yim*cos(a)+yre*sin(a))/sqrt(N);
  filet<<2*pi*aux/T<<" "<<re<<" "<<im<<endl;
 }

 filet.close();
 ifstream file ("temp");
 while (getline(file,s)) {
  fileout<<s<<endl;  
 }

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
 t0=clock();
 dft(N,fx,gw);
 t1=clock(); 
 fx.close();
 gw.close();

 //ifstream gww (ch1+"w.dat");
 //ofstream fxx (ch1+"t.dat");
 //cout<<"Transformación inversa"<<endl;

 //idft(N,gww,fxx); 
 //gww.close();
 //fxx.close();
 double time = (double(t1-t0)/CLOCKS_PER_SEC);
 cout << "Execution Time: " << time << endl;
 return 0;
}

