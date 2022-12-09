file=ARG1

set term pngcairo
set output 'potencia'.file.'.png'

set key off

plot 'pendulo_'.file.'w.dat' u 1:($2**2+$3**2) w l lc rgb "red", 'pendulo_'.file.'w.dat' u 1:($2**2+$3**2) pt 7 ps 0.7 lc rgb "blue"
