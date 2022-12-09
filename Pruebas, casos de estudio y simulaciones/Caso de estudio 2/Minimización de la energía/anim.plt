stats 'extremos.dat' nooutput

f(x,y) = 1/(x**2+y**2)**0.5+1/((x-1)**2+y**2)**0.5+1/((x-0.5)**2+(y-(3**0.5)/2)**2)**0.5

set surface
set pm3d explicit
set view map
set dgrid3d
set key off
set contour
set cntrparam levels 30
set xrange [0.4:.6]
set yrange [0.1:0.4]
set zrange [0:20]
set xlabel "x" font "times, 24"
set ylabel "y" font "times, 24"
set xtics 0.4,0.05,0.6 font "times, 20"
set ytics 0.1,0.1,0.4 font "times, 20"


do for [i=1:int(STATS_blocks)] {
  set label 1 sprintf("%3.5g",i-1) at 0.42,0.35 font "times, 24"
  splot 'extremos.dat' index (i-1) u 1:2:(0) with points pt 13 ps 4, f(x,y) lc rgb "#808080"
  
  pause 0.1
}
