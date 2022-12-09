#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
 for(int i=0; i<200; i++){

 double q=i/100.0;
 string qs=to_string(q);
 
 cout<<"q="<<q<<" :"<<endl;
 
 system(("./osci "+qs+" 100 100").c_str());
 system(("./ffts pendulo_"+qs).c_str());
 system(("gnuplot -c graf.plt "+qs).c_str());
 }
 
 return 0;
}










