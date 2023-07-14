#include <iostream>
#include <cmath>
#include "Tlist.h"
using namespace std;
/*
Разработать шаблон списка, реализовав групповые добавление, удаление и замену элементов.
Группа представляется диапазоном итераторов.
Реализовать методы поиска элементов.
Добавить методы комбинирова¬ния списков как объединение и пересечение множеств.
*/

int main()
{
	TList<bool> listbool;
	TList<int> list;
	list.push_back(1);
	list.push_front(2);
	list.push_back(3);
	list.push_front(4);
	list.print();
	cout << list << endl;
	list.pop_back();
	list.pop_front();
	list.print();
	list.clear();
	list.print();
	list.print();
	list.print();
	TList<int> list2;
	list2.push_back(1);
	list2.push_front(2);
	list2.push_back(3);
	list2.push_front(4);
	list2.print();
	list.merge(list2);
	list.print();
	list2.print();
	list2.push_back(1);
	list2.push_front(2);
	list2.push_back(3);
	list2.intersection(list);
	list2.print();
	auto g = list.begin();
	g++;
	list.replace(g, 5);
	list.print();
}