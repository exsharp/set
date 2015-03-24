#ifndef _LIST_H
#define	_LIST_H

typedef int type;

typedef struct LNode{
	type data;
	struct LNode *next;
}*List;

bool InitList(List &L);
bool DestroyList(List &L);
bool ClearList(List &L);
bool ListEmpty(List L);//ÅÐ¶ÏÁ´±íÊÇ·ñÎª¿Õ
int ListLength(List L);
bool GetElem(List L, int i, type &e);
int LocateElem(List L, type e);
bool ListInsert(List &L, int i, type e);
bool ListDelete(List &L, int i, type &e);

#endif