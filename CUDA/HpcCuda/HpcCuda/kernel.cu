
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include<iostream>

/* First Exercise
void helloCPU()
{
	std::cout << "Hello from CPU.\n";
}

__global__
void helloGPU()
{
	
	printf("Hello also from GPU.\n");
}

int main()
{

	helloCPU();
	helloGPU<<<5,5>>>();

	return 0;
}
*/

/*Second Exercise
using specific threads and block indicies


__global__ void printSuccessForCorrectExecutionConfiguration()
{
	if (threadIdx.x == 1023 && blockIdx.x == 255)
	{
		printf("Success!\n");
	}
}

int main()
{
	
	printSuccessForCorrectExecutionConfiguration << <256, 1024 >> > ();

	return 0;
}*/

/*Third Exercise
Accelerating a For Loop With a Single Block of Threads
*/
/* FIXME
 * Correct, and refactor 'loop' to be a CUDA Kernel.
 * The new kernel should only do the work
 * of 1 iteration of the original loop.
 */

/*
__global__ void loop()
{
	int i = threadIdx.x;
	printf("This is iteration number %d\n", i);
	
}

int main()
{

	int N = 10;
	loop<<<1,N>>>();
	cudaDeviceSynchronize();
}
*/

/*Fourth Excercise
Accelerating a for loop with multiple blocks of threads
*/

/* FIXME
 * Fix and refactor 'loop' to be a CUDA Kernel.
 * The new kernel should only do the work
 * of 1 iteration of the original loop.
 */
/*
#include <cstdio>

__global__ void loop(int N)
{
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	if(index < N){
		printf("This is iteration number %d\n", index);
	}
}

int main()
{
	
	int N = 10;
	int numBlcks = 2;
	loop<<<numBlcks, N/numBlcks>>>(N);
	cudaDeviceSynchronize();
}
*/

/*Fourth Exercise
array manipulation on both the host and device
*/

//void init(int* a, int N)
//{
//	for (int i = 0; i < N; ++i) {
//		a[i] = i;
//	}
//}
//
///*
// * Double elements in parallel on the GPU.
// */
//
//__global__
//void doubleElements(int* a, int N)
//{
//	int i = blockIdx.x * blockDim.x + threadIdx.x;
//	if (i < N) {
//		a[i] *= 2;
//	}
//}
//
///*
// * Check all elements have been doubled on the host.
// */
//
//bool checkElementsAreDoubled(int* a, int N)
//{
//	for (int i = 0; i < N; ++i) {
//		if (a[i] != i * 2) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int N = 100;
//	int* a;
//
//	size_t size = N * sizeof(int);
//
//	/*
//	 * Refactor this memory allocation to provide a pointer
//	 * 'a' that can be used on both the host and the device.
//	 */
//
//	cudaMallocManaged(&a, size);
//
//	init(a, N);
//
//	size_t threads_per_block = 10;
//	size_t number_of_blocks = 10;
//
//	/*
//	 * This launch will not work until the pointer 'a' is also
//	 * available to the device.
//	 */
//
//	doubleElements << <number_of_blocks, threads_per_block >> > (a, N);
//	cudaDeviceSynchronize();
//
//	bool areDoubled = checkElementsAreDoubled(a, N);
//	printf("All elements were doubled? %s\n", areDoubled ? "TRUE" : "FALSE");
//
//	/*
//	 * Refactor to free memory that has been allocated to be
//	 * accessed by both the host and the device.
//	 */
//
//	cudaFree(a);
//}
/* Fifth Exercise
use a grid-stride loop to manipulate an array larger than the grid
*/
//void init(int* a, int N)
//{
//	for (int i = 0; i < N; ++i) {
//		a[i] = i;
//	}
//}
//
///*
// * In the current application, 'N' is larger than the grid.
// * Refactor this kernel to use a grid-stride loop in order that
// * each parallel thread work on more than one element of the array.
// */
//
//__global__
//void doubleElements(int* a, int N)
//{
//	int indexWithinGrid = blockIdx.x * blockDim.x + threadIdx.x;
//	int stride = gridDim.x * blockDim.x;
//	for(int i = indexWithinGrid; i < N; i+= stride)
//	if (i < N) {
//		a[i] *= 2;
//	}
//}
//
//bool checkElementsAreDoubled(int* a, int N)
//{
//	for (int i = 0; i < N; ++i) {
//		if (a[i] != i * 2) {
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	/*
//	 * 'N' is greater than the size of the grid (see below).
//	 */
//
//	int N = 10000;
//	int* a;
//
//	size_t size = N * sizeof(int);
//	cudaMallocManaged(&a, size);
//
//	init(a, N);
//
//	/*
//	 * The size of this grid is 256*32 = 8192.
//	 */
//
//	size_t threads_per_block = 256;
//	size_t number_of_blocks = 32;
//
//	doubleElements << <number_of_blocks, threads_per_block >> > (a, N);
//	cudaDeviceSynchronize();
//
//	bool areDoubled = checkElementsAreDoubled(a, N);
//	printf("All elements were doubled? %s\n", areDoubled ? "TRUE" : "FALSE");
//
//	cudaFree(a);
//}


/*
 * Host function to initialize vector elements. This function
 * simply initializes each element to equal its index in the
 * vector.
 */

void initWith(float num, float* a, int N)
{
	for (int i = 0; i < N; ++i) {
		a[i] = num;
	}
}

/*
 * Device kernel stores into 'result' the sum of each
 * same-indexed value of 'a' and 'b'.
 */

__global__
void addVectorsInto(float* result, float* a, float* b, int N)
{
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	int stride = blockDim.x * gridDim.x;

	for (int i = index; i < N; i += stride) {
		result[i] = a[i] + b[i];
	}
}

/*
 * Host function to confirm values in 'vector'. This function
 * assumes all values are the same 'target' value.
 */

void checkElementsAre(float target, float* vector, int N)
{
	for (int i = 0; i < N; i++) {
		if (vector[i] != target)
		{
			printf("FAIL: vector[%d] - %0.0f does not equal %0.0f\n", i, vector[i], target);
			exit(1);
		}
	}
	printf("Success! All values calculated correctly.\n");
}

int main()
{
	const int N = 2 << 24;
	size_t size = N * sizeof(float);

	float* a, * b, * c;

	cudaMallocManaged(&a, size);
	cudaMallocManaged(&b, size);
	cudaMallocManaged(&c, size);

	initWith(3, a, N);
	initWith(4, b, N);
	initWith(0, c, N);

	size_t threadsPerBlock;
	size_t numberOfBlocks;

	threadsPerBlock = 80;
	numberOfBlocks = 1;

	addVectorsInto << <numberOfBlocks, threadsPerBlock >> > (c, a, b, N);

	cudaDeviceSynchronize();

	checkElementsAre(7, c, N);

	cudaFree(a);
	cudaFree(b);
	cudaFree(c);
	
	return 0;
}