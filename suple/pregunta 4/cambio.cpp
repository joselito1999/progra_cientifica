#include <iostream>
#include <fstream>
#include <math.h>
#define pi M_PI
using namespace std;
int main(int argc, char *argv[]) {

 int N;
 double f=0;
 
 string line;
 std::string ch1 = argv[1];
 ifstream fx (ch1+".dat");
 ofstream gw (ch1+"rep.dat");

 N=0;
 while(getline(fx,line) )
 {
  N++;
 }
 fx.clear();
 fx.seekg(0, ios::beg);
 for ( int j = 0; j < N; j++ )
 {
  fx>>f;
  gw<<0.01*j<<" "<<f<<endl;
 }
 }
