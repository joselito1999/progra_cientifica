set terminal pngcairo size 4000,2000
set output 'b_1.09.png'

set key off

set mxtics 5

set grid xtics ytics mxtics mytics lw 3, lw 3

set mxtics 2

set tics font "times,130"

set xtics offset 0,-6

#set yrange [-3.5:3.5]

set xtics 50,10,100

#set ylabel "~{/Symbol q}{1.2.}" font "Times,25" offset -2
set ylabel "{/Symbol q}" font "Times,130" offset -15
set xlabel "t[T]" font "Times,130" offset 0,-10

set lmargin at screen 0.067;
set rmargin at screen 0.95;
set bmargin at screen 0.165;
set tmargin at screen 0.95;

plot 'pendulo_1.09.dat' w l lw 5 lc rgb "blue"
