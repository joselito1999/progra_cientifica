set xlabel "sin({/Symbol q}/2)" font "times, 18" offset 0,-1
set ylabel "ln|dN/d{/Symbol W}|" font "times, 18" offset -2,0

set xtics font "times,16"
set ytics font "times,16"

set lmargin 10
set bmargin 5

set key font "times, 16"

plot "distang_10.dat" u (sin($1 /2)):(log($2)) pt 9 title "E=10"

pause -1
