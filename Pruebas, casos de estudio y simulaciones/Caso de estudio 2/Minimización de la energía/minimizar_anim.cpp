#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double f (double x, double y){
 double f;
 f = 2/pow(pow(x,2)+pow(y,2),0.5)+2/pow(pow(x-1,2)+pow(y,2),0.5)+1/pow(pow(x-0.5,2)+pow(y-0.866,2),0.5);
 
 return f;
}

double dfx (double x, double y){
 double df, h=1e-6;
 
 df = (f(x+h,y)-f(x,y))/h;
 
 return df;
}

double dfy (double x, double y){
 double df, h=1e-6;
 
 df = (f(x,y+h)-f(x,y))/h;
 
 return df;
}

int main (){
 double xo, yo, x, y, df, dfaux=1, a, error, del;
 
 int cont=0; 
 
 ofstream file("extremos.dat");
 
 del=1e-6;
 
 cout<<"Ingrese el valor de xo: "; cin>>xo;
 cout<<"Ingrese el valor de yo: "; cin>>yo;

 a=0.01;
 
 del=1e-6;
 do{
 
 df = pow(pow(dfx(xo,yo),2)+pow(dfy(xo,yo),2),0.5);
 
 
 if(abs(dfaux-df)>1e-1){
  a=0.1;
 }else{
  a=0.001;
 }
  
 dfaux = df;
 
 x = xo - a*dfx(xo,yo)/df;
 y = yo - a*dfy(xo,yo)/df;
 
 error = pow(pow(x-xo,2)+pow(y-yo,2),0.5);
 
 xo = x;
 yo = y;
 
 cont++;
  
 file<<xo<<" "<<yo<<endl;
 file<<endl;
 file<<endl;
 
 }while(cont<1000 && df>del);
 
 cout<<"El valor del mínimo es: x="<< xo<<", y="<<yo<<endl;
 cout<<"El error es: "<<error<<endl;
 cout<< "El número de iteraciones fue: "<<cont<<endl;
 
 return 0;
}
