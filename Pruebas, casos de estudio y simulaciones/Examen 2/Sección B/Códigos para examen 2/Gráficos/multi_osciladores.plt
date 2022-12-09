set multiplot layout 3, 1 title "Osciladores acoplados" font ",24"
set key off
set xlabel "t" font "Arial, 24"
set xrange [0:200]
set yrange [-2:2]
set xtics 0,50,200 font "Arial,16"
set ytics -2,1,2 font "Arial,16"
set grid

do for[i=1:N]{
set ylabel "x_".i font "Arial, 24"
plot 0 lc rgb "black", "osciladores.dat" u 1:i+1 with lines lc i
}
