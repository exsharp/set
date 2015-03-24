#include "list.h"
#include <iostream> //define NULL

bool InitList(List &L)
{
	L = new LNode;
	L->data = 0;  //ͷָ���ڵ�data������¼�����ȣ�������ͷָ��
	L->next = NULL;
	return true;
}

bool DestroyList(List &L)
{
	LNode *p;
	LNode *tmp;
	p = L;
	while (p)
	{
		tmp = p->next;
		delete p;
		p = tmp;
	}
	p = NULL;
	tmp = NULL;
	return true;
}

bool ClearList(List &L){
	LNode *p;
	LNode *tmp;
	p = L->next;
	L->next = NULL;
	while (p)
	{
		tmp = p->next;
		delete p;
		p = tmp;

		L->data--;
	}
	return true;
}

bool ListEmpty(List L)
{
	LNode *p;
	p = L->next;
	if (!p)
		return true;
	else
		return false;
}

int ListLength(List L)
{
	LNode *p;
	p = L->next;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	if (j != L->data){
		std::cout << "����������\n";
	}
	return j;
	//return L->data
}

bool GetElem(List L, int i, type &e)
{
	LNode *p;
	p = L->next;

	int j = 1;
	while (p&&j < i){
		p = p->next;
		j++;
	}
	if (!p || i <= 0){
		return false;
	}
	else{
		e = p->data;
		return true;
	}
}

int LocateElem(List L, type e)
{
	LNode *p;
	p = L->next;
	
	int j = 1;

	while (p&&p->data!=e)
	{
		p = p->next;
		++j;
	}
	if (!p){
		return -1;
	}
	else{
		return j;
	}
}

bool ListInsert(List &L, int i, type e){
	LNode *p;
	p = L;

	int j=1; //��¼λ��

	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || i <= 0)
		return false;
	else {
		LNode *temp = new LNode;
		temp->next = p->next;
		temp->data = e;
		p->next = temp;

		L->data++; //������+1
		return true;
	}
}

bool ListDelete(List &L, int i, type &e)
{
	LNode *p;
	p = L->next;
	int j = 1;
	while (p&&j < i){
		p = p->next;
		j++;
	}
	if (!p || i <= 0)
		return false;
	else {
		LNode *temp = p->next;
		p->next = temp->next;

		e = temp->data;

		L->data--;
		L = NULL;
		return true;
	}
}

