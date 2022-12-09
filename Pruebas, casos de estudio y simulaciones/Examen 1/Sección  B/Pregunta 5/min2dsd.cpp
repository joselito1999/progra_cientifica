//Marco V. Bayas May-2022.
//Mínimo de una función de dos variables
//Método: "Steepest descend"

#include <iostream>
#include <math.h>

using namespace std;

double fxyz (double x1, double x2, double x3)
{
 double f,C,Vo,ro;
 
 C=1.43996e-9;
 Vo=1.09e3;
 ro=3.2e-9;
 
 f=-C/(x3*ro) + Vo*exp(-x3)-C/(x2*ro) +Vo/C*exp(-x2)+C/(x1*ro);
 return f;
}

int main()
{
 int count;
 double a,x1o,x2o,x3o,x1,x2,x3,df,dfx1,dfx2,dfx3,error,h,del;
 del=1e-6;
 h=1e-4;
 a=0.1;
 
 cout << "Valor de x1" << endl;
 cin >> x1o;
 cout << "Valor de x2" << endl;
 cin >> x2o;
 cout << "Valor de x3" << endl;
 cin >> x3o;
 
 error=1;
 count=0;
 while( error > del && count<1000) {
  dfx1=(fxyz(x1o+h,x2o,x3o)-fxyz(x1o,x2o,x3o))/h;
  dfx2=(fxyz(x1o,x2o+h,x3o)-fxyz(x1o,x2o,x3o))/h;
  dfx3=(fxyz(x1o,x2o,x3o+h)-fxyz(x1o,x2o,x3o))/h;
  df=sqrt(dfx1*dfx1+dfx2*dfx2+dfx3*dfx3);
  x1=x1o-a*dfx1/df;
  x2=x2o-a*dfx2/df;
  x3=x3o-a*dfx3/df;
  error=sqrt((x1-x1o)*(x1-x1o)+pow((x2-x2o),2)+pow((x3-x3o),2));
  x1o=x1;
  x2o=x2;
  x3o=x3;
  count++;
 }

  cout << "Número de iteraciones: " <<count<< endl;
  cout << "Posición del mínimo: "<<x1<<" "<<x2<<" "<<x3<<endl;
  cout << "Error: "<<error<<endl;
  return 0;
}
