#pragma once
#include"SetHead.h"
#include "SetOnList.h"
#include "SetOnSet.h"
#include "OOPSet.h"
#include <windows.h>
#include <iomanip>
using namespace std;

void TestCreate(int col_width, int SetSize1);
void TestPower(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet);
void TestSubSet(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2);
void TestEquality(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2);
void TestCombinig(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2);
void TestIntersection(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2);
void TestSubstraction(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2, string name);
void TestSimmetricSubtraction(int col_width, Element* setOnNodes, SetClass* setOnNodeList, SetOnList* setOnList, SetOnSet* setOnSet,
	Element* setOnNodes2, SetClass* setOnNodeList2, SetOnList* setOnList2, SetOnSet* setOnSet2);