set terminal pngcairo size 700,550
set output "multiplot.png"

set xzeroaxis

set key off

set lmargin 10.5

set multiplot

set ylabel '|g_w|^2' font "Arial,20"  offset -1
set xlabel '{/Symbol w}[{/Symbol p} rad/s]' font "Arial,20
set origin 0,0
set size 1,1
set xtics font "Arial,18"
set ytics font "Arial,18"

set xrange [0:150]
set yrange [0: 0.21]

plot 'fuerza0.01w.dat' u ($1/pi):($2**2+$3**2) with lines lc rgb "red", 'fuerza0.01w.dat' u ($1/pi):($2**2+$3**2) pt 7 ps 0.5 lc rgb "blue"

set nokey

unset xlabel
unset ylabel

set xtics font "Arial,15"
set ytics font "Arial,15"

set origin 0.5, 0.5
set size 0.45, 0.3
set xrange [98:102]
set yrange [0:0.00005]
set xtics 1
set ytics 0,0.00005
replot
