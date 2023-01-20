//Marco V. Bayas.   Enero, 2023
//Programa para encontrar los valores y vectores propios de una matriz nxn. 
//Método: Iteración inversa.

//Compilation $g++ [program name].cpp
//Run ./exe file1 file2 vp

#include<fstream>
#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int n;
double id[10][10],mat[10][10],l[10],vp[10][10],a[10][10],b[10],L[10][10],U[10][10],vp1[10][10],mat1[10][10];

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

void read (ifstream & infile1, ifstream & infile2)
 {
  string line;

  n=0;
  while(getline(infile1,line) )
   {
    n++;
   }

  infile1.clear();
  infile1.seekg(0, ios::beg);
  for ( int i = 0; i < n; i++ )
   {
    for ( int j = 0; j < n; j++ )
    {
     infile1>>mat[i][j];
     cout<<mat[i][j]<<" ";
     mat1[i][j]=mat[i][j];
    }
    cout<<endl;
   }
   cout<<endl;
  
  for ( int i = 0; i < n; i++ )
   {
    infile2>>l[i];
    cout<<l[i]<<" ";
   }
  cout<<endl;
  for ( int i = 0; i < n; i++ )
   {
    for ( int j = 0; j < n; j++ )
    {
     infile2>>vp[i][j];
     cout<<vp[i][j]<<" ";
     vp1[i][j]=vp[i][j];
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

void system (int dim, int num)
 {
  for ( int i = 0; i < dim; i++ ) { 
   for ( int j = 0; j < dim; j++ ) {
    a[i][j]=mat[i][j];
   }
  }
  for ( int i = 0; i < dim; i++ ) {
   a[i][i]=a[i][i]-l[num];
   b[i]=vp[i][num];
  }
 }

void lu (int dim, double m[10][10])
{
 double aux[10][10];

 L[0][0]=m[0][0];
 U[0][0]=1;
 for ( int i = 1; i < dim; i++ ) {
  L[i][i]=m[i][i]-m[i][i-1]*m[i-1][i]/L[i-1][i-1];
  L[i][i-1]=m[i][i-1];
  U[i][i]=1;
  U[i-1][i]=m[i-1][i]/L[i-1][i-1];
 }

 for ( int i = 2; i < dim; i++ ) {
  for ( int j = 0; j<i-1; j++ ) {
   L[i][j]=0;
   U[dim-i-1][dim-j-1]=0;
  }
  for ( int j = i-1; j<dim; j++ ) {
   L[i-2][j]=0;
   U[dim-i+1][dim-j-1]=0;
  }
 }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void comprobacion(int dim,int num, double matrix[10][10],double vec[10], double v[10][10])
{
 for ( int i = 0; i < dim; i++ ) 
  { 
   matrix[i][i]=matrix[i][i]-vec[num];
  }
 product(dim,v,matrix,v);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main (int argc, char *argv[])
{
 int c,la;
 double tol,aa,t,norm,v[10][10],aux[10],s[10],p[10][10];

 std::string ch1 = argv[1];
 std::string ch2 = argv[2];
 std::string ch3 = argv[3]; 
 ifstream fx (ch1+".txt");
 ifstream fv (ch2+".txt");
 la=std::stoi(&ch3[0])-1;

 read(fx,fv);

 t = clock();
 c=1;
 do
 {
  system(n,la);
  lu(n,a);
  cout<<"Iteración: " <<c<<endl;
  for ( int i = 0; i < n; i++ )
   {
    cout<<b[i]<<endl;;
   }
  cout<<endl;
  aux[0]=b[0]/L[0][0];
  for ( int i = 1; i < n; i++ ) {
   aux[i]=(b[i]-aux[i-1]*L[i][i-1])/L[i][i];
  }

  s[n-1]=aux[n-1];
  for ( int i = 2; i <= n; i++ ) {
   s[n-i]=aux[n-i]-s[n-i+1]*U[n-i][n-i+1];
  }

  norm=0;
  for ( int i = 0; i < n; i++ )
   norm=norm+s[i]*s[i];
  norm=sqrt(norm); 
 
  for ( int i = 0; i < n; i++ )
   s[i]=s[i]/norm;

  aa=0;
   for ( int i = 0; i < n; i++ )
    aa=aa+s[i]*b[i]/norm;

  l[la]=l[la]+aa;
  tol=0;
   for ( int i = 0; i < n; i++ )
    tol=tol+b[i]*b[i]/(norm*norm);

  for ( int i = 0; i < n; i++ )
   vp[i][la]=s[i];
  c++;
 } while (sqrt(tol)>0.00001 and c<10); 
 
 cout<<endl;
 for ( int i = 0; i < n; i++ )
   {
    cout<<l[i]<<" ";
   }
  cout<<endl;
 print(n,vp);
 t = clock() - t;
 cout<<"_________________________________"<<endl;
 comprobacion(n,la,mat,l,vp);
 print(n,vp);
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 return 0;
}