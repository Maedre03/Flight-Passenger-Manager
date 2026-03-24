#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include "Passenger.h"

class Flight{
    private:
        std::string flightNo;
        std::string destination;
        int maxSeats;
        int numPassengers;
        std::vector<Passenger> passenger;

        //Koltuk tablosunu ekrana cizmek icin
        std::vector<std::vector<char>> seatingPlan;

        //Tum tabloyu 0 ile dolduracak
        void initializeSeatingPlan();

    public:
        //Constructor
        Flight(std::string flightNO, std::string destination, int maxSeats = 40);

        //Member Functions
        bool reserveSeat(const Passenger& passenger);
        bool cancelReservation(const Passenger& passenger);
        int numberOfPassengers()const;
        void printPassengers()const;
        bool isFlyingTo(const std::string& dest)const;

        //Getters
        std::string getFlightNo()const;
        std::string getDestination()const;
        int getMaxSeats()const;

        void printSeatingPlan()const;


};

#endif