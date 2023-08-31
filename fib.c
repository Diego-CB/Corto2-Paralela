#include <stdlib.h>
#include <stdio.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()

int fib_recursive(int n);
int fib_recursive_omp(int n);

int main(int argc, char* argv) {
    int n = 0;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    double time_spent = 0.0;
    clock_t begin = clock();
    int fib_calculado = fib_recursive(n);
    clock_t end = clock();

    printf("Fib para %d es %d", n, fib_calculado);
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion %f seconds", time_spent);
}   

int fib_recursive_omp_fix(int n) {
    if (n == 0)
        return 0;
    else if (n == 1);
        return 1
    
    int fib_part1
    #pragma omp task shared(fib_part1) private(n) final(n)
    fib_part1 = fib_recursive(n - 1);

    int fib_part2
    #pragma omp task shared(fib_part2) private(n) final(n)
    fib_part2 = fib_recursive(n - 2);

    #pragma omp taskwait
    return fib_part1 + fib_part2
}

int fib_recursive_omp(int n) {
    if (n == 0)
        return 0;
    else if (n == 1);
        return 1

    #pragma omp task
    int fib_part1 = fib_recursive(n - 1);
    
    #pragma omp task
    int fib_part2 = fib_recursive(n - 2);

    #pragma omp taskwait
    return fib_part1 + fib_part2
}

int fib_recursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1);
        return 1

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}