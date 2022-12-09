set xlabel "t[T_0]"
set ylabel "{/Symbol q}[rad]"

set xrange [0:4]

plot 'oscilador.dat' u 1:6 w l title "Valores simulados"
pause -1
