#ifndef CAR_H
#define CAR_H

#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Car
{
    unsigned int id;
    Car() : id(0) {}
    ~Car() {}

    // constructor that takes unsigned int and sets = unsigned int
    Car(unsigned int num) 
    {
        id = num;
    }

    // getter
    unsigned int getCar()
    {
        return id;
    }

    bool operator==(const Car car) { return this->id == car.id; }
    bool operator!=(const Car car) { return this->id != car.id; }

    /** Return the Car as a string */
    string toString() const
    {
        stringstream out;
        out << id;
        return out.str();
    } // end toString()

      /** Make insertion operator friend for a Car */
    friend std::ostream& operator<< (ostream& os, const Car& c)
    {
        os << c.toString();
        return os;
    } // end operator<<
};

#endif // CAR_H
