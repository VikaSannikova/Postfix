#pragma once
#ifndef    TABLEOFELEMENTS_CLASS_H
#define    TABLEOFELEMENTS_CLASS_H
#include "Element.h"
#include <iostream>
#include <string>
using namespace std;
class TableOfElements 
{
private:
	int size;                                  //������������ ������ ������� ���������
	int current_size;                          //������� ������ ������� ���������
public:
	Element* pTableOE;                         //��������� �� �������
	TableOfElements(int _size = 0);            //����������� �������������     
	~TableOfElements();                        //����������   
	int GetCurrentSize();                      //��������� ���������� ��������� � �������  
	string GetName(int number);                //����� ��� ����������� �� ������� � ������� *
	double GetValue(string name);              //����� �������� ���������� ��� ������  
	int GetIndex(string name);                 //����� ������ ���������� ��� ������

	void AddElement(Element element);          //�������� �������
	void AddLine(string name, double value);   //�������� �������     
	void DeleteElement(Element element);       //������� �������
	Element& operator[](int number);                //������ � ��������
};

TableOfElements::TableOfElements(int _size): size (_size), current_size(0)
{
	pTableOE = new Element[size];
}

TableOfElements::~TableOfElements()
{
	delete[]pTableOE;	
	pTableOE = NULL;
}

int TableOfElements::GetCurrentSize()
{
	return current_size;
}

string TableOfElements::GetName(int number)
{
	return pTableOE[number].GetNameE();
}

double TableOfElements::GetValue(string name)
{
	for (int i = 0; i < current_size; i++)
		if (name == pTableOE[i].GetNameE) return pTableOE[i].GetValueE;
	//�������� ��� ��� ��� ������ ���� ������ �������� ���.
}

int TableOfElements::GetIndex(string name)
{
	for (int i = 0; i < current_size; i++)
		if (name == pTableOE[i].GetNameE) return i;
	//�������� ��� ��� ��� ����� ���� ������ �������� ���
}

void TableOfElements::AddElement(Element element)
{
	int k = 0;
	for (int i = 0; i < current_size; i++)
		if (pTableOE[i].GetNameE() == element.GetNameE()) k = 1; //setget??
	if (k == 0)
	{
		pTableOE[current_size].SetName(element.GetNameE);
		pTableOE[current_size].SetValue(element.GetValueE);
	}
}

void TableOfElements::AddLine(string name, double value)
{
	Element element(name, value);
	AddElement(element);
}

void TableOfElements::DeleteElement(Element element)
{
	int number = GetIndex(element.GetNameE());
	if (number >= 0) pTableOE[number] = pTableOE[current_size--];
}

Element &TableOfElements::operator[](int number)  //��� ���� ��� �������
{
	return pTableOE[number];
}

#endif