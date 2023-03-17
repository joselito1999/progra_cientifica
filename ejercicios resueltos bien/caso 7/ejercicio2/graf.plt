name="pendulo"
set multiplot layout 2, 1
set key off


set xtics font "Arial,16"
set ytics font "Arial,16"

set grid

set title "Espectro de potencias" font "Arial,18"

set xrange [0:10]

set ylabel 'S' font "Arial,12"
set xlabel '{/Symbol w}[rad/s]' font "Arial,12"

plot name.'w.dat' u 1:($2**2+$3**2) with lines lc rgb "red", name.'w.dat' u 1:($2**2+$3**2) pt 7 ps 0.5 lc rgb "blue"

pause -1
set title "autocorrelacion" font "Arial,18"

set xrange [0:31.4]

set ylabel 'K(t)' font "Arial,12"
set xlabel 't[s]' font "Arial,12"

plot name.'wt.dat' u 1:2

pause -1
