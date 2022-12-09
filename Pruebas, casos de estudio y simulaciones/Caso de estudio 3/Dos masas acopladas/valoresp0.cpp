//Marco V. Bayas.   Junio, 2022
//Programa para encontrar valores propios de una matriz.
//Método: Resolución de la ecuación secular

//Compilation: $g++ [program name].cpp
//Run: ./exe

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

double l;

double det(int n, double m[10][10])
{
 double d=0;
 int subi, subj;
 double submat[10][10];  
 
 if (n == 2) 
 {
  d=m[0][0] * m[1][1] - m[1][0] * m[0][1];
 }
 else
 {  
  for(int col =0; col < n; col++)
  {  
   subi = 0;  
   for(int i = 1; i < n; i++)
   {  
    subj = 0;
    for(int j = 0; j < n; j++)
    {    
     if (j == col)
    {
     continue;
    }
    submat[subi][subj] = m[i][j];
    subj++;
    }
    subi++;
  }
  d = d + (pow(-1 ,col) * m[0][col] * det(n - 1 ,submat));
  }
 }
 return d;
}

double fdet(double x, int n, double m[10][10]) 
{
 double f;
 double a[10][10];

 for ( int i = 0; i < n; i++ )
  {
   for ( int j = 0; j < n; j++ )
   {
    if (i==j) {
    a[i][j]=m[i][j]-x;
   } else 
   {
    a[i][j]=m[i][j];
   }
  }
 }
 f=det(n,a); 
 return f;
}

void parametros ()
{
 cout << "Valor inicial de lambda \n";
 cin >> l;
}

int main()
{
 int n,c;
 string line;
 double u1,u2,a[10][10],h;

 h=0.001;
 ifstream fx ("matrix.txt");

 parametros();
 n=0;
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
 do
 {
  u1=fdet(l,n,a);
  cout<<l<<" "<<u1<<endl;
  u2=fdet(l+h, n, a); 
  l=l-h*u1/(u2-u1);
  c++;
 } while (abs(u1)>0.0001 and c<100);
 cout<<endl;
 cout <<"Listo! \n";
 cout <<c<<" iteraciones"<<endl;
 cout <<"l= "<<l<<endl;
 return 0;
}
