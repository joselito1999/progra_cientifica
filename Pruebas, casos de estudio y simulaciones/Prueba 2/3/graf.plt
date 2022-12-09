set xlabel "t[s]"
set ylabel "{/Symbol q}"

set xrange [0:40]

plot 'oscilador.dat' u 1:2 w l lc rgb "blue" title "Solución numérica"

pause -1
