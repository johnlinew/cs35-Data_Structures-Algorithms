//Camden Wagner
//CS35
//Professor Soni

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

#include "ugraph.h"
#include "graph-algorithms.h"
#include "library/pair.h"
#include "ticket.h"
#include "library/dictionary.h"
#include "library/list.h"

using namespace std;

typedef Graph<string,string,int> TTRMap; //To simplify syntax

//These methods have been provided as a starting point.  You should modify
//  them to fit your actual design
//TODO: You should change/move these files to improve your design
TTRMap* loadMapFromFile(string mapfile);
int getMenuChoice();
void printAndDisplay(TTRMap* g);
void printAvailableRoutes(TTRMap* g, TTRMap* p);
void claimRoute(TTRMap* p, TTRMap* o, TTRMap* g, string player);
vector<Ticket>* loadTicketsFromFile(string ticketfile, TTRMap* g);
void drawTickets(vector<Ticket>* deck, vector<Ticket>* playerHand, TTRMap* g, TTRMap* p);
void ticketStatus(vector<Ticket>* playerHand, TTRMap* g, TTRMap* p);
void printTickets(vector<Ticket>* drawn, TTRMap* g, TTRMap* p);
void calcScore(vector<Ticket>* playerHand, TTRMap* g, TTRMap* p);

int main(int argc, char *argv[]) {

  if(argc != 3) {
    cerr << "Incorrect number of arguments" << endl;
    cerr << "Usage: ticketToRide map-file ticket-file" << endl;
    return 1;
  }

  string mapfile = argv[1];
  string ticketfile = argv[2]; //added this to actually allow myself to load in ticket file
  //whole gameboard: never changes after initialization
  Graph<string,string,int>* gameboard = loadMapFromFile(mapfile);
  //players personal board: changes when player purchases routes (starts empty)
  Graph<string,string,int>* playerBoard = new UGraph<string,string,int>();
  //opponents personal board: changes when opponent purchases routes (starts empty)
  Graph<string,string,int>* opponentBoard = new UGraph<string,string,int>();
  //deck is a deck vector that is initialized at the beginning of the game
  vector<Ticket>* deck = loadTicketsFromFile(ticketfile, gameboard);
  //playerHand is a vector like the deck that is used to store what tickets the player is holding
  vector<Ticket>* playerHand = new vector<Ticket>();

  //first round of drawing tickets
  drawTickets(deck, playerHand, gameboard, playerBoard);
  int choice = getMenuChoice();
  
  //loop to keep the game going, unless the choice is 0 to exit, continue returning to menu
  while(choice != 0){
    if (choice == 1) {
      printAndDisplay(gameboard);
    } else if (choice == 2) {
      printAndDisplay(playerBoard);
    } else if (choice == 3) {
      printAvailableRoutes(gameboard, playerBoard);
    } else if (choice == 4) {
      claimRoute(playerBoard, opponentBoard, gameboard, "You");
    } else if (choice == 5) {
      claimRoute(opponentBoard, playerBoard, gameboard, "Your opponent");
    } else if (choice == 6) {
      drawTickets(deck, playerHand, gameboard, playerBoard);
    } else if (choice == 7) {
      ticketStatus(playerHand, gameboard, playerBoard);
    } else if (choice == 8) {
      calcScore(playerHand, gameboard, playerBoard);
    }

    choice = getMenuChoice();
  }

  cout << "\nThanks for playing!\n" << endl;

  //deletion of dynamically allocated contents
  delete gameboard;
  delete playerBoard;
  delete opponentBoard;
  delete deck;
  delete playerHand;
  
  return 0;
}

//loadTickets is basically a function that mirrors loadMapFromFile except it stores tickets in
//vectors instead of vertices and edges in a graph
vector<Ticket>* loadTicketsFromFile(string ticketfile, TTRMap* g) {
  vector<Ticket>* deck = new vector<Ticket>;

  ifstream input(ticketfile.c_str());
  if(input.is_open() == false){
    throw runtime_error("File does not exist for loadTicketsFromFile");
  }

  string line;
  int next, prev, length;
  string cityA, cityB, rest;
  int pts;

  while (getline(input, line)) {
    prev = 0;

    next = line.find_first_of(':', prev);
    cityA = line.substr(0, next);
    prev = next+1;

    next = line.find_first_of(':', prev);
    cityB = line.substr(prev/*, next-prev*/);
    prev = next+1;

    //using dijkstras to find the distance from the built dictionary
    Dictionary<string,int>* tempDict = dijkstras(cityA, g);
    pts = tempDict->get(cityB);
    Ticket t = Ticket(cityA, cityB, pts);
    deck->push_back(t);
  }

  return deck;
}

