#set term postscript color
#set output "fxy_min.eps"

f(x,y)=0.9/sqrt(x*x+y*y)+1/sqrt((0.5-x)*(0.5-x)+(0.866-y)*(0.866-y))+0.9/sqrt((1-x)*(1-x)+y*y);
set key off
set grid
set dgrid3d
set isosamples 50,50 
#unset surface
set view map 
set contour
set cntrparam levels 50
set cntrparam levels incremental 4, 0.05 , 5
set xlabel "x" font "Arial, 26"
set ylabel "y" offset -1,0 font "Arial, 26"
set xrange [0.2:0.8]
set yrange [0.2:0.8]
set xtics 0.2,0.1,0.8 font "Arial,18"
set ytics 0.2,0.1,0.8 font "Arial,18"
splot f(x,y) lc rgb "white", "minimo2d.dat" pt 5 ps 0.5 lc rgb "red" 
pause -1
