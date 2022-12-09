//Marco V. Bayas Noviembre 2022.
//Mínimo de una función de dos variables
//Método: "Steepest descend"

#include <iostream>
#include <assert.h>
#include <math.h>
#include <fstream>

using namespace std;

double fxyz (double x, double y, double z)
{
 double f;

 f=0.0411/x - 0.0411/y -  0.0411/sqrt(x*x+y*y- 2*x*y*cos(z)) + exp(-y)+exp(-sqrt(x*x+y*y- 2*x*y*cos(z)));
 return f;
}

int main()
{
 ofstream myfile;
 myfile.open ("datos.dat");
 int count;
 double a,xo,yo,zo,x,y,z,df,dfx,dfy,dfz,error,h,del,nite;
 del=1e-6;
 h=1e-6;
 a=1;
 
 cout << "Valor de xo" << endl;
 cin >> xo;
 cout << "Valor de yo" << endl;
 cin >> yo;
 cout << "Valor de zo" << endl;
 cin >> zo;
 cout << xo <<endl;
 cout << yo<< endl;
 cout << zo<< endl;
 error=1;
 count=0;
 myfile << "iteracion"<< "\t"<< "Valor r1" << "\tValor r2" <<endl;
 nite=1000;
 while( error > del && count<1000 ) {
  dfx=(fxyz(xo+h,yo,zo)-fxyz(xo,yo,zo))/h;
  dfy=(fxyz(xo,yo+h,zo)-fxyz(xo,yo,zo))/h;
  dfz=(fxyz(xo,yo,zo+h)-fxyz(xo,yo,zo))/h;
  df=sqrt(dfx*dfx+dfy*dfy+dfz*dfz);
  x=xo-a*dfx/df;
  y=yo-a*dfy/df;
  z=zo-a*dfz/df;
  error=sqrt((x-xo)*(x-xo)+(y-yo)*(y-yo)+(z-zo)*(z-zo));
  if(fxyz(x,y,z) > fxyz(xo,yo,zo)){
      a=a/5;
  }else{
    xo=x;
    yo=y;
    zo=z;
  }
  
  count++;
  
  myfile << count << " \t "<< xo << "\t " << yo << endl;
  
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<xo<<" "<<yo<<" "<<zo<< endl;
  cout << "Error: "<<error<<endl;
  myfile.close();
  return 0;
}

