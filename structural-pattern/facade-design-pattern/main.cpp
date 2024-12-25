#include <iostream>
#include "movieBooking.cpp"
using namespace std;

int main()
{
    MovieTicketBookingFacade movieTicketBookingFacade;
    movieTicketBookingFacade.BookTicket("Avatar", "user200@gmail.com", 350);
}