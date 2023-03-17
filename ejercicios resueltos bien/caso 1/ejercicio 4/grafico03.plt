#set term pngcairo size 500,500
#set output "figura.png"
#set term postscript color
#set output "figura.eps"

f(x,y)=x/exp(5*log(x**2+y**2)/2)+(x-1)/exp(5*log((x-1)**2+y**2)/2)+(x-0.5)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2)
g(x,y)=y/exp(5*log(x**2+y**2)/2)+y/exp(5*log((x-1)**2+y**2)/2)+(y-0.866)/exp(5*log((x-0.5)**2+(y-0.866)**2)/2)
set key off
set isosamples 100,100
set contour base
set cntrparam level incremental 0, 1, 0
set xlabel "x" font "Arial, 26"
set ylabel "y" font "Arial, 26"
set xrange [0:1]
set yrange [0:1]
set xtics 0,0.1,1
set ytics 0,0.1,1
set grid
unset surface
splot f(x,y), g(x,y)
pause -1
