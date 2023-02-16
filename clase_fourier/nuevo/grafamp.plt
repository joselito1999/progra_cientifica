set xlabel "t[T]"
set ylabel "X"
#set xrange [0:30]

plot 'oscilador0_15.dat' title "Euler-Cromer" w l , "oscilador0_15t" u 1:2, 0 w l
pause -1


set multiplot layout 1,2 title "transformada de fourier" font ",24"
set xlabel "w [rad/s]" font "Arial, 24"
set ylabel "x_1" font "Arial, 26"
set autoscale
set yrange [-2:2]
plot "oscilador0_15w.dat" u 1:2 w l, "oscilador0_15w.dat" u 1:3 w l

set ylabel "x_2" font "Arial, 24"
set autoscale
set xrange [95:100]
plot "oscilador0_15w.dat" u 1:2 w l, "oscilador0_15w.dat" u 1:3 w l

pause -1
unset multiplot
set autoscale
set xrange [0:5]
plot "oscilador0_15w.dat" u 1:($2*$2+$3*$3),0

pause -1
