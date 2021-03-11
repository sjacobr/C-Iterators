#ifndef SNAP_H
#define SNAP_H

using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#include "Student_ID.h"

class Snap : public Student_ID
{
private:
	string student_name;
	string student_address;
	string phone_number;
public:
	Snap(const string& s_ID, const string& s_n, const string& s_a, const string& p_n) : 
		Student_ID(s_ID), student_name(s_n), student_address(s_a), phone_number(p_n)
	{
	};

	// setter
	void setsnap(string s_ID, string s_n, string s_a, string p_n) {
		student_ID = s_ID;
		student_name = s_n;
		student_address = s_a;
		phone_number = p_n;
	}

	// getters

	string getsnap_student_ID()
	{
		return student_ID;
	}

	string getsnap_student_name()
	{
		return student_name;
	}

	string getsnap_student_address()
	{
		return student_address;
	}

	string getsnap_phone_number()
	{
		return phone_number;
	}

	string toString() const
	{
		stringstream out;
		out << student_ID << "," << student_name << "," << student_address << "," << phone_number << ")";
		return out.str();
	}

	friend std::ostream& operator<< (ostream& os, const Snap& Snap)
	{
		os << Snap.toString();
		return os;
	}

	~Snap() = default;

};



#endif // !SNAP_H
