#set term postscript color
#set output "fxy_min.eps"

f(x,y)=(x-1)*(x-1)*exp(-y*y)+y*(y+2)*exp(-2*x*x)
set key off
set grid
set dgrid3d
set isosamples 50,50 
#unset surface
set view map 
set contour
set cntrparam levels 20
set cntrparam levels incremental -0.8,0.2

set xlabel "x" font "Arial, 26"
set ylabel "y" offset -1,0 font "Arial, 26"
set xrange [-1:1]
set yrange [-2:1]
set xtics -1,0.5,1 font "Arial,18"
set ytics -2,1,1 font "Arial,18"
splot f(x,y) lc rgb "white", "minimo2d.dat" pt 5 ps 0.5 lc rgb "red", "minimo2d.dat" lc rgb "black"  
pause -1
