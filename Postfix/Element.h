#pragma once
#ifndef    ELEMENT_CLASS_H
#define    ELEMENT_CLASS_H
#include <string> 
using namespace std;
class Element
{
private:
	string name;              //���
	double value;             //��������

public:
	Element(string _name = "", double _value = 0)  {name = _name; value = _value;} //����������� �������������
	string GetNameE() {return name;}                                                //�������� ��� ����������
	float GetValueE() {return value;}                                               //�������� �������� ����������
    void SetValue(double _value) {value = _value;}                                     //������ �������� ����������
	void SetName(string nm) { name = name; }										//������ ��� ����������
};
#endif