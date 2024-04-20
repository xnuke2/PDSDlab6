#include "SetOnSet.h"

//создание пустого множества
SetOnSet::SetOnSet() {

}

//проверка пустое ли множество?
bool SetOnSet::setisEmpty()
{
    return Set.empty();
}

//проверка на наличие элемента в множестве
bool SetOnSet::setContains(int numToFind)
{

    return(Set.find(numToFind)!=Set.end());
}

//добавление элемента в начало множества
void SetOnSet::setAddFirst(int num)
{
    Set.insert(num);
}

SetOnSet* SetOnSet::createRandomSet(int length, int min, int max, string type)
{
    SetOnSet* rezult = new SetOnSet();
    if (length <= 0 || max - min < length) {
        return nullptr;
    }
    if (type == "b") {
        while (rezult->powerOfSet() != length) {
            int newNum = rand() % (max - min + 1) + min;
            while (newNum % 10 <= 3) {
                newNum = rand() % (max - min + 1) + min;
            }
            rezult->setAddFirst(newNum);
        }
    }
    if (type == "a") {
        while (rezult->powerOfSet() != length) {
            int newNum = rand() % (max - min + 1) + min;
            while (newNum % 10 >= 8) {
                newNum = rand() % (max - min + 1) + min;
            }
            rezult->setAddFirst(newNum);
        }

    }
    return rezult;
}

SetOnSet* SetOnSet::createRandomSet(int length)
{
    SetOnSet* rezult = new SetOnSet();
    if (length <= 0) {
        return nullptr;
    }
    while (rezult->powerOfSet() != length) {
        int newNum = rand() % (length * 10 + 1);
        rezult->setAddFirst(newNum);
    }
    return rezult;
}

int SetOnSet::powerOfSet()
{
    return Set.size();
}

string SetOnSet::printSet(char separator)
{
    string rezult = "";
    if (setisEmpty()) {
        return rezult;
    }
    set<int>::iterator iter = Set.begin();
    while (iter != Set.end()) {
        rezult = rezult + std::to_string(*iter) + separator;
        iter++;
    }
    rezult.pop_back();
    return rezult;
}

SetOnSet::~SetOnSet()
{
    if (setisEmpty()) {
        return;
    }
    Set.clear();
}

bool SetOnSet::subSet(SetOnSet* a)
{
    if (setisEmpty()) return true;
    if (a->setisEmpty()) return false;
    int sizea = powerOfSet();
    if (sizea > a->powerOfSet()) return false;
    int check = 0;
    set <int>::iterator iter = Set.begin();
    while (iter != Set.end()) {
        if (!a->setContains(*iter))return false;
        iter++;
    }
    return true;
}

bool SetOnSet::equalitySet(SetOnSet* a)
{
    return (subSet(a) && a->subSet(this));
}

SetOnSet* SetOnSet::CombiningSets(SetOnSet* a)
{
    set <int>::iterator iter = Set.begin();
    SetOnSet* rezult = new SetOnSet();
    if(!this->setisEmpty())
    {
        while (iter != Set.end())
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

SetOnSet* SetOnSet::intersectionOfSets(SetOnSet* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetOnSet* rezult = new SetOnSet();
    set <int>::iterator iter = Set.begin();
    while (iter != Set.end())
    {
        if (a->setContains(*iter)) rezult->setAddFirst(*iter);
        iter++;
    }
    return rezult;
}

SetOnSet* SetOnSet::subtraction(SetOnSet* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetOnSet* rezult = new SetOnSet();
    set <int>::iterator iter = Set.begin();
    while (iter != Set.end())
    {
        if (!a->setContains(*iter)) rezult->setAddFirst(*iter);
        iter++;
    }
    return rezult;
}

SetOnSet* SetOnSet::simmetricSubtraction(SetOnSet* a)
{
    return this->CombiningSets(a)->subtraction(this->intersectionOfSets(a));
}
