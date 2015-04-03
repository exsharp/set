#include "List.h"
#include<string.h>

#ifdef ARRAY_LIST

bool InitList(List &L){
	L.elem = new int[MAXSIZE];
	if(!L.elem)  
		return false;
	L.length = 0;
	//memset(L.elem,0,MAXSIZE*sizeof(int));
	return true;
}

bool DestroyList(List &L){
	delete L.elem;
	L.elem = NULL;
	L.length = 0;
	return true;
}

bool ClearList(List &L){
	L.length = 0;
	return true;
}

bool ListEmpty(List L){
	if (L.length == 0)
		return true;
	else
		return false;
}

int ListLength(List L){
	return L.length;
}

bool GetElem(List L, int i, int &e){
	if (i > 0 && i <= L.length){
		e = L.elem[i - 1];
		return true;
	}
	else{
		return false;
	}
}

int LocateElem(List L,int e){
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e) 
			return i+1;
	return -1;   
}

bool ListInsert(List &L,int i,int e){
	int j;
	if(i<1||i>L.length +1) 
		return false;
	if(L.length == MAXSIZE) 
		return false;
	for(j=L.length;j>=i;j--)
		L.elem[j]=L.elem[j-1];
	L.elem[i-1]=e;
	++L.length;
	return true;
}

bool ListDelete(List &L,int i, int &e){
	if(i<1||i>L.length) 
		return false;
	e=L.elem[i-1];
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return true;
}

#endif



