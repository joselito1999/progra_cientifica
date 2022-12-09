#set term postscript color
#set output "osciladores.eps"

set term pngcairo size 700,800
set output "4_masas_ki_5.png"

#N es el número de osciladores
N=4

set multiplot layout 4, 1 title "Osciladores acoplados" font ",24"
set key off
set xlabel "t[1/{/Symbol w}_0]" font "Arial, 24"
set xrange [0:100]
set yrange [-2:2]
set xtics 0,10,100 font "Arial,16"
set ytics -2,1,2 font "Arial,16"
set grid

do for[i=1:N]{
set ylabel "x_".i font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:i+1 with lines lc i
}

#set ylabel "x_1" font "Arial, 26"
#plot 0 lc rgb "black", "osciladores.dat" u 1:2 with lines lc rgb "red"

#set ylabel "x_2" font "Arial, 24"
#plot 0 lc rgb "black", "osciladores.dat" u 1:3 with lines lc rgb "blue"

#set ylabel "x_3" font "Arial, 24"
#plot 0 lc rgb "black", "osciladores.dat" u 1:4 with lines lc rgb "green"

#set ylabel "x_4" font "Arial, 24"
#plot 0 lc rgb "black", "osciladores.dat" u 1:5 with lines lc rgb "orange"

#set ylabel "x_5" font "Arial, 24"
#plot 0 lc rgb "black", "osciladores.dat" u 1:6 with lines lc rgb "red"

#set ylabel "x_6" font "Arial, 24"
#plot 0 lc rgb "black", "osciladores.dat" u 1:7 with lines lc rgb "red"
