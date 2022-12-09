f(x,y) = 1/(x**2+y**2)**0.5+1/((x-1)**2+y**2)**0.5+1/((x-0.5)**2+(y-(3**0.5)/2)**2)**0.5

set key off
set isosamples 100
set xlabel "x" font "Arial,18"
set ylabel "y" font "Arial,18"
set xrange [-.5:1.5]
set yrange [-.1:1]
set zrange [0:10]
set pm3d at b
set contour
set cntrparam levels 10


unset ztics

splot f(x,y) 

pause -1
