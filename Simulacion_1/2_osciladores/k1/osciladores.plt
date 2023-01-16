#set term postscript color
#set output "osciladores.eps"

set multiplot layout 6,1 
set key off
set xlabel "t" font "Arial, 24"
set ylabel "x_1" font "Arial, 26"
set xrange [0:200]
set yrange [-2:2]
set xtics 0,50,200 font "Arial,16"
set ytics -2,1,2 font "Arial,16"
set grid

set origin 0,1.25
set size 0.8,0.25
plot 0 lc rgb "black", "osciladores.dat" u 1:2 with lines lc rgb "red"

set origin 0,1
set size 0.8,0.25
set ylabel "x_2" font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:3 with lines lc rgb "blue"

set origin 0,0.75
set size 0.8,0.25
set ylabel "x_3" font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:4 with lines lc rgb "green"

set origin 0,0.5
set size 0.8,0.25
set ylabel "x_4" font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:5 with lines lc rgb "orange"

set origin 0,0.25
set size 0.8,0.25
set ylabel "x_5" font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:6 with lines lc rgb "red"

set origin 0,0
set size 0.8,0.25
set ylabel "x_6" font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:7 with lines lc rgb "red"
pause -1
