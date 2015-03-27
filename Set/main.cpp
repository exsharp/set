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

	cout << "��ʼ������A:" << endl;
	cout << "���뼯��A��Ԫ�ظ���:" << endl;
	int count,num;
	cin >> count;
	cout << "���뼯��A��Ԫ��:" << endl;
	for (int i = 0; i < count; i++){
		cin >> num;
		ListInsert(A, i + 1, num);
		//ListInsert(A, i+1, i);
		//ListInsert(B, i+1, i+5);
	}

	cout << "��ʼ������B:" << endl;
	cout << "���뼯��B��Ԫ�ظ���:" << endl;
	cin >> count;
	cout << "���뼯��B��Ԫ��:" << endl;
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
		cout << "3:��C=A��B" << endl;
		cout << "4:��C=A��B" << endl;
		cout << "5:��C=A-B" << endl;
		cout << "6:�½�C" << endl;
		cout << "7:��C�в���" << endl;
		cout << "8:��C��ɾ��" << endl;
		cout << "9:���C" << endl;
		cin >> count;
		switch (count)
		{
		case 3:
			system("cls");			
			EmptySets(C);
			cout << "A��B:";
			UnionSets(A, B, C);
			cout << "set C:";
			PrintSets(C);
			break;
		case 4:
			system("cls");
			EmptySets(C);
			cout << "A��B:";
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
			cout << "����Ҫ��������鳤��:" << endl;
			cin >> count;
			int *p = new int[count];
			cout << "�������Ԫ��:" << endl;
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
			cout << "�˿̵�set C:" << endl;
			PrintSets(C);
			cout << "����Ҫ���ҵ���:" << endl;
			cin >> num;
			int result = SerchFromSets(C, num);
			if (-1 == result)
				cout << "����������" << endl;
			else
				cout << "Ԫ��:" << num << "λ�ڵ�" << result << "λ" << endl;
			break;
		}
		case 8:{
			system("cls");
			cout << "�˿̵�set C:" << endl;
			PrintSets(C);
			cout << "����Ҫɾ����Ԫ��:" << endl;
			cin >> num;
			int result = DeleteFromSets(C, 2);
			cout << "�ɹ�ɾ��" << result << "��ֵΪ" << num << "��Ԫ��" << endl;
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