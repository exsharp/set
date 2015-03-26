#ifndef _SET_H
#define _SET_H
#include "list.h"

#define Elemtype int
typedef List set;

bool InitSets(set &s);
bool UnionSets(set A, set B, set &c); //并集
bool IntersectionSets(set A, set B, set &c); //交集
bool DifferenceSets(set A, set B, set &c);//差集
bool NewSets(Elemtype arg[],int argNum,set &c);
int SetsEleNum(set A);
int SerchFromSets(set A,Elemtype e);
int DeleteFromSets(set A,Elemtype e);
bool EmptySets(set A);

#endif