/* Loads the game board from file into a Graph object
 * @param mapfile - location of file defining the game board
 * @return TTRMap* - dynamically allocated graph object with
 *                   cities (vertex) and routes (edges)
 * @error throws runtime_error if file does not exist
 * The caller is responsible for cleaning up dynamically allocated memory
 */
TTRMap* loadMapFromFile(string mapfile) {
  //The map is an undirected graph
  TTRMap *graph = new UGraph<string,string,int>;

  ifstream input(mapfile.c_str());
  if(input.is_open() == false){
    throw runtime_error("File does not exist for loadMapFromFile");
  }

  
  string edge;
  int next, prev;
  string src, dest, rest;
  int length;
  
  /*getline obtains an entire line as a string.  This loop parses one line
   * in the format:
   *   vertexA : vertexB
   * and defines an undirected edge between vertexA and vertexB
   */
  while(getline(input, edge)) {
    prev = 0;

    next = edge.find_first_of(':', prev);
    src = edge.substr(0, next);
    prev = next+1;

    next = edge.find_first_of(':', prev);
    dest = edge.substr(prev, next-prev);
    prev = next+1;
    
    rest = edge.substr(prev);
    length = atoi(rest.c_str());


    graph->insertEdge(src, dest, src + " -- " + dest, length);
  }
  return graph;
}

/* Displays the main menu and obtains a legal choice from the user
 * @return int indicating the user's choice between 0 and 8
 */
int getMenuChoice(){
  int i = 0;
  cout << "\nMenu:\n";
  cout << "\t(" << i++ << ") Exit\n";
  cout << "\t(" << i++ << ") Print/display game board\n";
  cout << "\t(" << i++ << ") Print/display my routes\n";
  cout << "\t(" << i++ << ") Print available routes\n";
  cout << "\t(" << i++ << ") Claim route for self\n";
  cout << "\t(" << i++ << ") Claim route for opponent\n";
  cout << "\t(" << i++ << ") Draw and select tickets\n";
  cout << "\t(" << i++ << ") Print tickets and their status\n";
  cout << "\t(" << i++ << ") Calculate current score\n\n";
  
  int choice = -1;
  while(choice < 0 || choice >= i){
    cout << "Enter choice: ";
    cin >> choice;
  }
  cin.ignore(); //Removes new line character in case you want to use getline
  cout << endl;

  return choice;
}

/* Prints and displays map in neato format using graphViz package
 * @param g - a Graph object
 * @error throws runtime_error if g is NULL
 */
void printAndDisplay(TTRMap *g){
  if(g == NULL){
    throw runtime_error("printAndDisplay called on undefined graph");
  }
  /*This displays a graph.  This will not work on an outside system so
   * comment these four lines out if you are working from home */
  g->graphViz("out.neato");
  system("neato -Tpng -o out.png out.neato");
  system("xv out.png");
  system("rm -f out.png out.neato");
}

//printAvailableRoutes takes in the gameboard and the player board and finds which
//routes are in the gameboard that are not in the players board, hence the paths
//that are left for the taking
void printAvailableRoutes(TTRMap* g, TTRMap* p) {
  if(g == NULL){ //error checking
    throw runtime_error("printAvailableRoutes called on undefined graph");
  }
  if(p == NULL){ //error checking
    throw runtime_error("printAvailableRoutes called on undefined graph");
  }
  cout << "\nAvailable Routes:" << "\n-----------------\n" << endl;
  vector<Edge<string,string,int> > edges = g->getEdges();
  while (!edges.empty()) {
    Edge<string,string,int> currEdge = edges.back();
    edges.pop_back();
    if (!p->containsEdge(currEdge.getSrc(), currEdge.getDest())) {
      cout << currEdge.getSrc() << " --- " << currEdge.getDest() << " : " <<
        currEdge.getWeight() << " Train Cars" << endl;
    }
  }
}

