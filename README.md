# Flight Management System

This project implements a basic flight management system in C++. It provides functionalities for checking flight availability, making reservations, and viewing the flight schedule.

## Purpose

This project aims to provide a simple yet functional flight management system for managing airline reservations and schedules.

## Features

- Check flight availability by specifying the flight number, date, departure, destination, seats, and seat type.
- Make reservations for available flights.
- Display the flight schedule showing flight details such as date, departure, destination, and available seats.

## Usage

1. Clone the repository to your local machine.
2. Compile the source code using a C++ compiler (e.g., g++):
3. Run the compiled executable:
4. Follow the on-screen prompts to interact with the flight management system.

## Customization

You can set the number of flghts as well as the data, according to your own configuration in the **main** functon. Here is a sample code

```CPP
const int n_flights = 3;
    string data[n_flights][5] = {
        {"2027-07-27", "NewYork", "Lahore", "95", "economy"},
        {"2021-05-12", "Multan", "Islamabad", "110", "economy"},
        {"2023-03-17", "Karachi", "Tokyo", "90", "business"},
    };
```

### Usage Example

1. Checking Flight Availability

To check the availability of a flight, use the checkAvailability() method of the Flight class. Provide the flight number, date, departure city, destination city, desired number of seats, and seat type as parameters.

```CPP
if (flight.checkAvailability(1, "2027-07-27", "NewYork", "Lahore", 35, "economy")) {
    cout << "Flight Available!" << endl;
} else {
    cout << "Sorry, this flight is not available right now. Please check other available flights." << endl;
}
```

2. Making a Reservation

To make a reservation for a flight, use the makeReservation() method of the Reservation class. Pass the Flight object, flight number, date, departure city, destination city, desired number of seats, and seat type as parameters.
```CPP
Reservation reservation("Quaid-e-Azam", "PK-3894", "+92 311 9823672");
reservation.makeReservation(flight, 2, "2021-05-12", "Multan", "Islamabad", 35, "economy");
```
3. Display Flight Schedule
To display the flight schedule, use the displaySchedule() method of the Flight class. This will print out the schedule of all available flights, including date, departure city, destination city, total available seats in economy class, and total available seats in business class.
```CPP
flight.displaySchedule();
```

## Project Structure

This project consists of a single C++ source file **(main.cpp)** containing the implementation of the flight management system. Additional data such as flight schedules is provided inline within the source code.

## Dependencies

This project has no external dependencies and can be compiled using any standard C++ compiler.

## Contributing

Contributions are welcome! If you have any suggestions for improvements or would like to add new features, feel free to submit a pull request.
