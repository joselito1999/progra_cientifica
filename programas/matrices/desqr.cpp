//Marco V. Bayas.   Enero, 2023
//Programa para descomponer una matriz en la forma QR.
//Método: Matrices de Hausholder.

//compilation $g++ [program name].cpp

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

   aa=0;
   for ( int i = k; i < n; i++ )
   {
    w[i]=mat[i][k];
    aa=aa+w[i]*w[i];
   }
   aa=w[k]*sqrt(aa)/abs(w[k]);
   w[k]=w[k]+aa;

   for ( int i = 0; i < n; i++ )
    for ( int j =0 ; j < n; j++ )
     h[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k]);
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

int main()
{
 int c;
 double aa,w[10],p[10][10],q[10][10];

 ifstream fx ("matrix.txt");

 read(fx);

 for ( int i = 0; i < n; i++ )
  {
   id[i][i]=q[i][i]=1;
   for ( int j = i+1; j < n; j++ )
    {
     id[i][j]=id[j][i]=0;
     q[i][j]=q[j][i]=0;
    }
  }
 
 for (int k=0; k<n-1; k++)
  {
   householder(k,w,p);
   product(n,mat,p,mat);
   product(n,q,q,p);   
   w[k]=0;
  }
  
 cout<<"Matriz Q"<<endl;
 print(n,q);
 cout<<"Matriz R"<<endl;
 print(n,mat);
 product(n,q,q,mat);
 print(n,q);

 cout <<"Listo! \n";
 return 0;
}
