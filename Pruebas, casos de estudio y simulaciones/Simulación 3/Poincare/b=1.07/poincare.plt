set terminal pngcairo size 4000,4000
set output 'poincare_1.07.png'

set key off

set mxtics 5

set grid xtics ytics mxtics mytics lw 3, lw 3

set mxtics 2
set ytics 0.5
set mytics 1

set tics font "times,130"

set xtics offset 0,-6

set xrange [-3.15:3.15]

set yrange [0:2.5]

set ylabel "~{/Symbol q}{1.2.}" font "Times,130" offset -20
set xlabel "{/Symbol q}" font "Times,130" offset 0,-13

set lmargin at screen 0.09;
set rmargin at screen 0.95;
set bmargin at screen 0.09;
set tmargin at screen 0.95;

plot 'poincare_1.07.dat' pt 7 ps 5 lc rgb "blue"
