#include "set.h"
#include <iostream>

bool InitSets(set &s){
	return InitList(s);
}

bool UnionSets(set A, set B, set &c){

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
			if (!ListInsert(c, lenC, tmp))
				return false;
		}
	}
	return true;
}

bool IntersectionSets(set A, set B, set &c){ //½»¼¯

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

bool DifferenceSets(set A, set B, set &c){ //²î¼¯

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

bool NewSets(Elemtype *arg,int argNum, set &c){

	for (int i = 1; i <= argNum; i++){
		ListInsert(c, i, arg[i-1]);
	}
	return true;
}

int SetsEleNum(set A){
	return ListLength(A);
}

int SerchFromSets(set A, Elemtype e){
	return LocateElem(A, e);
}

int DeleteFromSets(set A, Elemtype e){
	int location = 0;
	int count = 0;
	Elemtype tmp;
	while(-1 != location){
		location = LocateElem(A, e);
		ListDelete(A, location, tmp);
		count++;
	}
	return count;
}

bool EmptySets(set A){
	return ClearList(A);
}
