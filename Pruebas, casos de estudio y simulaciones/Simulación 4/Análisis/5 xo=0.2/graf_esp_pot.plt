name=ARG1

set terminal pngcairo size 700,550
set output 'potencias_'.name.'.png'

set xtics font "Arial,18"
set ytics font "Arial,18"

set xrange [0:10]

set xtics 0,1,10

set key off

set ylabel '|g_w|^2' font "Arial,20"  offset -1
set xlabel '{/Symbol w}[{/Symbol p} rad/s]' font "Arial,20

set lmargin 10.5

plot name.'w.dat' u ($1/pi):($2**2+$3**2) with lines lc rgb "red", name.'w.dat' u ($1/pi):($2**2+$3**2) pt 7 ps 0.5 lc rgb "blue"
