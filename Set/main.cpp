#include <iostream>
using namespace std;

#include "set.h"

void PrintSets(set s){
	cout << "(";
	Elemtype tmp;
	int i = 1;
	for (i = 1; i <= SetsEleNum(s)-1; i++){
		GetElem(s, i, tmp);
		cout << tmp << ",";
	}
	if (0==SetsEleNum(s))
		cout << ")";
	else{
		GetElem(s, SetsEleNum(s), tmp);
		cout << tmp << ")";
	}


	cout << endl;
}

int main(){
	set A,B,C;
	InitSets(A);
	InitSets(B);
	InitSets(C);

	cout << "初始化集合A:" << endl;
	cout << "输入集合A的元素个数:" << endl;
	int count,num;
	cin >> count;
	cout << "输入集合A的元素:" << endl;
	for (int i = 0; i < count; i++){
		cin >> num;
		ListInsert(A, i + 1, num);
		//ListInsert(A, i+1, i);
		//ListInsert(B, i+1, i+5);
	}

	cout << "初始化集合B:" << endl;
	cout << "输入集合B的元素个数:" << endl;
	cin >> count;
	cout << "输入集合B的元素:" << endl;
	for (int i = 0; i < count; i++){
		cin >> num;
		ListInsert(B, i + 1, num);
	}

	cout << "set A:";
	PrintSets(A);
	cout << "set B:";
	PrintSets(B);
	cout << "set C:";
	PrintSets(C);
	cout << endl;

	while (1){
		cout << "3:求C=A∩B" << endl;
		cout << "4:求C=A∪B" << endl;
		cout << "5:求C=A-B" << endl;
		cout << "6:新建C" << endl;
		cout << "7:从C中查找" << endl;
		cout << "8:从C中删除" << endl;
		cout << "9:清空C" << endl;
		cin >> count;
		switch (count)
		{
		case 3:
			system("cls");			
			EmptySets(C);
			cout << "A∩B:";
			UnionSets(A, B, C);
			cout << "set C:";
			PrintSets(C);
			break;
		case 4:
			system("cls");
			EmptySets(C);
			cout << "A∪B:";
			IntersectionSets(A, B, C);
			cout << "set C:";
			PrintSets(C);
			EmptySets(C);
			break;
		case 5:
			system("cls");
			EmptySets(C);
			cout << "A - B:";
			DifferenceSets(A, B, C);
			cout << "set C:";
			PrintSets(C);
			EmptySets(C);
			break;
		case 6:{
			system("cls");
			EmptySets(C);
			cout << "输入要插入的数组长度:" << endl;
			cin >> count;
			int *p = new int[count];
			cout << "输入各个元素:" << endl;
			for (int i = 0; i < count; i++){
				cin >> *(p + i);
			}
			NewSets(p, count, C);
			cout << "set C:";
			PrintSets(C);
			delete[]p;
			break;
		}
		case 7:{
			system("cls");
			cout << "此刻的set C:" << endl;
			PrintSets(C);
			cout << "输入要查找的数:" << endl;
			cin >> num;
			int result = SerchFromSets(C, num);
			if (-1 == result)
				cout << "该数不存在" << endl;
			else
				cout << "元素:" << num << "位于第" << result << "位" << endl;
			break;
		}
		case 8:{
			system("cls");
			cout << "此刻的set C:" << endl;
			PrintSets(C);
			cout << "输入要删除的元素:" << endl;
			cin >> num;
			int result = DeleteFromSets(C, 2);
			cout << "成功删除" << result << "个值为" << num << "的元素" << endl;
			cout << "set C:";
			PrintSets(C);
			break;
		}
		case 9:
			system("cls");
			EmptySets(C);
		default:
			exit(1);
		}
	}
}