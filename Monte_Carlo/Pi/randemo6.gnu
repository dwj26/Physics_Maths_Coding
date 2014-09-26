set xlabel 'Number of iterations'
set ylabel 'Value'
set title 'Monte Carlo method for pi'
f(N) = N**(-0.5)
set xrange [1:200]
set term png
set output 'pi.png'
plot 'tmpfile' u 4:5 w lines, 3.14+f(x) with lines linetype 5, 3.14-f(x) with lines linetype 5
