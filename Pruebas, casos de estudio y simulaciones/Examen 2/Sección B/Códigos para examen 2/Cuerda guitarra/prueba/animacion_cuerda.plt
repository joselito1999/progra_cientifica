name=ARG1

stats name.'.dat' nooutput

set grid

set xrange [0:1]
set yrange [-10:15]

set key off

set tics font "Arial,20"

set xtics 0,0.1,1
set ytics -20,5,20

set xlabel "x[m]" font "Arial,20" offset 0,-1
set ylabel "u[mm]" font "Arial,20" offset -2

set lmargin 10
set bmargin 4.6



#ANIMACION:

plot name.'.dat' index 0 u 1:($2*1000) w l lc rgb "blue" #Grafica el bloque inicial del #archivo 
pause -1
do for [i=1:int(STATS_blocks)] {
  plot name.'.dat' index (i-1) u 1:($2*1000) w l lc rgb "blue" 
  pause 0.01
}
pause -1
