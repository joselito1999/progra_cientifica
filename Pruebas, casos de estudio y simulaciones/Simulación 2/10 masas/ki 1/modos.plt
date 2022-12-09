N=10

xmax=2*N
ymax=2*N+2

unset border
unset xtics
unset ytics
set xrange [-1:xmax]
set yrange [0:ymax]
set key off

do for[i=1:N]{
set label "Modo ".i at (N-3),2*i+1 font "Times, 24"
}

f(x,i)= (x>0 && x<2*(N-1)) ? 2*i : 1/0

plot for[i=1:N] f(x,i) lc rgb "black" lw 0.1

set style arrow 3 lc rgb "blue" lw 3

replot "vecprop.dat" with vectors head size 0.2,40 lc rgb "blue", "vecprop.dat" u 1:2 pt 4 ps 1 lc rgb "blue" 

pause -1
