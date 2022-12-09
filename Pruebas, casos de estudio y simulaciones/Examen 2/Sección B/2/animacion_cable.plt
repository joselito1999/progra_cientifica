stats "cabled.dat" nooutput


set grid

set xlabel "x[cm]" font "Arial, 26"
set ylabel "phi[V]" font "Arial, 26"
#set xrange [0:1]
#set yrange [-0.2:0.8]
#set xtics 0,0.1,1 font "Arial,16"
#set ytics -0.6,0.2,0.6 font "Arial,16"


r=1

plot "cabled.dat" index (0) w l lc rgb "red" title "Inicial", "cabled.dat" index (int(STATS_blocks)-1) w l lc rgb "blue" title "resultado final"

pause -1
