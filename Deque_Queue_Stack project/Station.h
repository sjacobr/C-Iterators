#ifndef STATION_H
#define STATION_H

#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <algorithm>

#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include "Car.h"


template <typename T>
class Station
{
private:
	Vector <T> train_;
	Stack <T> stack_;
	Queue <T> queue_;
	T turnTableCar_; // 
	bool empty = true;

public:

	Station() = default;
	~Station() = default;

	string addCar(const T& newCar)
	{
		if (empty) // put a car in turntable
		{
			empty = false;
			turnTableCar_ = newCar;
			return "OK";
		}
		else // turntable already has a car 
		{
			return "Turntable occupied!";
		}
	}

	string removeCar()
	{
		if (empty) // there is no car to remove
		{
			return "Turntable empty!";
		}
		else // there is a car so we remove it and push it onto outgoing vector
		{
			train_.push_back(turnTableCar_);

			empty = true;
			return "OK";
		}
	}

	// Output car ID
	string topCar() 
	{
		return turnTableCar_.str();
	}

	// Outputs size of train_ vector
	size_t sizeTrain()
	{
		return train_.size();
	}

	// Adds car from turntable => stack
	string addStack()
	{

		if (empty) // then we cannot add a car from turntable because there is none
		{
			return "Turntable empty!";
		}
		else // if there is a car in the turntable, push it to stack
		{
			empty = true;
			stack_.push(turnTableCar_);
			return "OK";
		}
	}

	// Removes from stack => turntable
	string removeStack()
	{
		if (stack_.size() == 0) // there is nothing to remove from stack
		{
			return "Stack empty!";
		}
		// otherwise have turntable car go to top of the stack,
		turnTableCar_ = stack_.top();
		// pop it,
		stack_.pop();
		// now turntablecar is on the turntable
		empty = false;
		return "OK";
	}

	// Outputs top of the stack
	string topStack()
	{
		if (stack_.size() == 0) // unless there are no train cars in the stack
		{
			return "Stack empty!";
		}
		return stack_.top().toString();
	}

	// Ouputs size of stack
	size_t sizeStack()
	{
		return stack_.size(); 
	}

	// Turntablecar => queue
	string addQueue()
	{
		if (empty) // there is nothing to add
		{
			return "Turntable empty!";
		}
		else // if there is a car in the turntable, put it on queue
		{
			empty = true;
			queue_.push(turnTableCar_);
			return "OK";
		}
	}

	// Queue => turntable
	string removeQueue()
	{
		if (queue_.size() == 0) // there is nothing to remove
		{
			return "Queue empty!";
		}
		// otherwise, make turntablecar top of the queue
		turnTableCar_ = queue_.top();
		// pop it, now it is on turntable
		queue_.pop();
		empty = false;
		return "OK";
	}

	// Outputs top item of queue
	string topQueue()
	{
		if (queue_.size() == 0) // there is nothing to show
		{
			return "Queue empty!";
		}
		return queue_.top().toString();
	}

	// Outputs size of queue
	size_t sizeQueue()
	{
		return queue_.size();
	}

	// Finds car ID
	string find(T car)
	{
		T item = car;

		// check if car ID is in queue
		for (size_t i = 0; i <= queue_.size(); ++i)
		{
			if (queue_.at(i) == item)
			{

				string returnString = "Queue[" + to_string(i) + "]";
				return returnString;
			}
		}

		// check if car ID is in stack
		for (size_t i = 0; i <= stack_.size(); ++i)
		{
			if (stack_.at(i) == item)
			{
				string returnString = "Stack[" + to_string(i) + "]";
				return returnString;
			}
		}

		// check if car ID is in vector 
		for (size_t i = 0; i <= train_.size(); ++i)
		{
			if (train_.at(i) == item)
			{
				string returnString = "Train[" + to_string(i) + "]";
				return returnString;
			}
		}

		// otherwise it is not in one of our containers
		return "Not Found!";

	}

	//----toStrings for each container----//

	string toString(void) const
	{
		return train_.toString();

	}

	string toStringStack(void) const
	{
		return stack_.toString();
	}

	string toStringQueue(void) const
	{
		return queue_.toString();
	}

};



#endif // STATION_H
