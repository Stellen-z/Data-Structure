#include "Heap.h"

void Test01()
{
	Heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 1);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	HeapPush(&hp, 4);
	HeapPush(&hp, 5);
	HeapPush(&hp, 6);

	while (HeapSize(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");

	HeapDestory(&hp);
}

void Test02()
{
	int* a[] = { 2,6,3,8,3,9,4,8,2,7,9,0 };
	HeapSort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}


int main()
{

	Test01();
	Test02();
	return 0;
}