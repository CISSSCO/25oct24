#include <stdio.h>
#include <mpi.h>
#define N 8
int main(int argc, char** argv) {
	int rank, size;
	int send_data[N];  // Array to be scattered from root process
	int recv_data; 	// Each process will receive one element
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank == 0) {
    	for (int i = 0; i < N; i++) {
        		send_data[i] = i + 1;  // Initialize the array with values 1 to 8
    	}
	}
	MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("Process %d received data: %d\n", rank, recv_data);
	MPI_Finalize();
	return 0;
}
