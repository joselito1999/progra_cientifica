stats "cabled.dat" nooutput

set grid

set xlabel "x" font "Arial, 26"
set ylabel "u" font "Arial, 26"
set xrange [0:1]
set yrange [-1:0.4]
set xtics 0,0.1,1 font "Arial,16"
set ytics -1,0.2,0.4 font "Arial,16"

f(x) = -1.13064 + 1.13064*cosh(5*x) - 1.11281*sinh(5*x)

r=1

plot "cabled.dat" index (int(STATS_blocks)-1) lc rgb "blue" title "Curva encontrada", f(x) lc rgb "red" title "Curva teórica"

pause -1
