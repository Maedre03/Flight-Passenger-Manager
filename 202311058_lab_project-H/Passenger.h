#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

class Passenger{
    private:
        string name;
        string surname;
        char gender;
        string seatNumber;

    public:
        //Constructors
        Passenger();
        Passenger(string name, string surname, char gender);

        //Getters
        string getName()const;
        string getSurname()const;
        char getGender()const;
        string getSeatnumber()const;

        //Setters
        void setName(const string& newName);
        void setSurname(const string& newSurname);
        void setGender(char newGender);
        void setSeatnumber(const string& newSeatnumber);

        //Overload Op
        bool operator==(const Passenger& other)const;
};

#endif