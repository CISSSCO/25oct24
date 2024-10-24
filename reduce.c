#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv) {
	int rank, size;
	int send_data;
	int recv_data;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	send_data = rank + 1;
	MPI_Reduce(&send_data, &recv_data, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0) {
        printf("The sum of all processes' data is: %d\n", recv_data);
	}
	MPI_Finalize();
	return 0;
}
