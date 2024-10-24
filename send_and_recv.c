#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0) {
            int data = 100;
    		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    		printf("Process 0 sent data %d to Process 1\n", data);
	} else if (rank == 1) {
            int received_data;
    		MPI_Recv(&received_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    		printf("Process 1 received data %d from Process 0\n", received_data);
	}
	MPI_Finalize();
	return 0;
}

