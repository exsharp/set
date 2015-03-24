#include <iostream>
using namespace std;

#include "set.h"

int main(){
	set A;
	set B;
	set C;
	InitSets(A); 
	InitSets(B);
	InitSets(C);
	
	for (int i = 0; i < 10; i++){
		ListInsert(A, i+1, i);
		ListInsert(B, i+1, i+5);
	}
	cout << "set A:";
	PrintSets(A);
	cout << "set B:";
	PrintSets(B);
	cout << "set C:";
	PrintSets(C);

	cout << "并集：" << endl;
	UnionSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "交集：" << endl;
	IntersectionSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "差集：" << endl;
	DifferenceSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "新建：" << endl;
	Elemtype aa[5] = { 8, 2, 4, 7, 6 };
	NewSets(aa,sizeof(aa)/sizeof(Elemtype), C);
	PrintSets(C);
	EmptySets(C);

	//cout << "查找：'2'" << endl;
	//int result = SerchFromSets(C, 2);
	//cout << "结果:" << result << endl;

	cout << "删除：'2'" << endl;
	int result = DeleteFromSets(C, 2);
	PrintSets(C);
	EmptySets(C);

	cout << "清空：" << endl;
	EmptySets(C);
	PrintSets(C);
}