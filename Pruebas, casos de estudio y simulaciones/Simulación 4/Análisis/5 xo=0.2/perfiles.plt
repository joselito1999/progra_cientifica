#gnuplot -c animacion_real.plt 0.1
set terminal pngcairo size 700,550
set output 'perf_tiempo.png'

name=ARG1

stats 'cuerda'.name.'.dat' nooutput

set grid

set xrange [0:1]
set yrange [-10:15]

set key font "Arial,15"

set tics font "Arial,20"

set xtics 0,0.1,1
set ytics -20,5,20

set xlabel "x[m]" font "Arial,20" offset 0,-1
set ylabel "y(x,t)[mm]" font "Arial,20" offset -2

set lmargin 10
set bmargin 4.6

plot 'cuerda'.name.'.dat' index 0 u 1:($2*1000) w l title "t=0 [s]", 'cuerda'.name.'.dat' index 20 u 1:($2*1000) w l title "t=0.1 [s]", 'cuerda'.name.'.dat' index 40 u 1:($2*1000) w l title "t=0.2 [s]", 'cuerda'.name.'.dat' index 60 u 1:($2*1000) w l title "t=0.3 [s]", 'cuerda'.name.'.dat' index 80 u 1:($2*1000) w l title "t=0.4 [s]", 'cuerda'.name.'.dat' index 100 u 1:($2*1000) w l title "t=0.5 [s]"
