stats 'extremos.dat' nooutput

vxo=10
vyo=10
m=1
g=9.81
tau=10

set grid
set key off
set yrange [3:5]
set xrange [6:10]
set xlabel "x" font "times, 24"
set ylabel "f(x)" font "times, 24"
set xtics font "times, 20"
set ytics font "times, 20"
f(x)=((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau)));
do for [i=1:int(STATS_blocks)] {
  set label 1 sprintf("%3.5g",i-1) at 5,-14 font "times, 24" 
  plot 'extremos.dat' index (i-1) u 1:(-1*$2) with points pt 13 ps 4, f(x) lw 2 lc rgb "red" 
  pause -1 
}
