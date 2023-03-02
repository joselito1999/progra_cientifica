#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI

using namespace std;

int main(){
 double T,N,o,dt,w;
 int i=0;
 cout<<"Tiempo total [s]"<<endl;
 cin>>T;
 cout<<"Numero de datos"<<endl;
 cin>>N;
 cout<<"Desfase"<<endl;
 cin>>o;
 cout<<"W"<<endl;
 cin>>w;
 dt=T/N;
 ofstream gw ("fuerza1.dat");
 while(i*dt<T){
  gw<<i*dt<<" "<<sin(w*i*dt+o)+cos(5*i*dt)<<endl;
  i++;
 }
 cout<<"finalizado"<<endl;
 return 0;
}
