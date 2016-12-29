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
	string infix;		//íàø èíôèêñ
	string postfix;	//ïîñòôèêñ
	string *operations;//ñòðîêà îïåðàöèé
	char *prioritet;   //ñòîêà ÷àðîâ ïðèîðèòåòîâ
public:
	Polish();  //êîíñòðóêòîð èíèöèàëèçîòîð
	~Polish();			   //äåñòðóêòîð
	void PutInfix(string &str) { infix = str; };
	string GetPostfix();					  //âîçâðàùàåò ïîñôèêñ
	string GetInfix();						  //âîçâðàùàåò èíôèêñ
	int IsOperation(string &str, int &i);    //âûäàåò íóæíóþ îïåðàöèþ èç òàáëèöû, ïðîâåðêà íà îïåðàöèþ 
	int GetPrioritet(string &str); //âûäàåò ïðèîðèòåò îïåðàöèè
	bool CINCheck();      //ïðîâåðêà ââåäåííîé èíôèêñíîé çàïèñè íà ñèìâîëû è îïåðàöèè
	void Translator();    //ïåðåâîä÷èê â ïîñòôèêñ
	double GetResult();   //âûñ÷èòûâàåò ðåçóëüòàò
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
	operations[6] = '('; prioritet[6] = 6;
	operations[7] = ')'; prioritet[7] = 6;

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

int Polish::IsOperation(string &str, int &i)
{
	for (int j = 0; j < 8; j++)
		if (str[i] == operations[j][0])
		{
			if (j == 4)
				if (str.substr(i, 3) == "sin")
					return 4;
				else
					break;
			if (j == 5)
				if (str.substr(i, 3) == "cos")
					return 5;
			if (str[i]=operations[j][0]) 
				return j;
		}
	return -1;
}

bool Polish::CINCheck()
{

	string Str = infix;  //инфикс
	setlocale(LC_ALL, "Russian");
	string Str1;     //строка в которую
	double tmp;      
	char* Str2;
	int i, j, p, m, check;
	int amount = 0;  //для количества скобок
	char now;        //текущий элемент строки
	int OperationIndex;    //индекс первой операции
	int OperationIndexj;   //индекс второй операции
	int size = Str.size();  //размер инфикса



	for (i = 0; i < size; i++)
	{
		now = Str[i];  //текщий элемент
		if (!(((now > 39) && (now < 58)) || ((now > 64) && (now < 91)) || ((now > 96) && (now < 123))))   //если недопустимый символ-ошибка
		{
			cout << "Неверный символ на  " << i + 1 << " позиции" << endl;
			cout << "Допустимые символы 'a-z', 'A-Z', '.', ',', '0-9', '+' , '-' , '*' , '/' " << endl;
			return 0;
		}
		if (now == 46)   //если точка то заменяем запятой
			Str[i] = ',';
	}
	infix = Str; //измененный инфикс с запятыми
	OperationIndex = IsOperation(Str, i = 0);  //берем индекс первого символа
	if ((OperationIndex > -1) && (OperationIndex < 4)&&(OperationIndex!=1) || (OperationIndex == 7))  //если это +-*\) то все фу. можно начать с минуса
	{
		cout << "Неверное выражение" << endl;
		cout << "Арифметическое выражение не может начинаться с '+' '-' '*' '/' ')' " << endl;
		return 0;
	}
	for (i = 0; i < size; i++)  //если все ок
	{
		OperationIndex = IsOperation(Str, i); //берем индекс символа на итом места
		if (OperationIndex != -1)  //если это операция
		{
			OperationIndexj = IsOperation(Str, j = i + 1); //берем индекс следующего символа
			if (OperationIndex < 4)  //если индекс первый  =-*\
		
			{
				if ((OperationIndexj > -1) && (OperationIndexj < 4)&&(OperationIndexj!=1) || (OperationIndexj == 7))  //если он -+*\или) может идти минус
				{
					cout << "Неверная запись выражения" << endl;
					cout << "После операции не может быль операции или ) " << i + 1 << endl;
					return 0;
				}
				if (((OperationIndexj < 4) && (OperationIndexj > -1) && (OperationIndexj != 6) || (Str[i + 1] == 0))) //если второй индекс +-*\ и не ( или нет следующего элемента
				{
					cout << "Неверная запись выражения" << endl;
					cout << "После операции нет переменной на " << i + 1 << " позиции" << endl;
					return 0;
				}
				continue;
			}
			if (OperationIndex == 4) //если это синус
			{
				i += 3;
				if (Str[i] != '(')
				{
					cout << "Неверная запись выражения" << endl;
					cout << "Нет параметра функции sin на " << i + 1 << endl;
					return 0;
				}
				amount++; //добавляем скубку
				continue;
			}
			if (OperationIndex == 5) //если это косинус
			{
				i += 3;
				if (Str[i] != '(')
				{
					cout << "Неверная запись выражения" << endl;
					cout << "нет параметра функции cos на " << i + 1 << endl;
					return 0;
				}
				amount++; //добавляем скобку
				continue;
			}
			if (OperationIndex == 6)  //если это (
			{
				if ((OperationIndexj > -1) && (OperationIndexj < 4)&&(OperationIndexj!=1) || (OperationIndexj == 7)) //если следующий элемент +-*\ или )
				{
					cout << "Неверная запись выражения" << endl;
					cout << "После закрывающейся скобки не может быть операции " << operations[OperationIndexj] << " на позиции " << i + 2 << endl;
					return 0;
					
				}
				amount++;
				continue;
			}
			if (OperationIndex == 7) //если это )
			{
				if ((OperationIndexj > -1) && (OperationIndexj < 4) || (OperationIndexj == 7)) ///если это +-*\)
				{
					amount--;
					continue;
				}
				if (Str[i + 1] == NULL)
				{
					amount--;
					continue;
				}
				else
				{
					cout << "Неверная запись выражения" << endl;
					cout << "После закрывающией скобки стоит операнд на " << i + 1 << " позиции" << endl;
					return 0;
				}
			}
		}
			else   //если это операнд
			{
				p = 0;
				m = i;
				do
				{
					p++;
					m++;
					OperationIndex = IsOperation(Str, m); //смотрим что за символ следующий
					if (m == size)
						break;
				} while (OperationIndex == -1); //делаем пока это символ
				Str1 = Str.substr(i, p);    //записываем в строку то что у нас было до первой операции
				Str2 = new char[Str1.size() + 1];  //создаем массив чаров с длиной на 1 больший записанной строки
				for (j = 0; j < Str1.size() + 1; j++)
					Str2[j] = Str1[j]; //заполняем массив чаров символами из 1 строки
				tmp = strtod(Str2, NULL);   //преобразуем строку 2 в дабл
				//if ((tmp != 0.0)) //если удалось преобразовать
					//check = 0;
					//for (p = 0; p < Str1.size(); p++)   
					//{
					//	if ((Str2[p] < '0') || (Str2[p] == ',') || (Str2[p] > '9'))
					//	{
					//		if (Str2[p] == ',')
					//		{
					//			check++;
					//			continue;
					//		}
					//		cout << "Неправильная запись. Переменная не должна начинаться с цифры на позиции: " << i + 1 << endl; //?
					//		return 0;
					//	}
					//	if (check > 1)
					//	{
					//		cout << "Неправильная запись. Лишняя запятая" << endl;;
					//		return 0;
					//	}
					//}

				//если там буковки
				i = i + p - 1; //переставляем i на операцию до которой считали
				if (IsOperation(Str, m = i + 1) == 6) //если это (
				{
					cout << "Неверная запись  выражения" << endl;
					cout << "После переменной не может стоять (" << endl;
					return 0;
				}
			}
		}
		if (amount != 0) //если количество скобок не равно
		{
			cout << "Неверная запись выражения" << endl;
			cout << "Число кобок не совпадает." << endl;
			return 0;
		}
		return 1;
}

