#pragma once
#ifndef __STACH_H__
#define __STACK_H__
#define MemSize 100

template <class ValType>
class Stack
{
private: ValType *pMem;
		 int size;   //������ �����
		 int top;    //������� �����
public:
		Stack(const int n=MemSize);             //����������� �������������
		~Stack();								//����������

		bool IsEmpty();           //�������� �� �������
		bool IsFull();            //�������� �� �������
		void Push(ValType Elem);  //�������� � ���� ��������
		ValType Pop();            //������� ������� �� ����� + ������� ���
		ValType Watchtop();       //���������� ������� �������

		int GetSize() const { return Size; }   //������ �����
		//void SetSize(int n);                   //���������� ������


		//Stack& operator=(const Stack &st);
		//bool operator==(const Stack &st) const;
		//bool operator!=(const Stack &st) const;
};

template <class ValType> //����������� ������������� ��� ����� �����
Stack<ValType>::Stack(const int n)
{
	if (( n < 0)||(n>MemSize)) throw 'Neg';
	pMem = new ValType[n];
	size = n;
	top = -1;
}

template <class ValType> //����������
Stack<ValType>::~Stack()
{
	delete[]pMem;
}

template <class ValType> //�������� �� �������
bool Stack<ValType>::IsEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template <class ValType> //�������� �� �������
bool Stack<ValType>::IsFull()
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

template<class ValType> //���������� ��������
void Stack<ValType>::Push(ValType elem)
{
	if (IsFull()==true) throw 'Full';
	else
		pMem[++top] = elem;
}

template <class ValType> //�������� �������� 
ValType Stack<ValType>::Pop()
{
	if (IsEmpty()) throw 'Emp';
	else
		return pMem[top--];
}

//template <class ValType> //������������ ����� �������� �����, ����� ����������� 0 ��� ����������
//void Stack<ValType>::SetSize(int n)
//{
//	//���������� �� ������ ���������� � ������ ����
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

template <class ValType> //�������� �������� ��� ��������
ValType Stack<ValType>::Watchtop()
{
return pMem[top];
}

#endif