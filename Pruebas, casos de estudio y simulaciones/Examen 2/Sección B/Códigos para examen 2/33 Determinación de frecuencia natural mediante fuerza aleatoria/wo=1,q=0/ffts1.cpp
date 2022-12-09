//Marco V. Bayas  Agosto 2022
//Programa para calcular la transformada discreta de Fourier 
//Transformada rápida: una descomposición.
//Compilación: $g++ [program name].cpp
//Ejecución: exe name
//Elimina la transformada inversa y se calcula solo hasta la mitad de los datos

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,T;

void fft (int N, istream& filein, ostream& fileout) 
{
 double a,x,f,re,im,xj[2][2];
 int aux;
 
 string s;

 for ( int j = 0; j < N/20; j++ )
 {
  filein.clear();
  filein.seekg(0, ios::beg);
  for ( int i = 0; i < 2; i++ )
   {
    xj[0][i]=0;
    xj[1][i]=0;
   }
  for ( int k = 0; k < N/2; k++ )
  {
   for ( int i = 0; i < 2; i++ )
   {
    a=2*pi*j*(2*k)/N;
    filein>>x>>f; 
    xj[0][i]=xj[0][i]+f*cos(a);
    xj[1][i]=xj[1][i]-f*sin(a);
   }
  }
  a=2*pi*j/N;
  re=(xj[0][0]+xj[0][1]*cos(a)+xj[1][1]*sin(a))/sqrt(N);
  im=(xj[1][0]+xj[1][1]*cos(a)-xj[0][1]*sin(a))/sqrt(N);
  fileout<<2*pi*j/T<<" "<<re<<" "<<im<<endl;
 }
}

int main(int argc, char *argv[]) {

 int N;
 double t;
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

