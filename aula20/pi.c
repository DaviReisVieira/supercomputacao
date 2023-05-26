
#include <stdio.h>
#include <math.h>
#include <mpi.h>

/* We define pi here so we can check and see how accurate our computation is. */
#define PI 3.141592653589793238462643

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int processes, myid;
    MPI_Comm_size(MPI_COMM_WORLD, &processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    
    int intervals;
    if (myid == 0) {
        printf("Number of intervals: ");
        fflush(stdout);
        scanf("%d", &intervals);
    }

    double time1 = MPI_Wtime();

    MPI_Bcast(&intervals, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int count = intervals / processes;
    int start = count * myid;
    int end = count * myid + count;

    int i;
    double subtotal, total = 0;
    for (i = start; i < end; ++i) {
        subtotal += pow(-1, i) / (2 * i + 1);
    }

    MPI_Reduce(&subtotal, &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    double time2 = MPI_Wtime();

    if (myid == 0) {
        total = total * 4;
        printf("Result:   %.10lf\n", total);
        printf("Accuracy: %.10lf\n", PI - total);
        printf("Time:     %.10lf\n", time2 - time1);
    }

    MPI_Finalize();
}
