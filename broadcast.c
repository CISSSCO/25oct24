#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
	int rank, size;
	int data;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank == 0) {
        data = 100; // The data to be broadcasted
	}
	MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Process %d received data: %d\n", rank, data);
	MPI_Finalize();
	return 0;
}

