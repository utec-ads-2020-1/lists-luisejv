#ifndef STACK_H
#define STACK_H

using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class stack
{
private:
	T *data;
	int top;
	int capacity;

public:
	stack(int size = MAX)
	{
		capacity = size;
		top = -1;
		data = new T[size];
	};

	~stack()
	{
		delete[] data;
	};

	void push(T elem)
	{
		if (top + 1 < capacity)
		{
			top++;
			data[top] = elem;
		}
		else
		{
			cout << "No se puede realizar la operacion porque el stack esta lleno." << endl;
		}
	};

	void pop()
	{
		if (top != -1)
		{
			data[top] = 0; //making sure the data is erased
			top--;
		}
		else
		{
			cout << "No se puede realizar la operacion porque el stack esta vacio." << endl;
		}
	};

	T lastElem()
	{
		if (top != -1)
		{
			return data[top];
		}
		else
		{
			throw string("El stack no contiene elementos. \n");
		}
	};

	int size()
	{
		return top + 1;
	};

	bool empty()
	{
		return top == -1;
	};
};

#endif