#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string.h>
#include <stdlib.h>
/**
 * @defgroup hashtable HashTable
 *
 * @brief A hashtable containing integers
 *
 * This module provides and implementation of a hashtable, containing
 * integers.
 * 
 * The buckets in this hashtable are dynamically allocated and can in principle 
 * hold an unlimited number of elements.
 * 
 * The number of buckets however is set to BUCKET_SIZE which could impact 
 * the speed of this module.
 * 
 * 
 * Example usage:
 *
 *
 *     HashTable* h = hash_create();
 *     hash_insert(h, cstring1, 4);
 *     hash_insert(h, cstring2, 8);
 *     hash_lookup(h, cstring1); // Pointer to integer 4
 *     hash_lookup(h, cstring2); // Pointer to integer 8
 *     hash_lookup(h, cstring3); // NULL pointer
 *     char** keys;
 *     int* values;
 *     int n = hash_as_array(h, &keys, &values);
 *     // keys now contains all the keys
 *     // values contains all the values
 *     // an n contains the number of elements.
 *     hash_destroy(tab); 
 * @{
 */
#define BUCKET_SIZE 8

struct hash_table;
struct pair;
struct bucket;

typedef struct hash_table HashTable;
/**
 * @brief      Creates an empty HashTable
 *
 * @return     The empty HashTable
 */

HashTable* hash_create(void);
/**
 * @brief      Frees memory allocated by the HashTable
 * 
 * Frees all memory allocated by the HashTable
 *
 * @param      tab   HashTable
 * @see hash_create
 */

void hash_destroy(HashTable *tab);
/**
 * @brief      Looks up a value based on key
 *
 * Retruns a pointer to the value stored at the index key
 * in the HashTable
 * 
 *
 * @param      tab   HashTable
 * @param[in]  key   Index
 *
 * @return     Integer pointer
 * @see hash_insert
 */

int* hash_lookup(HashTable *tab, const char *key);
/**
 * @brief      Inserts a new pair into the HashTable
 * 
 * Creates and inserts a new pair into the underlying HashTable
 * The key will be copied over into a new C_STRING and saved in the HashTable
 * so you still have ownership of the original key.
 * 
 *
 * @param      tab    HashTable
 * @param[in]  key    Index
 * @param[in]  value  Value
 * @see hash_lookup
 */

void hash_insert(HashTable *tab, const char *key, int value);
/**
 * @brief      Inserts the HashTable into a C_STRING array and integer array.
 *
 * Inserts the HashTable's keys into the keys array and it's
 * values into the values array. And then returns the number of elements
 * in the HashTable.
 * 
 * Remember that this will be pointer to the original pairs and should not
 * be freed by itself, see hash_destroy.
 *
 * @param      tab     HashTable
 * @param      keys    Keys
 * @param      values  Values
 *
 * @return     Number of elements
 * @see hash_destroy
 */
size_t hash_as_array(HashTable *tab, char ***keys, int **values);
/** @} */

#endif /* HASHTABLE_H */
