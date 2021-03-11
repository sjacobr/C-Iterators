#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <algorithm>

#include "Deque_Interface.h"
#include "Deque.h"
#include "Car.h"
#include "Stack.h"
#include "Vector.h"
#include "Queue.h"
#include "Station.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char* argv[])
{
	VS_MEM_CHECK               // enable memory leak check
// Your program...

if (argc < 3)
{
	cerr << "Please provide name of input and output files";
	return 1;
}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	//--------------------------------------------------------//

	Station<Car> myCar;

	// process input strings
	string line, command;
	unsigned int item3;
	while (getline(in, line))
	{
		if (line.size() == 0) continue;
		istringstream iss(line);
		iss >> command;
		iss >> item3;

		// Add train car
		if (command == "Add:station")
		{
			Car newCar(item3);
			out << line << " ";
			out << myCar.addCar(item3);
			out << endl;
			continue;
		}

		// Takes train car from turntable and moves it to outgoing vector
		else if (command == "Remove:station")
		{
			out << line << " ";
			out << myCar.removeCar();
			out << endl;
			continue;
		}

		// Outputs contents of outbound vector
		else if (command == "Train")
		{
			out << line << " ";
			out << myCar.toString();
			out << endl;
			continue;
		}

		// Outputs size of outbound vector
		else if (command == "Size:train")
		{
			out << line << " ";
			out << myCar.sizeTrain();
			out << endl;
			continue;
		}

		// Adds from the turntable => stack
		else if (command == "Add:stack")
		{
			out << line << " ";
			out << myCar.addStack();
			out << endl;
			continue;
		}

		// Outputs top of the stack
		else if (command == "Top:stack")
		{
			out << line << " ";
			out << myCar.topStack();
			out << endl;
			continue;
		}

		// Removes from stack => turntable
		else if (command == "Remove:stack")
		{
			out << line << " ";
			out << myCar.removeStack();
			out << endl;
			continue;
		}

		// Outputs contents of stack roundhouse
		else if (command == "Stack")
		{
			out << line << " ";
			out << myCar.toStringStack();
			out << endl;
			continue;
		}

		// Outputs size of stack roundhouse
		else if (command == "Size:stack")
		{
			out << line << " ";
			out << myCar.sizeStack();
			out << endl;
			continue;
		}

		// Adds from turntable => queue roundhouse
		else if (command == "Add:queue")
		{
			out << line << " ";
			out << myCar.addQueue();
			out << endl;
			continue;
		}

		// Outputs top of the queue roundhouse
		else if (command == "Top:queue")
		{
			out << line << " ";
			out << myCar.topQueue();
			out << endl;
			continue;
		}

		// Removes from queue roundhouse => turntable
		else if (command == "Remove:queue")
		{
			out << line << " ";
			out << myCar.removeQueue();
			out << endl;
			continue;
		}

		// Outputs contents of queue container
		else if (command == "Queue")
		{
			out << line << " ";
			out << myCar.toStringQueue();
			out << endl;
			continue;
		}

		// Outputs size of queue
		else if (command == "Size:queue")
		{
			out << line << " ";
			out << myCar.sizeQueue();
			out << endl;
			continue;
		}

		// Finds car ID in either the vector, stack, queue containers.
		else if (command == "Find")
		{
			out << line << " ";
			out << myCar.find(item3);
			out << endl;
			continue;
		}
	}
	
	return 0;
}
