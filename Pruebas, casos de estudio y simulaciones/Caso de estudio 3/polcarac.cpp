//Valor propio de matriz tridiagonal usando polinomio caracteristico y metodo de newton.

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;


//Polinomio caracteristico
double poln (double x, int n, double m[10][10]){

double f;
double p[n+1];
p[0]=1;
p[1]=m[0][0]-x;

for(int k=2; k<n+1 ;k++){
   p[k]=(m[k-1][k-1]-x)*p[k-1]-pow(m[k-2][k-1],2)*p[k-2];
}
f=p[n];
return f;
}



int main(){

int n,c;
string line;
double a[10][10],x,l;
double del=1e-8;
double dx=1.0;
double h=0.000001;

 ifstream fx ("matrix.txt");

 cout << "Valor inicial de lambda \n";
 cin >> l;

 n=0;

//Leer archivo con matriz:

 while(getline(fx,line) )
 {
  n++;
 }

 fx.clear();
 fx.seekg(0, ios::beg);
 for ( int i = 0; i < n; i++ )
 {
  for ( int j = 0; j < n; j++ )
  {
   fx>>a[i][j];
   cout<<a[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<endl;


c=0;

do{ 
  x=l-h*(poln(l,n,a))/(poln(l+h,n,a)-poln(l,n,a));
  dx=x-l;
  l=x;
  c++;
  cout<<l<<endl;
  }while( abs(dx) > del );

 cout<<endl;
 cout<<"Valor Propio: "<<l<<endl;
 cout <<c<<" iteraciones"<<endl;
 cout <<"Listo! \n";
 
 return 0;
}


