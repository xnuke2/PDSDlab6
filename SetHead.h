#pragma once
#include <iostream>
#include <string>
using std::string;

struct Element
{
	int Value;
	Element* Next;
};

//�������� ������� ���������
Element* createEmptySet();

//�������� ������ �� ���������?
bool setisEmpty(Element* firstElement);

//�������� �� ������� �������� � ���������
bool setContains(Element* firstElement, int numToFind);

//���������� �������� � ������ ���������
Element* setAddFirst(Element* firstElement, int num);

//�������� ���������� ���������
Element* createRandomSet(int length, int min, int max, string type);

Element* createRandomSet(int length);

//�������� ���������
int powerOfSet(Element* firstElement);

//����� ��������� ���������	
string printSet(Element* firstElement, char separator);

//�������� ���������
Element* deleteSet(Element* firstElement);

//������������ A-B
bool subSet(Element* a, Element* b);

//��������� ���� ��������
bool equalitySet(Element* a, Element* b);

//����������� ���� ��������
Element* CombiningSets(Element* a, Element* b);

//����������� ���� ��������
Element* intersectionOfSets(Element* a, Element* b);

//�������� ���� �������� a-b
Element* subtraction(Element* a, Element* b);

//������������ �������� ���� ��������
Element* simmetricSubtraction(Element* a, Element* b);
