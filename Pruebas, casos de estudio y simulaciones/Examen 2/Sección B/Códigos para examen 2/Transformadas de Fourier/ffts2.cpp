//Marco V. Bayas   Agosto 2022
// Programa para calcular la transformada rapida de Fourier 
// Transformada rápida: dos descomposiciones.
//Compilación: $g++ [program name].cpp
//Ejecución: exe name

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,T;

void fft (int N, istream& filein, ostream& fileout) 
{
 double a,x,f,re,im,xj[2][2],x1[2][4];
 int aux;
 
 string s;

 for ( int j = 0; j < N/4; j++ )
 {
  filein.clear();
  filein.seekg(0, ios::beg);
  for ( int i = 0; i < 4; i++ ) {
   x1[0][i]=0;
   x1[1][i]=0;
  }
  for ( int k = 0; k < N/4; k++ )
  {
   a=2*pi*j*(4*k)/N;
   for ( int i = 0; i < 4; i++ ) {
    filein>>x>>f;  
    x1[0][i]=x1[0][i]+f*cos(a);
    x1[1][i]=x1[1][i]-f*sin(a);
   }
  }
  a=2*pi*j/N;
  for ( int i = 0; i < 2; i++ ) {
   xj[0][i]=x1[0][i]+x1[0][i+2]*cos(2*a)+x1[1][i+2]*sin(2*a);
   xj[1][i]=x1[1][i]+x1[1][i+2]*cos(2*a)-x1[0][i+2]*sin(2*a);
  }
  
  re=(xj[0][0]+xj[0][1]*cos(a)+xj[1][1]*sin(a))/sqrt(N);
  im=(xj[1][0]+xj[1][1]*cos(a)-xj[0][1]*sin(a))/sqrt(N);

  fileout<<2*pi*j/T<<" "<<re<<" "<<im<<endl;
 }

}

int main(int argc, char *argv[]) {

 double t;
 int N;
 string line;

 std::string ch1 = argv[1];
 ifstream fx (ch1+".dat");
 ofstream gw (ch1+"w.dat");

 t = clock();
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

 fft(N,fx,gw);
 fx.close();
 gw.close();

 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 return 0;
}

