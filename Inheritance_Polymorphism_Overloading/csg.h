#ifndef CSG_H
#define CSG_H

#include "Student_ID.h"
#include  "Course_Name.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Csg : public Student_ID, public Course_Name
{
private:
	//string student_ID and course_name derived from ^^;
	string student_grade;
public:
	Csg(const string&c_n, const string& s_ID, const string& s_g) :
		Course_Name(c_n), Student_ID(s_ID), student_grade(s_g)
	{
	};
	

	// setter
	void setcsg(string c_n, string s_ID, string s_g) {
		course_name = c_n;
		student_ID = s_ID;
		student_grade = s_g;
	}

	// getter
	string getcsg_student_ID() {
		return student_ID;
	}

	string getcsg_course_name()
	{
		return course_name;
	}

	string getcsg_student_grade()
	{
		return student_grade;
	}

	string toString() const
	{
		stringstream out;
		out << course_name << "," << student_ID << "," << student_grade << ")";
		return out.str();
	}

	friend std::ostream& operator<< (ostream& os, const Csg& Csg)
	{
		os << Csg.toString();
		return os;
	}

	~Csg() = default;

};



#endif // !CSG_H
