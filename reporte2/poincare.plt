set xrange[-3:3]
set yrange[-3.1415:3.1415]

plot "poincare_AF_110_N_1000.dat" every::100 title"Fuerza 1.10" lc rgb("grey"), "poincare_AF_100_N_1000.dat" every::100 title"Fuerza 1", "poincare_AF_102_N_1000.dat" every::100 title"Fuerza 1.02", "poincare_AF_104_N_1000.dat" every::100 title"Fuerza 1.04", "poincare_AF_108_N_1000.dat" every::100 title"Fuerza 1.08"

pause -1

set xrange[0:20]
plot "pendulo_AF_100_N_1000.dat" w l title"Fuerza 1", "pendulo_AF_102_N_1000.dat" w l title"Fuerza 1.02", "pendulo_AF_104_N_1000.dat" w l title"Fuerza 1.04"
#, "pendulo_AF_108_N_1000.dat" w l title"Fuerza 1.08","pendulo_AF_110_N_1000.dat" w l title"Fuerza 1.10"

pause -1
