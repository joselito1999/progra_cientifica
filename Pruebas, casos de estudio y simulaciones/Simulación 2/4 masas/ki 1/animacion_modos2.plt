stats 'modos.dat' nooutput

#N es el número de osciladores

N=4

#m es el modo que queremos ver excitado

m=2

a=2*m-1
b=2*m

unset border
unset xtics
unset ytics
set grid
set key off
set xrange [0:3*N+2]
set yrange [-0.5:0.5]

set arrow 1 from 0,-0.05 to 0,0.05 lw 6 lc "black" nohead
set arrow 2 from (3*N+1),-0.05 to (3*N+1),0.05 lw 6 lc "black" nohead
set arrow 3 from 0,0 to (3*N+1),0 lw 2 lc "red" nohead

do for[i=1:N]{
set arrow i+3 from (3*i-1),-0.02 to (3*i-1),0.02 lw 2 lc "blue" nohead
}

plot 'modos.dat' index 0 u a:b with points pt 7 ps 5 lc rgb "blue"
pause -1
do for [i=1:int(STATS_blocks)] {
  plot 'modos.dat' index (i-1) u a:b with points pt 7 ps 5 lc rgb "blue" 
  pause 0.1 
}
pause -1
