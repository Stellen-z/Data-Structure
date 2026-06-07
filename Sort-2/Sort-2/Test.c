#include "Sort.h"

void TestInsertSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	InsertSort(a,sizeof(a)/sizeof(int));
	printf("InsertSort:");
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestShellSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	ShellSort(a, sizeof(a) / sizeof(int));
	printf("ShellSort:");
	PrintArr(a, sizeof(a) / sizeof(int));
}


void TestSelectSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	SelectSort(a, sizeof(a) / sizeof(int));
	printf("SelectSort:");
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	HeapSort(a, sizeof(a) / sizeof(int));
	printf("HeapSort:");
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	printf("BubbleSort:");
	PrintArr(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 2,5,2,8,3,9,3,5,3,5,8,4,1,9,0,5,7,2 };
	//QuickSort(a, 0,sizeof(a) / sizeof(int) -  1);
	//printf("QuickSort:");
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	printf("QuickSortNonR:");
	PrintArr(a, sizeof(a) / sizeof(int));
}




int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();

	return 0;
}