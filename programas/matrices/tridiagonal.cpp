//Marco V. Bayas.   Diciembre, 2022
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
      if(abs(m[i][j])<1e-10)
      {
       cout<<0<<" ";
      }else{     
       cout<<printf("%.1f",m[i][j])<<" ";
      }
    }
   cout<<endl;
  }
}

void printfl(int dim, double m[10][10],ostream& file)
{ 
 double aux;

 for ( int i = 0; i < dim; i++ )
  {
   for ( int j = 0; j < dim; j++ )
    {
     aux=round(1000*m[i][j])/1000;
     file<<aux<<" ";
    }
   file<<endl;
  }
}

int main()
{
 int n,c;
 string line;
 double aa,t,aux[10][10],w[10],mat[10][10],p[10][10],id[10][10],xx;

 ifstream fx ("matrix.txt");
 ofstream ft ("matrixt.txt");

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
    fx>>mat[i][j];
    cout<<mat[i][j]<<" ";
   }
   cout<<endl;
  }
  cout<<endl; 

 for ( int i = 0; i < n; i++ )
  {
   id[i][i]=1;
   w[i]=0;
   for ( int j = i+1; j < n; j++ )
     id[i][j]=id[j][i]=0;
  }
 
 for (int k=0; k<n-2; k++)
  {
   aa=0;
   for ( int i = k+1; i < n; i++ )
   {
    w[i]=mat[i][k];
    aa=aa+w[i]*w[i];
   }
   aa=w[k+1]*sqrt(aa)/abs(w[k+1]);
   w[k+1]=w[k+1]+aa;

   for ( int i = 0; i < n; i++ )
    for ( int j = 0 ; j < n; j++ )
     p[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k+1]);

   product(n,aux,mat,p);
   productt(n,mat,p,aux);

   cout<<"Vector w"<<k+1<<endl;
   for ( int j = 0 ; j < n; j++ )
    {
     cout<<w[j]<<endl;
    }
   cout<<endl;
   cout<<"Matriz P"<<k+1<<endl;
   print(n,p);
   cout<<endl;
   cout<<"Matriz A"<<k+1<<endl;
   print(n,mat);
   cout<<endl;
   cout<<"Continuar"<<endl;
   cin.get();
   for ( int i = 0; i < n; i++ )
    w[i]=0;
  }
  printfl(n,mat,ft);
 cout <<"Listo! \n";
 return 0;
}
