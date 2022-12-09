name=ARG1

set key off

set xtics font "Arial,18"
set ytics font "Arial,18" 

set xrange [0:20]

set ylabel 'x_3[A]' font "Arial,20"
set xlabel 't[T]' font "Arial,20
plot name.'.dat' with lines lc rgb "blue"

pause -1
