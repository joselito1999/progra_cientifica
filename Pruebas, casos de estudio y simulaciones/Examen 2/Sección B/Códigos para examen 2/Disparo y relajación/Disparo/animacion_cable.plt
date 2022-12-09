stats "cabled.dat" nooutput


set grid

set xlabel "x" font "Arial, 26"
set ylabel "u" font "Arial, 26"
#set xrange [0:1]
#set yrange [-0.2:0.8]
set xtics 0,0.1,1 font "Arial,16"
#set ytics -0.6,0.2,0.6 font "Arial,16"


r=1

#plot for [i=1:int(STATS_blocks)] "cabled.dat" index (i-1) w l lc i title "Iteración ".i
 
plot "cabled.dat" index (int(STATS_blocks)-1) w l lc rgb "blue"

pause -1
