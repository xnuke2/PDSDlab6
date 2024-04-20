#pragma once
#include <iostream>
#include <string>
using std::string;



class SetClass {

private: struct Node {
		int value;
		Node* next;
	};
	Node* firstNode;
public:
	//�������� ������� ���������
	SetClass();
	
	//�������� ������ �� ���������?
	bool setisEmpty();

	//�������� �� ������� �������� � ���������
	bool setContains(int numToFind);

	//���������� �������� � ������ ���������
	bool setAddFirst(int num);

	//�������� ���������� ���������
	static SetClass* createRandomSet(int length, int min, int max, string type);

	static SetClass* createRandomSet(int length);
	//�������� ���������
	int powerOfSet();

	//����� ��������� ���������	
	string printSet(char separator);

	//�������� ���������
	~SetClass();

	//������������ A-B
	bool subSet(SetClass* a);

	//��������� ���� ��������
	bool equalitySet(SetClass* a);

	//����������� ���� ��������
	SetClass* CombiningSets(SetClass* a);

	//����������� ���� ��������
	SetClass* intersectionOfSets(SetClass* a);

	//�������� ���� �������� a-b
	SetClass* subtraction(SetClass* a);

	//������������ �������� ���� ��������
	SetClass* simmetricSubtraction(SetClass* a);
};