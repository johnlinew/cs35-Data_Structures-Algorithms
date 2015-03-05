#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include <vector>
#include "dictionary.h"
#include "library/pair.h"
#include "library/queue.h"

/**
 * Defines a HashTable, an implementation of the Dictionary interface that
 * stores data using a hash table.  Collisions in this hash table are resolved
 * with separate chaining.
 */
template <typename K, typename V>
class HashTable : public Dictionary<K,V> {
  private:
    /* hash table data.  Each hash index stores a bucket of items mapped
     * to that index.  Each bucket is represented by a STL vector object
     */
    std::vector<Pair<K,V> >* table;   
    
    /* total number of elements in HashTable */
    int size;
    
    /* length of table array, i.e., the number of buckets */
    int capacity;
    
    /* the threshold for the load factor */
    double MAX_ALPHA;

    /* for debugging purposes: tracks the total comparisons done to 
     * stores the items in the data structure*/
    int comparisons;
    
  public:
    HashTable(int capacity = 53, double maxLoadFactor = 0.8);
    ~HashTable();

    /* public methods for the HashTable interface.  See the Dictionary interface
     * in dictionary.h for details*/
    void     insert(K key, V value);   
    void     update(K key, V value);
    V        get(K key);   
    V        remove(K key);  
    int      getSize();           
    bool     isEmpty();          
    bool     containsKey(K key);
    bool     containsValue(V value);
    std::vector<K> getKeys();  
    std::vector<V> getValues();
    Queue<Pair<K,V> >* getItems();
    void reportStats();      

  private:
    /* These are internal helper methods for the HashTable implementation*/

    /* Hash function for integer keys
     * @param key - integer key to map to an index
     * @param capacity - the number of buckets in the table
     * @return a mapping from key to an index between 0 and capacity-1
     */
    int hash(int key, int capacity); 
    
    /* Hash function for string keys
     * @param key - string key to map to an index
     * @param capacity - the number of buckets in the table
     * @return a mapping from key to an index between 0 and capacity-1
     */
    int hash(std::string key, int capacity);

    /* Obtains the current load factor for the Hashtable */
    double getLoadFactor();               
    
    /* Increases the capacity of the table to reduce the load factor
     */
    void expandCapacity();          
};

#include "hashTable-inl.h"

#endif
