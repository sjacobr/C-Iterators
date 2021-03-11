#ifndef DEQUE_H
#define DEQUE_H

#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <algorithm>

#include "Deque_Interface.h"
using namespace std;

template <typename T>

class Deque : public DequeInterface <T>
{
private:
	size_t num_items;
	T* the_data;
	size_t capacity; // = DEFAULT_CAPACITY;
	size_t front_index; // = 0;
	size_t rear_index; // = DEFAULT_CAPACITY - 1;

	// create new array of size(dfault capacity)
	void reallocate()
	{
		T* new_data = new T[2 * capacity];
		for (size_t i = 0; i < num_items; ++i)
		{
			new_data[i] = the_data[front_index];
			front_index = (front_index + 1) % capacity;
		}
		front_index = 0;
		rear_index = num_items - 1;
		capacity *= 2;
		swap(the_data, new_data);
		delete[] new_data;
		return;
	}

public:
	// Constructor and Destructor

	Deque(void) :num_items(0), the_data(new T[DEFAULT_CAPACITY]),
		rear_index(DEFAULT_CAPACITY - 1), front_index(0), capacity(DEFAULT_CAPACITY) {};
	~Deque()
	{
		delete[] the_data;
	};

	// Pushes item to back of array
	void push_back(const T& value)
	{
		if (num_items == capacity) reallocate();
		++num_items;
		rear_index = (rear_index + 1) % capacity;
		the_data[rear_index] = value;
		return;
	}

	// Pushes item to front of array
	void push_front(const T& value)
	{
		if (num_items == capacity) reallocate();
		++num_items;
		front_index = (front_index - 1) % capacity;
		the_data[front_index] = value;
		return;
	}

	// Returns number of items
	size_t size(void) const 
	{ 
		return num_items; 
	}


	/** Removes the front item from the deque. */  
	void pop_front(void) 
	{ 
		front_index = (front_index + 1) % capacity;
		--num_items;
		return;
	}

	// moves the last index back one
	void pop_back(void)
	{
		rear_index = (rear_index - 1) % capacity;
		--num_items;
		return;
	}

	// returns front element of array
	T& front(void)
	{
		return the_data[front_index];
	}

	// returns the last element of array
	T& back(void)
	{
		return the_data[rear_index];
	}

	// returns true if the array is empty
	bool empty(void) const
	{
		return num_items == 0;
	}

	// returns the position in the array we seek
	T& at(size_t index)
	{
		return the_data[index];
	}

	// Outputs data as string, not size_t
	string toString() const
	{
		ostringstream os;
		if (!empty())
		{
			for (int i = front_index; i <= rear_index; ++i)
			{
				os << the_data[i] << " ";
			}
		}
		return os.str();
	}

	// If you see "<<", your friend here comes to help 
	friend ostream& operator<< (ostream& os, Deque<T>& deque)
	{
		for (size_t i = 0; i < deque.num_items; ++i) os << " " << deque[i];
		return os;
	} // end operator<<

};

#endif // DEQUE_H
