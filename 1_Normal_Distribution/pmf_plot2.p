reset

set term png
set output "pmf2.png"
set xrange[0:12]
set yrange[0:0.5]

set xlabel "Data Set"
set ylabel "Probability"

plot "pmf.dat" using 1:2 with lines title "Mass Function Graph 2"
