//Marco V. Bayas.  Julio, 2022
//Programa para simular un conjunto de osciladores acoplados
//Método para encontrar los valores propios: Descomposición QR.

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

int n;
double id[15][15],mat[15][15],v[15][15];

void product(int dim, double r[15][15], double m1[15][15], double m2[15][15])
{
 double aux[15][15];
 
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

void productt(int dim, double r[15][15], double m1[15][15], double m2[15][15])
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

void productmv(int dim, double r[15], double m[15][15], double v[15])
{
 double aux[15];

 for ( int i = 0; i < dim; i++ )
  {
   aux[i]=0;
   for ( int k = 0; k < dim; k++ )
    {
     aux[i]=aux[i]+m[i][k]*v[k];
    }
  }
  for ( int i = 0; i < n; i++ )
   r[i]=aux[i];
}

void householder(int k, double w[15], double h[15][15])
{
 double aa;
 int m;

 aa=0;
 for ( int i = k; i < k+2; i++ )
  {
   w[i]=mat[i][k];
   aa=aa+w[i]*w[i];
  }
  aa=w[k]*sqrt(aa)/abs(w[k]);
  w[k]=w[k]+aa;
  
  m=k;
  if (k>0) m=k-1;
  for ( int i = m ; i < n; i++ )
   for ( int j = m ; j < n; j++ )
    h[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k]);
}

void read (ifstream & infile)
 {
  int count;
  string line;
  double k[15];

  count=0;
  while (!infile.eof())
    {
     infile >> k[count];
     count++;
    }
   n=count-2;
  for ( int i = 0; i < n; i++ )
   {
    mat[i][i]=k[i]+k[i+1];
    mat[i][i+1]=-k[i+1];
   }
  for ( int i = 0; i < n; i++ )
    for ( int j = i+2; j < n; j++ )
     mat[i][j]=0;
  for ( int i = 1; i < n; i++ )
   {
    for ( int j = 0; j < i; j++ )
    {
     mat[i][j]=mat[j][i];
    }
   }
 }

void print(int dim, double m[15][15])
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

void solve() 
{
 int c;
 double tol,aa,t,aux[15][15],w[15],p[15][15],q[15][15];

 for ( int i = 0; i < n; i++ )
  {
   v[i][i]=1; //Valores iniciales del vector V
   for ( int j = i+1; j < n; j++ )
    {
     v[i][j]=v[j][i]=0; //Valores iniciales del vector V
    }
  }
 c=1;
 do
 {
  for ( int i = 0; i < n; i++ )
   {
    id[i][i]=q[i][i]=1;
    w[i]=0;
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
    tol=tol+mat[i][j]*mat[i][j];
  c++;
 } while (sqrt(tol)>0.0001 and c<200); 
}

int main ()
{
 int c,m;
 double tol,aa,t,dt,aux[15][15],w[15],p[15][15],q[15][15],x[15],qx[15],fs[15],fq[15];

 ifstream fx ("system.txt");
 ofstream outfile1 ("modos.dat");
 ofstream outfile2 ("osciladores.dat");
 //ofstream outfile4 ("frecuencias_10_5.txt");
 m=20000;
 dt=0.01;
 read(fx);
 print(n,mat);

 t = clock();

 solve();

 cout<<"Frecuencias:"<<endl;
 for ( int i = 0; i < n; i++ )
  {
   fq[i]=sqrt(mat[i][i]);
   cout<<fq[i]<<" ";
  }
 cout<<endl;

 /*for ( int i = n-1; i > -1; i-- ) //Saca las frecuencias en modo ascendente
  {
   outfile4<<n-i<<" "<<fq[i]<<endl;
  }
 cout<<endl;*/

 for ( int i = 0; i < n; i++ )
   fs[i]=0;
 for ( int it = 0; it < m; it++ )
  {
   outfile2<<it*dt;
   for ( int i = 0; i < n; i++ )
    {
     qx[i]=cos(fq[i]*it*dt+fs[i]);
    }
    if (it%10==0 && it<=1000) {
     for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < n; j++ ) {
       outfile1<<3*i+2+v[i][j]*qx[j]<<" "<<0<<" ";
      }
      outfile1<<endl;
     }
     if (it!=1000) {
      outfile1<<endl;
      outfile1<<endl;
     }
    }
    productmv(n,x,v,qx);
    for ( int i = 0; i < n; i++ )
    {
     outfile2<<" "<<x[i];
    }
    outfile2<<endl;
  } 
 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;

 cout<<"Vectores propios: "<<endl;
 
 print(n,v);

 return 0;
}
