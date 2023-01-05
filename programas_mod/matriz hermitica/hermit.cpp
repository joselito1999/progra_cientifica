//Marco V. Bayas    Junio, 2022.
//Programa para generar la matriz real que contiene los valores propios de una matriz hermítica.
//g++ hermit.cpp 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
 
using namespace std;
int n;
double mat[20][20];

void cnumber (string s, double c[2])
 {
  int pos;
  string x,a,b;

  pos=0;

   if (s[0]!='i') {
      x=s[0];
      pos=1;
     } else {
      a='0';
      b='1';
      pos=2;
     }
     while (s[pos] != '+' && s[pos] != '-' && s[pos]!='i' && pos<s.length())
      {
       x=x+s[pos];
       pos++;
      }
    if ((pos) == (s.length()))
     {
      a=x;
      b='0';
     }
    if ((pos) == (s.length()-1))
     {
      a='0';
      if (s[pos] == '+' || s[pos] == '-') {
       b=x+'1';
      } else {
       b=x;
      }
     }

    if ((pos) < (s.length()-1))
     {
      a=x;
      while (s[pos]!='i' && pos<s.length())
      {
       b=b+s[pos];
       pos++;
      }
    }
    if ( b == "+" || b== "-" ) b=b+'1';

    c[0]=std::stod(a);
    c[1]=std::stod(b);
 }

void read (ifstream & infile)
 {
  string line,z;
  double aux[2];
  
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
     infile>>z;
     cnumber(z,aux);
     mat[i][j]=mat[n+i][n+j]=1.0*aux[0];
     mat[i][n+j]=-1.0*aux[1];
     mat[n+i][j]=1.0*aux[1];
    }
   }
 }

void print(int dim, double m[20][20], ofstream& outfile)
{
 for ( int i = 0; i < dim; i++ )
  {
   for ( int j = 0; j < dim; j++ )
    { 
      cout<<m[i][j]<<" ";
      outfile<<m[i][j]<<" ";
    }
   cout<<endl;
   outfile<<endl;
  }
  cout<<endl;
}

int main()
{
 using namespace std;
 ifstream infile ("matrix.txt");
 ofstream outfile ("matrixr.txt");

 read(infile);
 print(2*n,mat,outfile);   
 
 infile.close();
 outfile.close();
 return 0;
}
