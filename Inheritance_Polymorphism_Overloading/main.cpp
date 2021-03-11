#include "Course_Name.h"
#include "Student_ID.h"
#include "cr.h"
#include "csg.h"
#include "cdh.h"
#include "snap.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ostream>
#include <iomanip>

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


    // PART 1
    // Input Strings

    // These are vectors I will be working with, of class <_>
    vector <Cr> crs;
    vector <Cdh> cdhs;
    vector <Snap> snaps;
    vector <Csg> csgs;

    // cout << "test" << endl;

    out << endl << "Input Strings: " << endl;

    for (string line; getline(in, line);)	// Read until EOF 
    {

        try
        {
            if ((line.substr(0, 3) != "cr(") && (line.substr(0, 4) != "csg(") && (line.substr(0, 5) != "snap(") && (line.substr(0, 4) != "cdh("))
            {
                throw string(line);
            }
        }
        catch (string errorString)
        {
            out << "**Error: " << errorString << endl;
        }

        if ("cr(" == line.substr(0, 3))
        {
            out << line << endl;
            // Ex: cr('CS101','Turing Aud.').
            string courseName = line.substr(3, line.find(',') - 3);
            line = line.substr(line.find(',') + 1); // took out + 1
            string room = line.substr(0, line.find(')'));
            crs.push_back(Cr(courseName, room));
        }
        else if ("csg(" == line.substr(0, 4))
        {

        out << line << endl;
        // Ex: csg(CS101,12345,A).
        string courseName = line.substr(4, line.find(',') - 4);
        line = line.substr(line.find(',') + 1); //took away +1
        string student_ID = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1); // took off + 1
        string student_grade = line.substr(0, line.find(')'));
        csgs.push_back(Csg(courseName, student_ID, student_grade));
        }

        else if ("snap(" == line.substr(0, 5))
        {
        out << line << endl;
        // Ex: snap(67890,Lucy,Right Field,555-5678).
        string student_ID = line.substr(5, line.find(',') - 5);
        line = line.substr(line.find(',') + 1);
        string student_name = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);
        string student_address = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);
        string phone_number = line.substr(0, line.find(')'));
        snaps.push_back(Snap(student_ID, student_name, student_address, phone_number));
        }

        else if ("cdh(" == line.substr(0, 4))
        {
        out << line << endl;
        // Ex: cdh(CS101,M,9AM).
        string courseName = line.substr(4, line.find(',') - 4);
        line = line.substr(line.find(',') + 1); // add 2 instead of 1
        string day = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);
        string time = line.substr(0, line.find(')'));
        cdhs.push_back(Cdh(courseName, day, time));
        }
    }

    // PART 2

    // Output Vectors

    out << endl << "Vectors:" << endl;

    for (unsigned int i = 0; i < snaps.size(); i++)
    {
        out << "snap(" << snaps[i] << endl;
    }

    for (unsigned int i = 0; i < csgs.size(); i++)
    {
        out << "csg(" << csgs[i] << endl;
    }

    for (unsigned int i = 0; i < cdhs.size(); i++)
    {
        out << "cdh(" << cdhs[i] << endl;
    }

    for (unsigned int i = 0; i < crs.size(); i++)
    {
        out << "cr(" << crs[i] << endl;
    }

    // PART 3
    // Course Grades

    out << endl << "Course Grades:" << endl;

    for (unsigned int i = 0; i < csgs.size(); i++)
    {
        out << csgs.at(i).getcsg_course_name() << ",";
        for (unsigned int j = 0; j < snaps.size(); j++)
        {
            if (csgs.at(i).getcsg_student_ID() == snaps.at(j).getsnap_student_ID())
            {
                out << snaps.at(j).getsnap_student_name() << ",";
            }
        }
        out << csgs.at(i).getcsg_student_grade() << endl;
    }


    // PART 4
    // Student Schedules
    out << endl << "Student Schedules:" << endl;

    // It gets a little ugly...

    for (unsigned int i = 0; i < snaps.size(); i++)
    {
        out << snaps.at(i).getsnap_student_name() << ", "; // Prints name of student
        out << snaps.at(i).getsnap_student_ID() << ", "; // Prints their ID
        out << snaps.at(i).getsnap_student_address() << ", "; // Prints their address
        out << snaps.at(i).getsnap_phone_number() << endl; // Prints their phone #
        for (unsigned int j = 0; j < csgs.size(); j++)
        {
            if (snaps.at(i).getsnap_student_ID() == csgs.at(j).getcsg_student_ID())
            { // If ID's match, we output the proper info 
                out << csgs.at(j).getcsg_course_name() << " ";
                for (unsigned int k = 0; k < cdhs.size(); k++)
                {
                    if (csgs.at(j).getcsg_course_name() == cdhs.at(k).getcdh_course_name())
                    {
                        out << cdhs.at(k).getcdh_day();
                    }
                }
                for (unsigned int k = 0; k < cdhs.size(); k++)
                {
                    if (csgs.at(j).getcsg_course_name() == cdhs.at(k).getcdh_course_name())
                    {
                        out << " " << cdhs.at(k).getchd_time();
                        break;
                    }
                }
                for (unsigned int l = 0; l < crs.size(); l++) {
                    if (csgs.at(j).getcsg_course_name() == crs.at(l).get_course_name()) {
                        out << ", " << crs.at(l).getcr_room();
                    }
                }
                out << endl;
            }
        }
        out << endl;
    }

    return 0;
}
