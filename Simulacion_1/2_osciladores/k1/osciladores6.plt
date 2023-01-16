#set term postscript color
#set output "osciladores.eps"
set size 1,4
set origin 0,0
set multiplot layout 6,1 columnsfirst scale 0.8,1.2
set key off
set ylabel "x_1" font "Arial, 16"
set xrange [0:1500]
set yrange [-2:2]
set xtics 0,250,1500 font "Arial,8"
set ytics -2,1,2 font "Arial,8"
set grid

plot 0 lc rgb "black", "osciladores.dat" u 1:2 with lines lc rgb "red"

set ylabel "x_2" font "Arial, 16"
plot 0 lc rgb "black", "osciladores.dat" u 1:3 with lines lc rgb "blue"

set ylabel "x_3" font "Arial, 16"
plot 0 lc rgb "black", "osciladores.dat" u 1:4 with lines lc rgb "green"

set ylabel "x_4" font "Arial, 16"
plot 0 lc rgb "black", "osciladores.dat" u 1:5 with lines lc rgb "orange"

set ylabel "x_5" font "Arial, 16"
plot 0 lc rgb "black", "osciladores.dat" u 1:6 with lines lc rgb "red"
set xlabel "t" font "Arial, 16"
set ylabel "x_6" font "Arial, 16"
plot 0 lc rgb "black", "osciladores.dat" u 1:7 with lines lc rgb "blue"
pause -1
