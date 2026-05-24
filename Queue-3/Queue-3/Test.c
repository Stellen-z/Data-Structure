#include "Queue.h"


void Test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);


	while (!QueueEmpty(&q))
	{
		
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	

	QueueDestroy(&q);

}


int main()
{
	Test1();
	return 0;
}