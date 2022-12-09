name=ARG1

set multiplot layout 2, 1
set key off


set xtics font "Arial,16"
set ytics font "Arial,16"

set grid

set title "Serie temporal" font "Arial,18"

set xrange [0:314.128]

set ylabel 'x(t)' font "Arial,16"
set xlabel 't[s]' font "Arial,16"
plot name.'.dat' with lines lc rgb "blue"

set title "Espectro de potencias" font "Arial,18"

set xrange [0:10]

set ylabel 'S' font "Arial,16"
set xlabel '{/Symbol w}[rad/s]' font "Arial,16"

plot name.'w.dat' u 1:($2**2+$3**2) with lines lc rgb "red", name.'w.dat' u 1:($2**2+$3**2) pt 7 ps 0.5 lc rgb "blue" 

pause -1
