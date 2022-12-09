set terminal pngcairo size 4000,4000
set output 'bifurcacion.png'

set key off

set mxtics 5

set grid xtics ytics mxtics mytics lw 3, lw 3

set xrange [1.04:1.09]
set yrange [-2.8:-1.7]

set mxtics 1
set mytics 1

set tics font "times,130"

set xtics offset 0,-6

set ylabel "{/Symbol q}" font "Times,130" offset -30
set xlabel "b" font "Times,130" offset 0,-13

set lmargin at screen 0.11;
set rmargin at screen 0.95;
set bmargin at screen 0.09;
set tmargin at screen 0.95;

plot 'bifurcacion.dat' pt 7 ps 3 lc rgb "blue"
