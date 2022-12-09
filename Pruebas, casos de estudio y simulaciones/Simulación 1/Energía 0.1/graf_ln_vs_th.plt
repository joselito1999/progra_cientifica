set xlabel "{/Symbol q}" font "times, 18" offset 0,-1
set ylabel "ln|dN/d{/Symbol W}|" font "times, 18" offset -2,0

set xtics font "times,16"
set ytics font "times,16"

set lmargin 10
set bmargin 5

set key font "times, 16"

plot "distang_0.1.dat" u 1:(log($2)) pt 9 title "E=0.1"

pause -1
