//
//  HashTable.cpp
//  Pokemon Go IV Rater
//
//  Created by Cameron Smith on 1/3/17.
//  Copyright © 2017 Cameron Smith. All rights reserved.
//  A special thanks to Karlina Beringer for hash table structure
//

#include "HashTable.hpp"

// Creates a Hash Table
HashTable::HashTable(int tableLength)
{
    array = new LLPokemon[tableLength];
    length = tableLength;
}

// Returns array location for Pokemon
int HashTable::hash(string pokeKey)
{
    int value = 0;
    for (int i = 0; i < pokeKey.length(); i++)
        value += pokeKey[i];
    return (value *pokeKey.length() ) % length;
}

// Adds a Pokemon to the Hash Table.
void HashTable::insertPoke(Pokemon *newPoke)
{
    int index = hash(newPoke->pokeName);
    array[index].insertPoke(newPoke);
}

// Returns a Pokemon from the Hash Table.
// If the Pokemon isn't found, a null pointer is returned.
Pokemon *HashTable::getPokeByKey(string pokeKey)
{
    int index = hash(pokeKey);
    return array[index].getPoke(pokeKey);
}

// Display the contents of the Hash Table.
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::getNumberOfItems()
{
    int itemCount = 0;
    for (int i = 0; i < length; i++)
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}

