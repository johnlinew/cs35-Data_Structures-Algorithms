#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "graph.h"
#include "ugraph.h"
#include "graph-algorithms.h"

using namespace std;

void SimpleGraph();
void test1();

int main() {
  //SimpleGraph();
  test1();

  return 0;
}

void SimpleGraph(){
  Graph<char,string,int>* graph = new Graph<char,string,int>();

  graph->insertEdge('a','b',"a->b",5);
  graph->insertEdge('a','c',"a->c",5);
  graph->insertEdge('b','c',"b->c",6);
  graph->insertEdge('c','a',"c->a",6);
  graph->insertEdge('c','d',"c->d",5);
  cout << (*graph) << endl;
}

void test1() {
  Graph<string,string,int>* graph = new Graph<string,string,int>();

  graph->insertVertex("Softball");
  graph->insertVertex("Bridge");
  graph->insertVertex("Sharples");
  graph->insertVertex("Soccer");
  graph->insertVertex("Wharton");
  graph->insertVertex("Magill");
  graph->insertVertex("Tennis");
  graph->insertVertex("Parrish");
  graph->insertVertex("Train");
  graph->insertVertex("Ville");
  graph->insertVertex("Tunnel");
  graph->insertVertex("Clothier");

  graph->insertEdge("Softball", "Ville", "Softball->Ville", 1);
  graph->insertEdge("Softball", "Soccer", "Softball->Soccer", 1);
  graph->insertEdge("Softball", "Tunnel", "Softball->Tunnel", 1);
  graph->insertEdge("Softball", "Train", "Softball->Train", 1);
  graph->insertEdge("Bridge", "Tennis", "Bridge->Tennis", 1);
  graph->insertEdge("Bridge", "Wharton", "Bridge->Wharton", 1);
  graph->insertEdge("Sharples", "Clothier", "Sharples->Clothier", 1);
  graph->insertEdge("Sharples", "Tunnel", "Sharples->Tunnel", 1);
  graph->insertEdge("Soccer", "Softball", "Soccer->Softball", 1);
  graph->insertEdge("Soccer", "Tennis", "Soccer->Tennis", 1);
  graph->insertEdge("Wharton", "Bridge", "Wharton->Bridge", 1);
  graph->insertEdge("Wharton", "Clothier", "Wharton->Clothier", 1);
  graph->insertEdge("Magill", "Parrish", "Magill->Parrish", 1);
  graph->insertEdge("Magill", "Train", "Magill->Train", 1);
  graph->insertEdge("Tennis", "Soccer", "Tennis->Soccer", 1);
  graph->insertEdge("Tennis", "Bridge", "Tennis->Bridge", 1);
  graph->insertEdge("Tennis", "Tunnel", "Tennis->Tunnel", 1);
  graph->insertEdge("Parrish", "Magill", "Parrish->Magill", 1);
  graph->insertEdge("Parrish", "Clothier", "Parrish->Clothier", 1);
  graph->insertEdge("Train", "Magill", "Train->Magill", 1);
  graph->insertEdge("Train", "Ville", "Train->Ville", 1);
  graph->insertEdge("Train", "Softball", "Train->Softball", 1);
  graph->insertEdge("Ville", "Train", "Ville->Ville", 1);
  graph->insertEdge("Ville", "Softball", "Ville->Softball", 1);
  graph->insertEdge("Tunnel", "Softball", "Tunnel->Softball", 1);
  graph->insertEdge("Tunnel", "Sharples", "Tunnel->Sharples", 1);
  graph->insertEdge("Tunnel", "Tennis", "Tunnel->Tennis", 1);
  graph->insertEdge("Clothier", "Wharton", "Clothier->Wharton", 1);
  graph->insertEdge("Clothier", "Parrish", "Clothier->Parrish", 1);
  graph->insertEdge("Clothier", "Sharples", "Clothier->Sharples", 1);

  cout << "Let's build a map of Swarthmore!" << endl;
  cout << "\nThe graph:" << endl;
  cout << (*graph) << endl;
  cout << "\nCan I get from Parrish to the Ville?" << endl;
  cout << "DFS: ";
  if (reachableDFS(string("Parrish"), string("Ville"), graph)) {
    cout << "yes!" << endl;
  } else {
    cout << "no" << endl;
  }
  cout << "How do I get from Parrish to the Ville?" << endl;
  cout << "Using BFS:" << endl;
  vector<string> path = shortestLengthPathBFS(
      string("Parrish"), string("Ville"), graph);
  while (!path.empty()) {
    cout << "  " << path.back() << endl;
    path.pop_back();
  }

  //shortest path length TODO

}
