#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Flight
{
private:
    string **schedule;
    int numFlights;

public:
    Flight(int flights, string **sched)
    {
        numFlights = flights;
        // Dynamically Allocating a 2D array of type "string".

        // pointers of type string.
        schedule = new string *[numFlights];
        // each pointer is further points to an string array of 5 elements, representing
        for (int i = 0; i < numFlights; i++)
        {
            schedule[i] = new string[5];
        }

        for (int i = 0; i < numFlights; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                schedule[i][j] = sched[i][j];
            }
        }
    }

    ~Flight()
    {
        for (int i = 0; i < numFlights; i++)
        {
            delete[] schedule[i];
        }
        delete[] schedule;
    }

    bool checkAvailability(int flight_no, string date, string departure, string destination, int seats, string seatType)
    {
        int index = flight_no;
        if ((index - 1) < 0 || (index - 1) >= numFlights)
        {
            cout << "Invalid flight number!" << endl;
            return false;
        }

        // (index - 1) represents the flight number and 0 represents the dates, 1 represents departure, 2 represent destination stored in an array pointed by the "schedule".
        if (date != schedule[index - 1][0] || departure != schedule[index - 1][1] || destination != schedule[index - 1][2])
        {
            cout << "Flight not found!" << endl;
            return false;
        }

        int availableSeats;
        if (seatType == "economy")
        {
            // [][3] total number of seats in economy class Flight
            availableSeats = stoi(schedule[index - 1][3]);
        }
        else if (seatType == "business")
        {
            // [][4] total number of seats in Business class Flight
            availableSeats = stoi(schedule[index - 1][4]);
        }
        else
        {
            cout << "Invalid seat type." << endl;
            return false;
        }

        if (availableSeats >= seats)
        {
            return true;
        }
        else
        {
            cout << "Not Enough Available seats!" << endl;
            return false;
        }
    }

    void makeReservation(int flight_no, string date, string departure, string destination, int seats, string seatType)
    {
        int index = flight_no;
        if (checkAvailability(flight_no, date, departure, destination, seats, seatType))
        {
            if (seatType == "economy")
                schedule[index - 1][3] = to_string(stoi(schedule[index - 1][3]) - seats);
            else if (seatType == "business")
                schedule[index - 1][4] = to_string(stoi(schedule[index - 1][4]) - seats);
            cout << "----------" << endl;
            cout << "Reservation confirmed for flight: " << flight_no << endl;
            cout << "Departing on: " << date << endl;
            cout << "Departure: " << departure << endl;
            cout << "Destination: " << destination << endl;
            cout << "------------------------------" << endl;
        }
        else
        {
            cout << "Reservation cannot be made!" << endl;
        }
    }

    void displaySchedule()
    {
        cout << "Flight Schedule:" << endl;
        for (int i = 0; i < numFlights; i++)
        {
            cout << "Flight " << i + 1 << ": ";
            for (int j = 0; j < 5; j++)
            {
                cout << setw(12) << schedule[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Reservation
{
private:
    string name;
    string passportNumber;
    string contactNumber;

public:
    Reservation(string name, string passportNumber, string contactNumber)
    {
        this->name = name;
        this->passportNumber = passportNumber;
        this->contactNumber = contactNumber;
    }

    void makeReservation(Flight &flight, int flight_no, string date, string departure, string destination, int seats, string seatType)
    {
        if (seats == 0)
        {
            tentativeReservation();
        }

        flight.makeReservation(flight_no, date, departure, destination, seats, seatType);
    }

    string tentativeReservation()
    {
        return ("Tentative reservation made for " + name + ". Please confirm your booking later.");
    }

    void displayDetails()
    {
        cout << "-----------" << endl;
        cout << "Passenger Name: " << name << endl;
        cout << "Passport Number: " << passportNumber << endl;
        cout << "Contact Number: " << contactNumber << endl;
    }
};

int main()
{
    const int n_flights = 3;
    string data[n_flights][5] = {
        {"2027-07-27", "NewYork", "Lahore", "95", "economy"},
        {"2021-05-12", "Multan", "Islamabad", "110", "economy"},
        {"2023-03-17", "Karachi", "Tokyo", "90", "business"},
    };
    // Memory allocation.
    string **schedule = new string *[n_flights];
    for (int i = 0; i < n_flights; i++)
    {
        schedule[i] = new string[5];
    }

    for (int i = 0; i < n_flights; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            schedule[i][j] = data[i][j];
        }
    }

    Flight flight(n_flights, schedule);
    // checked for flight 1 (NewYork - Lahore)
    if (flight.checkAvailability(1, "2027-07-27", "NewYork", "Lahore", 35, "economy"))
    {
        cout << "Flight Available!" << endl;
    }
    else
    {
        cout << "Sorry this flight is not available right now! We Have other flight available, You can check it here..." << endl;
    }
    flight.displaySchedule();

    Reservation reservation("Quaid-e-Azam", "PK-3894", "+92 311 9823672");
    // Booked seats in flight 2 (Multan - Islamabad)
    reservation.makeReservation(flight, 2, "2021-05-12", "Multan", "Islamabad", 35, "economy");
    reservation.displayDetails();
    cout << "-------------------------------" << endl;
    return 0;
}