void Polish::Translator()
{
	string token = infix; //
	Stack <string> operations1; //стэк операций
	string str, output, operationTop;
	int size = infix.size(), operationIndex, p, m, j;


	for (int i = 0; i < size; i++) //идем до конца инфикса
	{
		if (token[i] == '(') //если откр скобка кидаем ее в стек
		{
			operations1.Push("(");
			continue;
		}
		if (token[i] == ')') //если закр скобка
		{
			str = operations1.Pop();
			while (str != "(") //пока не встретим откр скобку все вырисыдваем
			{
				output += str;
				str = operations1.Pop(); //записываем в строчку наши операции
			}
			continue;
		}

		operationIndex = IsOperation(token, i); //берем индекс опрации
		if (operationIndex == -1) //если это символ
		{
			p = 0;
			m = i;
			do
			{
				m++;
				p++; //считаем количесво символов
				if (m == size) //если размер то аут
					break;
				operationIndex = IsOperation(token, m); //берем индакс следующего элемента


			} while (operationIndex == -1); //пока это символ
			output += token.substr(i, p) + " "; //к выходу приделываем наши символы
			i = i + p - 1;

		}
		else  //если это операция
		{
			/*if (token[0] == '-') 
			{
				for (int i = size-1; i >= 0; i--)
					token[i + 1] = token[i];
				token[0] = '0';
			}

			if((i>0)&&(operationIndex==1)&&(IsOperation(token, j = i - 1)==6))
			{
				token.push_back('0');
			}*/
			if (operationIndex == 4 || operationIndex == 5) i += 2; //если это синус или косинус то добавляем 2
			if (operations1.IsEmpty()) //если стек пустой
			{
				operations1.Push(operations[operationIndex]); //добавляем в него операции
				continue;
			}

			operationTop = operations1.Watchtop(); //смотрим вершинку стека
			str = operations[operationIndex];
			if (operationTop == str)
			{
				operations1.Push(str);
				continue;
			}

			if (GetPrioritet(str) <= GetPrioritet(operationTop)) //<=
				operations1.Push(str);
			else
			{
				while (GetPrioritet(str) >= GetPrioritet(operationTop) && !(operations1.IsEmpty())) //=>
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
	if (postfix == "null") //если постфикс еще не создавали
	{
		cout << "Постфикс еще не создан" << endl; //
		return 0;
	}
	int OperationIndex; //индекс операции
	Stack <double> stack; //стек числе
	string str;  
	double tmp, var1, var2;
	int p, size = postfix.size();

	int i = 0;
	while (i < size)
	{
		OperationIndex = IsOperation(postfix, i); //берем индекс первой переменной
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
					cout << "Делить на 0 плохо. фуфуфу" << endl;
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