#include "Tests.h"

void TestCreate(int col_width, int SetSize1)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << "Создание множества" << '|';
	srand(0);
	start_time = clock();
	createRandomSet(SetSize1);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	SetClass::createRandomSet(SetSize1);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	SetOnList::createRandomSet(SetSize1);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	SetOnSet::createRandomSet(SetSize1);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestPower(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << "Мощность" << '|';
	start_time = clock();
	powerOfSet(setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->powerOfSet();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->powerOfSet();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->powerOfSet();
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestSubSet(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2)
{
	unsigned int start_time;
	unsigned int end_time;
	if (setOnNodes == setOnNodes2 && setOnNodeList == setOnNodeList2 && setOnList == setOnList2 && setOnSet == setOnSet2) {
		cout << left << setw(col_width) << setfill(' ') << "Подмножество A-A " << '|';
	}
	else if (setOnNodes != setOnNodes2 && setOnNodeList != setOnNodeList2 && setOnList != setOnList2 && setOnSet != setOnSet2) {
		cout << left << setw(col_width) << setfill(' ') << "Подмножество A-B " << '|';
	}
	else {
		return;
	}
	start_time = clock();
	subSet(setOnNodes2, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList2->subSet(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList2->subSet(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet2->subSet(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestEquality(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2)
{
	unsigned int start_time;
	unsigned int end_time;
	if (setOnNodes == setOnNodes2 && setOnNodeList == setOnNodeList2 && setOnList == setOnList2 && setOnSet == setOnSet2) {
		cout << left << setw(col_width) << setfill(' ') << "Равенство A-A " << '|';
	}
	else if (setOnNodes != setOnNodes2 && setOnNodeList != setOnNodeList2 && setOnList != setOnList2 && setOnSet != setOnSet2) {
		cout << left << setw(col_width) << setfill(' ') << "Равенство A-B " << '|';
	}
	else {
		return;
	}

	start_time = clock();
	equalitySet(setOnNodes, setOnNodes);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->equalitySet(setOnNodeList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->equalitySet(setOnList);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->equalitySet(setOnSet);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestCombinig(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << "Объединение " << '|';
	start_time = clock();
	CombiningSets(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->CombiningSets(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->CombiningSets(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->CombiningSets(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestIntersection(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << "Пересечение " << '|';
	start_time = clock();
	intersectionOfSets(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->intersectionOfSets(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->intersectionOfSets(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->intersectionOfSets(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestSubstraction(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2, string name)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << name << '|';
	start_time = clock();
	subtraction(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->subtraction(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->subtraction(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->subtraction(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}

void TestSimmetricSubtraction(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet, Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2)
{
	unsigned int start_time;
	unsigned int end_time;
	cout << left << setw(col_width) << setfill(' ') << "Симметричная разность" << '|';
	start_time = clock();
	simmetricSubtraction(setOnNodes, setOnNodes2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnNodeList->simmetricSubtraction(setOnNodeList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnList->simmetricSubtraction(setOnList2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|';
	start_time = clock();
	setOnSet->simmetricSubtraction(setOnSet2);
	end_time = clock();
	cout << fixed << setprecision(6) << setw(col_width) << setfill(' ') << (double(end_time - start_time) / CLOCKS_PER_SEC * 1000) << '|' << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
}
