#include<iostream>
#include<math.h>

using namespace std;


//Defino la funcion a evaluar
	double f (double x){

	 double f;
	 
	 f = -1/x+exp(-x);
	 
	 return f;
	}

int main(){
 
 double a, b, c, x, del;
 int cont=0;
 
 const double w1=0.38197, w2=0.61803; //Defino los valores para usar el golden ratio
 
 cout<<"Ingrese los puntos iniciales: "<<endl;
 cout << "a: "; cin>>a;
 cout << "b: "; cin>>b;
 cout << "c: "; cin>>c;
 
 del = 1e-6; //Defino la tolerancia
 
 do{
 
 if(abs(a-b)>=abs(b-c)){
  
  x=a+w1*(c-a);
   if(f(x)>f(b)){
    a=x;
   }else{
    c=b;
    b=x;
   }
 }else{
  
  x=a+w2*(c-a);
  
   if(f(x)>f(b)){
    c=x;
   }else{
    a=b;
    b=x;
   }
 }
  cont++;
 }while(abs(c-b)>del);

 cout<<"El mínimo de la función es: "<< b<<" \u03C3"<<endl;
 cout<<"Numero de iteraciones: "<< cont<<endl;
 cout<<"El error es: "<<abs(c-b)<<endl;
 return 0;
}
