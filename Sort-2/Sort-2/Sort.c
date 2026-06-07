#include "Sort.h"
#include "Stack.h"


void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int begin = i;
		int tmp = a[begin + 1];
		while (begin >= 0)
		{
			if (tmp < a[begin])
			{
				a[begin + 1] = a[begin];
				--begin;
			}
			else break;
		}
		Swap(&a[begin + 1], &tmp);
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n / 3;

	while (gap > 1)
	{
		for (int i = 0; i < n - gap; i++)
		{
			int begin = i;
			int tmp = a[begin + gap];

			while (begin >= 0)
			{
				if (tmp < a[begin])
				{
					a[begin + gap] = a[begin];
					begin -= gap;
				}
				else break;
			}
			Swap(&a[begin + gap], &tmp);
		}

		gap = gap / 3 + 1;
	}
}


// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while(begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini]) mini = i;
			if (a[i] > a[maxi]) maxi = i;
		}
		Swap(&a[mini], &a[begin]);
		if (maxi == begin) maxi = mini;
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}

}

void AdjustDwon(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child]) child++;

		if (a[root] < a[child])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = root * 2 + 1;
		}
		else break;
	}
}

// 堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}


// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
			}
		}
	}
}

//快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);

	return begin;
}

//// 快速排序挖坑法
//int PartSort2(int* a, int left, int right)
//{
//
//}
//
//// 快速排序前后指针法
//int PartSort3(int* a, int left, int right)
//{
//
//}


void QuickSort(int* a, int left, int right)
{
	if (left >= right) return;

	int keyi = PartSort1(a, left, right);

	//[left,keyi - 1] keyi [keyi + 1,right]
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}


// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort1(a, begin, end);
		//[begin,keyi - 1] keyi [keyi + 1,end]

		if (keyi - begin > 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
		if (end - keyi > 1)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}

	}

	StackDestroy(&st);

}
