#pragma once
#ifndef CALCULATOR_CLASS_H
#define	CALCULATOR_CLASS_H
#include "TranslatorToPolish.h"
#include <math.h>

class Calculator
{
private:
	string str;
	TranslatorToPolish* polish;
	Stack<double>*number;
	double result;
public:
	Calculator(string st= "");
	~Calculator();

	string GetString();
	void SetString(string st);
	string GetPolish();
	void Calculate();
	double GetResult();
	double GetValueTable(string name);
	int GetSizeTableOperand();
	void SetElementInTableOperand(string name, double value);
	string GetStringTable(int k);
	void SetElementInTable();
};

Calculator::Calculator(string st) :str(st), result(0)
{
	polish = new TranslatorToPolish(str);
	number = new Stack<double>(20);
}

Calculator::~Calculator()
{
	delete polish;
	delete number;
}

string Calculator::GetString()
{
	return str;
}

void Calculator::SetString(string st)
{
	str = st;
	if (polish != NULL) delete polish;
	polish = new TranslatorToPolish(str);
	result = 0;
}

string Calculator::GetPolish()
{
	string tmp = "";
	for (int i = 0; i < polish->GetLengthPolish(); i++)
		tmp += polish->GetElementPolish(i);
	return tmp;
}

void Calculator::Calculate()
{
	double first, second;
	for (int i = 0; i < polish->GetLengthPolish(); i++)
	{
		string tmp = polish->GetElementPolish(i);
		if (tmp == "+")
		{
			second = number->Pop();
			first = number->Pop();
			number->Push(first+second);
		}

		if (tmp == "-")
		{
			second = number->Pop();
			first = number->Pop();
			number->Push(first - second);
		}

		if (tmp == "*")
		{
			second = number->Pop();
			first = number->Pop();
			number->Push(first*second);
		}

		if (tmp == "/")
		{
			second = number->Pop();
			first = number->Pop();
			if (second != 0)
				number->Push(first / second);
			else
				cout << "Error Zero!";
		}

		if (tmp == "^")
		{
			second = number->Pop();
			first = number->Pop();
			number->Push(pow(first, second));
		}
		//sin cos tg ctg
		else
			number->Push(polish->tableoperand->GetValue(tmp));
	}
	result=number->Pop();
}

void Calculator::SetElementInTable()
{
	for (int i = 0; i < polish->tableoperand->GetCurrentSize(); i++)
	{
		double tmp;
		cout << polish->tableoperand->GetName(i) << "=";
		cin >> tmp;
		SetElementInTableOperand(polish->tableoperand->GetName(i), tmp);
		cout << endl;
	}
}

double Calculator::GetValueTable(string name)
{
	return polish->GetValueTable(name);
}

int Calculator::GetSizeTableOperand()
{
	return Calculator::polish->tableoperand->GetCurrentSize();
}

string Calculator::GetStringTable(int k)
{
	return polish->tableoperand->GetName(k);
}

void Calculator::SetElementInTableOperand(string name, double value)
{
	polish->tableoperand->AddLine(name, value);
}
#endif