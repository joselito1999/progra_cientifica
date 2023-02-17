set xlabel "t[T]"
set ylabel "X"
#set xrange [0:30]

set multiplot layout 2,1 title "espectro de potencias" font ",24"
set ylabel '|g_w|^2' font "Arial,20"  offset -1.6
set xlabel '{/Symbol w}[{/Symbol w_0}]' font "Arial,20
set autoscale
set xrange[0:2]
plot "pen_q_0_A_5_N_10_n_100w.dat" u 1:($2**2+$3**2) pt 7 ps 0.5 title "10T"

set ylabel '|g_w|^2' font "Arial,20"  offset -1.6
set xlabel '{/Symbol w}[{/Symbol w_0}]' font "Arial,20
set autoscale
set xrange[0:2]
plot "pen_q_0_A_5_N_100_n_100w.dat" u 1:($2**2+$3**2) pt 7 ps 0.5 title "100T"

set lmargin at screen 0.31;
set rmargin at screen 0.95;
set bmargin at screen 0.12;
pause -1
