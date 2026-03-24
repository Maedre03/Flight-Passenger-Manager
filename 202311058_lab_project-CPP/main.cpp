#include <iostream>
#include <string>
#include <cctype>
#include "FlightManager.h"
#include "Passenger.h"

using namespace std;


bool isValidName(const string& name) {
    if(name.empty()) return false;
    for (char c : name) {
        if (!isalpha(c) && c != ' ') return false; 
    }
    return true;
}

bool isValidFlightNo(const string& fNo) {
    if(fNo.length() < 3) return false;
    string prefix = fNo.substr(0, 2);

    return (prefix == "TK" || prefix == "PG" || prefix == "tk" || prefix == "pg");
}

int main() {
    FlightManager manager;
    int mainChoice;

    while (true) {

        cout << "\n=== Top-Level Menu: Flight Management ===" << endl;
        cout << "1. Add a Flight" << endl;
        cout << "2. Remove a Flight" << endl;
        cout << "3. List All Flights" << endl;
        cout << "4. Select a Flight and Manage passengers" << endl;
        cout << "5. Exit" << endl;
        cout << "Seciminiz: ";
        cin >> mainChoice;

        if (mainChoice == 1) {

            string fNo, dest;
            int seats;
            cout << "Ucus Numarasi girin (Orn: TK123 veya PG456): ";
            cin >> fNo;
            
            if(!isValidFlightNo(fNo)) {
                cout << "Hata: Gecersiz ucus numarasi. TK veya PG ile baslamalidir." << endl;
                continue;
            }

            cout << "Destinasyon (Gidilecek Yer): ";
            cin >> dest;
            cout << "Maksimum Koltuk Sayisi: ";
            cin >> seats;

            Flight newFlight(fNo, dest, seats);
            manager.addFlight(newFlight);

        } else if (mainChoice == 2) {

            string fNo;
            cout << "Silinecek Ucus Numarasi: ";
            cin >> fNo;
            manager.removeFlight(fNo);

        } else if (mainChoice == 3) {

            manager.listAllFlights();

        } else if (mainChoice == 4) {

            string fNo;
            cout << "Yonetmek istediginiz ucusun numarasi: ";
            cin >> fNo;

            Flight* selectedFlight = manager.getFlightByNumber(fNo);

            if (selectedFlight == nullptr) {
                cout << "Hata: Boyle bir ucus bulunamadi!" << endl;
            } else {

                int subChoice;
                bool inSubMenu = true;

                while (inSubMenu) {
                    cout << "\n--- Passenger Management (Flight: " << selectedFlight->getFlightNo() << ") ---" << endl;
                    cout << "1. Reserve a Seat" << endl;
                    cout << "2. Cancel a Reservation" << endl;
                    cout << "3. View Passenger List" << endl;
                    cout << "4. Back to Flight Management Menu" << endl;
                    cout << "Seciminiz: ";
                    cin >> subChoice;

                    if (subChoice == 1) {

                        selectedFlight->printSeatingPlan();
                        
                        string name, surname, seat;
                        char gender;
                        
                        cout << "\nYolcu Adi: ";
                        cin >> name;
                        cout << "Yolcu Soyadi: ";
                        cin >> surname;
                        
                        if(!isValidName(name) || !isValidName(surname)) {
                            cout << "Hata: Isim ve soyisim sadece harflerden olusmalidir!" << endl;
                            continue;
                        }

                        cout << "Cinsiyet (M/F): ";
                        cin >> gender;
                        cout << "Koltuk Secimi (Orn: 1A, 2B): ";
                        cin >> seat;

                        Passenger newPassenger(name, surname, gender);
                        newPassenger.setSeatnumber(seat);

                        if(selectedFlight->reserveSeat(newPassenger)) {
                            cout << "Rezervasyon basariyla tamamlandi." << endl;
                        }

                    } else if (subChoice == 2) {
                        string name, surname;
                        cout << "Iptal edilecek yolcunun Adi: ";
                        cin >> name;
                        cout << "Soyadi: ";
                        cin >> surname;

                        Passenger targetPassenger(name, surname, ' '); 
                        if(selectedFlight->cancelReservation(targetPassenger)) {
                            cout << "Rezervasyon basariyla iptal edildi." << endl;
                        }

                    } else if (subChoice == 3) {
                        selectedFlight->printPassengers();

                    } else if (subChoice == 4) {
                        inSubMenu = false;
                    } else {
                        cout << "Gecersiz secim!" << endl;
                    }
                }
            }

        } else if (mainChoice == 5) {
            cout << "Sistemden cikiliyor... Iyi gunler!" << endl;
            break;
        } else {
            cout << "Gecersiz secim, lutfen 1-5 arasi bir deger girin." << endl;
        }
    }

    return 0;
}