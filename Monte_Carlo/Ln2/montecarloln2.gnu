set xlabel 'Number of iterations'
set ylabel 'Value'
set title 'Monte Carlo method for ln(2)'
f(N) = N**(-0.5)
set xrange [1:200]
set term png size 400,300 
set output 'ln2.png'
plot 'tmpfile2' u 4:5 w lines, 0.69+f(x) with lines linetype 5,0.69-f(x) with lines linetype 5

