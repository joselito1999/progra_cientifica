f(x,y)=(x-1)*(x-1)*exp(-y*y)+y*(y+2)*exp(-2*x*x)
set key off
set grid
set sample 200
set isosample 60 
set hidden3d

set xlabel "x" font "Arial, 26"
set ylabel "y" offset -2,0 font "Arial, 26"
set zlabel "f(x,y)" offset -2,6 font "Arial, 26"
set xrange [-5:5]
set yrange [-5:5]
set xtics -5,1,5 font "Arial,18"
set ytics -5,1,5 font "Arial,18"
set ztics 0,10,50 font "Arial, 18"
splot f(x,y) lc rgb "blue"
pause -1

set contour
set cntrparam levels 10
set cntrparam levels incremental -0.8,0.2
set xrange [-2:2]
set yrange [-2:2]
set xtics -2,1,2 font "Arial,18"
set ytics -2,1,2 font "Arial,18"
set ztics 0,2,10 font "Arial, 18"
splot f(x,y) lc rgb "blue"
pause -1

unset surface
set view map
set xrange [-2:2]
set yrange [-2:2]
set xtics -2,1,2 font "Arial,18"
set ytics -2,1,2 font "Arial,18"
splot f(x,y) lw 2 lc rgb "blue"
pause -1

set xrange [-1.5:1.5]
set yrange [-2.5:0.5]
set xtics -1,0.5,1 font "Arial,18"
set ytics -2,0.5,0 font "Arial,18"
splot f(x,y) lw 2 lc rgb "blue"
pause -1

