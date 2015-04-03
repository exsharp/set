#include "list.h"
#include <iostream> //define NULL

#ifdef LINK_LIST

bool InitList(List &L)
{
	L = new LNode;
	L->data = 0;  //头指针内的data用来记录链表长度，不包括头指针
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
	L = NULL;
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
	if (!L->next)
		return true;
	else
		return false;
}

int ListLength(List L)
{
	int total = L->data;
	int j = -1;
	while (L)
	{
		L = L->next;
		j++;
	}
	if (j != total){
		std::cout << "程序有问题\n";
	}
	return j;
	//return L->data
}

bool GetElem(List L, int i, type &e)
{
	int j = 0;
	while (L&&j < i){
		L = L->next;
		j++;
	}
	if (!L || i <= 0){
		return false;
	}
	else{
		e = L->data;
		return true;
	}
}

int LocateElem(List L, type e)
{
	L = L->next;
	int j = 1;
	while (L&&L->data!=e)
	{
		L = L->next;
		++j;
	}
	if (!L){
		return -1;
	}
	else{
		return j;
	}
}

bool ListInsert(List &L, int i, type e){
	LNode *p;
	p = L;

	int j=1; //记录位置

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

		L->data++; //链表长度+1
		return true;
	}
}

bool ListDelete(List &L, int i, type &e)
{
	LNode *p;
	p = L;
	int j = 1;
	while (p&&j < i){
		p = p->next;
		j++;
	}
	if (!p->next || i <= 0)
		return false;
	else {
		LNode *temp = p->next;
		p->next = temp->next;

		e = temp->data;
		delete temp;

		L->data--;
		return true;
	}
}

#endif