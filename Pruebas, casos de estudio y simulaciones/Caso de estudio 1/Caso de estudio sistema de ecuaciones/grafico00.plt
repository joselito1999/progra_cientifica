#set term pngcairo size 500,500
#set output "figura.png"
#set term postscript color
#set output "figura.eps"


vxo=10
vyo=10
tau=1
m=1
b=m/tau
g=9.81
vy=m*g/b

f(x)=((vyo+vy)/(vxo))*x+vy*tau*log(1-(x/(vxo*tau)))

set key off
set xlabel "x" font "Arial, 26"
set ylabel "y" font "Arial, 26"
set xrange [0:10]
set yrange [0:4]
#set xtics 0,0.05,0.5 font "Arial,18"
#set ytics 0,0.1,0.25 font "Arial,18"
set grid
plot f(x) lw 2 lc rgb "red",0 lw 2 lc rgb "blue"
