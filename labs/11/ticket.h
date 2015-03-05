#ifndef TICKET_H_
#define TICKET_H_
#include <string>
#include <iostream>

#include "library/pair.h"

using std::string;

/*A class for representing a destination ticket in Ticket to Ride.  Each
 * ticket has two cities (order does not matter) and a point value.
 */
class Ticket{

  private:
    string cityA;
    string cityB;
    int points;
    //User cannot call default constructor
    Ticket();

  public:
    Ticket(string a, string b, int pts);
    Pair<string, string> getCities();
    int getPoints();

    // to print ticket data
    friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
};

#endif
