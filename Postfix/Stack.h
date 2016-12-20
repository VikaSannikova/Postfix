#pragma once
#ifndef __STACH_H__
#define __STACK_H__
#define MemSize 100

template <class ValType>
class Stack
{
private: ValType *Pmem;
		 int size;
		 int head;
public: Stack();
		Stack(int n);
		Stack(const Stack &st);
		~Stack();

		bool IsEmpty();
		bool IsFull();
		void Push(ValType Elem);
		ValType Pop();
		ValType WatchTop();

		int GetSize() const { return Size; }
		int GetTop() { return Top; }
		void SetSize(int n);


		//Stack& operator=(const Stack &st);
		//bool operator==(const Stack &st) const;
		//bool operator!=(const Stack &st) const;
};

template <class ValType> //конструктор инициализатор
Stack<ValType>::Stack()
{
	pMem = new ValType[MemSize];
	Size = MemSize;
	Top = -1;
}

template <class ValType> //конструктор инициализатор для новой длины
Stack<ValType>::Stack(int n)
{
	if (n < 0) throw 'Neg';
	pMem = new ValType[n];
	Size = n;
	Top = -1;
}

template <class ValType> //деструктор
Stack<ValType>::~Stack()
{
	delete[]pMem;
}

template <class ValType>  //конструктор копирования
Stack<ValType>::Stack(const Stack &st)
{
	Size = st.Size;
	Top = st.Top;
	pMem = new ValType[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = st.pMem[i];
}

template <class ValType> //проверка на пустоту
bool Stack<ValType>::IsEmpty()
{
	if (Top == -1)
		return true;
	else
		return false;
}

template <class ValType> //проверка на полноту
bool Stack<ValType>::IsFull()
{
	if (Top == (Size - 1))
		return true;
	else
		return false;
}

template<class ValType> //добавление элемента
void Stack<ValType>::Push(ValType elem)
{
	if (this->IsFull) throw 'Full';
	else
		pMem[++Top] = elem;
}

template <class ValType> //удаление элемента 
ValType Stack<ValType>::Pop()
{
	//if (this->IsEmpty) throw 'Empty';
	//else
		return pMem[Top--];
}

template <class ValType> //установление стеку заданной длины, хвост заполняется 0 или обрезается
void Stack<ValType>::SetSize(int n)
{
	//исключения на размер негативный и меньше топа

	ValType *s = new ValType[Top + 1];
	for (int i = 0; i < Top + 1; i++)
	{
		s[i] = pMem[i];
	}
	Size = n;
	delete[]pMem;
	pMem = new ValType[Size];
	for (int i = 0; i < Top + 1; i++)
	{
		pMem[i] = s[i];
	}
	for (int i = Top + 1; i < Size; i++)
	{
		pMem[i] = 0;
	}
}

template <class ValType> //просмотр верхушки без удаления
ValType Stack<ValType>::WatchTop()
{
	//if (Top == -1)
	//{
	//	//throw ("Стэк пуст!");
	//}
return pMem[Top];
}

#endif