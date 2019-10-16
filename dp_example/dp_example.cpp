// dp_example.cpp: 定义应用程序的入口点。
//

#include<iostream>
#include <stdlib.h>



#define MAX_LENGTH 100
#define SIZE       10
int max(int i, int j) {
	return i > j ? i : j;
}

int array_src[MAX_LENGTH][MAX_LENGTH];
void initSrcArray() {
	for (int i = 0; i < SIZE;i++) {
		for (int j = 0; j <= i; j++) {
			array_src[i][j] = rand() % 100;
		}
	}
}

void printSrcArray() {
	printf("array_src:\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%4d ", array_src[i][j]);
		}
		printf("\n");
	}
}

int array_dst[MAX_LENGTH][MAX_LENGTH];
void initDstArray() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			array_dst[i][j] = -1;
		}
	}
}

void printDstArray() {
	printf("array_dst:\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%4d ", array_dst[i][j]);
		}
		printf("\n");
	}
}

int MaxSum(int i,int j) {
	if (array_dst[i][j] != -1) {
		return array_dst[i][j];
	}
	else {
		if (i == SIZE - 1) {
			array_dst[i][j] = array_src[i][j];
			return array_dst[i][j];
		}
		else {
			array_dst[i][j] = max(MaxSum(i+1,j),MaxSum(i+1,j+1))+ array_src[i][j];
			return array_dst[i][j];
		}
	}

}

using namespace std;

int main()
{
	initSrcArray();
	printSrcArray();
	initDstArray();
	printDstArray();
	cout << "MaxSum:" << MaxSum(0, 0) << endl;
	printDstArray();


	cout << "Hello CMake。" << endl;
	return 0;
}
