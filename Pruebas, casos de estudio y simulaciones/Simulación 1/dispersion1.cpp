//Marco V. Bayas Junio 2022.
//Simulación de la dispersión clásica de partículas.
//Potencial: V(r)=k/r exp(-r/a)
//k=1,a=1;
//Visualización.

//Run: ./exe energy // Es ejecutar el programa y poner la energía ./a.out "Valor de la energía"

#include <iostream>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <time.h>
#define pi 3.14159265359

using namespace std;

double x,y;

double fx (double x, double p1, double p2) //Funcion auxiliar para integrar
{
 double f;
 f=1/(x*x*sqrt(1-p1*p1/(x*x)-p2*exp(-x)/x));
 return f;
}

double gx (double x, double p1, double p2)//Ecuacion no lineal a reolver
{
 double f;
 f=1-p1*p1/(x*x)-p2*exp(-x)/x;
 return f;
}

double dgx (double x, double p1, double p2) //Derivada de la ecuacion
{
 double f;
 f=2*p1*p1/(x*x*x)+p2*exp(-x)/(x*x)+p2*exp(-x)/x;
 return f;
}

double root (double p1,double p2) //Calcula la raíz de g(x)
{
 double aux,r;
 int n;

 n=0;
 r=p1+0.1;
 do
 {
  aux=r;
  r=r-gx(r,p1,p2)/dgx(r,p1,p2);
  n++;
 } while (fabs(aux-r)>0.00001 and n<1000);
 return r;
}

double integral (double xo, double p1, double p2) //Método de simpson para integrar
{
 double aux,delta,xn,f;
 int n;
 n=0;
 delta=0.00001;
 f=0;
 xn=xo+0.05*delta;
 do {
  aux=(delta/3)*(fx(xn,p1,p2)+4*fx(xn+delta,p1,p2)+fx(xn+2*delta,p1,p2)); //El fx es el integrando
  f=f+aux;
  aux=aux/f;
  n++;
  xn=xn+2*delta;
 } while (n<100000);
 return f;
}

double theta (double xm, double p1, double p2) //Con esto calculo el ángulo theta
{
 double f;

 f= 2*p1*(integral(p1,p1,0)-integral(xm,p1,p2)); //Es la resta de integrales
 return f;
}

void plotconf (FILE *gp) //Envía comandos al gnuplot y va a mostrar los datos como animación. 
{
 double a,b;
 a=-100;
 b=100;
 fprintf(gp,"set key off\n");
 fprintf(gp,"set xlabel \"x\"\n");
 fprintf(gp,"set ylabel \"y\"\n");
 fprintf(gp,"set xrange [%g:%g]\n",a,b);
 fprintf(gp,"set yrange [%g:%g]\n",a,b);
 fprintf(gp,"set size square\n");
 fprintf(gp,"set grid\n");
 fprintf(gp,"set parametric\n");
}

void distribution (istream& filein, ostream& fileout) { //Cuenta el # particulas por angulo solido. Toma los resultados de la simulación. Para cada theta hay ciertas particulas dispersadas y con eso se cuenta por unidad de angulo solido (min 29)
 double c[100],t,x,y;

 for ( int i = 0; i < 100; i++ )
  {
   c[i]=0;
  }
 do
 {
  filein>>t>>x>>y;
  for ( int i = 0; i < 100; i++ )
   {
    if (0.01*i<abs(t) && t<=0.01*(i+1)) {
     c[i]=c[i]+1;
    }
   }
 } while(!filein.eof());

 for ( int i =0 ; i < 100; i++ )
  {
   t=0.01*(i+1);
   fileout<<t<<" "<<c[i]/sin(t)<<endl;
  }
}

int main (int argc, char *argv[]) //Los argumentos hace poner la energía en la linea de comandos
{
 double ale,a,b,phi,r,I,t,to,ke;
 char ch;
 int N,count;
 FILE *plotg = NULL;

 srand(time(NULL));

 N=100000; //Nosotros con 10e5 :c
 std::string ch1 = argv[1];
 ke=1/(std::stod(&ch1[0],0));
 ofstream file ("dispersion_"+ch1+".dat");
 ofstream temp ("temp.dat");

 if(plotg == NULL){ //Aqui comentar para que no se haga la animacion, o sino se demora mucho
   plotg = popen("gnuplot -persist", "w");
   assert(plotg != NULL);
 }

 plotconf(plotg);
 fprintf(plotg, "plot 100*sin(t),100*cos(t), 90*sin(t),90*cos(t),80*sin(t),80*cos(t), 70*sin(t),70*cos(t),60*sin(t),60*cos(t),50*sin(t),50*cos(t),40*sin(t),40*cos(t),30*sin(t),30*cos(t),20*sin(t),20*cos(t),10*sin(t),10*cos(t)\n");
 fflush(plotg);
 cout<<"Continuar?"<<endl;
 cin>>ch;
 
 for (int i=0; i<N;i++) {
  ale=rand(); //Da un numero aleatorio
  b=100.0*ale/RAND_MAX; //Deffine un numero aleatorio de 0 a 100
  ale=rand();
  phi=3.14*(2.0*ale/RAND_MAX-1); //Define el angulo phi. Tiene distribucion uniforme porque tiene simetría al rededor del eje del centro dispersor. Es un numero aleatorio entre 0y 2pi
  r=root(b,ke);
  t=theta(r,b,ke);
  a=tan(t);
  x= (a+b)*sin(phi);
  y= (a+b)*cos(phi);
  file<<t<<" "<<x<<" "<<y<<" "<<endl;  
 
  if (i%1 == 0 && t<1) //Aquí anima cada 10 pasos para no saturar el gráfico c:
  {
   temp<<x<<" "<<y<<" "<<endl;
   fprintf(plotg, "plot 100*sin(t),100*cos(t),90*sin(t),90*cos(t),80*sin(t),80*cos(t),70*sin(t),70*cos(t),60*sin(t),60*cos(t),50*sin(t),50*cos(t),40*sin(t),40*cos(t),30*sin(t),30*cos(t),20*sin(t),20*cos(t),10*sin(t),10*cos(t),'temp.dat' pt 3 lc rgb 'blue' \n");
   fflush(plotg);
  }
 }
 pclose(plotg); //Cierro conexión con el plot
 file.close();
 temp.close();
 remove("temp.dat");
 
 ifstream infile ("dispersion_"+ch1+".dat");
 ofstream outfile ("distang_"+ch1+".dat");

 distribution(infile,outfile); 
 infile.close();
 outfile.close();

 return 0;
}
