#include "project"

///////////////////////////////////  TICKETS IMPLEMENTATION  /////////////////////////////////////
// ---------------------------------------------------------------------------------------------//

Ticket::Ticket() : Registration_number(""), Bar_Code(""), Date(""), Time(""), Name(""), Seat(""), Price(0.0) {}

Ticket::Ticket(const std::string &reg_no, const std::string &scan_code, std::string date,
                std::string time, std::string Person_name, std::string seat_no, double ticket_price) 
                : Registration_number(reg_no), Bar_Code(scan_code), Date(date),
                Time(time), Name(Person_name), Seat(seat_no), Price(ticket_price) {}


void Ticket::PrintTicketDetails() const {
    std::cout << "==============================\n";
    std::cout << "         TICKET DETAILS        \n";
    std::cout << "==============================\n";
    std::cout << "Registration Number: " << Registration_number << "\n";
    std::cout << "Bar Code           : " << Bar_Code << "\n";
    std::cout << "Date               : " << Date << "\n";
    std::cout << "Time               : " << Time << "\n";
    std::cout << "Name               : " << Name << "\n";
    std::cout << "Seat               : " << Seat << "\n";
    std::cout << "Price              : $" << std::fixed << std::setprecision(2) << Price << "\n";
    std::cout << "------------------------------\n";
}

void Ticket::Print_Ticket_To_File(std::ofstream &outfile) const {
    if (!outfile.is_open()) {
        std::cerr << "Error opening file: \n";
        return;
    }

    outfile << "==============================\n";
    outfile << "         TICKET DETAILS        \n";
    outfile << "==============================\n";
    outfile << "Name               : " << Name << "\n";
    outfile << "Registration Number: " << Registration_number << "\n";
    outfile << "Bar Code           : " << Bar_Code << "\n";
    outfile << "Date               : " << Date << "\n";
    outfile << "Time               : " << Time << "\n";
    outfile << "Seat               : " << Seat << "\n";
    outfile << "Price              : $" << std::fixed << std::setprecision(2) << Price << "\n";
    outfile << "------------------------------\n";
}

