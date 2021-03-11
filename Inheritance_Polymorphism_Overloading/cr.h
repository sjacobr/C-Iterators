#ifndef CR_H
#define CR_H

#include  "Course_Name.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Cr : public Course_Name
{
private:
	string room;
public:
	Cr(const string& c_n, const string& r) : Course_Name(c_n), room(r)
	{
	};
	

	// setter
	void setcr(string c_n, string r) {
		course_name = c_n;
		room = r;
	}

	// getters

	string getcr_room()
	{
		return room;
	}

	string toString() const
	{
		stringstream out;
		out << course_name << "," << room << ")";
		return out.str();
	}

	friend std::ostream& operator<< (ostream& os, const Cr& Cr)
	{
		os << Cr.toString();
		return os;
	}

	~Cr() = default;

};



#endif // !CR_H
