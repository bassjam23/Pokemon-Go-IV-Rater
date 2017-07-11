//
//  LinkedList.cpp
//  Pokemon Go IV Rater
//
//  Created by Cameron Smith on 1/3/17.
//  Copyright © 2017 Cameron Smith. All rights reserved.
//

#include "LinkedList.hpp"

LLPokemon::LLPokemon()
{
    head = new Pokemon;
    head->next = NULL;
    length = 0;
}

void LLPokemon::insertPoke(Pokemon *newPoke)
{
    if (!head->next)
    {
        head->next = newPoke;
        length++;
        return;
    }
    Pokemon *p = head;
    Pokemon *q = head;
    while (q)
    {
        p = q;
        q = p->next;
    }
    p->next = newPoke;
    newPoke->next = NULL;
    length++;
}

Pokemon *LLPokemon::getPoke(string pokeKey)
{
    Pokemon *p = head;
    Pokemon *q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p->pokeName == pokeKey))
            return p;
        q = p->next;
    }
    return NULL;
}

void LLPokemon::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Pokemon *p = head;
    Pokemon *q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p->pokeName;
            if (p->next) cout << ", ";
            else cout << " ";
        }
        q = p->next;
    }
    cout << "}\n";
}

int LLPokemon::getLength()
{
    return length;
}

LLPokemon::~LLPokemon()
{
    Pokemon *p = head;
    Pokemon *q = head;
    while (q)
    {
        p = q;
        q = p->next;
        if (q) delete p;
    }
}

