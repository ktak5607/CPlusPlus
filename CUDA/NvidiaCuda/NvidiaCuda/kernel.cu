
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<iostream>
#include <stdio.h>
#include <chrono>

using namespace std::chrono;

/*
void addKernel(float* a, float* b, float* c, int N)
{
	for (int i = 0; i < N; i++) {
		c[i] = a[i] * b[i] + a[i];
	}
    
}
*/
const int N = 10000;
__global__ void VecAdd(float* A, float* B, float* C) {
	int i = threadIdx.x;
	int j = threadIdx.y;
	C[i*j] = A[i*j] + B[i*j];
}

int main()
{
	
	
	float* a = new float[N*N];
	float* b = new float[N*N];
	float* c = new float[N*N];
	
	for (int i = 0; i < N*N; i++) {
			a[i] = 1.0f;
			b[i] = 2.0f;
		}
		
	
	
	dim3 threadsPerBlock(16, 16);
	dim3 numBlocks = (N / threadsPerBlock.x, N / threadsPerBlock.y);
	VecAdd<< <numBlocks, threadsPerBlock >> > (a, b, c);
	cudaDeviceSynchronize();
	/*auto start = high_resolution_clock::now();
	addKernel(a, b, c, N);
	delete(a);
	delete(b);
	delete(c);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() << std::endl;*/

	return 0;

}