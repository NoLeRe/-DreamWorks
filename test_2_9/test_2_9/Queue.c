#include"Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, DataType data)
{
	QNode *Node = (QNode*)malloc(sizeof(QNode));
	Node->val = data;
	Node->next = NULL;
	if (q->front == NULL)
	{
		q->front = Node;
		q->rear = Node;
	}
	else
	{
		q->rear->next = Node;
		q->rear = Node;
	}
}
// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode *next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
// 获取队列头部元素
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->val;
}
// 获取队列队尾元素
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->val;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode *cur = q->front;
	while (cur != q->rear)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front != q->rear)
	{
		QNode *next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
//打印队列
void QueuePrint(Queue* q)
{
	assert(q);
	QNode *cur = q->front;
	while (cur)
	{
		printf("%d ->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}