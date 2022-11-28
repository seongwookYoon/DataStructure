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

	return 0; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List* lp)
{
	// TODO

	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List* lp)
{
	// TODO

	return;
}
