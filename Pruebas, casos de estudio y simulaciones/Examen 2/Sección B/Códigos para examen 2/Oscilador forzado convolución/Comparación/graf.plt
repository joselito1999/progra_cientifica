set xrange [0:100]

set xtics font "Arial,18"
set ytics font "Arial,18"


set ylabel 'x' font "Arial,20"
set xlabel 't[s]' font "Arial,20

plot "pendulo_2.dat" w l lc rgb "red" t "resolución numérica", "funcionwt.dat" w l lc rgb "blue" t "Con convolución"

pause -1
