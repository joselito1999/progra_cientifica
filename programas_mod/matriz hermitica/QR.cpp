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
//////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////
void productt(int dim, double r[10][10], double m1[10][10], double m2[10][10]) //producto entre una transpuesta por otra matriz
{
 for ( int i = 0; i < dim; i++ )
  {
   for ( int j = 0; j < dim; j++ )
    {
     r[i][j]=0;
     for ( int k = 0; k < dim; k++ )
      {
       r[i][j]=r[i][j]+m1[k][i]*m2[k][j];
      }
    }
  }
}

//////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////
void print(int dim, double m[10][10])
{ 
 for ( int i = 0; i < dim; i++ ) 
  { 
   for ( int j = 0; j < dim; j++ )
    {
      if(abs(m[i][j])<1e-10)
      {
       cout<<0<<" ";
      }else{     
       cout<<printf("%.2f",m[i][j])<<" ";
      }
    }
   cout<<endl;
  }
}
//////////////////////////////////////////////////////////////////
double eta(int dim, double m[10][10])
{
 double d;
 d=0;
 for ( int i = 0; i < dim; i++ ) 
  { 
   for ( int j = i; j < dim; j++ )
    {
     d=d+pow(m[i][j],2);
    }
   }
  return sqrt(d);
}
//////////////////////////////////////////////////////////////////
void qr(int dim,double m[10][10], double n[10][10],double o[10][10])
{
 for (int k=0; k<dim-1; k++)
  {
   householder(k,o,m);
   product(dim,mat,m,mat);
   product(dim,n,n,m);   
   o[k]=0;
  }
 cout<<"Matriz Q"<<endl;
 print(dim,n);
 cout<<"Matriz R"<<endl;
 print(dim,mat);
 product(dim,n,n,mat);
 cout<<"\n";
 print(dim,n);
 cout<<"\n";
 cout <<"Listo! \n";
}

//////////////////////////////////////////////////////////////////
int main()
{
 int c;
 double aa,w[10],p[10][10],q[10][10],aux[10][10];

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
  
 qr(n,p,q,w);
 do {
 cout<<"iteracion 1"<<endl;
 
 qr(n,p,q,w);
 
 
 
 }
 while()
 
 return 0;
}
