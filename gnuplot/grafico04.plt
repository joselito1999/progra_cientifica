#set term pngcairo size 500,500
#set output "figura.png"
#set term postscript color
#set output "figura.eps"

f(x,y)=exp(x)-3*y-1
g(x,y)=x*x+y*y-4
set key off
set isosamples 100,100
set contour base
set cntrparam level incremental 0, 1, 0
set xlabel "x" font "Arial, 26"
set ylabel "y" font "Arial, 26"
set xrange [-3:3]
set yrange [-3:3]
set xtics -3,0.5,3
set ytics -3,0.5,3
set grid
splot f(x,y), g(x,y)
pause -1
