#ifndef COURSE_NAME_H
#define COURSE_NAME_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Course_Name
{
private:
	string course_name;
public:
	Course_Name(const string& c_n) : course_name(c_n)
	{

	};

	string get_course_name() const
	{
		return course_name;
	}
	string toString() const;

	friend class Cdh;
	friend class Cr;
	friend class Csg;

	~Course_Name() = default;
};




#endif // !COURSE_NAME_H

