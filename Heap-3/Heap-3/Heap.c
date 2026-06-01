#include "Heap.h"

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//初始化
void HeapInit(Heap* php)
{
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

// 堆的销毁
void HeapDestory(Heap* php)
{
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}


//向上调整算法
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else break;
	}

}


//向下调整算法
void AdjustDown(HPDataType* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1]) child++;
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}


// 堆的插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->_capacity == php->_size)
	{
		int newcapacity = php->_capacity == 0 ? 4 : 2 * php->_capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!\n");
			exit(1);
		}
		php->_a = tmp;
		php->_capacity = newcapacity;
	}

	php->_a[php->_size] = x;
	AdjustUp(php->_a, php->_size);
	php->_size++;

}

// 堆的删除
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);

	Swap(&php->_a[php->_size - 1], &php->_a[0]);
	php->_size--;
	AdjustDown(php->_a, 0, php->_size);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* php)
{
	assert(php);

	return php->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* php)
{
	assert(php);
	
	return php->_size;
}

// 堆的判空
int HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0;
}



//堆排序
void HeapSort(HPDataType* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}

	int end = n - 1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		end--;
	}
}