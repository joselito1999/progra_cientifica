f(x,y) = 2/(x**2+y**2)**0.5+2/((x-1)**2+y**2)**0.5+1/((x-0.5)**2+(y-(3**0.5)/2)**2)**0.5

set key off
set isosamples 100
set xlabel "x" font "Arial,18"
set ylabel "y" font "Arial,18"
set xrange [0.4:0.6]
set yrange [0.3:0.6]
#set zrange [2:14]
set pm3d at b
set view map 
unset surface
set contour
set cntrparam levels 50
#set cntrparam levels incremental 5.2,0.01

splot f(x,y) 

pause -1
