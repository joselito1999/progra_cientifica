name="serie"

set key off


set xtics font "Arial,16"
set ytics font "Arial,16"

set grid


set title "Autocorrelación" font "Arial,18"

set ylabel 'K(t)' font "Arial,16"
set xlabel 't[s]' font "Arial,16"

plot name.'wt.dat' w l lc rgb "blue" 

pause -1
