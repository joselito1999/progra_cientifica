f(x)=-0.041/x+exp(-x)

set key off
set xrange [2:10]
set yrange [-.006:0.006]
set grid

set xlabel "x" font "times,18"
set ylabel "f(x)" font "times,18"
p f(x)
pause -1
