set encoding utf8
set xrange [0:23]
set yrange [-1:15]
set xlabel "V_o (2ma^2/\U+210F^2)" font "Arial,12"
set ylabel "|E| (2ma^2/\U+210F^2)" font "Arial,12"
plot 'datos.dat' w points pt 4 lc rgb "blue" notitle
pause -1
