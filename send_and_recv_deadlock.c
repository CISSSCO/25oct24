#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
	int rank;
	int data;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {
        data = 100;
        printf("Process 0: Sending data = %d to Process 1...\n", data);
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); 
        MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        printf("Process 0: Receives data = %d from Process 1...\n", data);
	} else if (rank == 1) {
        data = 200;
        printf("Process 1: Sending data = %d to Process 0...\n", data);
        MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        printf("Process 1: Receives data = %d from Process 0...\n", data);
	}
	MPI_Finalize();
	return 0;
}


