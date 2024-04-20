#pragma once
#include <list>
#include <string>
using std::list;
using std::string;

class SetOnList
{
private:
	list<int> List;

public:
	list <int>::iterator begin() { return List.begin(); }
	list <int>::iterator end() { return List.end(); }


	//�������� ������ �� ���������?
	bool setisEmpty();

	//�������� �� ������� �������� � ���������
	bool setContains(int numToFind);

	//���������� �������� � ������ ���������
	bool setAddFirst(int num);

	//�������� ���������� ���������
	static SetOnList* createRandomSet(int length, int min, int max, string type);

	static SetOnList* createRandomSet(int length);

	//�������� ���������
	int powerOfSet();

	//����� ��������� ���������	
	string printSet(char separator);

	//�������� ���������
	~SetOnList();

	//������������ A-B
	bool subSet(SetOnList* a);

	//��������� ���� ��������
	bool equalitySet(SetOnList* a);

	//����������� ���� ��������
	SetOnList* CombiningSets(SetOnList* a);

	//����������� ���� ��������
	SetOnList* intersectionOfSets(SetOnList* a);

	//�������� ���� �������� a-b
	SetOnList* subtraction(SetOnList* a);

	//������������ �������� ���� ��������
	SetOnList* simmetricSubtraction(SetOnList* a);
};

