//Marco V. Bayas.   Junio, 2022
//Programa para encontrar los valores y vectores propios de una matriz nxn. 
//Método: Descomposición QR.

//Compilation $g++ [program name].cpp
//ejecucion del programa junto al numero N de osciladores deseado (./a.out N)

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

int n;
double id[101][101],mat[101][101];

void product(int dim, double r[101][101], double m1[101][101], double m2[101][101])
{
 double aux[101][101];
 
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

void householder(int k, double w[101], double h[101][101])
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

void matriz (int n) //Genera la matriz tridiagonal que corresponde al problema planteado
 {
  for ( int i = 0; i < n; i++ ) {
   for ( int j = i; j<=i+1; j++ ) {
    mat[i][j]=2-3*(j-i);
   }
   for ( int j = i+2; j< n; j++ ) {
    mat[i][j]=0;
   }
   for ( int j = 0; j<i+1; j++ ) {
    mat[i][j]=mat[j][i];
   }
  }
 }

void print(int dim, double m[101][101])
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
 double tol,aa,t,v[101][101],w[101],p[101][101],q[101][101];

 std::string ch = argv[1];
 ofstream file ("frecuencias_"+ch+".dat" );
 n=std::stoi(&ch[0],0); //Transforma caracteres a integrales
 matriz(n);
 //print(n,mat);
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

  tol=0;
  for ( int i = 0; i < n; i++ )
   for ( int j = i+1; j < n; j++ )
    tol=tol+mat[i][j]*mat[i][j];
  c++;
 } while (sqrt(tol)>0.0001 and c<500); 
 
 cout<<"Iteraciones: "<<c<<endl;
 cout<<"Móduloij:       "<<sqrt(tol)<<endl;
 cout<<endl;
 cout<<"Frecuencias:  wi/w1:"<<endl;
 for ( int i = 0; i < n; i++ )
  {
  cout<<sqrt(mat[n-i-1][n-i-1])<<"   "<<sqrt(mat[n-i-1][n-i-1])/sqrt(mat[n-1][n-1])<<endl;
  file<<i+1<<" "<<sqrt(mat[n-i-1][n-i-1])<<endl;
  }
 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 return 0;
}
