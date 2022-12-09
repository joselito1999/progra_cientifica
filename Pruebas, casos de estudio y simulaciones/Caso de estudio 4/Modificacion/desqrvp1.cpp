//Marco V. Bayas.   Junio, 2022
//Programa para encontrar los valores y vectores propios de una matriz nxn. 
//Método: Descomposición QR.

//Compilation $g++ [program name].cpp
//Run ./name file

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

int n;
double id[10][10],mat[10][10];

void product(int dim, double r[10][10], double m1[10][10], double m2[10][10])
{
 double aux[10][10];
 
 for ( int i = 0; i < dim; i++ )
  {
   for ( int j = 0; j < dim; j++ )
    {
     aux[i][j]=0;
     for ( int k = 0; k < dim; k++ )
      {
       aux[i][j]=aux[i][j]+m1[i][k]*m2[k][j];
      }
    }
  }
  for ( int i = 0; i < n; i++ ) 
    for ( int j = 0; j < n; j++ )
     r[i][j]=aux[i][j];
}

void householder(int k, double w[10], double h[10][10])
{
 double aa;
 int m;

   aa=0;
   for ( int i = k; i < n; i++ )
   {
    w[i]=mat[i][k];
    aa=aa+w[i]*w[i];
   }
   aa=sqrt(aa);

   if (w[k]!=0)
    aa=aa*w[k]/abs(w[k]);

   w[k]=w[k]+aa;
   m=k;
   if (k>0) m=k-1;
   if (w[k]!=0) {
    for ( int i = m; i < n; i++ )
     for ( int j = m ; j < n; j++ )
      h[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k]);
   } else
    {
     for ( int i = 0; i < n; i++ )
      for ( int j = 0 ; j < n; j++ )
       h[i][j]=id[i][j];
    }
}

void read (ifstream & infile)
 {
  string line;

  n=0;
  while(getline(infile,line) )
   {
    n++;
   }

  infile.clear();
  infile.seekg(0, ios::beg);
  for ( int i = 0; i < n; i++ )
   {
    for ( int j = 0; j < n; j++ )
    {
     infile>>mat[i][j];
     cout<<mat[i][j]<<" ";
    }
    cout<<endl;
   }
   cout<<endl;
 }

void print(int dim, double m[10][10])
{ 
 for ( int i = 0; i < dim; i++ ) 
  { 
   for ( int j = 0; j < dim; j++ )
    {
      cout<<m[i][j]<<" ";
    }
   cout<<endl;
  }
  cout<<endl;
}

int main (int argc, char *argv[])
{
 int c;
 double tol,aa,t,v[10][10],w[10],p[10][10],q[10][10];

 std::string ch = argv[1];

 ifstream fx (ch+".txt");
 read(fx);
 
 ofstream fm ("modos.dat");

 t = clock();
 for ( int i = 0; i < n; i++ )
  {
   v[i][i]=1;
   for ( int j = i+1; j < n; j++ )
    {
     v[i][j]=v[j][i]=0;
    }
  }
 c=1;
 do
 {
  for ( int i = 0; i < n; i++ )
   {
    id[i][i]=q[i][i]=1;
    for ( int j = i+1; j < n; j++ )
     {
      id[i][j]=id[j][i]=0;
      q[i][j]=q[j][i]=0;
     }
   }
 
  for (int k=0; k<n; k++)
   {
    householder(k,w,p); 
    product(n,mat,p,mat);
    product(n,q,q,p);
    w[k]=0;
   }
  
  product(n,mat,mat,q); 
  product(n,v,v,q);

  tol=0;
  for ( int i = 0; i < n; i++ )
   for ( int j = i+1; j < n; j++ )
    tol=tol+2*mat[i][j]*mat[i][j];
    
  tol=sqrt(tol/(n*(n-1)));
  
  c++;
 } while (tol>0.0001 and c<100); 
 
 print(n,mat);
 
 cout<<"Número de iteraciones: "<<c<<endl;
 cout<<"Valor de alpha_k: "<<tol<<endl;
 
 for(int i =0; i<n; i++){
  for(int j=0; j<n; j++){
   fm<<2*(j+1)<<" "<<0.5*i+0.5<<" "<<v[j][i]<<endl;
  }
 }
 
 cout<<"Vectores propios:"<<endl;
 print(n,v);
 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 return 0;
}
