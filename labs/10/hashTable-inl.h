/* Camden Wagner
 * CS035 Data Structures and Algorithms
 * 11/23/2013
 */

#include <string>
#include <stdexcept>
#include "library/arrayQueue.h"
#include <iostream>
#include <vector>

using namespace std;

//TODO: implement constructor/destructors
template <typename K, typename V>
HashTable<K,V>:: HashTable(int capacity, double maxLoadFactor){
  this->capacity = capacity;
  this->MAX_ALPHA = maxLoadFactor;
  this->size = 0;
  this->comparisons = 0;
  this->table = new std::vector<Pair<K,V> >[capacity];
}

template <typename K, typename V>
HashTable<K,V>::~HashTable() { //destructor
  for (int i = 0; i < capacity; i++) {
    table[i].clear();
  }
}

/* insert - adds a key-value pair into the dictionary.  If the key
 *          already exists,
 * @param key - search key for the new item
 * @param value - value to associate with the key
 * @error throws runtime_error if key already exists
 */
template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value) {
  /* Hash the key to an index
   * search the bucket for key (comparisons++)
   *   throw runtime_error if key exists
   * increase size
   * add item to bucket big-O(1)
   * check load factor
   *   expand if needed
   */

  int index = hash(key, this->capacity); //hash key
  this->comparisons++; //update comparisons before possible runtime_error
  if (containsKey(key)) { //check to see if key exists
    throw std::runtime_error("This key already exists.");
  }
  this->size++; //update size (+1)
  Pair<K,V> p; //new pair to push_back to table[index]
  p.first = key;
  p.second = value;
  this->table[index].push_back(p); //adding to bucket
  double size = (double)getSize();
  double cap = (double)this->capacity;
  if (getLoadFactor() < (double)(size/cap)) {
    expandCapacity(); //checking load factor
  }

}

//TODO: Implement other public methods

template <typename K, typename V>
void HashTable<K,V>::update(K key, V value) {
  int bucket = hash(key, this->capacity);
  for (int i = 0; i < table[bucket].size(); i++) {
    if (table[bucket][i].first == key) {
      table[bucket][i].second = value;
    }
  }
}

template <typename K, typename V>
V HashTable<K,V>::get(K key) {
  int bucket = hash(key, this->capacity);
  for (int i = 0; i < table[bucket].size(); i++) {
    if (table[bucket][i].first == key)
      return table[bucket][i].second;
  }
  throw std::runtime_error("Key does not exist.");
}

template <typename K, typename V>
V HashTable<K,V>::remove(K key) {
  int index = hash(key, this->capacity);
  for (int i = 0; i < table[index].size(); i++) {
    table[index].erase(table[index].begin()+i);
  }
}

template <typename K, typename V>
int HashTable<K,V>::getSize() {
  return size;
}

template <typename K, typename V>
bool HashTable<K,V>::isEmpty() {
  return size == 0;
}

template <typename K, typename V>
bool HashTable<K,V>::containsKey(K key) {
  int bucket = hash(key, this->capacity);
  for (int i = 0; i < table[bucket].size(); i++) {
    if (table[bucket][i].first == key)
      return true;
  }
  return false;
}

template <typename K, typename V>
bool HashTable<K,V>::containsValue(V value) {
  for (int i = 0; i < this->capacity; i++) {
    for (int j = 0; j < table[i].size(); j++) {
      if (table[i][j].second == value)
        return true;
    }
  }
  return false;
}

template <typename K, typename V>
std::vector<K> HashTable<K,V>::getKeys() {
  std::vector<K> keys;
  for (int i = 0; i < this->capacity; i++) {
    for (int j = 0; j < table[i].size(); j++) {
      keys.push_back(table[i][j].first);
    }
  }
  return keys;
}

template <typename K, typename V>
std::vector<V> HashTable<K,V>::getValues() {
  std::vector<V> values;
  for (int i = 0; i < this->capacity; i++) {
    for (int j = 0; j < table[i].size(); j++) {
      values.push_back(table[i][j].second);
    }
  }
  return values;
}

template <typename K, typename V>
Queue<Pair<K,V> >* HashTable<K,V>::getItems() {
  Queue<Pair<K,V> >* queue;
  std::vector<K> keys = getKeys();
  std::vector<V> values = getValues();
  for (int i = 0; i < this->capacity; i++) {
    for (int j = 0; j < table[i].size(); j++) {
      Pair<K,V> p;
      p.first = keys.back();
      p.second = values.back();
      keys.pop_back();
      values.pop_back();
      queue->enqueue(p);
    }
  }
  return queue;
}

template <typename K, typename V>
void HashTable<K,V>::reportStats() {
  cout << "\nSTATS\n-----" << endl;
  cout << "Load Factor = " << this->MAX_ALPHA << endl;
  cout << "Capacity = " << this->capacity << endl;
  cout << "Size = " << getSize() << endl;
  cout << "Comparisons = " << comparisons << endl;

  int maxBucket = 0;
  for (int i = 0; i < this->capacity; i++) {
    if (table[i].size() > maxBucket)
      maxBucket = table[i].size();
  }

  cout << "Max list size = " << maxBucket << endl;
}


//////////////////////////////HELPER METHODS/////////////////////////////////

/**
 * Given a key and a hash table capacity, returns the hash code for that key.
 * This is a default implementation for mapping ints to a table index
 */
template <typename K, typename V>
int HashTable<K,V>::hash(int key, int capacity) {
  int rv = key % capacity;
  if (rv < 0) {      // Ensuring that our return value is positive, because
    rv += capacity;  // mod in C++ can return a negative value.
  }
  return rv;
}

/**
 * Given a key and a hash table capacity, returns the hash code for that key.
 * This maps strings to a table index
 */
template <typename K, typename V>
int HashTable<K,V>::hash(std::string key, int capacity) {
  int total = 0;
  for (int i = 0; i < key.length(); ++i) {
    total = 31*total + key[i];
  }
  int rv = total % capacity;
  if (rv < 0) {      // Ensuring that our return value is positive, because
    rv += capacity;  // mod in C++ can return a negative value.
  }
  return rv;
}

//TODO: Implement other private methods

template <typename K, typename V>
double HashTable<K,V>::getLoadFactor() {
  return this->MAX_ALPHA;
}

template <typename K, typename V>
void HashTable<K,V>::expandCapacity() {
  /* double capacity value
   * allocate new table
   * for each "bucket" (pos in table)
   *   for each item in bucket
   *     get new hash value
   *     insert into new bucket
   * cleanup:
   *   remove old table
   *   set table
   */

  int oldCap = this->capacity;
  this->capacity = this->capacity*2;
  std::vector<Pair<K,V> >* newTable = new std::vector<Pair<K,V> >[capacity];
  for (int i = 0; i < oldCap; i++) {
    for (int j = 0; j < table[i].size(); ++j) {
      int bucket = hash(table[i][j].first, this->capacity);
      Pair<K,V> p = table[i][j];
      newTable[bucket].push_back(p);
    }
  }
  table = newTable;
}



