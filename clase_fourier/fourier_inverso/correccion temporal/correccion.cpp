#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime> 
#define pi M_PI

using namespace std;
double d;
int N=0,n=0;





int main(int argc, char *argv[]) {
 string line;
 std::string ch1 = argv[1];
 ifstream fx (ch1+".dat");
 ofstream gw (ch1+"_ct.dat");
 while(getline(fx,line) )
 {
  N++;
 }
 for(int i =1;i<N;i++){
 
 
 }
 
}
