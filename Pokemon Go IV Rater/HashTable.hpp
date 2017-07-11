//
//  HashTable.hpp
//  Pokemon Go IV Rater
//
//  Created by Cameron Smith on 1/3/17.
//  Copyright © 2017 Cameron Smith. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "LinkedList.hpp"

class HashTable
{
private:
    
    // Array is a reference to an array of Linked Lists.
    LLPokemon *array;
    
    // Length is the size of the Hash Table array.
    int length;
    
    int hash(string pokeKey);
    
public:
    
    // Creates Hash Tables with 13 entries
    HashTable(int tableLength = 13);
    
    // Adds a Pokemon to the Hash Table.
    void insertPoke(Pokemon *newPoke);
 
    // Returns a Pokemon from the Hash Table.
    Pokemon *getPokeByKey(string pokeKey);
    
    // Display the contents of the Hash Table.
    void printTable();
    
    // Prints a histogram illustrating the Item distribution.
    void printHistogram();
    
    // Returns the number of locations in the Hash Table.
    int getLength();
    
    // Returns the number of Items in the Hash Table.
    int getNumberOfItems();
    
    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};

#endif /* HashTable_hpp */

