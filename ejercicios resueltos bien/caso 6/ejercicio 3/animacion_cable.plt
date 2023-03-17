stats "cabler.dat" nooutput

set multiplot

set grid

set xlabel "x" font "Arial, 26"
set ylabel "u" font "Arial, 26"
set xrange [0:1]
set yrange [-.3:0]
set xtics 0,0.1,1 font "Arial,16"
set ytics -0.6,0.2,0.6 font "Arial,16"


r=1

plot "cabler.dat" index (0) w l lc rgb "red" title "Propuesta inicial"

plot for [i=2:int(STATS_blocks):10] "cabler.dat" index (i-1) w l lc rgb "blue" notitle
 
pause -1
