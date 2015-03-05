#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <vector>
#include "queue.h"
#include "pair.h"

/**
 * Dictionary defines a templated pure-virtual interface for a dictionary.
 * K is the key type, V the value type
 */
template <typename K, typename V>
class Dictionary {
 public:
  virtual ~Dictionary() {}
  
  /* getSize - accessor method for number of elements in Dictionary
   */
  virtual int  getSize() = 0;              
  
  /* isEmpty - returns true if there are no elements in the Dictionary
   */
  virtual bool isEmpty() = 0;              
  
  /* insert - adds a key-value pair into the dictionary.  
   * @param key - search key for the new item
   * @param value - value to associate with the key
   * @error throws runtime_error if key already exists
   */
  virtual void insert(K key, V value) = 0;  
  
  /* update - updates the value associated with the given key in the Dictionary
   * @param key - search key for the item
   * @param value - value to associate with the key
   * @error throws runtime_error if key does not exist
   */
  virtual void update(K key, V value) = 0;  

  /* get - returns the value associated with the given key
   * @param key - key to search for
   * @return V - value stored with key
   * @error throws runtime_error if key does not exist
   */
  virtual V    get(K key) = 0;              
  
  /* containsKey - returns True if the Dictionary contains an item matching
   *               the given key
   * @param key - key to search for
   * @return bool - true if the key exists in the Dictionary
   */
  virtual bool containsKey(K key) = 0;      // Returns true if dictionary 
  
  /* remove - removes element based on search key
   * @param key - key to search for
   * @return V - value of item removed from Dictionary
   * @error throws runtime_error if key does not exist
   */
  virtual V    remove(K key) = 0;   

  /* containsValue - returns True if the Dictionary contains an item matching
   *               the given value
   * @param value - value to search for
   * @return bool - true if the value exists in the Dictionary
   */
  virtual bool containsValue(V value) = 0; 
  
  /* getKeys - returns a vector containing all of the keys in the Dictionary
   * @return STL vector object containing all keys
   */
  virtual std::vector<K> getKeys() = 0;  
  
  /* getValues - returns a vector containing all of the values in the Dictionary
   * @return STL vector object containing all values
   */
  virtual std::vector<V> getValues() = 0;   
  
  /* getItems - returns an iterator of key-values in a Pair object
   * @return dynamically allocated Queue object containing key-values in Pairs
   * NOTE: the caller is responsible for handling heap memory
   */
  virtual Queue<Pair<K,V> >* getItems() = 0;
  
  /* reportStats - for debugging purposes only.  Reports performance statistics
   * of the object to standard output
   */
  virtual void reportStats() = 0;
};

#endif
