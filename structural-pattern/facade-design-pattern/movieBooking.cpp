#include <iostream>
using namespace std;

class SeatReservation
{
public:
    void AllocateSeat(string movie)
    {
        cout << "Selected seat allocation logic goes here for movie - " << movie << "\n";
    }
};

class PaymentProcessor
{
public:
    void AcceptPayment(double amount)
    {
        cout << "Accepting Payment - " << amount << "\n";
    }
};

class EmailSender
{
public:
    void SendEmail(string email, string movie)
    {
        cout << "Sending booking deatils to - " << email << " for " << movie << "\n";
    }
};

class MovieTicketBookingFacade
{
    SeatReservation reservation;
    PaymentProcessor payment;
    EmailSender emailSender;

    public:

    void BookTicket(string movie, string email, double amount) {
        reservation.AllocateSeat(movie);
        payment.AcceptPayment(amount);
        emailSender.SendEmail(email, movie);
    }

};