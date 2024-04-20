#pragma once
#include <set>
#include <string>
using std::set;
using std::string;

class SetOnSet
{
private:
	set<int> Set;

public:
	set <int>::iterator begin() { return Set.begin(); }
	set <int>::iterator end() { return Set.end(); }
	//�������� ������� ���������
	SetOnSet();

	//�������� ������ �� ���������?
	bool setisEmpty();

	//�������� �� ������� �������� � ���������
	bool setContains(int numToFind);

	//���������� �������� � ������ ���������
	void setAddFirst(int num);

	//�������� ���������� ���������
	static SetOnSet* createRandomSet(int length, int min, int max, string type);

	static SetOnSet* createRandomSet(int length);
	//�������� ���������
	int powerOfSet();

	//����� ��������� ���������	
	string printSet(char separator);

	//�������� ���������
	~SetOnSet();

	//������������ A-B
	bool subSet(SetOnSet* a);

	//��������� ���� ��������
	bool equalitySet(SetOnSet* a);

	//����������� ���� ��������
	SetOnSet* CombiningSets(SetOnSet* a);

	//����������� ���� ��������
	SetOnSet* intersectionOfSets(SetOnSet* a);

	//�������� ���� �������� a-b
	SetOnSet* subtraction(SetOnSet* a);

	//������������ �������� ���� ��������
	SetOnSet* simmetricSubtraction(SetOnSet* a);
};


