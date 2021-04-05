
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

__global__ void mykernel(void) {
	printf("Hellow World\n");
}

__global__ void vecadd_kernel(int* a, int* b, int* c, int N) {
	//int i = threadIdx.x;
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		c[i] = a[i] + b[i];
	}
}
void vecadd(int* a, int* b, int* c, int N) {
	//vecadd_kernel << < 1, N >> > (a, b, c, N);
	vecadd_kernel << < (N+1023)/1024/1024, 1024 >> > (a, b, c, N);
	cudaDeviceSynchronize();
	//for (int i = 0; i < N; i++) {
		//vecadd_kernel(a, b, c, N, i);
	//}
}
int main(void) {
	int N = 512;
	int* a, * b, * c;

	cudaMallocManaged(&a, N * sizeof(int));
	cudaMallocManaged(&b, N * sizeof(int));
	cudaMallocManaged(&c, N * sizeof(int));

	//a = (int*)malloc(N * sizeof(int));
	//b = (int*)malloc(N * sizeof(int));
	//c = (int*)malloc(N * sizeof(int));

	vecadd(a, b, c, N);
	//mykernel <<<1, 1 >>> ();
	//cudaDeviceSynchronize();

	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	return 0;
}
