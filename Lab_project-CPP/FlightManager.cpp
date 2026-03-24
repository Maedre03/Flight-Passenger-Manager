#include "FlightManager.h"
#include <iostream>
#include <iomanip>

using namespace std;


void FlightManager::addFlight(const Flight& flight) {
    for (const auto& f : flights) {
        if (f.getFlightNo() == flight.getFlightNo()) {
            cout << "Hata: Bu ucus numarasi zaten sistemde mevcut!" << endl;
            return;
        }
    }
    flights.push_back(flight);
    cout << "Ucus basariyla eklendi." << endl;
}

bool FlightManager::removeFlight(const string& flightNumber) {
    for (size_t i = 0; i < flights.size(); ++i) {
        if (flights[i].getFlightNo() == flightNumber) {
            flights.erase(flights.begin() + i);
            cout << "Ucus basariyla silindi." << endl;
            return true;
        }
    }
 
    cout << "Hata: Silinecek ucus (" << flightNumber << ") bulunamadi!" << endl; 
    return false;
}


void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        cout << "Sistemde kayitli ucus bulunmamaktadir." << endl;
        return;
    }

    cout << "\n--- Tum Ucuslar ---" << endl;

    cout << setw(10) << left << "Flight No" << " | "
         << setw(15) << left << "Destination" << " | "
         << "Available Seats" << endl;
    cout << string(47, '-') << endl;

    for (const auto& f : flights) {

        int availableSeats = f.getMaxSeats() - f.numberOfPassengers(); 
        cout << setw(10) << left << f.getFlightNo() << " | "
             << setw(15) << left << f.getDestination() << " | "
             << availableSeats << endl;
    }
}


Flight* FlightManager::getFlightByNumber(const string& flightNumber) {
    for (auto& f : flights) {
        if (f.getFlightNo() == flightNumber) {
            return &f;
        }
    }
    return nullptr;
}


Flight* FlightManager::getFlightByDestination(const string& destination) {
    for (auto& f : flights) {
        if (f.getDestination() == destination) {
            return &f;
        }
    }
    return nullptr;
}