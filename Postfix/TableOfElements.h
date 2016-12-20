#pragma once
#ifndef    ELEMENT_CLASS_H
#define    ELEMENT_CLASS_H
#include "Element.h"
#include <iostream>
#include <string>
using namespace std;
class TableOfElements 
{
private:
	int size; //максимальный рахмер таблицы
	int current_size; //текущий размер таблицы
public:
	Element* Mem;
	TableOfElements(int _size = 0);
	~TableOfElements();
	int GetCount();
	string GetName(int number);
	double GetValue(string name);
	int GetIndex(string name);

	void AddElement(Element element);
	void AddLine(string, double);
	void DeleteElement(Element element);
	Element& operator[](int n);

};




#endif