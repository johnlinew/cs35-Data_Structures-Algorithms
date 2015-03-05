#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

#include <assert.h>

#include "list.h"
#include "circularArrayList.h"

using namespace std;

void testInsertGet();
void testExpandCapacity();

int main(){

  testInsertGet();
  testExpandCapacity();
}

/* A simple test for adding a few items and verifying the were placed in
 * the list*/
void testInsertGet(){
  List<string> * list = new CircularArrayList<string>();

  cout << "Test Insert/Get: ";

  list->insertAtHead("a");
  assert(list->get(0) == "a");
  cout << ".";
  cout.flush();

  list->insertAtHead("b");
  assert(list->get(0) == "b");
  cout << ".";
  cout.flush();

  assert(list->get(1) == "a");
  cout << ".";
  cout.flush();
  
  list->insertAtTail("c");
  assert(list->get(2) == "c");
  cout << ".";
  cout.flush();

  list->insertAtTail("d");
  assert(list->get(3) == "d");
  assert(list->get(2) == "c");
  assert(list->get(1) == "a");
  cout << ".";
  cout.flush();

  /* out of bounds get test*/
  try{
    list->get(list->getSize());
    assert(0); //fail if get here
  }catch(runtime_error& e){
    //pass if get here
    cout << ".";
    cout.flush();
  }

  try{
    list->get(-1);
    assert(0); //fail if get here
  }catch(runtime_error& e){
    //pass if get here
    cout << ".";
    cout.flush();
  }


  
  delete list;

  cout << " PASS" << endl;
}

/* TODO: implement this test
 */
void testExpandCapacity(){
  List<int> * list = new CircularArrayList<int>();
  cout << "Test Expanding: ";
  cout.flush();
  //Here is a simple test
  for(int i = 0; i < 11; i++){
    list->insertAtHead(i);
  }
  cout<<list->getSize()<<endl;

  for(int i = 0; i < 11; i++){
    list->removeHead();
  }


  cout<<list->getSize()<<endl;
  for(int i = 0; i < 101; i++){
    list->insertAtHead(i);
  }

  cout<<list->getSize()<<endl;
  assert(list->getSize() == 101);
  cout << " PASS" << endl;
  cout<<list->peekHead();
  CircularArrayList<string>* lst=new CircularArrayList<string>();
  lst->insertAtHead("bob");
  //lst->replaceItem(0,2);
  cout<<lst->peekHead()<<endl;
  cout<<"list[9]= "<<lst->replaceItem(9,"rob")<<endl;
   cout<<lst->peekHead()<<endl;

  
  //This is a simple test and will not completely prove your method works
  //you must make it more complex
  
  delete list;
  delete lst;
}

