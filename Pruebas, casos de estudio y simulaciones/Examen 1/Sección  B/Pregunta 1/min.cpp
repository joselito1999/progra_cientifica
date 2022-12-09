#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double f(double x, double a){
 double f;
 f = tan(pow(a-x,0.5))+pow(a/x -1,0.5);
 
 return f;
}

double df(double x, double a){
 double df, h=1e-6;
 df = (f(x+h,a)-f(x,a))/h;
 
 return df;
}

double raiz (double *xo, double a){
 double del=1e-6, error, x;
 
 do{
 x=*xo-f(*xo,a)/df(*xo,a);
 error = abs(x-*xo);
 *xo=x;
 }while(error>del);
 
 return *xo;
}

int main(){

 double xo=0.1;
 
 ofstream file("datos.dat");
  
 for(int a=3;a<23;a++){
  raiz(&xo,a);
  file<<a<<" "<<xo<<endl;
 }
  
 return 0;
}
