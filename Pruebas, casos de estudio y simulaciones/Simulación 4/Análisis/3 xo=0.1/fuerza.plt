file=ARG1

set terminal pngcairo size 700,550
set output file.'_tiempo.png'

set grid

set key off

set tics font "Arial,20"

set xlabel "t[s]" font "Arial,20" offset 0,-0.4
set ylabel "Fuerza" font "Arial,20" offset -1.8

set lmargin 12
set bmargin 4


plot file.'.dat' w l lc rgb "blue"
