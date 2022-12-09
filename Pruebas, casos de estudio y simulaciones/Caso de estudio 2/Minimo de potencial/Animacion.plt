stats 'extremos.dat' nooutput

f(x)=4*((1/x)**12-(1/x)**6)

set grid
set key off
set xrange [0.5:3]
set yrange [-2:2]
set xlabel "x" font "times, 24"
set ylabel "f(x)" font "times, 24"
set xtics font "times, 20"
set ytics font "times, 20"

do for [i=1:int(STATS_blocks)] {
  set label 1 sprintf("%3.5g",i-1) at 1,-1 font "times, 24" 
  plot 'extremos.dat' index (i-1) with points pt 13 ps 4, f(x) lw 2 lc rgb "red"
  pause 0.5  
}
