set term pngcairo size 2000,500
set output "distribucion.png"

set encoding iso_8859_1 #Para poner el +/-

a1=1.89973; b1=-1.84021
a2=1.43277; b2=-1.96425
a3=0.809264; b3=-2.12979
a4=-0.0192343; b4=-2.33851
a5=-1.85996; b5=-2.73999

f1(x)=a1+b1*log(sin(x/2))
f2(x)=a2+b2*log(sin(x/2))
f3(x)=a3+b3*log(sin(x/2))
f4(x)=a4+b4*log(sin(x/2))
f5(x)=a5+b5*log(sin(x/2))

set key font "times, 20"
set key title "Energías"
set key title font "times, 20"
set pointsize 1.5

set key box width 5 height 1 opaque

set size ratio 0.5

set yrange [0:16]
set xrange [0:1]

set xlabel "{/Symbol q}" font "times,25"
set ylabel "ln|dN/d{/Symbol W}|" font "times,25" offset -2,0

set xtics font "times, 20"
set ytics font "times, 20"

set multiplot layout 1, 2

set arrow 1 from 0.11,14 to 0.13,14 nohead lc rgb "red" lw 3
set arrow 2 from 0.11,12.5 to 0.13,12.5 nohead lc rgb "blue" lw 3
set arrow 3 from 0.11,11 to 0.13,11 nohead lc rgb "green" lw 3

set label 1 sprintf("%s","a_1=1.89 \261 0.09, b_1=-1.84 \261 0.05, rms=0.45") at 0.14,14.1 font "times, 21"
set label 2 sprintf("%s","a_2=1.43 \261 0.09, b_2=-1.96 \261 0.05, rms=0.43") at 0.14,12.6 font "times, 21"
set label 3 sprintf("%s","a_3=0.81 \261 0.09, b_3=-2.13 \261 0.05, rms=0.42") at 0.14,11.1 font "times, 21"

plot "distang_0.001.dat" u 1:(log($2)) lc rgb "red" pt 9 title  "E=10^{-3} {/Symbol k}", f1(x) lc rgb "red" notitle, "distang_0.01.dat" u 1:(log($2)) lc rgb "blue" pt 9 title "E=10^{-2} {/Symbol k}", f2(x) lc rgb "blue" notitle, "distang_0.1.dat" u 1:(log($2)) lc rgb "green" pt 9 title "E=10^{-1} {/Symbol k}", f3(x) lc rgb "green" notitle

unset arrow 1
unset arrow 2
unset arrow 3
unset label 1
unset label 2
unset label 3

set arrow 4 from 0.11,14 to 0.13,14 nohead lc rgb "#FF00FF" lw 3
set arrow 5 from 0.11,12.5 to 0.13,12.5 nohead lc rgb "#D2691E" lw 3

set label 4 sprintf("%s","a_4=-0.02 \261 0.09, b_4=-2.34 \261 0.05, rms=0.44") at 0.14,14.1 font "times, 21"
set label 5 sprintf("%s","a_5=-1.86 \261 0.12, b_5=-2.74 \261 0.06, rms=0.55") at 0.14,12.6 font "times, 21"

plot"distang_1.dat" u 1:(log($2)) lc rgb "#FF00FF" pt 9 title "E=1 {/Symbol k}", f4(x) lc rgb "#FF00FF" notitle, "distang_10.dat" u 1:(log($2)) lc rgb "#D2691E" pt 9 title "E=10 {/Symbol k}", f5(x) lc rgb "#D2691E" notitle

unset multiplot

