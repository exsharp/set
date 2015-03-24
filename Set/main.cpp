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

	cout << "������" << endl;
	UnionSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "������" << endl;
	IntersectionSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "���" << endl;
	DifferenceSets(A, B, C);
	PrintSets(C);
	EmptySets(C);

	cout << "�½���" << endl;
	Elemtype aa[5] = { 8, 2, 4, 7, 6 };
	NewSets(aa,sizeof(aa)/sizeof(Elemtype), C);
	PrintSets(C);
	EmptySets(C);

	//cout << "���ң�'2'" << endl;
	//int result = SerchFromSets(C, 2);
	//cout << "���:" << result << endl;

	cout << "ɾ����'2'" << endl;
	int result = DeleteFromSets(C, 2);
	PrintSets(C);
	EmptySets(C);

	cout << "��գ�" << endl;
	EmptySets(C);
	PrintSets(C);
}