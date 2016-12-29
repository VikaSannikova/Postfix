#pragma once
#ifndef __STACH_H__
#define __STACK_H__
#define MemSize 100

template <class ValType>
class Stack
{
private: ValType *pMem;
		 int size;   //размер стека
		 int top;    //вершина стека
public:
		Stack(const int n=MemSize);             //конструктор инициализатор
		~Stack();								//деструктор

		bool IsEmpty();           //проверка на пустоту
		bool IsFull();            //проверка на полноту
		void Push(ValType Elem);  //положить в стек элемемнт
		ValType Pop();            //извлечь элемент из стека + удалить его
		ValType Watchtop();       //посмотреть верхний элемент

		int GetSize() const { return Size; }   //размер стека
		//void SetSize(int n);                   //установить размер


		//Stack& operator=(const Stack &st);
		//bool operator==(const Stack &st) const;
		//bool operator!=(const Stack &st) const;
};

template <class ValType> //конструктор инициализатор для новой длины
Stack<ValType>::Stack(const int n)
{
	if (( n < 0)||(n>MemSize)) throw 'Neg';
	pMem = new ValType[n];
	size = n;
	top = -1;
}

template <class ValType> //деструктор
Stack<ValType>::~Stack()
{
	delete[]pMem;
}

template <class ValType> //проверка на пустоту
bool Stack<ValType>::IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template <class ValType> //проверка на полноту
bool Stack<ValType>::IsFull()
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

template<class ValType> //добавление элемента
void Stack<ValType>::Push(ValType elem)
{
	if (IsFull()==true) throw 'Full';
	else
		pMem[++top] = elem;
}

template <class ValType> //удаление элемента 
ValType Stack<ValType>::Pop()
{
	if (IsEmpty()) throw 'Emp';
	else
		return pMem[top--];
}

//template <class ValType> //установление стеку заданной длины, хвост заполняется 0 или обрезается
//void Stack<ValType>::SetSize(int n)
//{
//	//исключения на размер негативный и меньше топа
//
//	ValType *s = new ValType[top + 1];
//	for (int i = 0; i < top + 1; i++)
//	{
//		s[i] = pMem[i];
//	}
//	Size = n;
//	delete[]pMem;
//	pMem = new ValType[Size];
//	for (int i = 0; i < top + 1; i++)
//	{
//		pMem[i] = s[i];
//	}
//	for (int i = top + 1; i < Size; i++)
//	{
//		pMem[i] = 0;
//	}
//}

template <class ValType> //просмотр верхушки без удаления
ValType Stack<ValType>::Watchtop()
{
return pMem[top];
}

#endif