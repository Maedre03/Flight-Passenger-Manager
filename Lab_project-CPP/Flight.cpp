#include "Flight.h"
#include <iostream>
#include <iomanip>
using namespace std;

Flight::Flight(string flightNo, string destination, int maxSeats)
    : flightNo(flightNo), destination(destination), numPassengers(0){
        
        if(maxSeats > 80){
            this->maxSeats = 80;
        }
        else if(maxSeats % 2 != 0){
            this->maxSeats = maxSeats + 1;
        }
        else{
            this->maxSeats = maxSeats;
        }
        
        initializeSeatingPlan();
    }

void Flight::initializeSeatingPlan(){
    int rows = (maxSeats + 3) / 4;

    seatingPlan = vector<vector<char>>(rows, vector<char>(4, 'O'));
}

bool Flight::reserveSeat(const Passenger& passenger){
    if(numPassengers >= maxSeats){
        cout << "Hata: Ucus dolu!" << endl;
        return false;
    }

    string seat = passenger.getSeatnumber();
    if(seat.length() < 2 )return false;

    int row = stoi(seat.substr(0, seat.length() - 1)) -1;
    char colChar = seat.back();
    int col = colChar - 'A';

    if(row >= 0 && row < seatingPlan.size() && col >= 0 && col < 4){
        if(seatingPlan[row][col] == 'O'){
            seatingPlan[row][col] = 'X';
            this->passenger.push_back(passenger);
            numPassengers++;
            return true;
    }
        else{
            cout << "Hata: Bu koltuk zaten dolu!" << endl;
            return false;
        }
    }
    cout << "Hata: Gecersiz koltuk numarasi!" << endl;
    return false;
}

bool Flight::cancelReservation(const Passenger& targetPassenger){
    for(size_t i = 0; i < passenger.size(); ++i){
        if(passenger[i] == targetPassenger){
            string seat = passenger[i].getSeatnumber();
            int row = stoi(seat.substr(0, seat.length() - 1)) -1;
            int col = seat.back() - 'A';

            seatingPlan[row][col] = 'O';

            passenger.erase(passenger.begin() + i);
            numPassengers--;
            return true;
        }
    }
    cout << "Hata: Yolcu bulunamadi!" << endl;
    return false;
}

int Flight::numberOfPassengers()const{
    return numPassengers;
}

bool Flight::isFlyingTo(const string& dest) const{
    return destination == dest;
}

void Flight::printSeatingPlan() const {
    cout << "\nSeating Plan:" << endl;
    cout << "   A B   C D" << endl;  
    cout << "  --Front--" << endl;
    
    for (size_t i = 0; i < seatingPlan.size(); ++i) {
        cout << setw(2) << setfill('0') << (i + 1) << " ";
        
        for (size_t j = 0; j < 4; ++j) {
            cout << seatingPlan[i][j] << " ";
            
            if (j == 1) {
                cout << "| "; 
            }
        }
        cout << setfill(' ') << endl;
    }
}

void Flight::printPassengers() const {
    cout << "\nPassenger List for Flight " << flightNo << ":" << endl; 
    cout << setw(5) << left << "Seat" << " | " 
         << setw(15) << left << "Passenger Name" << " | " 
         << "Gender" << endl; 
    cout << string(30, '-') << endl;

    for (const auto& p : passenger) {
        string fullName = p.getName() + " " + p.getSurname();
        
         
        if (fullName.length() > 15) {
            fullName = fullName.substr(0, 14) + ".";
        }

        
        cout << setw(5) << left << p.getSeatnumber() << " | "
             << setw(15) << left << fullName << " | "
             << p.getGender() << endl; 
    }
}

string Flight::getFlightNo() const { return flightNo; }
string Flight::getDestination() const { return destination; }
int Flight::getMaxSeats() const { return maxSeats; }