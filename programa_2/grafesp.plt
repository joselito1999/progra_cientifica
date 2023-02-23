#set xlabel "t[T]"
#set ylabel "X"
#set multiplot layout 3,1 title "Transformada de fourier" font ",24"
#set autoscale
#set xrange[0:2]
#set grid
#set arrow from 1, graph 0 to 1, graph 1 nohead
#plot "pos1w.dat" u 1:2 title "x1" pt 7 ps 0.5
#plot "pos2w.dat" u 1:2 title "x2" pt 7 ps 0.5
#plot "pos3w.dat" u 1:2 title "x3" pt 7 ps 0.5
#set lmargin at screen 0.11;
#set rmargin at screen 0.95;
#set bmargin at screen 0.12;
#pause -1
#__________________________________________________________________________________________________________
set xrange[0:4]
set grid
plot "pos1w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=1000" w l, "pos1w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=1000" pt 7 ps 0.5
set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.12;
pause -1
