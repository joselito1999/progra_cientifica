set terminal pngcairo size 700,550
set output 'nx_vs_xo.png'

set key off

set xlabel "x_o[m]" font "Arial, 18"
set ylabel "n_x" font "Arial, 18"

set tics font "Arial, 18"

set yrange [0:101]
set xrange [0:0.21]

plot "puntos.dat" pt 7 ps 1.2 lc rgb "blue"
