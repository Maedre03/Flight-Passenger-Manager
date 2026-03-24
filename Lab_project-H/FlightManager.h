#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include <vector>
#include <string>
#include "Flight.h"

class FlightManager {
private:
    std::vector<Flight> flights;

public:

    void addFlight(const Flight& flight);
    bool removeFlight(const std::string& flightNumber); 
    void listAllFlights() const;
    

    Flight* getFlightByNumber(const std::string& flightNumber);
    Flight* getFlightByDestination(const std::string& destination);
};

#endif