set xrange [2:51]
set yrange [1.8:2.1]

set key left
set xlabel "N" font "times,13"
set ylabel "{/Symbol w}_N /{/Symbol w}_0" font "times,13"
set key font "times, 13"

set xtics font "times,13"
set ytics font "times,13"

plot 'datos.txt' pt 9 notitle

pause -1
