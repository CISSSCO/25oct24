#include <stdio.h>
#include <mpi.h>
#define N 10000

int main(int argc, char** argv) {
    int rank, size;
    int array[N];  // Array to hold the data (initialized only by root)
    int elements_per_process;
    int local_sum = 0, global_sum = 0;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);
    
    // Get rank of the current process and total number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // Define how many elements each process will receive
    elements_per_process = N / size;

    // Root process initializes the array
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            array[i] = i + 1;  // Fill the array with values 1, 2, ..., 8
        }
    }

    // Buffer to store the part of the array received by each process
    int sub_array[elements_per_process];

    // Scatter the array to all processes
    MPI_Scatter(array, elements_per_process, MPI_INT, sub_array, elements_per_process, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates the sum of its portion of the array
    for (int i = 0; i < elements_per_process; i++) {
        local_sum += sub_array[i];
    }

    // Reduce all local sums into the global sum on the root process
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Root process prints the global sum
    if (rank == 0) {
        printf("The sum of all elements is: %d\n", global_sum);
    }

    // Finalize MPI environment
    MPI_Finalize();
    
    return 0;
}

