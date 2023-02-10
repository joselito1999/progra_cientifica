//Marco V. Bayas   Febrero 2023
// Programa para calcular la transformada discreta de Fourier 

//Ejecución: ./exe name

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,T;

void dft (int N, istream& filein, ostream& fileout) 
{
 double x,f,re,im;
 
 for ( int j = 0; j < N; j++ )
 {
  re=0;
  im=0;
  filein.clear();
  filein.seekg(0, ios::beg);

  for ( int k = 0; k < N; k++ )
  {
   filein>>x>>f;
   re=re+f*cos(-2*pi*j*k/N);
   im=im+f*sin(-2*pi*j*k/N);
  }
  re=re/sqrt(N);
  im=im/sqrt(N);
  fileout<<2*pi*j/T<<" "<<re<<" "<<im<<endl;
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
 cout<<N<<" datos"<<endl;
 cout<<"Intervalo: "<<T<<endl;
 d=T/(N-1);

 dft(N,fx,gw);
 fx.close();
 gw.close();

 ifstream gww (ch1+"w.dat");
 ofstream fxx (ch1+"t.dat");
 cout<<"Transformación inversa"<<endl;

 idft(N,gww,fxx); 
 gww.close();
 fxx.close();
 return 0;
}

