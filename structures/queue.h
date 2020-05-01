#ifndef QUEUE_H
#define QUEUE_H

#include "queue.cpp"

using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class queue
{
private:
	T *data;
	int top;
	int capacity;

public:
	queue(int size = MAX)
	{
		capacity = size;
		top = -1;
		data = new T[size];
	};

	~queue()
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
			cout << "No se puede realizar la operacion porque la queue esta llena." << endl;
		}
	};

	void pop()
	{
		if (top != -1)
		{
			for (int i = 0; i < top; i++)
			{
				data[i] = data[i + 1];
			}
			data[top] = 0; //making sure the data is erased
			top--;
		}
		else
		{
			cout << "No se puede realizar la operacion porque la queue esta vacia." << endl;
		}
	};

	T front()
	{
		if (top != -1)
		{
			return data[0];
		}
		else
		{
			throw string("La queue no contiene elementos. \n");
		}
	};

	T back()
	{
		if (top != -1)
		{
			return data[top];
		}
		else
		{
			throw string("La queue no contiene elementos. \n");
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