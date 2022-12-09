//Marco V. Bayas   Agosto 2022

// Programa para encontrar la solución partícular de la ecuación del movimiento de las oscilaciones forzadas. 
//Ecuación: x"=-x-q*x'+b*cos(wt)
//Método: Transformación discreta de Fourier. 

#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;
 
double d,dw,T;

double funcionr(double x) //Calcula la parte real del número complejo adjunto a la transformada de fourier de la función. O sea gj/F(wj), eso es lo que se está calculando
{
 double q,f,w;

 q=0.5; //Coeficiente de rozamiento

 f=(x*x-1)/((x*x-1)*(x*x-1)+q*q*x*x); //El 1 es el wo²
 return f;
}

double funcioni(double x) //Parte imaginaria de lo anterior dicho
{
 double q,f,w;

 q=0.5;

 f=q*x/((x*x-1)*(x*x-1)+q*q*x*x);
 return f;
}

void ftconv (int N, istream& filein, ostream& fileout) //Tranformada de fourier de la convolucion, es decir, del gj
{
 double x,xx,fr,fi,gr,gi,re,im;

 filein.clear();
 filein.seekg(0, ios::beg);
 for ( int k = 0; k < N/2; k++ ) //Todo esto es la transformada de Fourier de la convolución, esto por las propiedades de la convolución, solo se multipĺican dos números ocmplejos
 {
  filein>>x>>gr>>gi; //El archivo tiene 3 columnas. x las frecuencias, la segunda la parte real y la tercera la parte imaginaria
  fr=funcionr(x);
  fi=funcioni(x);
  re=gr*fr-gi*fi; //Multiplicación del número de F(w) con el número complejoj asociado, esto para el cálculo dl gi
  im=gr*fi+gi*fr;
  fileout<<x<<" "<<re<<" "<<im<<endl;
 }
 for ( int k = 0; k < N/2; k++ ) //Segunda mitad c:
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

void idft (int N, istream& filein, ostream& fileout) //Transformada inversa de fourier no rapida
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

int main(int argc, char *argv[]) { //El argumento es el nombre del archivo con el que vamos a trabajar. La transformada de fourier de la fuerza

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
 cout<<N<<" datos"<<endl; //No es necesario considerar un numero par de datos porque la inversa no es rapida
 cout<<"Intervalo: "<<T<<endl;
 d=2*pi/T;
 dw=T/(N-1);
 
 ftconv(N,fw,gw); //Se crea la transformada de la convolución y lo saco
 fw.close();
 gw.close();
 
 ifstream gww (ch1+"w.dat"); //Llamamos al archivo
 ofstream fx (ch1+"t.dat");  //El archivo con wt al final es el que nos interesa
 idft(N,gww,fx);//Calculo la transformada inversa y ya tengo mi solución
 gww.close();
 fx.close();
 return 0;
}

