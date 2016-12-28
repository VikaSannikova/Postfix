//#pragma once
//#ifndef    TABLEOFELEMENTS_CLASS_H
//#define    TABLEOFELEMENTS_CLASS_H
//#include "Element.h"
//#include <iostream>
//#include <string>
//using namespace std;
//class TableOfElements 
//{
//private:
//	int size;                                  //максимальный рахмер таблицы элементов
//	int current_size;                          //текущий размер таблицы элементов
//public:
//	Element* pTableOE;                         //указатель на элемент
//	TableOfElements(int _size = 0);            //конструктор инициализатор     
//	~TableOfElements();                        //деструктор   
//	int GetCurrentSize();                      //посчитать количество элементов в таблице  
//	string GetName(int number);                //взять имя переменнтов из таблицы с номером *
//	double GetValue(string name);              //взять значение переменной под именем  
//	int GetIndex(string name);                 //взять индекс переменной под именем
//
//	void AddElement(Element element);          //добавить элемент
//	void AddLine(string name, double value);   //добавить строчку     
//	void DeleteElement(Element element);       //удалить элемент
//	Element& operator[](int number);                //доступ к элементу
//};
//
//TableOfElements::TableOfElements(int _size): size (_size), current_size(0)
//{
//	pTableOE = new Element[size];
//}
//
//TableOfElements::~TableOfElements()
//{
//	delete[]pTableOE;	
//	pTableOE = NULL;
//}
//
//int TableOfElements::GetCurrentSize()
//{
//	return current_size;
//}
//
//string TableOfElements::GetName(int number)
//{
//	return pTableOE[number].GetNameE();
//}
//
//double TableOfElements::GetValue(string name)
//{
//	for (int i = 0; i < current_size; i++)
//		if (name == pTableOE[i].GetNameE) return pTableOE[i].GetValueE;
//	//подумать над тем что делает если такого элемента нет.
//}
//
//int TableOfElements::GetIndex(string name)
//{
//	for (int i = 0; i < current_size; i++)
//		if (name == pTableOE[i].GetNameE) return i;
//	//подумать над тем что будет если такого элемента нет
//}
//
//void TableOfElements::AddElement(Element element)
//{
//	int k = 0;
//	for (int i = 0; i < current_size; i++)
//		if (pTableOE[i].GetNameE() == element.GetNameE()) k = 1; //setget??
//	if (k == 0)
//	{
//		pTableOE[current_size].SetName(element.GetNameE);
//		pTableOE[current_size].SetValue(element.GetValueE);
//	}
//}
//
//void TableOfElements::AddLine(string name, double value)
//{
//	Element element(name, value);
//	AddElement(element);
//}
//
//void TableOfElements::DeleteElement(Element element)
//{
//	int number = GetIndex(element.GetNameE());
//	if (number >= 0) pTableOE[number] = pTableOE[current_size--];
//}
//
//Element &TableOfElements::operator[](int number)  //для чего эта бякушка
//{
//	return pTableOE[number];
//}
//
//#endif