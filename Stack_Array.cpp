#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Stack
{
	public:
		Stack() :top(-1), size(3) { array = new T[size]; };
		~Stack() { delete array; };
		bool Full();
		bool Empty();
		void Push(T);
		T Pop();
		void PrintArray();
	private:
		T *array;
		int size;
		int top;
};

int main()
{
	Stack<int> stack;
	stack.Push(10);
	stack.Push(11);
	stack.Push(12);
	stack.Pop();
	stack.Push(13);
	stack.Pop();
	stack.PrintArray();

	Stack<char> stack1;
	stack1.Push('A');
	stack1.Push('B');
	stack1.Push('C');
	stack1.Pop();
	stack1.Push('D');
	stack1.Pop();
	stack1.PrintArray();

	system("pause");
	return 0;
}

template <class T>
bool Stack<T>::Full()
{
	if (top == size) { return true; }
	else { return false; };
}

template <class T>
bool Stack<T>::Empty()
{
	if (top == -1) { return true; }
	else { return false; };
}

template <class T>
void Stack<T>::Push(T x)
{
	if (Full() == true)
	{
		size *= 2;
		array = new T[size];
	}
	array[++top] = x;
}

template <class T>
T Stack<T>::Pop()
{
	if (Empty() == false) { return array[top--]; }
}

template <class T>
void Stack<T>::PrintArray()
{
	T i = 0;
	for (i = 0; i <= top; i++)
	{
		cout << array[i] << " ";
	}
	if (i == 0) { cout << "Array is empty!"; };
	cout << endl;
}