#include <iostream>
#include <string>
#include "Postfix.h"
using namespace std;


//int main()
//{
//	string expression;
//	double res;
//
//	setlocale(LC_ALL, "Russian");
//	cout << "                ������������ ������ �3" << endl;
//	cout << "          ���������� �������������� ���������" << endl;
//	cout << endl;
//	cout << "������� ��������������� ���������" << endl;
//	cin >> expression;
//	Polish Polish(expression);
//	if (Polish.CINCheck())
//	{
//		Polish.Translator();
//		cout << "�������������� ���������: " << Polish.GetInfix() << endl;
//		cout << "����������� �����: " << Polish.GetPostfix() << endl;
//		res = Polish.GetResult();
//		cout << "�����:  " << res << endl;
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	string expression;
	double res;
	Polish postfix;
	setlocale(LC_ALL, "Russian");
	cout << "������� �������������� ���������: ";
	cin >> expression;
	postfix.PutInfix(expression);
	if (postfix.CINCheck())
	{
		cout << "�������������� ���������: " << postfix.GetInfix() << endl;
		postfix.Translator();
		cout << "����������� �����: " << postfix.GetPostfix() << endl;
		res = postfix.GetResult();
		cout <<"���������: "<< res << endl;
	}
	else
		cout << "�������� ������ ���������" << endl;
	system("pause");
	return 0;
}
