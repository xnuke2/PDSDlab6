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
	//создание пустого множества
	SetOnSet();

	//проверка пустое ли множество?
	bool setisEmpty();

	//проверка на наличие элемента в множестве
	bool setContains(int numToFind);

	//добавление элемента в начало множества
	void setAddFirst(int num);

	//создание случайного множества
	static SetOnSet* createRandomSet(int length, int min, int max, string type);

	static SetOnSet* createRandomSet(int length);
	//мощность множества
	int powerOfSet();

	//вывод элементов множества	
	string printSet(char separator);

	//удаление множества
	~SetOnSet();

	//подмножество A-B
	bool subSet(SetOnSet* a);

	//равенство двух множеств
	bool equalitySet(SetOnSet* a);

	//объединение двух множеств
	SetOnSet* CombiningSets(SetOnSet* a);

	//пересечение двух множеств
	SetOnSet* intersectionOfSets(SetOnSet* a);

	//разность двух множеств a-b
	SetOnSet* subtraction(SetOnSet* a);

	//симметричная разность двух множеств
	SetOnSet* simmetricSubtraction(SetOnSet* a);
};


