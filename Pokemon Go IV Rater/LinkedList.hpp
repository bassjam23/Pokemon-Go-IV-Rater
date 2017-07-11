//
//  LinkedList.hpp
//  Pokemon Go IV Rater
//
//  Created by Cameron Smith on 1/3/17.
//  Copyright © 2017 Cameron Smith. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct Move
{
    string moveName;
    string type;
    float damage;
    float duration;
};

struct Pokemon
{
    string pokeName;
    int Attack;
    int Defense;
    int Stamina;
    string type1;
    string type2;
    string evolvesTo;
    int evolutionCode; // 1=can't evolve 2=can evolve once 3=can evolve twice
    int candyToEvolve;
    string family;
    Move *qMove1;
    Move *qMove2;
    Move *qMove3;
    Move *qMove4;
    Move *cMove1;
    Move *cMove2;
    Move *cMove3;
    Move *cMove4;
    Move *cMove5;
    Move *cMove6;
    Pokemon *next;
};

class LLPokemon
{
private:
    Pokemon *head;
    int length;
public:
    LLPokemon();
    void insertPoke(Pokemon *newPoke);
    Pokemon *getPoke(string pokeKey);
    void printList();
    int getLength();
    ~LLPokemon();
};

#endif /* LinkedList_hpp */

