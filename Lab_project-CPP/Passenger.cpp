#include "Passenger.h"

Passenger::Passenger() : name(""), surname(""), gender(' '){}

Passenger::Passenger(string name, string surname, char gender) : name(name), surname(surname), gender(gender) {}

string Passenger::getName()const{
    return name;
}
string Passenger::getSurname()const{
    return surname;
}
char Passenger::getGender() const {
    return gender;
}

string Passenger::getSeatnumber()const{
    return seatNumber;
}

void Passenger::setName(const string& newName){
    name = newName;
}

void Passenger::setSurname(const string& newSurname){
    surname = newSurname;
}

void Passenger::setGender(char newGender){
    gender = newGender;
}

void Passenger::setSeatnumber(const string& newSeatnumber){
    seatNumber = newSeatnumber;
}

bool Passenger::operator==(const Passenger& other)const{
    return (name == other.name && surname == other.surname);
}


