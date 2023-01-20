vxo=10
vyo=10
m=1
g=9.81

set yrange [0:5]
set xrange [0:20]

f(x,tau)=((vyo+tau*g)/(vxo))*x+tau*g*tau*log(1-(x/(vxo*tau)));

plot for[i=1:10] f(x,i) title "tau=".i

pause -1
