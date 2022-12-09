f(a,x)=(x>0 && x<a)? tan((a-x)**0.5)+(a/x +1)**0.5:1/0
set xrange [0:5]
set yrange [-15:15]
plot for [i=3:9] f(i,x) title "a=".i, 0 notitle
pause -1
