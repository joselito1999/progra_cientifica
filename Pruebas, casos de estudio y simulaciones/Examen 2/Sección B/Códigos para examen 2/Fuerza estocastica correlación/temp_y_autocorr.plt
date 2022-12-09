name=ARG1

set multiplot layout 2, 1
set key off


set xtics font "Arial,16"
set ytics font "Arial,16"

set grid

set title "Serie temporal" font "Arial,18"

set xrange [0:100]

set ylabel 'x(t)' font "Arial,16"
set xlabel 't[s]' font "Arial,16"
plot name.'.dat' with lines lc rgb "blue"

set title "Autocorrelación" font "Arial,18"

unset xrange

set ylabel 'K(t)' font "Arial,16"
set xlabel 't[s]' font "Arial,16"

plot name.'wt.dat' w l lc rgb "blue" 

pause -1
