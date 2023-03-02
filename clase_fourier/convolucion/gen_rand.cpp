#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define pi M_PI

using namespace std;

int main(){
 double T,N,dt;
 int i=0;
 srand(time(NULL));
 cout<<"Tiempo total [s]"<<endl;
 cin>>T;
 cout<<"Numero de datos"<<endl;
 cin>>N;
 dt=T/N;
 ofstream gw ("random.dat");
 while(i*dt<T){
  gw<<i*dt<<" "<<1.0*rand()/(RAND_MAX)<<endl;
  i++;
 }
 cout<<"finalizado"<<endl;
 return 0;
}
