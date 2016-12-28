#include <iostream>
#include <string>
#include "Postfix.h"
using namespace std;


int main()
{
	string expression;
	double res;

	setlocale(LC_ALL, "Russian");
	cout << "                Лабораторная работа №3" << endl;
	cout << "          Вычисление арифметических выражений" << endl;
	cout << endl;
	cout << "Введите африфмитическое выражение" << endl;
	cin >> expression;
	Polish Polish(expression);
	if (Polish.CINCheck())
	{
		Polish.Translator();
		cout << "Арифметическое выражение: " << Polish.GetInfix() << endl;
		cout << "Постфиксная форма: " << Polish.GetPostfix() << endl;
		res = Polish.GetResult();
		cout << "Ответ:  " << res << endl;
	}
	system("pause");
	return 0;
}


