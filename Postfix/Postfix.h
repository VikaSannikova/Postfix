#pragma once
#ifndef POLISH_CLASS_H
#define POLISH_CLASS_H
#include <string>
#include "Stack.h"
#include <iostream>
using namespace std;

#define MaxSizeStr 1000

 class Polish
 {
 private:
	 string infix;		//��� ������
	 string postfix;	//��������
	 string *operations;//������ ��������
	 char *prioritet;   //����� ����� �����������
 public:
	 Polish();  //����������� �������������
	 ~Polish();			   //����������
	 void PutInfix(string &str) { infix = str; };
	 string GetPostfix();					  //���������� �������
	 string GetInfix();						  //���������� ������
	 int IsOperation(string &str, int &i);    //������ ������ �������� �� �������, �������� �� �������� 
	 int GetPrioritet(string &str); //������ ��������� ��������
	 bool CINCheck();      //�������� ��������� ��������� ������ �� ������� � ��������
	 void Translator();    //���������� � ��������
	 double GetResult();   //����������� ���������
 };
  
 Polish::Polish()
 {
	 infix = " ";
	 postfix = "null";
	 operations = new string[9];
	 prioritet = new char[9];
		 operations[0] = '+'; prioritet[0] = 1;
		 operations[1] = '-'; prioritet[1] = 1;
		 operations[2] = '*'; prioritet[3] = 2;
		 operations[3] = '/'; prioritet[3] = 2;
		// operations[4] = '^'; prioritet[4] = 3;
		 operations[4] = "sin"; prioritet[4] = 4;
		 operations[5] = "cos"; prioritet[5] = 4;
		 operations[6] = '('; prioritet[6] = 0;
		 operations[7] = ')'; prioritet[7] = 0;
	
 }

 Polish::~Polish()
 {
	 delete[]operations;
	 delete[]prioritet;
 }

 string Polish::GetPostfix()
 {
	 return postfix;
 }

 string Polish::GetInfix()
 {
	 return infix;
 }
 
 int Polish::GetPrioritet(string &str)
 {
	 int i = 0;
	 while (str != operations[i])
		 i++;
	 return prioritet[i];
 }

 int Polish::IsOperation(string &str, int &i )
 {
	 
	 for (int j = 0; j <= 8; j++)
		 if (str[i] == operations[j][0])
		 {
			 if (j == 5)
				 if (str.substr(i, 3) == "sin")
					 return 5;
				 else
					 break;
			 if (j == 6)
				 if (str.substr(i, 6) == "cos")
					 return 6;
				 else
					 break;
			return j;
		 }
	 return -1;
 }

 bool Polish::CINCheck()
 {
	// setlocale(LC_ALL, "Russian");
	// string str = infix;
	// int kol;
	// for (int i = 0; i < str.size(); i++)
	// {
	//	 char cur = str[i];
	//	 if (!(((cur > 39) && (cur < 58)) || ((cur > 64) && (cur < 91)) || ((cur > 96) && (cur < 123))))
	//	 {
	//		 cout << endl << "�� ����� �������� ������ �� " << i + 1 << " �������" << endl;
	//		 cout << "���������� �������: 'a-z', 'A-Z', '0-9' � �������������� ��������" << endl;
	//		 return 0;
	//	 }
	//	 if (cur == 46) str[i] = ',';
	//	 if ((cur == 's') || (cur == 'c'))
	//	 {
	//		 if ((str.substr(i, 3) == "sin") || (str.substr(i, 3) == "cos")) i += 2;
	//		 else
	//		 {
	//			 cout << "������ ����������� �������." << endl;
	//			 return 0;
	//		 }
	//	 }
	// }
	//// infix = str;
	// int i, j;
	// int OperationIndex = IsOperation(str, i = 0);
	// if ((OperationIndex >= 0) && (OperationIndex <= 4) || (OperationIndex == 8))
	// {
	//	 cout << endl << "���� ��������� ���������� � ������������ �������� ��� )" << endl;
	//	 return 0;
	// }

	// for (int i = 0; i < str.size(); i++)
	// {
	//	 OperationIndex = IsOperation(str, i);
	//	 if (OperationIndex != -1) //���� ��� ���������� ��������
	//	 {
	//		 int OperationIndex_1 = IsOperation(str,j=i+1);
	//		 if (OperationIndex <= 4)
	//		 {
	//			 if ((OperationIndex_1 >= 0) && (OperationIndex_1 <= 4) || (OperationIndex_1 == 8))
	//			 {
	//				 cout << "�� ����� ������������ ������ ��" << i + 1 << "�������" << endl << "����� ����.�������� �� ����� ������ +_*/^��� )" << endl;
	//				 return 0;
	//			 }
	//			 if ((OperationIndex_1 >= 0) && (OperationIndex_1 <= 4) && (OperationIndex_1 != 6) || (str[i + 1] == NULL))
	//			 {
	//					 cout << "�� ����� ������������ ������ �� " << i + 1 << "�������" << endl << "����� �������� �� ����� ����������" << endl;
	//					 return 0;
	//			 }
	//			 continue;
	//			 
	//		 }
	//		 //if (OperationIndex == 4) //�����? ���������
	//		 //{
	//			// if (OperationIndex_1 == 4)
	//			// {
	//			//	 cout << "�� ����� ������������ ������ �� " << i + 1 << "�������" << endl << "����� ^ �� ����� ���� ^" << endl;
	//			//	 return 0;
	//			// }
	//			// continue;
	//		 //}

	//		 if (OperationIndex == 5) //sin
	//		 {
	//			 i += 2;
	//			 if (infix[i+1] != '(')
	//			 {
	//				 cout << "�� ����� ������������ ������ ��" << i+1 << "�������" << endl << "����������� �������� ������� sin" << endl;
	//				 return 0;
	//			 }
	//			 continue;
	//		 }
	//		 if (OperationIndex == 6) //cos
	//		 {
	//			 i += 3;
	//			 if (str[i] != '(')
	//			 {
	//				 cout << "�� ����� ������������ ������ ��" << i << "�������" << endl << "����������� �������� ������� cos" << endl;
	//				 return 0;
	//			 }
	//			 continue;
	//		 }
	//		 if (OperationIndex == 7) // (
	//		 {
	//			 if ((OperationIndex_1 >= 0) && (OperationIndex_1 <= 4) || (OperationIndex_1 == 8))
	//			 {
	//				 cout << "�� ����� ������������ ������ ��" << i + 1 << "�������" << endl << "����� ( �� ����� ������ �������� ��� )" << endl;
	//				 return 0;
	//			 }
	//			 kol++;
	//			 continue;
	//		 }

	//		 if (OperationIndex == 8) // )
	//		 {
	//			 if ((OperationIndex_1 >= 0) && (OperationIndex_1 <= 4) || (OperationIndex_1 == 7) || str[i + 1] == NULL)
	//			 {
	//				 kol--;
	//				 continue;
	//			 }
	//			 cout << "�� ����� ������������� ������ ��" << i + 1 << "�������" << endl << "����� ) �� ������ ���� ����������, ������� ��� (" << endl;
	//			 return 0;
	//		 }
	//	 }
	//	 else
	//	 {
	//		 int p = 0;
	//		 int m = i;
	//		 do
	//		 {
	//			 p++;
	//			 m++;
	//			 OperationIndex = IsOperation(str, m);
	//			 if (m == str.size())
	//				 break;
	//		 } while (OperationIndex == -1);
	//		 string Str1 = str.substr(i, p);
	//		 char *Str2 = new char[Str1.size() + 1];
	//		 for (int j = 0; j < Str1.size() + 1; j++)
	//			 Str2[j] = Str1[j];
	//		 double tmp = strtod(Str2, NULL);
	//		 if ((tmp != 0.0))
	//		 {
	//			int check = 0;
	//			 for (p = 0; p < Str1.size(); p++)
	//			 {
	//				 if ((Str2[p] < '0') || (Str2[p] == ',') || (Str2[p] > '9'))
	//				 {
	//					 if (Str2[p] == ',')
	//					 {
	//						 check++;
	//						 continue;
	//					 }
	//					 cout << "������������ ������ ���������� (���������� �� ������ ��������� � �����) �� ������� " << i + 1 << endl;
	//					 return 0;
	//				 }
	//				 if (check > 1)
	//				 {
	//					 cout << "������������ ������ ����� - ������ �������" << endl;;
	//					 return 0;
	//				 }
	//			 }
	//		 }
	//		 i = i + p - 1;
	//		 if (IsOperation(str, m = i + 1) == 7)
	//		 {
	//			 cout << "�������� ������ ���������" << endl;
	//			 cout << "����� ���������� �� ����� ���� ����������� ������" << endl;
	//			 return 0;
	//		 }
	//	 }
	// }
	// if (kol != 0)
	// {
	//	 cout << "������� ������ ������" << endl;
	//	 return 0;
	// }
	// return 1;


string Str = infix;
setlocale(LC_ALL, "Russian");
string Str1;
double tmp;
char* Str2;
int i, j, p, m, check;
int amount = 0;
char now;
int OperationIndex;
int OperationIndexj;
int size = Str.size();
for (i = 0; i < size; i++)
{
	now = Str[i];
	if (!(((now > 39) && (now < 58)) || ((now > 64) && (now < 91)) || ((now > 96) && (now < 123))))
	{
		cout << "����� ������������ ������ �� " << i + 1 << " �������" << endl;
		cout << "���������� ������� 'a-z', 'A-Z', '.', ',', '0-9', '+' , '-' , '*' , '/' " << endl;
		return 0;
	}
	if (now == 46)
		Str[i] = ',';
}
infix = Str;
OperationIndex = IsOperation(Str, i = 0);
if ((OperationIndex > -1) && (OperationIndex < 4) || (OperationIndex == 7))
{
	cout << "�������� ������ ���������" << endl;
	cout << "������ �� ����� ��������� � �������� '+' '-' '*' '/' ')' " << endl;
	return 0;
}
for (i = 0; i < size; i++)
{
	OperationIndex = IsOperation(Str, i);
	if (OperationIndex != -1)
	{
		OperationIndexj = IsOperation(Str, j = i + 1);
		if (OperationIndex < 4)
		{
			if (((OperationIndexj > -1) && (OperationIndexj < 4)) || (OperationIndexj == 7))
			{
				cout << "�������� ������ ���������" << endl;
				cout << "����� �������� �� ����� ���� �������� ��� ����������� ������ �� ������� " << i + 1 << endl;
				return 0;
			}
			if (((OperationIndexj < 4) && (OperationIndexj>-1) && (OperationIndexj != 6) || (Str[i + 1] == 0)))
			{
				cout << "�������� ������ ���������" << endl;
				cout << "����������� ���������� ����� �������� �� ������� " << i + 1 << endl;
				return 0;
			}
			continue;
		}
		if (OperationIndex == 4)
		{
			i += 2;
			if (Str[i + 1] != '(')
			{
				cout << "�������� ������ ���������" << endl;
				cout << "���������� �������� ������� sin �� ������� " << i + 2 << endl;
				return 0;
			}
			continue;
		}
		if (OperationIndex == 5)
		{
			i += 2;
			if (Str[i + 1] != '(')
			{
				cout << "�������� ������ ���������" << endl;
				cout << "���������� �������� ������� cos �� ������� " << i + 2 << endl;
				return 0;
			}
			continue;
		}
		if (OperationIndex == 6)
		{
			if (((OperationIndexj>-1) && (OperationIndexj<4)) || (OperationIndexj == 7))
			{
				cout << "�������� ������ ���������" << endl;
				cout << "����� ����������� ������ �� ����� ���� �������� " << operations[OperationIndexj] << " � ������� " << i + 1 << endl;
				return 0;
			}
			amount++;
			continue;
		}
		if (OperationIndex == 8)
		{
			if ((((OperationIndexj > -1) && (OperationIndexj<4))) || (OperationIndexj == 6))
			{
				amount--;
				continue;
			}
			if (Str[i + 1] == NULL)
			{
				amount--;
				continue;
			}
			cout << "�������� ������ ���������" << endl;
			cout << "����� ����������� ������ �� ������� " << i + 1 << " �� ������ ���� ��������, ����������� ������ ��� �������" << endl;
			return 0;
		}
	}
	else
	{
		p = 0;
		m = i;
		do
		{
			p++;
			m++;
			OperationIndex = IsOperation(Str, m);
			if (m == size)
				break;
		} while (OperationIndex == -1);
		Str1 = Str.substr(i, p);
		Str2 = new char[Str1.size() + 1];
		for (j = 0; j < Str1.size() + 1; j++)
			Str2[j] = Str1[j];
		tmp = strtod(Str2, NULL);
		if ((tmp != 0.0))
		{
			check = 0;
			for (p = 0; p < Str1.size(); p++)
			{
				if ((Str2[p] < '0') || (Str2[p] == ',') || (Str2[p] > '9'))
				{
					if (Str2[p] == ',')
					{
						check++;
						continue;
					}
					cout << "������������ ������ ���������� (���������� �� ������ ��������� � �����) �� ������� " << i + 1 << endl;
					return 0;
				}
				if (check > 1)
				{
					cout << "������������ ������ ����� - ������ �������" << endl;;
					return 0;
				}
			}
		}
		i = i + p - 1;
		if (IsOperation(Str, m = i + 1) == 6)
		{
			cout << "�������� ������ ���������" << endl;
			cout << "����� ���������� �� ����� ���� ����������� ������" << endl;
			return 0;
		}
	}
}
if (amount != 0)
{
	cout << "�������� ������ ���������" << endl;
	cout << "������������ ������ ������" << endl;
	return 0;
}
return 1;
 }

 void Polish::Translator()
 {
	 string token = infix;
	 Stack <string> operations1;
	 string str, output, operationTop;
	 int size = infix.size(), operationIndex, p, m;

	 for (int i = 0; i < size; i++)
	 {
		 if (token[i] == '(')
		 {
			 operations1.Push("(");
			 continue;
		 }
		 if (token[i] == ')')
		 {
			 str = operations1.Pop();
			 while (str != "(")
			 {
				 output += str;
				 str = operations1.Pop();
			 }
			 continue;
		 }

		 operationIndex = IsOperation(token, i);
		 if (operationIndex == -1) //���� ������ �� ��������
		 {
			 p = 0;
			 m = i;
			 do
			 {
				 m++;
				 p++;
				 if (m == size)
					 break;
				 operationIndex = IsOperation(token, m);


			 } while (operationIndex == -1);
			 output += token.substr(i, p) + " ";
			 i = i + p - 1;

		 }
		 else  //���� �������� 
		 {

			 if (operationIndex == 4 || operationIndex == 5) i += 2;
			 if (operations1.IsEmpty())
			 {
				 operations1.Push(operations[operationIndex] );
				 continue;
			 }

			 operationTop = operations1.Watchtop();
			 str = operations[operationIndex];
			 if (operationTop == str)
			 {
				 operations1.Push(str);
				 continue;
			 }

			 if (GetPrioritet(str) >= GetPrioritet(operationTop))
				 operations1.Push(str);
			 else
			 {
				 while (GetPrioritet(str) <= GetPrioritet(operationTop) && !(operations1.IsEmpty()))
				 {
					 output += operations1.Pop();
					 if (operations1.IsEmpty())
					 {
						 continue;
					 }
					 operationTop = operations1.Watchtop();
				 }
				 operations1.Push(str);
			 }
		 }
	 }
	 while (!operations1.IsEmpty())
		 output += operations1.Pop();
	 postfix = output;
 }

 double Polish::GetResult()
 {
	 if (postfix == "Not exist")
	 {
		 cout << "Eror" << endl;
		 return 0;
	 }
	 int OperationIndex;
	 Stack <double> stack;
	 string str;
	 double tmp, var1, var2;
	 int p, size = postfix.size();

	 int i = 0;
	 while (i < size)
	 {
		 OperationIndex = IsOperation(postfix, i);
		 if (OperationIndex == -1)
		 {
			 p = 0;
			 do
			 {
				 p++;
				 if (i + p == size)
					 break;
			 } while (postfix[i + p] != ' ');
			 str = postfix.substr(i, p);
			 tmp = atof(str.c_str());
			 i = i + p;
			 stack.Push(tmp);
			 i++;
			 continue;
		 }
		 else
		 {

			 var1 = stack.Pop();
			 if (OperationIndex == 4)
			 {
				 i = i + 2;
				 stack.Push(sin((var1*3.14159265) / 180));
				 i++;
				 continue;
			 }
			 if (OperationIndex == 5)
			 {
				 i = i + 2;
				 stack.Push(cos((var1*3.14159265) / 180));
				 i++;
				 continue;
			 }
			 var2 = stack.Pop();
			 switch (OperationIndex)
			 {
			 case 0:
			 {
				 var1 += var2;
				 stack.Push(var1);
				 i++;
				 break;
			 }
			 case 1:
			 {
				 var1 = var2 - var1;
				 stack.Push(var1);
				 i++;
				 break;
			 }
			 case 2:
			 {
				 var1 *= var2;
				 stack.Push(var1);
				 i++;
				 break;
			 }
			 case 3:
			 {
				 if (var1 == 0)
				 {
					 cout << "������: � �������� ���������� ���������� ������� �� 0" << endl;
					 return 0;
				 }
				 var1 = var2 / var1;
				 stack.Push(var1);
				 i++;
				 break;
			 }
			 case 8:
			 {
				 var1 = pow(var2, var1);
				 stack.Push(var1);
				 i++;

				 break;
			 }
			 }
		 }
	 }
	 return stack.Pop();
 }

#endif