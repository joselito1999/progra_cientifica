name=ARG1

set xtics font "Arial,18"
set ytics font "Arial,18"

set title "Espectro de potencias"
set title font "Arial,20"
set key off

set ylabel '|g_w|^2' font "Arial,20"  offset -1.6
set xlabel '{/Symbol w}[rad/s]' font "Arial,20

#set lmargin 0.11
#set rmargin 0.95
#set bmargin 0.12

plot name.'w.dat' u 1:($2**2+$3**2) with lines lc rgb "red", name.'w.dat' u 1:($2**2+$3**2) pt 7 lc rgb "blue" 

pause -1
