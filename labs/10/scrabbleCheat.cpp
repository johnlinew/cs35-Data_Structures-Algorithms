/* Camden Wagner
 * CS035 Data Structures and Algorithms
 * 11/23/2013
 */

#include <iostream>
#include "hashTable.h"
#include <string>
#include <locale>
#include <fstream>
#include <assert.h>
#include "library/binaryHeap.h"
#include "library/queue.h"

using namespace std;

void menu(HashTable<string,int> dictionary);
void checkPlay(HashTable<string,int> dictionary);
void anagrams(HashTable<string,int> dictionary);
void legalPlays(HashTable<string,int> dictionary);
string lowercase(string word);
string getAlpha(string letters);
void printAnagrams(std::vector<string> anagrams);
void printPlays(std::vector<string> plays);
std::vector<string> getAllLegalPlays(string letters);

//Throughout all of the main functions, the dictionary HashTable is being passed around, and
//is never altered in any functions, just used to compare against.

int main() {

  cout << "\nWelcome to Scrabble Solver\n" << endl;

  HashTable<string,int> dictionary; //allocate dictionary
  ifstream inFile("/usr/local/doc/sowpods.txt");
  string word;
  int counter = 0;
  while (inFile >> word) {  //load the dictionary
    word = lowercase(word);
    dictionary.insert(word, counter);
    ++counter;
    assert(dictionary.containsKey(word));
  }

  menu(dictionary);

  return 0;
}

//main menu function that the other three option functions come back to after returning
void menu(HashTable<string,int> dictionary) {
  cout << "Menu:" << endl;
  cout << "     (0) Exit\n     (1) See if a play is legal\n     (2) Find all legal anagrams for a set of tiles\n     (3) Find all legal plays for a set of tiles\n" << endl;
  
  int choice;
  cout << "Select your choice (0-3) :: ";
  cin >> choice;
  if (choice == 0) {
    cout << "\nThanks for playing!" << endl;
    return;
  } else if (choice == 1) {
    checkPlay(dictionary);
  } else if (choice == 2) {
    anagrams(dictionary);
  } else if (choice == 3) {
    legalPlays(dictionary);
  } else {
    cerr << "Not a choice" << endl;
    menu(dictionary);
  }

}

//option 1, check a play to see if it is legal
void checkPlay(HashTable<string,int> dictionary) {
  cout << "\nEnter the word you wish to play: ";
  string word;
  cin >> word; //getting the word from user
  word = lowercase(word); //make word lowercase
  if (dictionary.containsKey(word)) { //check if it is in the dictionary or not
    cout << "Congratulations! You have found a legal play!\n" << endl;
  } else {
    cout << "Sorry, that is not a legal play.\n" << endl;
  }
  menu(dictionary); //back to menu
}

void anagrams(HashTable<string,int> dictionary) {
  cout << "\nEnter the letters you wish to play: ";
  string letters;
  cin >> letters; //getting the letters from the user
  letters = lowercase(letters); //make lowercase
  letters = getAlpha(letters);
  std::vector<string> anagrams; //eventually the vector of strings that will be printed out
  std::vector<string> allWords = dictionary.getKeys(); //vector of all words in the dictionary
  int allWordsLength = allWords.size();
  for (int i = 0; i < allWordsLength; i++) { //loop to check the letters against the dictionary
    if (letters == getAlpha(allWords[i])) {
      anagrams.push_back(allWords[i]); //adding to anagrams vector
    }
  }

  printAnagrams(anagrams); //print function to output the anagrams

  menu(dictionary); //back to menu

}

void legalPlays(HashTable<string,int> dictionary) {
  cout << "\nEnter the letters you wish to play: ";
  string letters;
  cin >> letters; //getting the letters from the user
  letters = lowercase(letters); //make lowercase
  std::vector<string> anagrams = getAllLegalPlays(letters);
  int anaSize = anagrams.size();

  for (int i = 0; i < anaSize; i++) {
    anagrams[i] = getAlpha(anagrams[i]); //loop sets all the anagrams of the letters to ordered
                                         //alphabetical arrangement
  }

  std::vector<string> plays; //eventually the vector of strings that will be printed out
  std::vector<string> allWords = dictionary.getKeys();
  int allWordsLength = allWords.size();
  for (int h = 0; h < anaSize; h++) {
    for (int i = 0; i < allWordsLength; i++) {
      if (anagrams[h] == getAlpha(allWords[i])) {
        plays.push_back(allWords[i]); //adding to plays if in the dictionary
      }
    }
  }
  
  printPlays(plays); //print function for all possible plays

  menu(dictionary); //back to menu

}


//lowercase(string word) returns the inputted string, just all in lowercase.
//I looked online for information on how to do this. Locale was a new one, for
//me. Used for ease and good coding style.
string lowercase(string word) {
  locale loc;
  string answer;
  for (string::size_type i = 0; i < word.length(); ++i) {
    answer += tolower(word[i],loc);
  }
  return answer;
}

//getAlpha uses a binaryHeap to get the word I want alphabetized.
string getAlpha(string letters) {
  BinaryHeap<char,char> getInOrder;
  for (int i = 0; i < letters.length(); i++) {
    getInOrder.insert(letters[i], letters[i]);
  }
  string alphaWord = "";
  for (int j = 0; j < letters.length(); j++) {
    alphaWord += getInOrder.removeMin();
  }
  return alphaWord;
}

//print function, for good coding style
void printAnagrams(std::vector<string> anagrams) {
  if (anagrams.size() == 0) {
    cout << "Sorry, no anagram exists." << endl;
  } else {
    cout << "Your legal plays are:" << endl;
  }
  for (int j = 0; j < anagrams.size(); j++) {
    cout << "   " << anagrams[j] << endl;
  }
  cout << endl;
}

//second print function, for good coding style
void printPlays(std::vector<string> plays) {
  if (plays.size() == 0) {
    cout << "Sorry, no possible plays." << endl;
  } else {
    cout << "All possible plays:" << endl;
  }
  for (int j = 0; j < plays.size(); j++) {
    cout << "   " << plays[j] << endl;
  }
  cout << endl;
}

//this function is recursively called to create a vector that has all of (what I call anagrams
//for convenience in the code) the different plays you can make with that set of letters
//function returns the vector of string of possible plays
std::vector<string> getAllLegalPlays(string letters) {
  std::vector<string> allAnagrams; //not actually anagrams, just used to not have long var names
  if (letters.length() == 0) {
    string temp = getAlpha(letters);
    allAnagrams.push_back(temp);
    return allAnagrams;
  } else {
    int i = letters.length()-1;
    string newStr = letters.substr(1, i);
    std::vector<string> tempVect = getAllLegalPlays(newStr);
    int length = tempVect.size();
    for (int j = 0; j < length; j++) {
      string a = letters[0] + tempVect[j];
      string b = getAlpha(a);
      tempVect.push_back(b);
    }
    return tempVect;
  }
  return allAnagrams;
}

