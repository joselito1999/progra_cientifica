stats "cabled.dat" nooutput


set grid

set xlabel "x" font "Arial, 26"
set ylabel "u" font "Arial, 26"
set xrange [0:1]
set yrange [-0.4:2]
set xtics 0,0.1,1 font "Arial,16"
set ytics -0.6,0.2,2 font "Arial,16"


r=1

 plot for [i=1:int(STATS_blocks)] "cabled.dat" index (i-1) w l lc i title "Iteración ".i
 
pause -1
