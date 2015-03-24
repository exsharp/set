#include "set.h"
#include <iostream>

void PrintSets(set s){
	for (int i = 1; i <= ListLength(s); i++){
		Elemtype tmp;
		GetElem(s, i, tmp);
		std::cout << tmp << " ";
	}
	std::cout << std::endl;
}

bool InitSets(set &s){
	if (InitList(s)){
		return true;
	}
	else{
		return false;
	}
}

bool UnionSets(set A, set B, set &c){
	if (!InitList(c))
		return false;

	int lenC = 0;
	Elemtype tmp;
	for (int i = 1; i <= ListLength(A); i++){
		GetElem(A, i, tmp);
		if (-1==LocateElem(c, tmp)){
			++lenC;
			ListInsert(c, lenC,tmp);
		}
	}
	for (int i = 1; i <= ListLength(B); i++){
		GetElem(B, i, tmp);
		if (-1==LocateElem(c, tmp)){
			++lenC;
			ListInsert(c, lenC, tmp);
		}
	}
	return true;
}

bool IntersectionSets(set A, set B, set &c){ //交集
	if (!InitList(c))
		return false;

	int lenC = 0;
	Elemtype tmp;
	for (int i = 1; i <= ListLength(A); i++){
		GetElem(A, i, tmp);
		if (-1 != LocateElem(B, tmp)){
			++lenC;
			ListInsert(c, lenC, tmp);
		}
	}
	return true;
}

bool DifferenceSets(set A, set B, set &c){ //差集
	if (!InitList(c))
		return false;

	int lenC = 0;
	Elemtype tmp;
	for (int i = 1; i <= ListLength(A); i++){
		GetElem(A, i, tmp);
		if (-1 == LocateElem(B, tmp)){
			++lenC;
			ListInsert(c, lenC, tmp);
		}
	}
	return true;
}

bool NewSets(Elemtype arg[],int argNum, set &c){
	if (!InitList(c))
		return false;
	
	for (int i = 0; i < argNum; i++){
		ListInsert(c, i+1, arg[i]);
	}

	return true;
}

int SerchFromSet(set A, Elemtype e){
	int location = LocateElem(A, e);
	if (-1 == location){
		return -1;
	}
	else{
		return location;
	}
}

int DeleteFromSets(set A, Elemtype e){
	int location = 0;
	Elemtype tmp;
	while(-1 != location){
		location = LocateElem(A, e);
		ListDelete(A, location, tmp);		
		std::cout << "被删除的元素:" <<tmp<<std::endl;
	}
	return location;
}

bool EmptySets(set A){
	if (ClearList(A)){
		return true;
	}
	else {
		return false;
	}
}
