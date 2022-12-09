set key at 11,2

set key font "Times,24"

set xrange [0:11]
set yrange [0:4.1]

set xlabel "i" font "Times,24"
set ylabel "{/Symbol w}_i [{/Symbol w}_0]" font "Times,24"

set xtics font "Times,15"
set ytics font "Times,15"

plot 'frecuencias_4_5.txt' pt 9 ps 1.7 lc rgb "red" title "N=4", 'frecuencias_6_5.txt' pt 11 ps 1.7 lc rgb "blue" title "N=6", 'frecuencias_10_5.txt' pt 7 ps 1.7 lc rgb "green" title "N=10"

pause -1
