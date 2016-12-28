//#pragma once
//#ifndef TRANSLATORTOPOLISH_CLASS_H
//#define TRANSLATORTOPOLISH_CLASS_H
//#include"Stack.h"
//#include"TableOfElements.h"
//
//class TranslatorToPolish
//{
//private:
//	int polishlength;									        //длина польской записи
//	int numberofoperand;							            //количество операндов в польскоинфверсной записи
//	string *polish;							    	            //сама польская запись
//	Stack <Element>*operstack;							        //стек операций(рельсы-паровозик)
//	TableOfElements *opertable;									//таблица операций и их приоритетов 
//	void MakeTable(int tablesize = 5);							//сделать таблицу приоритетов
//	void WorkOperation(string Lex, int prioritet);				//обработка операций
//	void WorkOperand(string *Lex);								//обработка операндов
//	void MakePolish(string st = "");                            //создание польской записи
//public:
//	string GetPostfix(return polish);
//	TableOfElements *tableoperand;							    //таблица операндов
//	TranslatorToPolish(string st = "");                         //конструктор инициализатор
//	~TranslatorToPolish();                                      //деструктор
//	int GetLengthPolish();                                        //длина польской записи
//	string GetElementPolish(int _elem);                         //достать имя элмента полиза
//	double GetValueTable(string _Name);                         //достать значение элемента
//	void StringToArray(string st, string zn, string *w, int &k); //....
//};
//
//TranslatorToPolish::TranslatorToPolish(string st = "")
//{
//	operstack = new Stack <Element>(st.length());
//	MakeTable();
//	MakePolish(st);
//}
//
//TranslatorToPolish::~TranslatorToPolish()
//{
//	delete tableoperand;
//	delete opertable;
//	delete[]polish;
//}
//
//int TranslatorToPolish::GetLengthPolish()
//{
//	return polishlength;
//}
//
//string TranslatorToPolish::GetElementPolish(int elem)
//{
//	return polish[elem];
//}
//
//double TranslatorToPolish::GetValueTable(string name)
//{
//	return tableoperand->GetValue(name);
//}
//
//void TranslatorToPolish::StringToArray(string st, string zn, string *w, int &k)
//{
//	string t = st + '_';
//	k = 0;
//	int length = st.length();
//	for (int i = 0; i < length; i++)
//	{
//		if (zn.find(t[i]) == -1)
//			w[k] = w[k] + t[i];
//		else
//		{
//			if (t[i] == '_')
//			{
//				if (w[k] != "")
//				{
//					if (k < length)
//						w[++k] = "";
//				}
//			}
//			else
//			{
//				if (w[k] != "")
//					w[++k] = t[i];
//				else
//					w[k] = t[i];
//				w[++k] = "";
//			}
//		}
//	}
//}
//
//void TranslatorToPolish::MakeTable(int tablesize = 7)
//{
//	opertable = new TableOfElements(tablesize);
//	opertable->AddLine("+", 1);
//	opertable->AddLine("-", 1);
//	opertable->AddLine("*", 2);
//	opertable->AddLine("/", 2);
//	opertable->AddLine("^", 3);
//	//opertable->AddLine("sin", 4);
//	//opertable->AddLine("cos", 4);
//	//opertable->AddLine("tg", 4);
//}
//
//void TranslatorToPolish::WorkOperation(string Lex, int prioritet)
//{
//	while ((TranslatorToPolish::operstack->IsEmpty() == false) && (TranslatorToPolish::operstack->WatchTop().GetValueE() >= prioritet))
//		polish[polishlength++] = TranslatorToPolish::operstack->Pop().GetNameE();
//	TranslatorToPolish::operstack->Push(Element(Lex, prioritet));
//}
//
//void TranslatorToPolish::WorkOperand(string *Lex)
//{
//	for (int i = 0; i < 1; i++)
//	{
//		polish[++polishlength] = Lex[i];
//		if ((atof(Lex[i].c_str()) <= 0) || (atof(Lex[i].c_str()) > 0))
//			tableoperand->AddLine(*Lex, atof(Lex[i].c_str()));
//		else
//			tableoperand->AddLine(*Lex, 0);
//    }
//}
//
//void TranslatorToPolish::MakePolish(string st)
//{
//	string *Lex = new string[st.length()];
//	int Lexsize = 0;
//	string zn = "+-/*^()";
//	//delstrwithzn(st,zn,Lex,Lexsize);
//	polish = new string[Lexsize];
//	polishlength = 0;
//	tableoperand = new TableOfElements(Lexsize / 2 + 1);
//	int prioritet = 0;
//	for (int i = 0; i < Lexsize; i++)
//	{
//		if (Lex[i] == "(")
//			operstack->Push(Element("(", 0));
//		else
//			if (Lex[i] == ")")
//			{
//				while (operstack->WatchTop().GetNameE() != "(")
//					polish[polishlength++] = operstack->Pop().GetNameE();
//				operstack->Pop().GetNameE();
//			}
//			else 
//			{
//				prioritet = opertable->GetValue(Lex[i]);
//				if (prioritet >= 1 && prioritet <= 3) //4
//					WorkOperation(Lex[i], prioritet);
//				else
//					WorkOperand(Lex);
//			}
//	}
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#endif