unset border
unset xtics
unset ytics
set xrange [0:8]
set yrange [0:2]
set key off
set label "Modo 1" at 0,0.52 font "Times, 24"
set label "Modo 2" at 0,1.02 font "Times, 24"
set label "Modo 3" at 0,1.52 font "Times, 24"
plot 0.5 lc rgb "black" lw 0.1, 1.0 lc rgb "black" lw 0.1, 1.5 lc rgb "black" lw 0.1, "modos.dat" u 1:2:3:(0) with vectors lc rgb "blue" lw 4, "modos.dat" u 1:2 pt 4 ps 1 lc rgb "blue" 

pause -1
