#include "SetHead.h"

//�������� ������� ���������
Element* createEmptySet() {
	Element* firstElement = NULL;
	return firstElement;
}

//�������� ������ �� ���������?
bool setisEmpty(Element* firstElement)
{
	if (firstElement == NULL) {
		return true;
	}
	return false;
}

//�������� �� ������� �������� � ���������
bool setContains(Element* firstElement, int numToFind) {
	if (setisEmpty(firstElement)) {
		return false;
	}
	Element* tmp = firstElement;
	while (tmp != NULL)
	{
		if (tmp->Value == numToFind) {
			return true;
		}
		tmp = tmp->Next;
	}
	return false;
}

//���������� �������� � ������ ���������
Element* setAddFirst(Element* firstElement, int num) {
	if (setContains(firstElement, num)) {
		return firstElement;

	}
	Element* newStart = new Element;
	newStart->Value = num;
	newStart->Next = firstElement;
	return newStart;
}

//�������� ���������� ���������
Element* createRandomSet(int length, int min, int max, string type) {
	Element* newSet = createEmptySet();
	if (length <= 0 || max - min < length) {
		return newSet;
	}
	if (type == "b") {
		for (int i = 0; i < length; i++) {
			int newNum = rand() % (max - min + 1) + min;
			while (setContains(newSet, newNum) || newNum % 10 <= 3) {
				newNum = rand() % (max - min + 1) + min;
			}
			newSet = setAddFirst(newSet, newNum);
		}
	}
	if (type == "a") {
		for (int i = 0; i < length; i++) {
			int newNum = rand() % (max - min + 1) + min;
			while (setContains(newSet, newNum) || newNum % 10 >= 8) {
				newNum = rand() % (max - min + 1) + min;
			}
			newSet = setAddFirst(newSet, newNum);
		}
	}
	return newSet;
	
}

Element* createRandomSet(int length)
{
	Element* newSet = createEmptySet();
	if (length <= 0) {
		return newSet;
	}
	for (int i = 0; i < length; i++) {
		int newNum = rand() % (length * 10 + 1);
		Element* tmp = setAddFirst(newSet, newNum);;
		while (tmp == newSet) {
			tmp = setAddFirst(newSet, rand() % (length * 10 + 1));
		}
		newSet = tmp;
	}
	return newSet;
}


//�������� ���������
int powerOfSet(Element* firstElement) {

	Element* tmp = firstElement;
	int length = 0;
	while (tmp != NULL)
	{
		length++;
		tmp = tmp->Next;
	}
	return length;
}

//����� ��������� ���������	
string printSet(Element* firstElement, char separator) {
	string rezult = "";
	if (setisEmpty(firstElement)) {
		return rezult;
	}
	Element* tmp = firstElement;
	while (tmp != NULL) {
		rezult = rezult + std::to_string(tmp->Value);
		if (tmp->Next != NULL) {
			rezult = rezult + separator;
		}
		tmp = tmp->Next;
	}
	return rezult;
}

//�������� ���������
Element* deleteSet(Element* firstElement) {
	if (setisEmpty(firstElement)) {
		return firstElement;
	}
	Element* tmp = firstElement;
	Element* tmpLast;
	while (tmp) {
		tmpLast = tmp;
		tmp = tmp->Next;
		delete tmpLast;
	}
	firstElement = NULL;
	return firstElement;
}

//������������ A-B
bool subSet(Element* a, Element* b) {
	if (setisEmpty(a)) return true;
	if (setisEmpty(b)) return false;
	int check = 0;
	Element* tmpa = a;
	while (tmpa != NULL) {
		if (!setContains(b, tmpa->Value))return false;
		tmpa = tmpa->Next;
	}
	return true;
}

//��������� ���� ��������
bool equalitySet(Element* a, Element* b) {
	if (subSet(a, b) && subSet(b, a)) return true;
	return false;
}

//����������� ���� ��������
Element* CombiningSets(Element* a, Element* b) {
	if (setisEmpty(a) || setisEmpty(b)) return NULL;
	Element* tmp = b;
	Element* rezult = createEmptySet();
	while (tmp != NULL)
	{
		rezult = setAddFirst(rezult, tmp->Value);
		tmp = tmp->Next;
	}
	tmp = a;
	while (tmp != NULL)
	{
		rezult = setAddFirst(rezult, tmp->Value);
		tmp = tmp->Next;
	}
	return rezult;
}

//����������� ���� ��������
Element* intersectionOfSets(Element* a, Element* b) {
	if (setisEmpty(a) || setisEmpty(b)) return NULL;
	Element* rezult = createEmptySet();
	Element* tmpa = a;
	while (tmpa != NULL)
	{
		if (setContains(b, tmpa->Value)) rezult = setAddFirst(rezult, tmpa->Value);
		tmpa = tmpa->Next;
	}

	return rezult;
}

//�������� ���� �������� a-b
Element* subtraction(Element* a, Element* b) {
	if (setisEmpty(a) && setisEmpty(b)) return NULL;
	Element* rezult = createEmptySet();
	Element* tmpa = a;
	while (tmpa != NULL)
	{
		if (!setContains(b, tmpa->Value))rezult = setAddFirst(rezult, tmpa->Value);
		tmpa = tmpa->Next;
	}
	return rezult;
}

//������������ �������� ���� ��������
Element* simmetricSubtraction(Element* a, Element* b) {
	return subtraction(CombiningSets(a, b), intersectionOfSets(a, b));
}