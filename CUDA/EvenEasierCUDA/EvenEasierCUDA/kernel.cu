#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <math.h>

__global__ void add(int n, float* x, float* y) {
	//int index = threadIdx.x;
	//int stride = blockDim.x;

	//need to take into account new grid of thread blocks
	//index of thread in block
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	
	int stride = blockDim.x * gridDim.x;
	for (int i = index; i < n; i += stride) {
		y[i] = x[i] * y[i] + x[i];
	}
}

int main(void) {

	int N = 1 << 20;
	//to make these accessible to GPU need to put in Unified memory using cudaMallocManaged()
	//float* x = new float[N];
	//float* y = new float[N];
	float *x, *y;

	cudaMallocManaged(&x, N*sizeof(float));
	cudaMallocManaged(&y, N * sizeof(float));

	for (int i = 0; i < N; i++) {
		x[i] = 1.0f;
		y[i] = 2.0f;
	}

	/* 
	use <<<# blocks, # threads>>> to launch add on GPU, <<<1,1>>> launches one thread to run function on GPU
	will get error in VS on these, but program will still run
	   
	*/
	//calc number of blocks to get N threads
	int blockSize = 1024;
	int numBlocks = (N + blockSize - 1) / blockSize;

	add<<<numBlocks,256>>>(N, x, y);
	//use cudaDeviceSynchronize() to make sure kernel is done before CPU access results
	cudaDeviceSynchronize();

	float maxError = 0.0f;
	for (int i = 0; i < N; i++) {
		maxError = fmax(maxError, fabs(y[i] - 3.0f));
	}

	std::cout << "Max error: " << maxError << std::endl;
	//to free data in Unified memory need to use cudaFree()
	//delete[] x;
	//delete[] y;

	cudaFree(x);
	cudaFree(y);

	return 0;
}