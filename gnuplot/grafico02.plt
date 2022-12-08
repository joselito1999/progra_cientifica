#set term pngcairo size 500,500
#set output "figura.png"
#set term postscript color
#set output "figura.eps"

set parametric
set key off
set xlabel "x" offset 0,-1.5 font "Arial, 30"
set ylabel "y" offset -1.5,0 font "Arial, 30"
set xrange [-3:3]
set yrange [-3:3]
set xtics -3,0.5,3 font "Arial,20"
set ytics -3,0.5,3 font "Arial,20"
set grid
set label 1 "x^2+y^2-4=0" at 1.9,-1 textcolor rgb "red" font "Arial, 20"
set label 2 "e^x-3y-1=0" at 1.9,1.8 textcolor rgb "blue" font "Arial, 20"
plot 2*sin(t),2*cos(t) lw 2 lc rgb "red", t,(exp(t)-1)/3 lw 2 lc rgb "blue"
pause -1
