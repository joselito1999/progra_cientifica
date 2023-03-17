//Marco V. Bayas   Febrero 2023

// Programa para encontrar la autocorrelación de una serie temporal. 
//
//Método: Transformación discreta de Fourier. 
//Ejecución: ./exe file

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,dw,T;

void corr (int N, istream& filein, ostream& fileout)
{
 double x,xx,fr,fi,gr,gi,re,im;

 filein.clear();
 filein.seekg(0, ios::beg);
 for ( int k = 0; k < N; k++ )
 {
  filein>>x>>gr>>gi;
  re=gr*gr+gi*gi;
  im=0;
  fileout<<x<<" "<<re<<" "<<im<<endl;
 }
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
  re=re/sqrt(N+1);
  im=im/sqrt(N+1);
  fileout<<k*d<<" "<<re<<" "<<im<<endl;
 }
}

int main(int argc, char *argv[]) {

 int N;
 string line;

 std::string ch1 = argv[1];
 ifstream fw (ch1+".dat");
 ofstream gw (ch1+"w.dat");
 
 N=0;
 while(getline(fw,line) )
 {
  N++;
  fw>>T;
 }
 cout<<N<<" datos"<<endl;
 cout<<"Intervalo: "<<T<<endl;
 d=2*pi/T;
 dw=T/(N-1);
 
 corr(N,fw,gw);
 fw.close();
 gw.close();
 
 ifstream gww (ch1+"w.dat");
 ofstream fx (ch1+"t.dat"); 
 idft(N,gww,fx);
 gww.close();
 fx.close();
 return 0;
}

