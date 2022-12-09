vxo=10
vyo=10
m=1
g=9.81
tau=10

set yrange [3:5]
set xrange [6:10]

f(x)=((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau)));

plot f(x)

pause -1
