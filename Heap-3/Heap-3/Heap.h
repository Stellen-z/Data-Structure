#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//初始化
void HeapInit(Heap* php);
// 堆的销毁
void HeapDestory(Heap* php);
// 堆的插入
void HeapPush(Heap* php, HPDataType x);
// 堆的删除
void HeapPop(Heap* php);
// 取堆顶的数据
HPDataType HeapTop(Heap* php);
// 堆的数据个数
int HeapSize(Heap* php);
// 堆的判空
int HeapEmpty(Heap* php);

//堆排序
void HeapSort(HPDataType* a, int n);