void Ticket::view_tickets() const {
    while (true) {
        std::cout << "\n======= VIEW TICKETS =======\n";
        std::cout << "Select Ticket Type:\n";
        std::cout << "1. Cinema Tickets\n";
        std::cout << "2. Airplane Tickets\n";
        std::cout << "3. Train Tickets\n";
        std::cout << "4. Bus Tickets\n";
        std::cout << "5. Back to Main Menu\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nAvailable Cinema Tickets:\n"
                          << "1. The Nun - Screen 1\n"
                          << "2. Money Heist - Screen 2\n"
                          << "3. Lone Wolf - Screen 3\n";
                break;
            }
            case 2: {
                std::cout << "\nAvailable Airplane Tickets:\n"
                          << "1. Dubai Package - $1200 (Economy)\n"
                          << "2. Paris Getaway - $1500 (Business)\n"
                          << "3. New York Journey - $1800 (First Class)\n";
                break;
            }
            case 3: {
                std::cout << "\nAvailable Train Tickets:\n"
                          << "1. City Express - $50 (Economy)\n"
                          << "2. National Train - $80 (Business)\n";
                break;
            }
            case 4: {
                std::cout << "\nAvailable Bus Tickets:\n"
                          << "1. Intercity Bus - $20 (Standard)\n"
                          << "2. Sleeper Bus - $40 (Luxury)\n";
                break;
            }
            case 5:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

///////////////////////////////////  LOCATION IMPLEMENTATION  /////////////////////////////////////
// ----------------------------------------------------------------------------------------------//

Location::Location(const std::string &src, const std::string &dest)
    : source(src), destination(dest) {}

std::string Location::GetSource() const {
    return source;
}

std::string Location::GetDestination() const {
    return destination;
}

void Location::PrintLocation() const {
    std::cout << "From: " << source << " To: " << destination << std::endl;
}

///////////////////////////////////  TRAVELING IMPLEMENTATION  /////////////////////////////////////
// ----------------------------------------------------------------------------------------------//
TravelTicket::TravelTicket(const std::string &reg_no, const std::string &scan_code, const std::string &date,
                           const std::string &time, const std::string &person_name, const std::string &seat_no, 
                           double ticket_price, const Location &loc, const std::string &arrival)
    : Ticket(reg_no, scan_code, date, time, person_name, seat_no, ticket_price),
    route(loc), arrivalTime(arrival) {
    bookingTime = GetCurrentTime();
}


std::string TravelTicket::GetCurrentTime() const {
    std::time_t now = std::time(nullptr);
    char buf[80];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

void TravelTicket::PrintTicketDetails() const {
    Ticket::PrintTicketDetails();
    std::cout << "Booking Time: " << bookingTime << "\n"
              << "Arrival Time: " << arrivalTime << "\n";
    route.PrintLocation();
}


///////////////////////////////////  AIRPLANE IMPLEMENTATION  /////////////////////////////////////
// ----------------------------------------------------------------------------------------------//
AirplaneTicket::AirplaneTicket(const std::string &reg_no, const std::string &scan_code, const std::string &date,
                               const std::string &time, const std::string &person_name, const std::string &seat_no,
                               double ticket_price, const Location &loc, const std::string &arrival, const std::string &flight_class)
    : TravelTicket(reg_no, scan_code, date, time, person_name, seat_no, ticket_price, loc, arrival), flightClass(flight_class) {}

void AirplaneTicket::PrintTicketDetails() const {
    std::cout <<"==============================\n";
    std::cout <<"         AIRPLANE TICKET      \n";
    TravelTicket::PrintTicketDetails();
    std::cout << "Flight Class: " << flightClass << "\n";
    std::cout <<"==============================\n";
}

void AirplaneTicket::Print_Ticket_To_File(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }
    outFile <<"===============================\n";
    outFile <<"         AIRPLANE TICKET       \n";
    Ticket::Print_Ticket_To_File(outFile);
    outFile << "Source             : " << route.GetSource() << "\n";
    outFile << "Destination        : " << route.GetDestination() << "\n";
    outFile << "Class              : " << flightClass << "\n";
    outFile << "==============================\n";

    outFile.close();
}
/////////////////////////////////////  TRAIN IMPLEMENTATION  ///////////////////////////////////////
// -----------------------------------------------------------------------------------------------//
TrainTicket::TrainTicket(const std::string &reg_no, const std::string &scan_code, const std::string &date,
                         const std::string &time, const std::string &person_name, const std::string &seat_no,
                         double ticket_price, const Location &loc, const std::string &arrival, const std::string &seat_class)
    : TravelTicket(reg_no, scan_code, date, time, person_name, seat_no, ticket_price, loc, arrival), seatClass(seat_class) {}

void TrainTicket::PrintTicketDetails() const {
    std::cout <<"==============================\n";
    std::cout <<"         TRAIN TICKET          \n";
    TravelTicket::PrintTicketDetails();
    std::cout << "Seat Class: " << seatClass << "\n";
    std::cout <<"==============================\n";
}

void TrainTicket::Print_Ticket_To_File(const std::string &filename) const {
        std::ofstream outFile(filename, std::ios::app);
        Ticket::Print_Ticket_To_File(outFile);
        if (!outFile.is_open()) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        outFile << "Source             : " << route.GetSource() << "\n";
        outFile << "Destination        : " << route.GetDestination() << "\n";
        outFile << "Class              : " << seatClass << "\n";
        outFile << "==============================\n";


        outFile.close();
    }

///////////////////////////////////  BUS IMPLEMENTATION  /////////////////////////////////////
// -----------------------------------------------------------------------------------------//

BusTicket::BusTicket(const std::string &reg_no, const std::string &scan_code, const std::string &date,
                     const std::string &time, const std::string &person_name, const std::string &seat_no,
                     double ticket_price, const Location &loc, const std::string &arrival, const std::string &stop)
    : TravelTicket(reg_no, scan_code, date, time, person_name, seat_no, ticket_price, loc, arrival), stopOver(stop) {}

void BusTicket::PrintTicketDetails() const {
    std::cout <<"==============================\n";
    std::cout <<"            BUS TICKET         \n";
    TravelTicket::PrintTicketDetails();
    std::cout << "Stop Over: " << stopOver << "\n";
    std::cout <<"==============================\n";

}

void BusTicket::Print_Ticket_To_File(const std::string &filename) const {
    std::ofstream outFile(filename, std::ios::app);
    Ticket::Print_Ticket_To_File(outFile);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    outFile << "Source             : " << route.GetSource() << "\n";
    outFile << "Destination        : " << route.GetDestination() << "\n";
    outFile << "Stop Over          : " << stopOver << "\n";
    outFile << "==============================\n";
    outFile.close();
}


///////////////////////////////////  CENIMA IMPLEMENTATION  /////////////////////////////////////
// ----------------------------------------------------------------------------------------- --//
CinemaTicket::CinemaTicket(const std::string &reg_no, const std::string &scan_code, const std::string &date,
                           const std::string &time, const std::string &person_name, const std::string &seat_no,
                           double ticket_price, const std::string &movie, const std::string &screen)
    : Ticket(reg_no, scan_code, date, time, person_name, seat_no, ticket_price), movieName(movie), screenNumber(screen) {}

void CinemaTicket::PrintTicketDetails() const {
    std::cout <<"==============================\n";
    std::cout <<"          CENIMA TICKET        \n";
    Ticket::PrintTicketDetails();
    std::cout << "Movie: " << movieName << "\nScreen Number: " << screenNumber << "\n";
    std::cout <<"==============================\n";

}