//claimRoute takes in the player's board, the opponents board and the gameboard and
//a string that is included specifically for cout output
//claimRoute uses polymorphism to allow the option to claim for player and opponent 
//to both be done through this method
void claimRoute(TTRMap* p, TTRMap* o, TTRMap* g, string player) {
  if(p == NULL){ //error checking
    throw runtime_error("printAvailableRoutes called on undefined graph");
  }
  string cityA, cityB;
  cout << "Enter city: ";
  getline(cin,cityA);
  if (!g->containsVertex(cityA)) { //error checking
    cerr << "ERROR: That city does not exist. Returning to main menu." << endl;
    return;
  }
  cout << "Enter city: ";
  getline(cin,cityB);
  if (!g->containsVertex(cityB)) { //error checking
    cerr << "ERROR: That city does not exist. Returning to main menu." << endl;
    return;
  }
  if (!g->containsEdge(cityA, cityB)) { //error checking
    cerr << "ERROR: Route is not available. Returning to main menu." << endl;
    return;
  }
  if (p->containsEdge(cityA, cityB)) { //error checking
    cerr << "ERROR: This player already owns this route. Returning to main menu." <<endl;
    return;
  }
  if (o->containsEdge(cityA, cityB)) { //error checking
    cerr << "ERROR: This player's opponent already owns this route. Returning to main menu." << endl;
    return;
  }
  
  p->insertEdge(cityA, cityB, cityA + " --> " + cityB, g->getEdge(cityA, cityB).getWeight());

  cout << player << " successfully claimed the route for " << g->getEdge(cityA, cityB).getWeight() <<
    " points" << endl;

}

//drawTickets takes in the deck, the playerHand, the gameboard and the player board
//the player selects the tickets they want, which are taken from the deck and put into
//the playerHand
void drawTickets(vector<Ticket>* deck, vector<Ticket>* playerHand, TTRMap* g, TTRMap* p) {
  
  vector<Ticket>* deckCopy = deck; //so I do not mess up deck
  vector<Ticket>* drawn = new vector<Ticket>(); //temporary vector to hold drawn tickets
  int deckSize = deck->size();
  int i,j,k = 0;
  srand(time(NULL));
  i = rand() % (deckSize-2);
  j = i+1;
  k = j+1;
  drawn->push_back(deck->at(i));
  drawn->push_back(deck->at(j));
  drawn->push_back(deck->at(k));

  cout << "\nSelect a ticket to add to your hand:\n";
  printTickets(drawn, g, p);

  int choice = -1;
  int chosen = 0; //variable that increments the number of tickets selected by user
  while (choice < 0 || choice > 3) { //loop to continue if more tickets will be offered
    cout << "\nEnter choice or 0 to discard remaining tickets: ";
    cin >> choice;
    int used = 0;
    int used2 = 0;
    if (choice == 0) {
      return;
    } else if (choice == 1 && used != 1 && used2 != 1) {
      cout << "Selected ticket 1" << endl;
      playerHand->push_back(drawn->at(0));
      used = 1;
    } else if (choice == 2 && used != 2 && used2 != 2) {
      cout << "Selected ticket 2" << endl;
      playerHand->push_back(drawn->at(1));
      used = 2;
    } else if (choice == 3 && used != 3 && used2 != 3) {
      cout << "Selected ticket 3" << endl;
      playerHand->push_back(drawn->at(2));
      used = 3;
    } else {
      cout << "Not an option. Try again." << endl;
      chosen--;
    }
    chosen++;
    if (chosen != 3) {
      choice = -1;
    }
    if (choice != 0) {
      printTickets(drawn, g, p);
    }
  }

  delete drawn; //getting rid of temporary vector
}

