#include"Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}
// ��β�����
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
// ��ͷ������
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
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->val;
}
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->val;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;
}
// ���ٶ���
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
//��ӡ����
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