#ifndef STUDENT_ID_H
#define STUDENT_ID_H


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Student_ID
{
private:
	string student_ID;

public:
	Student_ID(const string& s_ID) : student_ID(s_ID) 
	{
	};
	string get_student_ID() const
	{
		return student_ID;
	}
	string toString() const;

	friend class Csg;
	friend class Snap;

	~Student_ID() = default;

};




#endif // !STUDENT_ID_H
