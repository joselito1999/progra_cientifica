set xtics font "Arial,18"
set ytics font "Arial,18" 


set ylabel 'f(t)' font "Arial,20"
set xlabel 't[s]' font "Arial,20
plot 'pendulo_0.2.dat' with lines lc rgb "red" t 'Función de entrada'

pause -1


set ylabel 'g_w' font "Arial,20"
set xlabel '{/Symbol w}[rad/s]' font "Arial,20"
plot 'pendulo_0.2w.dat' u 1:2 with lines lc rgb "orange" t 'Transformada Directa, parte real', 'pendulo_0.2w.dat' pt 1 ps 0.4lc rgb "red"

pause -1

set ylabel 'g_w' font "Arial,20"
set xlabel '{/Symbol w}[rad/s]' font "Arial,20"
plot 'pendulo_0.2w.dat' u 1:3 with lines lc rgb "purple" t 'Transformada Directa, parte imaginaria', 'pendulo_0.2w.dat' u 1:3 pt 1 ps 0.4lc rgb "blue"

pause -1
