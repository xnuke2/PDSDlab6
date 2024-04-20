#include "SetOnList.h"




//проверка пустое ли множество?
bool SetOnList::setisEmpty()
{
    return List.empty();
}

//проверка на наличие элемента в множестве
bool SetOnList::setContains(int numToFind)
{
    if (setisEmpty()) {
        return false;
    }
    return std::find(List.begin(), List.end(), numToFind) != List.end();

}

//добавление элемента в начало множества
bool SetOnList::setAddFirst(int num)
{
    if (setContains(num)) {
        return false;
    }
    List.push_front(num);
    return true;
}

SetOnList* SetOnList::createRandomSet(int length, int min, int max, string type)
{
    SetOnList* rezult = new SetOnList();
    if (length <= 0 || max - min < length) {
        return nullptr;
    }
    if (type == "b") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while (newNum % 10 <= 3) {
                newNum = rand() % (max - min + 1) + min;
            }
            if (!rezult->setAddFirst(newNum)) {
                i--;
            }
        }
    }
    if (type == "a") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while ( newNum % 10 >= 8) {
                newNum = rand() % (max - min + 1) + min;
            }
            if (!rezult->setAddFirst(newNum)) {
                i--;
            }
        }
    }
    return rezult;
}

SetOnList* SetOnList::createRandomSet(int length)
{
    SetOnList* rezult = new SetOnList();
    if (length <= 0) {
        return nullptr;
    }
    for (int i = 0; i < length; i++) {
        int newNum = rand() % (length * 10 + 1);
        if (!rezult->setAddFirst(newNum))i--;
    }
    return rezult;
}

int SetOnList::powerOfSet()
{

    return List.size();
}

string SetOnList::printSet(char separator)
{
    string rezult = "";
    if (setisEmpty()) {
        return rezult;
    }
    list <int>::iterator iter = List.begin();
    while (iter != List.end()) {  
        rezult = rezult + std::to_string(*iter) + separator;
        iter++;
    }
    rezult.pop_back();
    return rezult;
}

SetOnList::~SetOnList()
{
    List.clear();
}

bool SetOnList::subSet(SetOnList* a)
{
    if (setisEmpty()) return true;
    if (a->setisEmpty()) return false;
    int sizea = powerOfSet();
    if (sizea > a->powerOfSet()) return false;
    list <int>::iterator iter = List.begin();
    while (iter!=List.end()) {
        if (!a->setContains(*iter))return false;
        iter++;
    }
    return true;
}

bool SetOnList::equalitySet(SetOnList* a)
{
    return (subSet(a) && a->subSet(this));
}

SetOnList* SetOnList::CombiningSets(SetOnList* a)
{
    list <int>::iterator iter;
    SetOnList* rezult = new SetOnList();
    if(!this->setisEmpty())
    {
        iter = List.begin();
        while (iter != List.end())
        {
            rezult->setAddFirst(*iter);
            iter++;
        }
    }
    if(!a->setisEmpty())
    {
        iter = a->begin();
        while (iter != a->end())
        {
            rezult->setAddFirst(*iter);
            iter++;
        }
    }
    return rezult;
}

SetOnList* SetOnList::intersectionOfSets(SetOnList* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetOnList* rezult = new SetOnList();
    list <int>::iterator iter = List.begin();
    while (iter!=List.end())
    {
        if (a->setContains(*iter)) rezult->setAddFirst(*iter);
        iter++;
    }
    return rezult;
}

SetOnList* SetOnList::subtraction(SetOnList* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetOnList* rezult = new SetOnList();
    list <int>::iterator iter = List.begin();
    while (iter != List.end())
    {
        if (!a->setContains(*iter)) rezult->setAddFirst(*iter);
        iter++;
    }
    return rezult;
}

SetOnList* SetOnList::simmetricSubtraction(SetOnList* a)
{
    return this->CombiningSets(a)->subtraction(this->intersectionOfSets(a));
}



