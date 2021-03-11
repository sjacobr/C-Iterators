#ifndef CDH_H
#define CDH_H

#include "Course_Name.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Cdh : public Course_Name
{
private:
	string day;
	string time;
public:
	Cdh(const string& c_n, const string& d, const string& t) : Course_Name(c_n), day(d), time(t)
	{
	}
	
	// setter
	void setcdh(string c_n, string d, string t) {
		course_name = c_n;
		day = d;
		time = t;
	}

	// getter
	string getcdh_course_name() {
		return course_name;
	}

	string getcdh_day()
	{
		return day;
	}

	string getchd_time()
	{
		return time;
	}



	string toString() const
	{
		stringstream out;
		out << course_name << "," << day << "," << time << ")";
		return out.str();
	}

	friend std::ostream& operator<< (ostream& os, const Cdh& Cdh)
	{
		os << Cdh.toString();
		return os;
	}

	~Cdh() = default;

};






#endif // !CDH_H
