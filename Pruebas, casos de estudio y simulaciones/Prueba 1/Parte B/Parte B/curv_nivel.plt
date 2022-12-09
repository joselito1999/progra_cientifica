f(x,y) = 2/(x**2+y**2)**0.5+1/((x-1)**2+y**2)**0.5+1/(x**2+(y-1)**2)**0.5+1/((x-1)**2+(y-1)**2)**0.5

set key off
set isosamples 100
set xlabel "x" font "Arial,18"
set ylabel "y" font "Arial,18"
set xrange [0.6:0.7]
set yrange [0.6:0.7]
set zrange [6.5:7.6]
set pm3d at b
set view map 
unset surface
set contour
set cntrparam levels 100
#set cntrparam levels incremental 6,0.1

splot f(x,y) 

pause -1