//ticketStatus prints information about the tickets in the playerHand
//therefore, it needs to pass in the playerHand, gameboard and playerBoard
void ticketStatus(vector<Ticket>* playerHand, TTRMap* g, TTRMap* p) {
  cout << "Your current destination tickets and their status:" << endl;
  int handSize = playerHand->size();
  for (int i = 0; i < handSize; i++) { //loop through each ticket
    cout << "  " << i+1 << ") " << playerHand->at(i).getCities().first << " to " <<
      playerHand->at(i).getCities().second << " for " << playerHand->at(i).getPoints() << " points" << endl;
    if (p->containsVertex(playerHand->at(i).getCities().first) && p->containsVertex(playerHand->at(i).getCities().second)) {
      if (reachableDFS(playerHand->at(i).getCities().first, playerHand->at(i).getCities().second, p)) {
        cout << "          Ticket punched." << endl;
      }
    } else {
      cout << "          Ticket not punched, ";
      if (reachableDFS(playerHand->at(i).getCities().first, playerHand->at(i).getCities().second, g)) {
        cout << " but path still exists" << endl;
      } else {
        cout << " no path exists" << endl;
      }
    }
    cout << "          You need at least ";
    vector<string> vertices = shortestLengthPathBFS
      (playerHand->at(i).getCities().first, playerHand->at(i).getCities().second, g);
    int resources = 0; //counter for the amount of resources necessary
    for (int y = 0; y < vertices.size()-1; y++) {
      if (p->containsEdge(vertices.at(y), vertices.at(y+1))) {
        //allow for free
      } else {
        Edge<string,string,int> edge = g->getEdge(vertices.at(y), vertices.at(y+1));
        resources += edge.getWeight();
      }
    }
    cout << resources << " cars to complete the path." << endl;
  }
}

//printTickets - helper function to be called in drawTickets for good program style
//passed in: drawn (temp) vector, gameboard and playerBoard
void printTickets(vector<Ticket>* drawn, TTRMap* g, TTRMap* p) {
  for (int x = 0; x < 3; x++) {
    cout << "  " << x+1 << ") ";
    cout << drawn->at(x).getCities().first << " to " << drawn->at(x).getCities().second << " for " <<
      drawn->at(x).getPoints() << endl;
    if (reachableDFS(drawn->at(x).getCities().first, drawn->at(x).getCities().second, g)) {
      cout << "                 Achieveable." << endl;
    } else {
      cout << "                 Unachieveable." << endl;
    }
    cout << "                 Fewest routes needed (original board): ";
    vector<string> vertices = shortestLengthPathBFS
      (drawn->at(x).getCities().first, drawn->at(x).getCities().second, g);
    cout << vertices.size() << endl;
    cout << "                 Fewest train cars needed (current board): ";
    int resources = 0;
    for (int y = 0; y < vertices.size()-1; y++) {
      if (p->containsEdge(vertices.at(y), vertices.at(y+1))) {
        //allow for free
      } else {
        Edge<string,string,int> edge = g->getEdge(vertices.at(y), vertices.at(y+1));
        resources += edge.getWeight();
      }
    }
    cout << resources << endl;
  }
}

//calcScore takes in the playerHand, gameboard and playerBoard
//this function simply tallies up and prints out where points are gained and lost
void calcScore(vector<Ticket>* playerHand, TTRMap* g, TTRMap* p) {
  cout << "Your current score breakdown:" << endl;
  cout << "-----------------------------" << endl;
  cout << "Routes:" << endl;
  int TOTAL_POINTS = 0; //tally of total points
  vector<Edge<string,string,int> > edges = p->getEdges();
  while (!edges.empty()) {
    Edge<string,string,int> currEdge = edges.back();
    edges.pop_back();
    cout << "     " << currEdge.getSrc() << " --- " << currEdge.getDest() << ": +"
      << currEdge.getWeight() << " points" << endl;
    TOTAL_POINTS += currEdge.getWeight(); //+ points
  }

  cout << "\nDestination tickets:" << endl;
  int handSize = playerHand->size();
  for (int i = 0; i < handSize; i++) {
    cout << "     " << playerHand->at(i).getCities().first << " --- " <<
      playerHand->at(i).getCities().second << ": ";
    if (p->containsVertex(playerHand->at(i).getCities().first) && p->containsVertex(playerHand->at(i).getCities().second)) { //checks to make sure the vertices are in p to avoid seg fault
      if (reachableDFS(playerHand->at(i).getCities().first, playerHand->at(i).getCities().second, p)) {
        cout << "+" << playerHand->at(i).getPoints() << " points" << endl;
        TOTAL_POINTS += playerHand->at(i).getPoints(); //+ points
      } else {
        cout << "-" << playerHand->at(i).getPoints() << " points" << endl;
        TOTAL_POINTS -= playerHand->at(i).getPoints(); //- points
      }
    } else {
      cout << "-" << playerHand->at(i).getPoints() << " points" << endl;
      TOTAL_POINTS -= playerHand->at(i).getPoints(); //- points
    }
  }
  cout << "\nTotal: " << TOTAL_POINTS << " points" << endl; // Total: x points
}

