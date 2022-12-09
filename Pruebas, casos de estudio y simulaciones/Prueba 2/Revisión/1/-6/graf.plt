set title "dt=10^{-6}*2{/Symbol p}"

set xlabel "t[s]"
set ylabel "x"

set xrange [1.3:1.8]
set yrange [0.96:1.01]

set samples 200

plot 'oscilador.dat' u 1:3 lc rgb "red" title "Solución numérica", sin(x) lc rgb "blue" title "Solución teórica"

pause -1
