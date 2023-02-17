set xlabel "t[T]"
set ylabel "X"

set multiplot layout 3,1 title "Analisis espectral" font ",24"
set autoscale
set xrange[0.85:1]
set grid
set arrow from 1, graph 0 to 1, graph 1 nohead
set arrow from 0.96, graph 0 to 0.96, graph 1 nohead
plot "pen_q_0_A_15_N_100_n_100w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=1000" pt 7 ps 0.5
plot "pen_q_0_A_10_N_100_n_100w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=100" pt 7 ps 0.5
plot "pen_q_0_A_5_N_100_n_100w.dat" u 1:($2*$2+$3*$3) title "100 periodos, n=100" pt 7 ps 0.5
set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.12;
pause -1
