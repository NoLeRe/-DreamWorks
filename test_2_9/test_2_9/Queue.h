#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct QListNode{
	DataType val;
	struct QListNode *next;
}QNode;

typedef struct Queue{
	QNode *front;
	QNode *rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, DataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
//��ӡ����
void QueuePrint(Queue* q);


