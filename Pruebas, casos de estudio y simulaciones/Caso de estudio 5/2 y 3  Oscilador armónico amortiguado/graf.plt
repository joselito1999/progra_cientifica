set xlabel "t[T]"
set ylabel "A"

plot 'amp.dat' u 1:(abs($2)) w l title "Amplitud en función del tiempo"
pause -1
