//Marco V. Bayas   Febrero 2023

// Programa para encontrar la solución de la ecuación del movimiento de las oscilaciones forzadas. 
//Ecuación: x"=-x-q*x'+b*cos(wt)
//Método: Transformación discreta de Fourier. 

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,dw,T;

double funcionr(double x)
{
 double q,f,w;

 q=0.1;

 f=(x*x-1)/((x*x-1)*(x*x-1)+q*q*x*x);
 return f;
}

double funcioni(double x)
{
 double q,f,w;

 q=0.1;

 f=q*x/((x*x-1)*(x*x-1)+q*q*x*x);
 return f;
}

void ftconv (int N, istream& filein, ostream& fileout)
{
 double x,xx,fr,fi,gr,gi,re,im;

 filein.clear();
 filein.seekg(0, ios::beg);
 for ( int k = 0; k < N/2; k++ )
 {
  filein>>x>>gr>>gi;
  fr=funcionr(x);
  fi=funcioni(x);
  re=gr*fr-gi*fi;
  im=gr*fi+gi*fr;
  fileout<<x<<" "<<re<<" "<<im<<endl;
 }
 for ( int k = 0; k < N/2; k++ )
 {
  filein>>x>>gr>>gi;
  xx=x-(2*k)*dw;
  fr=funcionr(xx);
  fi=-funcioni(xx);
  re=gr*fr-gi*fi;
  im=gr*fi+gi*fr;
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
  fileout<<k*d<<" "<<-re<<" "<<-im<<endl;
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
 
 ftconv(N,fw,gw);
 fw.close();
 gw.close();
 
 ifstream gww (ch1+"w.dat");
 ofstream fx (ch1+"t.dat"); 
 idft(N,gww,fx);
 gww.close();
 fx.close();
 
 return 0;
}

