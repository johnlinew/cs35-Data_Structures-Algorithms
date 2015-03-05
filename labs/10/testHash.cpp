#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"

using namespace std;
void test1();
void myTest();
void helper(HashTable<string,int>* table);

int main() {  
  
  test1();
  myTest();

  return 0;
}

/* test1 - add comment here explaining purpose
 */
  //TODO: add comments below to indicate you understand the purpose of the
  // given tests
void test1(){
  HashTable<string,int> stringTable; //What is capacity and max alpha?  capacity = 53 maxAlpha = 0.8

  ifstream wordsFile("/usr/local/doc/sowpods.txt"); //quicker way of opening file with an ifstream
  assert(wordsFile.good()); //makes sure file opened properly
  string word;
  int counter = 0; //used to verify that the inserted items are done properly
  while (wordsFile >> word) {
    stringTable.insert(word, counter);
    ++counter;
    assert(stringTable.containsKey(word)); //checking against the dictionary that the word was inserted
  }
  assert(stringTable.getSize() == counter);
  wordsFile.close(); //closes file

  wordsFile.open("/usr/local/doc/sowpods.txt"); //reopen file to read in everything for tests again
  assert(wordsFile.good()); //makes sure file opened properly
  counter = 0; //reset to 0 to start over with tests below
  while (wordsFile >> word) {
    assert(stringTable.get(word) == counter); //tests the words that were entered to the stringTable (Hash Table)
    stringTable.update(word, 2*counter);
    assert(stringTable.get(word) == 2*counter); //makes sure update works
    ++counter;
  }
  wordsFile.close(); //closes file
  stringTable.reportStats();

}

  // TODO:  Add tests to ensure your functions work
  
  // TODO:  Add tests to analyze the runtime performance of the hash table
  //         by varying the initial capacity and/or load factor


void myTest() {
  
  HashTable<string,int>* table1 = new HashTable<string,int>(80, 0.05);
  cout << "\nTable 1 ";
  helper(table1);
  HashTable<string,int>* table2 = new HashTable<string,int>(80, 0.5);
  cout << "\nTable 2 ";
  helper(table2);
  HashTable<string,int>* table3 = new HashTable<string,int>(80, 0.95);
  cout << "\nTable 3 ";
  helper(table3);

}

void helper(HashTable<string,int>* table) {
  ifstream wordsFile("/usr/local/doc/sowpods.txt"); //quicker way of opening file with an ifstream
  assert(wordsFile.good()); //makes sure file opened properly
  string word;
  int counter = 0; //used to verify that the inserted items are done properly
  while (wordsFile >> word) {
    table->insert(word, counter);
    ++counter;
    assert(table->containsKey(word)); //checking against the dictionary that the word was inserted
  }
  assert(table->getSize() == counter);
  wordsFile.close(); //closes file

  wordsFile.open("/usr/local/doc/sowpods.txt"); //reopen file to read in everything for tests again
  assert(wordsFile.good()); //makes sure file opened properly
  counter = 0; //reset to 0 to start over with tests below
  while (wordsFile >> word) {
    assert(table->get(word) == counter); //tests the words that were entered to the stringTable (Hash Table)
    table->update(word, 2*counter);
    assert(table->get(word) == 2*counter); //makes sure update works
    ++counter;
  }
  wordsFile.close(); //closes file
  table->reportStats();
}

