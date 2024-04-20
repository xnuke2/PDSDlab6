
#include <iostream>
#include"Tests.h"
using namespace std;


int main() {
	//keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	setlocale(LC_ALL, "ru");
	int SetSize1;
	int SetSize2;
	unsigned int start_time;
	unsigned int end_time;
	const int col_width = 23;
	string headers[] = { "", "Односвязный список", "Класс список", "List", "Set" };
	cout << "Введите размер первого множества (от 1000 до 5000):";
	cin >> SetSize1;
	while (SetSize1 > 5000 || SetSize1 < 1000) {
		cout << "Неверный размер" << endl;
		cout << "Введите размер первого множества (от 1000 до 5000): ";
		cin >> SetSize1;
	}
	cout << "Введите размер второго множества (от 1000 до 5000):";
	cin >> SetSize2;
	while (SetSize2 > 5000 || SetSize2 < 1000) {
		cout << "Неверный размер" << endl;
		cout << "Введите размер первого множества (от 1000 до 5000): ";
		cin >> SetSize2;
	}
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	for (int i = 0; i < end(headers) - begin(headers); i++) {
		cout << left << setw(col_width) << setfill(' ') << (headers[i]) << "|";
	}
	cout << endl;
	cout << setfill('-') << setw((col_width + 1) * 5) << "" << endl;
	Element* setOnNodes = createRandomSet(SetSize1);
	SetClass* setOnNodeList = SetClass::createRandomSet(SetSize1);
	SetOnList* setOnList = SetOnList::createRandomSet(SetSize1);;
	SetOnSet* setOnSet = SetOnSet::createRandomSet(SetSize1);
	Element* setOnNodes2 = createRandomSet(SetSize2);
	SetClass* setOnNodeList2 = SetClass::createRandomSet(SetSize2);
	SetOnList* setOnList2 = SetOnList::createRandomSet(SetSize2);
	SetOnSet* setOnSet2 = SetOnSet::createRandomSet(SetSize2);
	//Создание множества
	TestCreate(col_width, SetSize1);
	//Мощность множества
	TestPower(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet);
	//Подмножество A-A
	TestSubSet(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes, setOnNodeList, setOnList, setOnSet);
	//Подмножество B-A
	TestSubSet(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2);
	//Равенство А-А
	TestEquality(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes, setOnNodeList, setOnList, setOnSet);
	//Равенство B-A
	TestEquality(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2);
	//Объединение множеств
	TestCombinig(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2);
	//Пересечение множеств
	TestIntersection(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2);
	//Разность A-B
	TestSubstraction(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2,"Разность A-B");
	//Разность B-A
	TestSubstraction(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2, "Разность B-A");
	//Симметричная разность
	TestSimmetricSubtraction(col_width, setOnNodes, setOnNodeList, setOnList, setOnSet, setOnNodes2, setOnNodeList2, setOnList2, setOnSet2);
}



