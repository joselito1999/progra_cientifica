stats 'modos.dat' nooutput

unset border
unset xtics
unset ytics
set grid
set key off
set xrange [0:7]
set yrange [-0.5:0.5]
set arrow 1 from 0,-0.05 to 0,0.05 lw 6 lc "black" nohead
set arrow 2 from 7,-0.05 to 7,0.05 lw 6 lc "black" nohead
set arrow 3 from 2,-0.02 to 2,0.02 lw 2 lc "blue" nohead
set arrow 4 from 5,-0.02 to 5,0.02 lw 2 lc "blue" nohead
set arrow 5 from 0,0 to 7,0 lw 2 lc "red" nohead

plot 'modos.dat' index 0 u 1:2 with points pt 7 ps 5 lc rgb "blue"
pause -1
do for [i=1:int(STATS_blocks)] {
  plot 'modos.dat' index (i-1) u 1:2 with points pt 7 ps 5 lc rgb "blue" 
  pause 0.1 
}
pause -1
