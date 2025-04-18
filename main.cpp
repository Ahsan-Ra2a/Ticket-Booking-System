#include "project"
#include "Account"

int main(void) {
    // Home user;
    // user.Front_Page();

    Location airplaneRoute("New York", "Los Angeles");
    AirplaneTicket flight("REG123", "BAR456", "2024-12-10", "10:00 AM",
                          "Ahsan", "12A", 500.00, airplaneRoute,
                          "2024-12-10 02:00 PM", "Business");
    flight.PrintTicketDetails();
    flight.Print_Ticket_To_File("ticket.txt");

     
    Location trainRoute("Berlin", "Munich");
    TrainTicket train("REG789", "BAR321", "2024-12-11", "08:00 AM",
                      "Ali", "S-5", 150.00, trainRoute,
                      "2024-12-11 01:00 PM", "First Class");
    train.PrintTicketDetails();
    train.Print_Ticket_To_File("ticket.txt");


    Location busRoute("Houston", "Austin");
    BusTicket bus("REG456", "BAR654", "2024-12-12", "07:00 AM",
                  "Raja", "B12", 30.00, busRoute,
                  "2024-12-12 09:30 AM", "Midway Stop");
    bus.PrintTicketDetails();
    bus.Print_Ticket_To_File("ticket.txt");


    CinemaTicket cinema("REG555", "BAR999", "2024-12-13", "06:00 PM",
                        "Charlie Brown", "C10", 12.50,
                        "Avatar: The Way of Water", "Screen 1");
    cinema.PrintTicketDetails();
    // cinema.Print_Ticket_To_File("ticket.txt");


}