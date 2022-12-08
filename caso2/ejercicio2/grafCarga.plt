#set term pngcairo size 500,500
#set output "figura.png"
#set term postscript color
#set output "figura.eps"

f(x,y)=x/exp(5*log(x**2+y**2)/2)+(x-1)/exp(5*log((x-1)**2+y**2)/2)+(x-0.5)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2)
g(x,y)=y/exp(5*log(x**2+y**2)/2)+y/exp(5*log((x-1)**2+y**2)/2)+(y-0.866)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2)
u(x,y)=1/sqrt(x*x+y*y)+0.9/sqrt((0.5-x)*(0.5-x)+(0.866-y)*(0.866-y))+1/sqrt((1-x)*(1-x)+y*y);
set key off
set isosamples 100,100
#set contour base
set pm3d at b
set contour
set cntrparam level 50 #valor inicial primera curva, separacion entre las curvas de nivel, valor final
set xlabel "x" font "Arial, 16"
set ylabel "y" font "Arial, 16"
set xrange [0.1:0.9]
set yrange [0.1:0.9]
set zrange [2:14]
set xtics 0,0.05,1
set ytics 0,0.05,1
set grid
set view map
unset surface
splot u(x,y)
#splot g(x,y)
pause -1
