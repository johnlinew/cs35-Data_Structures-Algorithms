#include "ticket.h"

/* Constructor - initializes data members of Ticket object
 * @param a, b - the two cities connected by the destination ticket
 * @param pts - the point value for the ticket
 */
Ticket::Ticket(string a, string b, int pts){
  this->cityA = a;
  this->cityB = b;
  this->points = pts;
}

/* getCities - accessor method for cities
 * @return - retruns both cities as a Pair of strings
 */
Pair<string, string> Ticket::getCities(){
  return Pair<string, string>(cityA, cityB);
}

/* getPoints - returns point value of ticket
 */
int Ticket::getPoints(){
  return this->points;
}

/* operator<< - outputs ticket object in format:
 *   "cityA to cityB for N points" where N is an integer
 * @param os - stream to print to
 * @param ticket - ticket object to print
 * @return original stream with possibly changed state
 */
std::ostream& operator<<(std::ostream& os, const Ticket& ticket){
  os << ticket.cityA << " to " << ticket.cityB << " for "
     << ticket.points << " points" << std::endl;
  return os;
}

