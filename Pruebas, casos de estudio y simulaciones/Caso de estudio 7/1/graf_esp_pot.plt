set xtics font "Arial,18"
set ytics font "Arial,18"

set title "Espectro de potencias"
set title font "Arial,20"
set key off

set xrange [0:10]

set ylabel '|g_w|^2' font "Arial,20"  offset -1.6
set xlabel '{/Symbol w}[rad/s]' font "Arial,20

plot 'pendulo_0.5w.dat' u 1:($2**2+$3**2) with lines lc rgb "red", 'pendulo_0.5w.dat' u 1:($2**2+$3**2) pt 7 lc rgb "blue" 

set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.12;

pause -1
