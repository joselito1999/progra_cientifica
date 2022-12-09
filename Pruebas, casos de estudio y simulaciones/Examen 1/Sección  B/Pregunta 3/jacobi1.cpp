//Marco V. Bayas.   Junio, 2022
//Programa para encontrar valores propios de una matriz.
//Método: Transformación de Jacobi 

//compilation $g++ [program name].cpp

#include<fstream>
#include<iostream>
#include<math.h>
#include <cstdlib>

using namespace std;

int n;
double mat[10][10];
double mataux[10][10];

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

void read (ifstream & infile)
 {
  string line;

  n=0;
  while(getline(infile,line) )//Lee el archivo hasta encontrar la dimensión n
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

void equal(){

   for ( int i = 0; i < n; i++ )
   {
    for ( int j = 0; j < n; j++ )
    {
     mataux[i][j]=mat[i][j];
    }
   }
}

void print(int dim, double m[10][10])
{ 
 for ( int i = 0; i < dim; i++ ) 
  { 
   for ( int j = 0; j < dim; j++ )
    {
    if(abs(m[i][j])<1e-5){
    	cout<<0<<" ";
    }else{
      cout<<m[i][j]<<" ";
    }
    }
   cout<<endl;
  }
}

int main(int argc, char *argv[]) //Tenemos el ingreso del nómbre del archivo en la línea de compando
{

 int c;
 double tol,aa,t,aux[10][10],o[10][10],d[10][10],p[10][10],id[10][10],r[10][10];

 std::string ch = argv[1]; //Transformo el nombre del archivo en un string y lo guardo en ch

 ifstream fx (ch+".txt"); //Lo llamo al archivo. Puedo ingresar todo archivo con extensión .txt

 ofstream datos ("datos.dat");

 read(fx); //Lee el archivo llamado fx
 //Todo lo demás es simplemente lo mismo
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
 
 equal();
 
 for(double i1=0.2; i1<5.1; i1+=.4){
 
 mataux[0][0]=mataux[0][0]*i1;
 mataux[0][1]=mataux[0][1]*i1;
 mataux[2][1]=mataux[2][1]*i1;
 mataux[2][2]=mataux[2][2]*i1;
 
 c=1;
 do {
  for ( int i = 0; i < n; i++ )
   {
    for ( int j =i+1 ; j < n; j++ )
     {
      if (mataux[i][j]!=0) {
       aa=(mataux[j][j]-mataux[i][i])/mataux[i][j];
       t=(-aa+sqrt(aa*aa+4))/2;
       p[i][i]=p[j][j]=1/sqrt(1+t*t);
       p[i][j]=t*p[i][i];
       p[j][i]=-p[i][j];  
  
       product(n,aux,mataux,p);
       productt(n,mataux,p,aux);
       p[i][i]=p[j][j]=1;
       p[i][j]=p[j][i]=0;
      } 
     }
   }
  cout<<"ciclo: "<<c<<endl;
  print(n,mataux);

  tol=0;
  for ( int i = 0; i < n; i++ )
   for ( int j = i+1; j < n; j++ )
    tol=tol+mataux[i][j]*mataux[i][j];
   cout<<"tol"<<" "<<sqrt(tol)<<endl;
   cout<<endl;
  c++;
  } while (sqrt(tol)>0.0001 and c<10);

 t = clock() - t;
 cout <<"Listo! "<<(float)t/CLOCKS_PER_SEC<<"s"<<endl;
 
 for(int i=0; i<n; i++){
  datos<<i1<<" "<<sqrt(mataux[i][i])<<endl;
 }
 datos<<endl;
 datos<<endl;
 
 equal();
 }
 return 0;
}
