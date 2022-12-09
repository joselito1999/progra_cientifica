//Marco V. Bayas.   Junio, 2022
//Programa para reducir una matriz simétrica a su forma tridiagonal.
//Método: Método de Hausholder.

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

void product(int dim, double r[10][10], double m1[10][10], double m2[10][10]) 
{
 for ( int i = 0; i < dim; i++ )
  {
   for ( int j = 0; j < dim; j++ )
    {
     r[i][j]=0;
     for ( int k = 0; k < dim; k++ )
      {
       r[i][j]=r[i][j]+m1[i][k]*m2[k][j];
      }
    }
  }
}

void productt(int dim, double r[10][10], double m1[10][10], double m2[10][10])
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
}

int main()
{
 int n,c;
 string line;
 double aa,t,aux[10][10],w[10],mat[10][10],p[10][10],id[10][10];

 ifstream fx ("matrix.txt");

 n=0;
 while(getline(fx,line) )
  {
   n++;
  }

 fx.clear();
 fx.seekg(0, ios::beg);
 for ( int i = 0; i < n; i++ )//Leemos la información del archivo y lo enviamos a la matriz mat
  {
   for ( int j = 0; j < n; j++ )
   {
    fx>>mat[i][j];
    cout<<mat[i][j]<<" ";
   }
   cout<<endl;
  }
  cout<<endl; 

 for ( int i = 0; i < n; i++ )//Definimos las matrices identidad y w
  {
   id[i][i]=1;
   w[i]=0;
   for ( int j = i+1; j < n; j++ )
     id[i][j]=id[j][i]=0;
  }
 
 for (int k=0; k<n-2; k++)
  {
   aa=0; //Alpha
   for ( int i = k+1; i < n; i++ )
   {
    w[i]=mat[i][k];//Igualo el vector igual a los valores de la matriz desde k+1 hasta n. Son los elementos fuera de la diagonal
    aa=aa+w[i]*w[i];
   }
   aa=w[k+1]*sqrt(aa)/abs(w[k+1]);
   w[k+1]=w[k+1]+aa;

   for ( int i = 0; i < n; i++ )
    for ( int j = 0 ; j < n; j++ )
     p[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k+1]); //Es equivalente a la dada en nclase

   product(n,aux,mat,p); //Multiplico la matriz mat por p
   productt(n,mat,p,aux);//Multiplico pt por aux y ya tengo la tranformación kesima

   print(n,p);
   cout<<"columna: "<<k<<endl;
   print(n,mat);
   for ( int i = 0; i < n; i++ )
    w[i]=0;
  }

 cout <<"Listo! \n";
 return 0;
}
