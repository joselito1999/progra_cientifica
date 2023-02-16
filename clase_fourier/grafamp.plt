set xlabel "t[T]"
set ylabel "X"
#set xrange [0:30]

plot 'oscilador.dat' title "Euler-Cromer" w l , "osciladort.dat" u 1:2, 0 w l
pause -1


set multiplot layout 1,2 title "transformada de fourier" font ",24"
set xlabel "w [rad/s]" font "Arial, 24"
set ylabel "x_1" font "Arial, 26"
set xrange [0:5]
set yrange [-1:1.2]
plot "osciladorw.dat" u 1:2 w l, "osciladorw.dat" u 1:3 w l

set ylabel "x_2" font "Arial, 24"
set xrange [95:100]
plot "osciladorw.dat" u 1:2 w l, "osciladorw.dat" u 1:3 w l

pause -1
unset multiplot

set xrange [0:5]
plot "osciladorw.dat" u 1:($2*$2+$3*$3),0

pause -1
