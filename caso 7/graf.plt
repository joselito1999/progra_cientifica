set xlabel "t[T]"
set ylabel "X"
#set multiplot layout 2,1 title "Transformada de fourier" font ",24"
set autoscale
set xrange[0:10]
set grid
set arrow from 1, graph 0 to 1, graph 1 nohead
#plot "pen_q_5_A_20_N_10_n_100w.dat" u 1:2 title "10 periodos, n=1000" pt 7 ps 0.5
plot "pen_q_5_A_10_N_10_n_100w.dat" u 1:2 title "10 periodos, n=100" pt 7 ps 0.5
#plot "pen_q_5_A_1_N_100w.dat" u 1:2 title "100 periodos, n=100" pt 7 ps 0.5
set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.12;
pause -1

#unset multiplot
#set multiplot layout 2,1 title "Analisis espectral" font ",24"
set autoscale
#set xrange[0.8:1.2]
set grid
set arrow from 1, graph 0 to 1, graph 1 nohead
set arrow from 0.96, graph 0 to 0.96, graph 1 nohead
#plot "pen_q_5_A_20_N_10_n_100w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=1000" pt 7 ps 0.5
plot "pen_q_5_A_10_N_10_n_100w.dat" u 1:($2*$2+$3*$3) title "10 periodos, n=100" pt 7 ps 0.5
#plot "pen_q_5_A_1_N_100w.dat" u 1:($2*$2+$3*$3) title "100 periodos, n=100" pt 7 ps 0.5
set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.12;
pause -1
