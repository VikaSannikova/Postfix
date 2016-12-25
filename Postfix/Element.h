#pragma once
#ifndef    ELEMENT_CLASS_H
#define    ELEMENT_CLASS_H
#include <string> 
using namespace std;
class Element
{
private:
	string name;              //имя
	double value;             //значение

public:
	Element(string _name = "", double _value = 0)  {name = _name; value = _value;} //конструктор инициализатор
	string GetNameE() {return name;}                                                //получить имя переменной
	float GetValueE() {return value;}                                               //получить значение переменной
void SetValue(double _value) {value = _value;}                                     //задать значение переменной

};
#endif