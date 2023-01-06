//Marco V. Bayas.   Enero, 2023
//Programa para descomponer una matriz en la forma QR.
//Método: Matrices de Hausholder.

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>

using namespace std;

int n;
double id[10][10],mat[10][10],q[10][10];

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

void householder(int k, double w[10], double h[10][10]) //genera matriz householder
{
 double aa;

   aa=0; //contiene el parabametro alpha de la forma del vector w
   for ( int i = k; i < n; i++ )
   {
    w[i]=mat[i][k];
    aa=aa+w[i]*w[i];  //Norma
   }
   aa=w[k]*sqrt(aa)/abs(w[k]);
   
   w[k]=w[k]+aa;
   
   
   for ( int i = 0; i < n; i++ )
    for ( int j =0 ; j < n; j++ )
     h[i][j]=id[i][j]-w[i]*w[j]/(aa*w[k]); //matriz Pk
}

void read (ifstream & infile) //lectura matriz
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

void ini_valores()
{
	for ( int i = 0; i < n; i++ ) //inicializacion de la matriz
  {
   id[i][i]=q[i][i]=1;
   for ( int j = i+1; j < n; j++ )
    {
     id[i][j]=id[j][i]=0;
     q[i][j]=q[j][i]=0;
    }
  }
}

int main()
{
 int c;
 double aa,w[10],p[10][10],tol, d[10][10],aux[10][10];

 ifstream fx ("uno.txt");
 read(fx); //aqui obtenemos la matriz mat
  c=1;

 do
 {
	 
 ini_valores();
 
 for (int k=0; k<n-1; k++) 
  {
   householder(k,w,p); //generamos P
   //cout<<"P "<<k+1<<endl;
   //print(n,p);
   product(n,mat,p,mat); //producto P y mat, y se guarda en mat
   //cout<<"P "<<k+1<<"A"<<k<<endl;
   //print(n,mat);
   product(n,q,q,p);   //producto q y p, y se guarda en q
   w[k]=0;
  }
 cout<<"iteracion "<<c<<endl; 
 cout<<"Matriz Q"<<endl;
 print(n,q);
 cout<<"Matriz R"<<endl;
 print(n,mat);
 
 //product(n,aux,q,mat); //aqui comprobamos que indeed A=QR
 //print(n,aux);

 product(n,mat,mat,q);
 print(n,mat);//matriz diagonal 

  tol=0;
  for ( int i = 0; i < n; i++ ) //cálculo del parámetro n.
   for ( int j = i+1; j < n; j++ )
    tol=tol+mat[i][j]*mat[i][j];
   cout<<"tol"<<" "<<sqrt(tol)<<endl;
   cout<<endl;
  c++;
  } while (sqrt(tol)>0.0001 and c<100);


 cout <<"Listo! \n";
 return 0;
}
