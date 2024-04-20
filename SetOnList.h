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


	//проверка пустое ли множество?
	bool setisEmpty();

	//проверка на наличие элемента в множестве
	bool setContains(int numToFind);

	//добавление элемента в начало множества
	bool setAddFirst(int num);

	//создание случайного множества
	static SetOnList* createRandomSet(int length, int min, int max, string type);

	static SetOnList* createRandomSet(int length);

	//мощность множества
	int powerOfSet();

	//вывод элементов множества	
	string printSet(char separator);

	//удаление множества
	~SetOnList();

	//подмножество A-B
	bool subSet(SetOnList* a);

	//равенство двух множеств
	bool equalitySet(SetOnList* a);

	//объединение двух множеств
	SetOnList* CombiningSets(SetOnList* a);

	//пересечение двух множеств
	SetOnList* intersectionOfSets(SetOnList* a);

	//разность двух множеств a-b
	SetOnList* subtraction(SetOnList* a);

	//симметричная разность двух множеств
	SetOnList* simmetricSubtraction(SetOnList* a);
};

