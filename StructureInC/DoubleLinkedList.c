#include "DoubleLinkedList.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List* lp)
{
	// TODO
	if (lp == NULL) return FALSE;
	lp->head = (Node*)malloc(sizeof(Node));
	if (lp->head == NULL) return FALSE;
	lp->tail = (Node*)malloc(sizeof(Node));
	if (lp->tail == NULL)
	{
		free(lp->head);
		return FALSE;
	}

	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;
	lp->size = 0;
	return TRUE;
}
/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List* lp, int data)
{
	// TODO
	Node* tempNode;
	if (lp == NULL) return FALSE;
	tempNode = (Node*)malloc(sizeof(Node));
	if (tempNode != NULL)
	{
		tempNode->data = data;
		tempNode->prev = lp->head;
		tempNode->next = lp->head->next;
		lp->head->next->prev	= tempNode;
		lp->head->next			= tempNode;
		++lp->size;
		return TRUE;
	}
	else return FALSE;
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List* lp, int data)
{
	// TODO
	Node* tempNode;
	if (lp == NULL)	return FALSE;
	tempNode = (Node*)malloc(sizeof(Node));
	if (tempNode != NULL)
	{
		tempNode->data = data;
		tempNode->prev = lp->tail->prev;
		tempNode->next = lp->tail;
		lp->tail->prev->next	= tempNode;
		lp->tail->prev			= tempNode;
		++lp->size;
		return TRUE;
	}
	else return FALSE; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List* lp)
{
	// TODO		
	Node* curp;
	if (lp == NULL) return;
	curp = lp->head->next;
	while (curp != lp->tail)
	{
		printf("Data= %d\n", curp->data);
		curp = curp->next;
	}
}
/*----------------------------------------------------------------------------------
Function name	: searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------------------------*/
Node* searchNode(List* lp, int data)
{
	// TODO
	Node* curPoint;
	if (lp == NULL) return NULL;
	curPoint = lp->head->next;
	while (curPoint != lp->tail)
	{
		if (curPoint->data == data) return curPoint;
		else curPoint = curPoint->next;
	}
	return NULL;
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List* lp, int data)
{
	// TODO
	Node* delNode;
	if (lp == NULL) return FALSE;
	delNode = searchNode(lp, data);
	if (delNode != NULL)
	{
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
		free(delNode);
		--lp->size;
		return TRUE;
	}
	else return FALSE; 
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List* lp)
{
	// TODO
	Node* curp;
	Node* nextp;
	int temp = 0;
	if (lp == NULL) return;
	curp = lp->head->next;
	while (curp->next != lp->tail)
	{
		nextp = curp->next;
		while(nextp != lp->tail)
		{
			if (curp->data > nextp->data)
			{
				temp = curp->data;
				curp->data = nextp->data;
				nextp->data = temp;
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
	
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List* lp)
{
	// TODO
	Node* curp;
	Node* nextp;
	if (lp == NULL) return;
	curp = lp->head->next;
	while (curp != lp->tail)
	{
		nextp = curp->next;
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = NULL;
	lp->tail = 0;
	return;
}
