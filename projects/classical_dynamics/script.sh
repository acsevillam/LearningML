
g++ dynamics.cpp -O3 -o no_omp.out

g++-9 dynamics.cpp -O3 -fopenmp -o omp.out
for i in 1000 10000 100000
do
echo $i
echo NO OMP
time ./no_omp.out 1000 $i 
echo OMP
time ./omp.out 1000 $i 
done
