//Marco V. Bayas.   Junio, 2022
//Programa para encontrar valores propios de una matriz.
//Método: Transformación de Jacobi 

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

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
  for ( int i = 0; i < dim; i++ )
    for ( int j = 0; j < dim; j++ )
    r[i][j]=aux[i][j];
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


void printVal(int dim, double m[10][10])
{ 
 cout<<"Valores propios:"<<"\n";
 cout<<"\n";
 for ( int i = 0; i < dim; i++ ) 
  { 
   for ( int j = 0; j < dim; j++ )
    {
      if(i==j)
      {     
       cout<<printf("%.4f",m[i][j])<<"; ";
      }
    }
   cout<<endl;
  }
}



int main(int argc, char *argv[])
{
 int n,c;
 string line;
 double tol,aa,t,aux[10][10],o[10][10],mat[10][10],d[10][10],p[10][10],id[10][10],r[10][10];

 std::string ch = argv[1];

 ifstream fx (ch+".txt");

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
    o[i][j]=mat[i][j];
    cout<<mat[i][j]<<" ";
   }
   cout<<endl;
  }
  cout<<endl; 

 t = clock();
 for ( int i = 0; i < n; i++ )
  {
   p[i][i]=1;
   id[i][i]=1;
   r[i][i]=1; //Valores iniciales del vector R   
   for ( int j = i+1; j < n; j++ )
    {
     p[i][j]=p[j][i]=0;
     id[i][j]=id[j][i]=0;
     r[i][j]=r[j][i]=0; //Valores iniciales del vector R
    }
  }
 
 c=1;
 do {
  for ( int i = 0; i < n; i++ )
   {
    for ( int j =i+1 ; j < n; j++ )
     {
      if (mat[i][j]!=0) {
       aa=(mat[j][j]-mat[i][i])/mat[i][j];
       t=(-aa+sqrt(aa*aa+4))/2;
       p[i][i]=p[j][j]=1/sqrt(1+t*t);
       p[i][j]=t*p[i][i];
       p[j][i]=-p[i][j];  
  
       product(n,aux,mat,p);
       productt(n,mat,p,aux);
       p[i][i]=p[j][j]=1;
       p[i][j]=p[j][i]=0;
      } 
     }
   }
  cout<<"ciclo: "<<c<<endl;
  print(n,mat);

  tol=0;
  for ( int i = 0; i < n; i++ )
   for ( int j = i+1; j < n; j++ )
    tol=tol+mat[i][j]*mat[i][j];
   cout<<"tol"<<" "<<sqrt(tol)<<endl;
   cout<<endl;
  c++;
  } while (sqrt(tol)>1e-10 and c<20);
 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 cout<<"\n";
 printVal(n,mat);
 return 0;
}
