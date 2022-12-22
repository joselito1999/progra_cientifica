//Marco V. Bayas.  Diciembre, 2022
//Programa para encontrar valores propios de una matriz tridiagonal.
//Método: Polinomio característico.

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

int n;
double l,d[10],b[10];

double pol(double x, int n, double a[10], double b[10]) 
{
 double p0,p1,f;
 
 p0=1;
 p1=a[0]-x;
 for ( int i = 1; i < n; i++ )
  {
   f=(a[i]-x)*p1-b[i-1]*b[i-1]*p0;
   p0=p1;
   p1=f;
  }
 return f;
}

void read (ifstream& infile)
 {
  string line;
  double aux;
 n=0;
 while(getline(infile,line) )
 {
  n++;
 }

 infile.clear();
 infile.seekg(0, ios::beg);
 for ( int i = 0; i < n-1; i++ )
  {
   for ( int j = 0; j <i; j++ )
    {
     infile>>aux;
     cout<<aux<<" ";
    }
    infile>>d[i];
    cout<<d[i]<<" ";
    infile>>b[i];
    cout<<b[i]<<" ";
    for ( int j = i+2; j < n; j++ )
     {
   infile>>aux;
   cout<<aux<<" ";
  }
  cout<<endl;
 }

 for ( int j = 0; j <n-1; j++ )
  {
   infile>>aux;
   cout<<aux<<" ";
  }
  infile>>d[n-1];
  cout<<d[n-1]<<" ";
 cout<<endl;

 cout<<endl;
}

void parametros ()
{
 cout << "Valor inicial de lambda \n";
 cin >> l;
}

bool comp (list<double> a,double b)
{
 int d=1e-6
 for (int i=0;i<a.size();i++){
   if (abs(a[i]-b)<d){
     return true;
   }
 }
 return false;
 
}


int main()
{
 int c,m,v1,v2,v3;
 double u1,u2,h,t,eps,dd;
 eps=1e-6;
 h=0.001;
 ifstream fx ("matrixt.txt");

 read(fx);
 list<double> val;
 cout<<"limite inferior"<<endl;
 cin>>v1;
 cout<<"limite superior"<<endl;
 cin>>v2;
 cout<<"paso"<<endl;
 cin>>v3;
 
 for (int k=v1; k<v2; k=k+v3){
 
 for ( int i = 0; i <n; i++ )
  {
   //t = clock();
   //parametros();
   l=k
   c=0;
   do
   {
    u1=pol(l,n,d,b);
    cout<<l<<" "<<u1<<endl;
    u2=pol(l+h, n, d, b); 
    l=l-h*u1/(u2-u1);
    c++;
   } while (abs(u1)>0.0001 and c<100);
   cout<<endl;
   cout <<"Listo! \n";
   cout <<c<<" iteraciones"<<endl;double b
   cout <<"l= "<<l<<endl;
  //t = clock() - t;
  }
 //cout<<"tiempo: "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 if (comp(val,l,n)!){
   
 
 
 
 
 
 
 
 
 
 
 
 cout<<endl;
 return 0;
}
