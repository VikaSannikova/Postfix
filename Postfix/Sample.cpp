#include <iostream>
#include <string>
#include "Postfix.h"
using namespace std;


int main()
{
	string expression;
	double res;
	Polish postfix;
	setlocale(LC_ALL, "Russian");
	cout << "Введите арифметическое выражение: ";
	cin >> expression;
	postfix.PutInfix(expression);
	if (postfix.CINCheck())
	{
		cout << "Инфиксная запись арифметического выражения: " << postfix.GetInfix() << endl;
		postfix.Translator();
		cout << "Постфиксная запись фрифметического выражения: " << postfix.GetPostfix() << endl;
		res = postfix.GetResult();
		cout <<"Результат вычисления постфиксного выражения: "<< res << endl;
	}
	system("pause");
	return 0;
}
