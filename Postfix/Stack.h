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

template <class ValType> //����������� �������������
Stack<ValType>::Stack()
{
	pMem = new ValType[MemSize];
	Size = MemSize;
	Top = -1;
}

template <class ValType> //����������� ������������� ��� ����� �����
Stack<ValType>::Stack(int n)
{
	if (n < 0) throw 'Neg';
	pMem = new ValType[n];
	Size = n;
	Top = -1;
}

template <class ValType> //����������
Stack<ValType>::~Stack()
{
	delete[]pMem;
}

template <class ValType>  //����������� �����������
Stack<ValType>::Stack(const Stack &st)
{
	Size = st.Size;
	Top = st.Top;
	pMem = new ValType[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = st.pMem[i];
}

template <class ValType> //�������� �� �������
bool Stack<ValType>::IsEmpty()
{
	if (Top == -1)
		return true;
	else
		return false;
}

template <class ValType> //�������� �� �������
bool Stack<ValType>::IsFull()
{
	if (Top == (Size - 1))
		return true;
	else
		return false;
}

template<class ValType> //���������� ��������
void Stack<ValType>::Push(ValType elem)
{
	if (this->IsFull) throw 'Full';
	else
		pMem[++Top] = elem;
}

template <class ValType> //�������� �������� 
ValType Stack<ValType>::Pop()
{
	//if (this->IsEmpty) throw 'Empty';
	//else
		return pMem[Top--];
}

template <class ValType> //������������ ����� �������� �����, ����� ����������� 0 ��� ����������
void Stack<ValType>::SetSize(int n)
{
	//���������� �� ������ ���������� � ������ ����

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

template <class ValType> //�������� �������� ��� ��������
ValType Stack<ValType>::WatchTop()
{
	//if (Top == -1)
	//{
	//	//throw ("���� ����!");
	//}
return pMem[Top];
}

#endif