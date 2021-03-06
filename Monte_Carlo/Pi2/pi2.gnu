set xlabel 'Number of iterations'
set ylabel 'Value'
set title 'Monte Carlo (Euler) method for pi'
f(N) = N**(-0.5)
set xrange [1:200]
set term png
set output 'pi2.png'
plot 'tmpfile3' u 1:3 w lines, 3.14+f(x) with lines linetype 5, 3.14-f(x) with lines linetype 5
