//
//  main.cpp
//  Pokemon Go IV Rater
//
//  Created by Cameron Smith on 1/3/17.
//  Copyright © 2017 Cameron Smith. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <stdexcept>
#include <stdio.h>
#include <math.h>
#include "HashTable.hpp"

double findLevel(double levelSD);
double findCpM(double pokeLvl);
void findMaxReqs(int &pUps, int &cMax, int &sMax, double currLvl, double maxLvl);
float typeEffectiveMultiplier(Move *attackMove, string Type);

int main()
{
    // QUICK MOVES
    Move *IronTail = new Move {"Iron Tail", "Steel", 11, .8};
    Move *Counter = new Move {"Counter", "Fight", 12, .9};
    Move *Bite = new Move {"Bite", "Dark", 6, .5};
    Move *KarateChop = new Move {"Karate Chop", "Fight", 8, .8};
    Move *BulletPunch = new Move{"Bullet Punch", "Steel", 9, .9};
    
    cout << "Iron Tail's type is " << IronTail->type << endl;
    
    // CHARGE MOVES
    Move *CloseCombat = new Move {"Close Combat", "Fight", 100, 2.3};
    Move *StoneEdge = new Move {"Stone Edge", "Rock", 100, 2.3};
    Move *FireBlast = new Move {"Fire Blast", "Fire", 140, 4.2};
    Move *DynamicPunch = new Move {"Dynamic Punch", "Fight", 90, 2.7};
    Move *HeavySlam = new Move {"Heavy Slam", "Steel", 70, 2.1};
    Move *CrossChop = new Move {"Cross Chop", "Fight", 50, 1.5};
    Move *Submission = new Move {"Submission", "Fight", 60, 2.2};
    Move *Crunch = new Move {"Crunch", "Dark", 70, 3.2};
    
    // TO FILL AN EMPTY SLOT
    Move *NoMove = new Move {"NoMove", "N", 0, 1};
    
    Pokemon *Bulbasaur = new Pokemon {"Bulbasaur", 118, 118, 90, "Grs", "Poi", "Ivysaur", 3, 25, "Bulbasaur", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ivysaur = new Pokemon {"Ivysaur", 151, 151, 120, "Grs", "Poi", "Venusaur", 2, 100, "Bulbasaur", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Venusaur = new Pokemon {"Venusaur", 198, 198, 160, "Grs", "Poi", "", 1, 0, "Bulbasaur", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Charmander = new Pokemon {"Charmander", 116, 96, 78, "Fire", "", "Charmeleon", 3, 25, "Charmander", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Charmeleon = new Pokemon {"Charmeleon", 158, 129, 116, "Fire", "", "Charizard", 2, 100, "Charmander", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Charizard = new Pokemon {"Charizard", 223, 176, 156, "Fire", "Fly", "", 1, 0, "Charmander", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Squirtle = new Pokemon {"Squirtle", 94, 122, 88, "W", "", "Wartortle", 3, 25, "Squirtle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Wartortle = new Pokemon {"Wartortle", 126, 155, 118, "W", "", "Blastoise", 2, 100, "Squirtle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Blastoise = new Pokemon {"Blastoise", 171, 210, 158, "W", "", "", 1, 0, "Squirtle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Caterpie = new Pokemon {"Caterpie", 55, 62, 90, "Bug", "", "Metapod", 3, 12, "Caterpie", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Metapod = new Pokemon {"Metapod", 45, 94, 100, "Bug", "", "Butterfree", 2, 50, "Caterpie", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Butterfree = new Pokemon {"Butterfree", 167, 151, 120, "Bug", "Fly", "", 1, 0, "Caterpie", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Weedle = new Pokemon {"Weedle", 63, 55, 80, "Bug", "Poi", "Kakuna", 3, 12, "Weedle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kakuna = new Pokemon {"Kakuna", 46, 86, 90, "Bug", "Poi", "Beedrill", 2, 50, "Weedle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Beedrill = new Pokemon {"Beedrill", 169, 150, 130, "Bug", "Poi", "", 1, 0, "Weedle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pidgey = new Pokemon {"Pidgey", 85, 76, 80, "N", "Fly", "Pidgeotto", 3, 12, "Pidgey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pidgeotto = new Pokemon {"Pidgeotto", 117, 108, 126, "N", "Fly", "Pidgeot", 2, 50, "Pidgey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pidgeot = new Pokemon {"Pidgeot", 166, 157, 166, "N", "Fly", "", 1, 0, "Pidgey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Rattata = new Pokemon {"Rattata", 103, 70, 60, "N", "", "Raticate", 2, 25, "Rattata", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Raticate = new Pokemon {"Raticate", 161, 144, 110, "N", "", "", 1, 0, "Rattata", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Spearow = new Pokemon {"Spearow", 112, 61, 80, "N", "Fly", "Fearow", 2, 50, "Spearow", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Fearow = new Pokemon {"Fearow", 182, 135, 130, "N", "Fly", "", 1, 0, "Spearow", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ekans = new Pokemon {"Ekans", 110, 102, 70, "Poi", "", "Arbok", 2, 50, "Ekans", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Arbok = new Pokemon {"Arbok", 167, 158, 120, "Poi", "", "", 1, 0, "Ekans", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pikachu = new Pokemon {"Pikachu", 112, 101, 70, "Ele", "", "Raichu", 2, 50, "Pikachu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Raichu = new Pokemon {"Raichu", 193, 165, 120, "Ele", "", "", 1, 0, "Pikachu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sandshrew = new Pokemon {"Sandshrew", 126, 145, 100, "Grd", "", "Sandslash", 2, 50, "Sandshrew", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sandslash = new Pokemon {"Sandslash", 182, 202, 150, "Grd", "", "", 1, 0, "Sandshrew", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *NidoranF = new Pokemon {"NidoranF", 86, 94, 110, "Poi", "", "Nidorina", 3, 25, "NidoranF", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Nidorina = new Pokemon {"Nidorina", 117, 126, 140, "Poi", "", "Nidoqueen", 2, 100, "NidoranF", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Nidoqueen = new Pokemon {"Nidoqueen", 180, 174, 180, "Poi", "Grd", "", 1, 0, "NidoranF", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *NidoranM = new Pokemon {"NidoranM", 105, 76, 92, "Poi", "", "Nidorino", 3, 25, "NidoranM", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Nidorino = new Pokemon {"Nidorino", 137, 112, 122, "Poi", "", "Nidoking", 2, 100, "NidoranM", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Nidoking = new Pokemon {"Nidoking", 204, 157, 162, "Poi", "Grd", "", 1, 0, "NidoranM", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Clefairy = new Pokemon {"Clefairy", 107, 116, 140, "Fairy", "", "Clefable", 2, 50, "Clefairy", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Clefable = new Pokemon {"Clefable", 178, 171, 190, "Fairy", "", "", 1, 0, "Clefairy", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Vulpix = new Pokemon {"Vulpix", 96, 122, 76, "Fire", "", "Ninetales", 2, 50, "Vulpix", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ninetales = new Pokemon {"Ninetales", 169, 204, 146, "Fire", "", "", 1, 0, "Vulpix", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Jigglypuff = new Pokemon {"Jigglypuff", 80, 44, 230, "N", "Fairy", "Wigglytuff", 2, 50, "Jigglypuff", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Wigglytuff = new Pokemon {"Wigglytuff", 156, 93, 280, "N", "Fairy", "", 1, 0, "Jigglypuff", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Zubat = new Pokemon {"Zubat", 83, 76, 80, "Poi", "Fly", "Golbat", 3, 25, "Zubat", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Golbat = new Pokemon {"Golbat", 161, 153, 150, "Poi", "Fly", "Crobat", 2, 100, "Zubat", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Oddish = new Pokemon {"Oddish", 131, 116, 90, "Grs", "Poi", "Gloom", 3, 25, "Oddish", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Gloom = new Pokemon {"Gloom", 153, 139, 120, "Grs", "Poi", "Multiple", 2, 100, "Oddish", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Vileplume = new Pokemon {"Vileplume", 202, 170, 150, "Grs", "Poi", "", 1, 0, "Oddish", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Paras = new Pokemon {"Paras", 121, 99, 70, "Bug", "Grs", "Parasect", 2, 50, "Paras", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Parasect = new Pokemon {"Parasect", 165, 146, 120, "Bug", "Grs", "", 1, 0, "Paras", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Venonat = new Pokemon {"Venonat", 100, 102, 120, "Bug", "Poi", "Venomoth", 2, 50, "Venonat", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Venomoth = new Pokemon {"Venomoth", 179, 150, 140, "Bug", "Poi", "", 1, 0, "Venonat", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Diglett = new Pokemon {"Diglett", 109, 88, 20, "Grd", "", "Dugtrio", 2, 50, "Diglett", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dugtrio = new Pokemon {"Dugtrio", 167, 147, 70, "Grd", "", "", 1, 0, "Diglett", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Meowth = new Pokemon {"Meowth", 92, 81, 80, "N", "", "Persian", 2, 50, "Meowth", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Persian = new Pokemon {"Persian", 150, 139, 130, "N", "", "", 1, 0, "Meowth", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Psyduck = new Pokemon {"Psyduck", 122, 96, 100, "W", "", "Golduck", 2, 50, "Psyduck", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Golduck = new Pokemon {"Golduck", 191, 163, 160, "W", "", "", 1, 0, "Psyduck", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Mankey = new Pokemon {"Mankey", 148, 87, 80, "Fight", "", "Primeape", 2, 50, "Mankey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Primeape = new Pokemon {"Primeape", 207, 144, 130, "Fight", "", "", 1, 0, "Mankey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Growlithe = new Pokemon {"Growlithe", 136, 96, 110, "Fire", "", "Arcanine", 2, 50, "Growlithe", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Arcanine = new Pokemon {"Arcanine", 227, 166, 180, "Fire", "", "", 1, 0, "Growlithe", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Poliwag = new Pokemon {"Poliwag", 101, 82, 80, "W", "", "Poliwhirl", 3, 25, "Poliwag", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Poliwhirl = new Pokemon {"Poliwhirl", 130, 130, 130, "W", "", "Multiple", 2, 100, "Poliwag", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Poliwrath = new Pokemon {"Poliwrath", 182, 187, 180, "W", "Fight", "", 1, 0, "Poliwag", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Abra = new Pokemon {"Abra", 195, 103, 50, "Psy", "", "Kadabra", 3, 25, "Abra", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kadabra = new Pokemon {"Kadabra", 232, 138, 80, "Psy", "", "Alakazam", 2, 100, "Abra", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Alakazam = new Pokemon {"Alakazam", 271, 194, 110, "Psy", "", "", 1, 0, "Abra", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Machop = new Pokemon {"Machop", 137, 88, 140, "Fight", "", "Machoke", 3, 25, "Machop", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Machoke = new Pokemon {"Machoke", 177, 130, 160, "Fight", "", "Machamp", 2, 100, "Machop", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Machamp = new Pokemon {"Machamp", 234, 162, 180, "Fight", "", "", 1, 0, "Machop", Counter, BulletPunch, KarateChop, NoMove, CloseCombat, DynamicPunch, HeavySlam, StoneEdge, CrossChop, Submission, NULL};
    Pokemon *Bellsprout = new Pokemon {"Bellsprout", 139, 64, 100, "Grs", "Poi", "Weepinbell", 3, 25, "Bellsprout", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Weepinbell = new Pokemon {"Weepinbell", 172, 95, 130, "Grs", "Poi", "Victreebel", 2, 100, "Bellsprout", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Victreebel = new Pokemon {"Victreebel", 207, 138, 160, "Grs", "Poi", "", 1, 0, "Bellsprout", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tentacool = new Pokemon {"Tentacool", 97, 182, 80, "W", "Poi", "Tentacruel", 2, 50, "Tentacool", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tentacruel = new Pokemon {"Tentacruel", 166, 237, 160, "W", "Poi", "", 1, 0, "Tentacool", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Geodude = new Pokemon {"Geodude", 132, 163, 80, "Rock", "Grd", "Graveler", 3, 25, "Geodude", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Graveler = new Pokemon {"Graveler", 164, 196, 110, "Rock", "Grd", "Golem", 2, 100, "Geodude", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Golem = new Pokemon {"Golem", 211, 229, 160, "Rock", "Grd", "", 1, 0, "Geodude", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ponyta = new Pokemon {"Ponyta", 170, 132, 100, "Fire", "", "Rapidash", 2, 50, "Ponyta", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Rapidash = new Pokemon {"Rapidash", 207, 167, 130, "Fire", "", "", 1, 0, "Ponyta", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Slowpoke = new Pokemon {"Slowpoke", 109, 109, 180, "W", "Psy", "Multiple", 2, 50, "Slowpoke", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Slowbro = new Pokemon {"Slowbro", 177, 194, 190, "W", "Psy", "", 1, 0, "Slowpoke", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magnemite = new Pokemon {"Magnemite", 165, 128, 50, "Ele", "Steel", "Magneton", 2, 50, "Magnemite", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magneton = new Pokemon {"Magneton", 223, 182, 100, "Ele", "Steel", "", 1, 0, "Magnemite", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Farfetchd = new Pokemon {"Farfetch'd", 124, 118, 104, "N", "Fly", "", 1, 0, "Farfetch'd", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Doduo = new Pokemon {"Doduo", 158, 88, 70, "N", "Fly", "Dodrio", 2, 50, "Doduo", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dodrio = new Pokemon {"Dodrio", 218, 145, 120, "N", "Fly", "", 1, 0, "Doduo", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Seel = new Pokemon {"Seel", 85, 128, 130, "W", "", "Dewgong", 2, 50, "Seel", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dewgong = new Pokemon {"Dewgong", 139, 184, 180, "W", "Ice", "", 1, 0, "Seel", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Grimer = new Pokemon {"Grimer", 135, 90, 160, "Poi", "", "Muk", 2, 50, "Grimer", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Muk = new Pokemon {"Muk", 190, 184, 210, "Poi", "", "", 1, 0, "Grimer", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Shellder = new Pokemon {"Shellder", 116, 168, 60, "W", "", "Cloyster", 2, 50, "Shellder", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Cloyster = new Pokemon {"Cloyster", 186, 323, 100, "W", "Ice", "", 1, 0, "Shellder", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Gastly = new Pokemon {"Gastly", 186, 70, 60, "Ghost", "Poi", "Haunter", 3, 25, "Gastly", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Haunter = new Pokemon {"Haunter", 223, 112, 90, "Ghost", "Poi", "Gengar", 2, 100, "Gastly", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Gengar = new Pokemon {"Gengar", 261, 156, 120, "Ghost", "Poi", "", 1, 0, "Gastly", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Onix = new Pokemon {"Onix", 85, 288, 70, "Rock", "Grd", "Steelix", 2, 50, "Onix", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Drowzee = new Pokemon {"Drowzee", 89, 158, 120, "Psy", "", "Hypno", 2, 50, "Drowzee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hypno = new Pokemon {"Hypno", 144, 215, 170, "Psy", "", "", 1, 0, "Drowzee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Krabby = new Pokemon {"Krabby", 181, 156, 60, "W", "", "Kingler", 2, 50, "Krabby", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kingler = new Pokemon {"Kingler", 240, 214, 110, "W", "", "", 1, 0, "Krabby", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Voltorb = new Pokemon {"Voltorb", 109, 114, 80, "Ele", "", "Electrode", 2, 50, "Voltorb", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Electrode = new Pokemon {"Electrode", 173, 179, 120, "Ele", "", "", 1, 0, "Voltorb", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Exeggcute = new Pokemon {"Exeggcute", 107, 140, 120, "Grs", "Psy", "Exeggutor", 2, 50, "Exeggcute", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Exeggutor = new Pokemon {"Exeggutor", 233, 158, 190, "Grs", "Psy", "", 1, 0, "Exeggcute", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Cubone = new Pokemon {"Cubone", 90, 165, 100, "Grd", "", "Marowak", 2, 50, "Cubone", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Marowak = new Pokemon {"Marowak", 144, 200, 120, "Grd", "", "", 1, 0, "Cubone", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hitmonlee = new Pokemon {"Hitmonlee", 224, 211, 100, "Fight", "", "", 1, 0, "Tyrogue", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hitmonchan = new Pokemon {"Hitmonchan", 193, 212, 100, "Fight", "", "", 1, 0, "Tyrogue", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Lickitung = new Pokemon {"Lickitung", 108, 137, 180, "N", "", "", 1, 0, "Lickitung", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Koffing = new Pokemon {"Koffing", 119, 164, 80, "Poi", "", "Weezing", 2, 50, "Koffing", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Weezing = new Pokemon {"Weezing", 174, 221, 130, "Poi", "", "", 1, 0, "Koffing", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Rhyhorn = new Pokemon {"Rhyhorn", 140, 157, 160, "Grd", "Rock", "Rhydon", 2, 50, "Rhyhorn", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Rhydon = new Pokemon {"Rhydon", 222, 206, 210, "Grd", "Rock", "", 1, 0, "Rhyhorn", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Chansey = new Pokemon {"Chansey", 60, 176, 500, "N", "", "Blissey", 2, 50, "Chansey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tangela = new Pokemon {"Tangela", 183, 205, 130, "Grs", "", "", 1, 0, "Tangela", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kangaskhan = new Pokemon {"Kangaskhan", 181, 165, 210, "N", "", "", 1, 0, "Kangaskhan", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Horsea = new Pokemon {"Horsea", 129, 125, 60, "W", "", "Seadra", 3, 25, "Horsea", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Seadra = new Pokemon {"Seadra", 187, 182, 110, "W", "", "Kingdra", 2, 100, "Horsea", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Goldeen = new Pokemon {"Goldeen", 123, 115, 90, "W", "", "Seaking", 2, 50, "Goldeen", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Seaking = new Pokemon {"Seaking", 175, 154, 160, "W", "", "", 1, 0, "Goldeen", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Staryu = new Pokemon {"Staryu", 137, 112, 60, "W", "Psy", "Starmie", 2, 50, "Staryu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Starmie = new Pokemon {"Starmie", 210, 184, 120, "W", "Psy", "", 1, 0, "Staryu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *MrMime = new Pokemon {"Mr Mime", 192, 233, 80, "Psy", "Fairy", "", 1, 0, "Mr Mime", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Scyther = new Pokemon {"Scyther", 218, 170, 140, "Bug", "Fly", "Scizor", 2, 50, "Scyther", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Jynx = new Pokemon {"Jynx", 223, 182, 130, "Ice", "Psy", "", 1, 0, "Jynx", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Electabuzz = new Pokemon {"Electabuzz", 198, 173, 130, "Ele", "", "", 1, 0, "Electabuzz", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magmar = new Pokemon {"Magmar", 206, 169, 130, "Fire", "", "", 1, 0, "Magmar", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pinsir = new Pokemon {"Pinsir", 238, 197, 130, "Bug", "", "", 1, 0, "Pinsir", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tauros = new Pokemon {"Tauros", 198, 197, 150, "N", "", "", 1, 0, "Tauros", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magikarp = new Pokemon {"Magikarp", 29, 102, 40, "W", "", "Gyarados", 2, 400, "Magikarp", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Gyarados = new Pokemon {"Gyarados", 237, 197, 190, "W", "Fly", "", 1, 0, "Magikarp", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Lapras = new Pokemon {"Lapras", 165, 180, 260, "W", "Ice", "", 1, 0, "Lapras", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ditto = new Pokemon {"Ditto", 91, 91, 96, "N", "", "", 1, 0, "Ditto", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Eevee = new Pokemon {"Eevee", 104, 121, 110, "N", "", "Multiple", 2, 25, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Vaporeon = new Pokemon {"Vaporeon", 205, 177, 260, "W", "", "", 1, 0, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Jolteon = new Pokemon {"Jolteon", 232, 201, 130, "Ele", "", "", 1, 0, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Flareon = new Pokemon {"Flareon", 246, 204, 130, "Fire", "", "", 1, 0, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Porygon = new Pokemon {"Porygon", 153, 139, 130, "N", "", "Porygon2", 2, 50, "Porygon", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Omanyte = new Pokemon {"Omanyte", 155, 174, 70, "Rock", "W", "Omastar", 2, 50, "Omanyte", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Omastar = new Pokemon {"Omastar", 207, 227, 140, "Rock", "W", "", 1, 0, "Omanyte", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kabuto = new Pokemon {"Kabuto", 148, 162, 60, "Rock", "W", "Kabutops", 2, 50, "Kabuto", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kabutops = new Pokemon {"Kabutops", 220, 203, 120, "Rock", "W", "", 1, 0, "Kabuto", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Aerodactyl = new Pokemon {"Aerodactyl", 221, 164, 160, "Rock", "Fly", "", 1, 0, "Aerodactyl", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Snorlax = new Pokemon {"Snorlax", 190, 190, 320, "N", "", "", 1, 0, "Snorlax", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Articuno = new Pokemon {"Articuno", 192, 249, 180, "Ice", "Fly", "", 1, 0, "Articuno", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Zapdos = new Pokemon {"Zapdos", 253, 188, 180, "Ele", "Fly", "", 1, 0, "Zapdos", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Moltres = new Pokemon {"Moltres", 251, 184, 180, "Fire", "Fly", "", 1, 0, "Moltres", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dratini = new Pokemon {"Dratini", 119, 94, 82, "Dragon", "", "Dragonair", 3, 25, "Dratini", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dragonair = new Pokemon {"Dragonair", 163, 138, 122, "Dragon", "", "Dragonite", 2, 100, "Dratini", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dragonite = new Pokemon {"Dragonite", 263, 201, 182, "Dragon", "Fly", "", 1, 0, "Dratini", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Mewtwo = new Pokemon {"Mewtwo", 330, 200, 212, "Psy", "", "", 1, 0, "Mewtwo", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Mew = new Pokemon {"Mew", 210, 210, 200, "Psy", "", "", 1, 0, "Mew", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    
    Pokemon *Chikorita = new Pokemon {"Chikorita", 92, 122, 90, "Grs", "", "Bayleef", 3, 25, "Chikorita", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Bayleef = new Pokemon {"Bayleef", 122, 155, 120, "Grs", "", "Meganium", 2, 100, "Chikorita", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Meganium = new Pokemon {"Meganium", 168, 202, 160, "Grs", "", "", 1, 0, "Chikorita", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Cyndaquil = new Pokemon {"Cyndaquil", 116, 96, 78, "Fire", "", "Quilava", 3, 25, "Cyndaquil", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Quilava = new Pokemon {"Quilava", 158, 129, 116, "Fire", "", "Typhlosion", 2, 100, "Cyndaquil", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Typhlosion = new Pokemon {"Typhlosion", 223, 176, 156, "Fire", "", "", 1, 0, "Cyndaquil", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Totodile = new Pokemon {"Totodile", 117, 116, 100, "W", "", "Croconaw", 3, 25, "Totodile", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Croconaw = new Pokemon {"Croconaw", 150, 151, 130, "W", "", "Feraligatr", 2, 100, "Totodile", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Feraligatr = new Pokemon {"Feraligatr", 205, 197, 170, "W", "", "", 1, 0, "Totodile", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sentret = new Pokemon {"Sentret", 79, 77, 70, "N", "", "Furret", 2, 25, "Sentret", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Furret = new Pokemon {"Furret", 148, 130, 170, "N", "", "", 1, 0, "Sentret", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hoothoot = new Pokemon {"Hoothoot", 67, 101, 120, "N", "Fly", "Noctowl", 2, 50, "Hoothoot", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Noctowl = new Pokemon {"Noctowl", 145, 179, 200, "N", "Fly", "", 1, 0, "Hoothoot", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ledyba = new Pokemon {"Ledyba", 72, 142, 80, "Bug", "Fly", "Ledian", 2, 25, "Ledyba", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ledian = new Pokemon {"Ledian", 107, 209, 110, "Bug", "Fly", "", 1, 0, "Ledyba", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Spinarak = new Pokemon {"Spinarak", 105, 73, 80, "Bug", "Poi", "Ariados", 2, 50, "Spinarak", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ariados = new Pokemon {"Ariados", 161, 128, 140, "Bug", "Poi", "", 1, 0, "Spinarak", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Crobat = new Pokemon {"Crobat", 194, 178, 170, "Poi", "Fly", "", 1, 0, "Zubat", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Chinchou = new Pokemon {"Chinchou", 106, 106, 150, "W", "Ele", "Lanturn", 2, 50, "Chinchou", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Lanturn = new Pokemon {"Lanturn", 146, 146, 250, "W", "Ele", "", 1, 0, "Chinchou", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pichu = new Pokemon {"Pichu", 77, 63, 40, "Ele", "", "Pikachu", 3, 25, "Pikachu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Cleffa = new Pokemon {"Cleffa", 75, 91, 100, "Fairy", "", "Clefairy", 3, 25, "Clefairy", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Igglybuff = new Pokemon {"Igglybuff", 69, 34, 180, "N", "Fairy", "Jigglypuff", 3, 25, "Jigglypuff", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Togepi = new Pokemon {"Togepi", 67, 116, 70, "Fairy", "", "Togetic", 2, 50, "Togepi", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Togetic = new Pokemon {"Togetic", 139, 191, 100, "Fairy", "Fly", "", 1, 0, "Togepi", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Natu = new Pokemon {"Natu", 134, 89, 80, "Psy", "Fly", "Xatu", 2, 50, "Natu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Xatu = new Pokemon {"Xatu", 192, 146, 130, "Psy", "Fly", "", 1, 0, "Natu", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Mareep = new Pokemon {"Mareep", 114, 82, 110, "Ele", "", "Flaaffy", 3, 25, "Mareep", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Flaaffy = new Pokemon {"Flaaffy", 145, 112, 140, "Ele", "", "Ampharos", 2, 100, "Mareep", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ampharos = new Pokemon {"Ampharos", 211, 172, 180, "Ele", "", "", 1, 0, "Mareep", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Bellossom = new Pokemon {"Bellossom", 169, 189, 150, "Grs", "", "", 1, 0, "Oddish", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Marill = new Pokemon {"Marill", 37, 93, 140, "W", "Fairy", "Azumarill", 2, 25, "Marill", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Azumarill = new Pokemon {"Azumarill", 112, 152, 200, "W", "Fairy", "", 1, 0, "Marill", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sudowoodo = new Pokemon {"Sudowoodo", 167, 198, 140, "Rock", "", "", 1, 0, "Sudowoodo", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Politoed = new Pokemon {"Politoed", 174, 192, 180, "W", "", "", 1, 0, "Poliwag", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hoppip = new Pokemon {"Hoppip", 67, 101, 70, "Grs", "Fly", "Skiploom", 3, 25, "Hoppip", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Skiploom = new Pokemon {"Skiploom", 91, 127, 110, "Grs", "Fly", "Jumpluff", 2, 100, "Hoppip", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Jumpluff = new Pokemon {"Jumpluff", 118, 197, 150, "Grs", "Fly", "", 1, 0, "Hoppip", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Aipom = new Pokemon {"Aipom", 136, 112, 110, "N", "", "", 1, 0, "Aipom", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sunkern = new Pokemon {"Sunkern", 55, 55, 60, "Grs", "", "Sunflora", 2, 50, "Sunkern", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sunflora = new Pokemon {"Sunflora", 185, 148, 150, "Grs", "", "", 1, 0, "Sunkern", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Yanma = new Pokemon {"Yanma", 154, 94, 130, "Bug", "Fly", "", 1, 0, "Yanma", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Wooper = new Pokemon {"Wooper", 75, 75, 110, "W", "Grd", "Quagsire", 2, 50, "Wooper", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Quagsire = new Pokemon {"Quagsire", 152, 152, 190, "W", "Grd", "", 1, 0, "Wooper", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Espeon = new Pokemon {"Espeon", 261, 194, 130, "Psy", "", "", 1, 0, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Umbreon = new Pokemon {"Umbreon", 126, 250, 190, "Dark", "", "", 1, 0, "Eevee", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Murkrow = new Pokemon {"Murkrow", 175, 87, 120, "Dark", "Fly", "", 1, 0, "Murkrow", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Slowking = new Pokemon {"Slowking", 177, 194, 190, "W", "Psy", "", 1, 0, "Slowpoke", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Misdreavus = new Pokemon {"Misdreavus", 167, 167, 120, "Ghost", "", "", 1, 0, "Misdreavus", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Unown = new Pokemon {"Unown", 136, 91, 96, "Psy", "", "", 1, 0, "Unown", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Wobbuffet = new Pokemon {"Wobbuffet", 60, 106, 380, "Psy", "", "", 1, 0, "Wobbuffet", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Girafarig = new Pokemon {"Girafarig", 182, 133, 140, "N", "Psy", "", 1, 0, "Girafarig", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pineco = new Pokemon {"Pineco", 108, 146, 100, "Bug", "", "Forretress", 2, 50, "Pineco", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Forretress = new Pokemon {"Forretress", 161, 242, 150, "Bug", "Steel", "", 1, 0, "Pineco", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Dunsparce = new Pokemon {"Dunsparce", 131, 131, 200, "N", "", "", 1, 0, "Dunsparce", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Gligar = new Pokemon {"Gligar", 143, 204, 130, "Grd", "Fly", "", 1, 0, "Gligar", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Steelix = new Pokemon {"Steelix", 148, 333, 150, "Steel", "Grd", "", 1, 0, "Onix", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Snubbull = new Pokemon {"Snubbull", 137, 89, 120, "Fairy", "", "Granbull", 2, 50, "Snubbull", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Granbull = new Pokemon {"Granbull", 212, 137, 180, "Fairy", "", "", 1, 0, "Snubbull", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Qwilfish = new Pokemon {"Qwilfish", 184, 148, 130, "W", "Poi", "", 1, 0, "Qwilfish", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Scizor = new Pokemon {"Scizor", 236, 191, 140, "Bug", "Steel", "", 1, 0, "Scyther", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Shuckle = new Pokemon {"Shuckle", 17, 396, 40, "Bug", "Rock", "", 1, 0, "Shuckle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Heracross = new Pokemon {"Heracross", 234, 189, 160, "Bug", "Fight", "", 1, 0, "Heracross", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Sneasel = new Pokemon {"Sneasel", 189, 157, 110, "Dark", "Ice", "", 1, 0, "Sneasel", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Teddiursa = new Pokemon {"Teddiursa", 142, 93, 120, "N", "", "Ursaring", 2, 50, "Teddiursa", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Ursaring = new Pokemon {"Ursaring", 236, 144, 180, "N", "", "", 1, 0, "Teddiursa", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Slugma = new Pokemon {"Slugma", 118, 71, 80, "Fire", "", "Magcargo", 2, 50, "Slugma", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magcargo = new Pokemon {"Magcargo", 139, 209, 100, "Fire", "Rock", "", 1, 0, "Slugma", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Swinub = new Pokemon {"Swinub", 90, 74, 100, "Ice", "Grd", "Piloswine", 2, 50, "Swinub", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Piloswine = new Pokemon {"Piloswine", 181, 147, 200, "Ice", "Grd", "", 1, 0, "Swinub", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Corsola = new Pokemon {"Corsola", 118, 156, 110, "W", "Rock", "", 1, 0, "Corsola", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Remoraid = new Pokemon {"Remoraid", 127, 69, 70, "W", "", "Octillery", 2, 50, "Remoraid", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Octillery = new Pokemon {"Octillery", 197, 141, 150, "W", "", "", 1, 0, "Remoraid", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Delibird = new Pokemon {"Delibird", 128, 90, 90, "Ice", "Fly", "", 1, 0, "Delibird", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Mantine = new Pokemon {"Mantine", 148, 260, 130, "W", "Fly", "", 1, 0, "Mantine", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Skarmory = new Pokemon {"Skarmory", 148, 260, 130, "Steel", "Fly", "", 1, 0, "Skarmory", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Houndour = new Pokemon {"Houndour", 152, 93, 90, "Dark", "Fire", "Houndoom", 2, 50, "Houndour", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Houndoom = new Pokemon {"Houndoom", 224, 159, 150, "Dark", "Fire", "", 1, 0, "Houndour", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Kingdra = new Pokemon {"Kingdra", 194, 194, 150, "W", "Dragon", "", 1, 0, "Horsea", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Phanpy = new Pokemon {"Phanpy", 107, 107, 180, "Grd", "", "Donphan", 2, 50, "Phanpy", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Donphan = new Pokemon {"Donphan", 214, 214, 180, "Grd", "", "", 1, 0, "Phanpy", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Porygon2 = new Pokemon {"Porygon2", 198, 183, 170, "N", "", "", 1, 0, "Porygon", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Stantler = new Pokemon {"Stantler", 192, 132, 146, "N", "", "", 1, 0, "Stantler", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Smeargle = new Pokemon {"Smeargle", 40, 88, 110, "N", "", "", 1, 0, "Smeargle", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tyrogue = new Pokemon {"Tyrogue", 64, 64, 70, "Fight", "", "Multiple", 2, 50, "Tyrogue", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Hitmontop = new Pokemon {"Hitmontop", 173, 214, 100, "Fight", "", "", 1, 0, "Tyrogue", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Smoochum = new Pokemon {"Smoochum", 153, 116, 90, "Ice", "Psy", "Jynx", 2, 25, "Jynx", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Elekid = new Pokemon {"Elekid", 135, 110, 90, "Ele", "", "Electabuzz", 2, 25, "Electabuzz", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Magby = new Pokemon {"Magby", 151, 108, 90, "Fire", "", "Magmar", 2, 25, "Magmar", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Miltank = new Pokemon {"Miltank", 157, 211, 190, "N", "", "", 1, 0, "Miltank", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Blissey = new Pokemon {"Blissey", 129, 229, 510, "N", "", "", 1, 0, "Chansey", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Raikou = new Pokemon {"Raikou", 241, 210, 180, "Ele", "", "", 1, 0, "Raikou", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Entei = new Pokemon {"Entei", 235, 176, 230, "Fire", "", "", 1, 0, "Entei", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Suicune = new Pokemon {"Suicune", 180, 235, 200, "W", "", "", 1, 0, "Suicune", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Larvitar = new Pokemon {"Larvitar", 115, 93, 100, "Rock", "Grd", "Pupitar", 3, 25, "Larvitar", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Pupitar = new Pokemon {"Pupitar", 155, 133, 140, "Rock", "Grd", "Tyranitar", 2, 100, "Larvitar", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Tyranitar = new Pokemon {"Tyranitar", 251, 212, 200, "Rock", "Dark", "", 1, 0, "Larvitar", IronTail, Bite,  NoMove, NoMove, StoneEdge, FireBlast, Crunch, NoMove, NoMove, NoMove, NULL};
    Pokemon *Lugia = new Pokemon {"Lugia", 193, 323, 212, "Psy", "Fly", "", 1, 0, "Lugia", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *HoOh = new Pokemon {"Ho-oh", 263, 301, 212, "Fire", "Fly", "", 1, 0, "Ho-oh", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    Pokemon *Celebi = new Pokemon {"Celebi", 210, 210, 200, "Psy", "Grs", "", 1, 0, "Celebi", NULL, NULL,  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    
    // Create a Hash Table of 13 Linked List elements.
    HashTable table;
    
    // Insert into table
    table.insertPoke(Dragonite);
    table.insertPoke(Snorlax);
    table.insertPoke(Gyarados);
    table.insertPoke(Bulbasaur);
    table.insertPoke(Ivysaur);
    table.insertPoke(Venusaur);
    table.insertPoke(Charmander);
    table.insertPoke(Charmeleon);
    table.insertPoke(Charizard);
    table.insertPoke(Squirtle);
    table.insertPoke(Wartortle);
    table.insertPoke(Blastoise);
    table.insertPoke(Caterpie);
    table.insertPoke(Metapod);
    table.insertPoke(Butterfree);
    table.insertPoke(Weedle);
    table.insertPoke(Kakuna);
    table.insertPoke(Beedrill);
    table.insertPoke(Pidgey);
    table.insertPoke(Pidgeotto);
    table.insertPoke(Pidgeot);
    table.insertPoke(Rattata);
    table.insertPoke(Raticate);
    table.insertPoke(Spearow);
    table.insertPoke(Fearow);
    table.insertPoke(Ekans);
    table.insertPoke(Arbok);
    table.insertPoke(Pikachu);
    table.insertPoke(Raichu);
    table.insertPoke(Sandshrew);
    table.insertPoke(Sandslash);
    table.insertPoke(NidoranF);
    table.insertPoke(Nidorina);
    table.insertPoke(Nidoqueen);
    table.insertPoke(NidoranM);
    table.insertPoke(Nidorino);
    table.insertPoke(Nidoking);
    table.insertPoke(Clefairy);
    table.insertPoke(Clefable);
    table.insertPoke(Vulpix);
    table.insertPoke(Ninetales);
    table.insertPoke(Jigglypuff);
    table.insertPoke(Wigglytuff);
    table.insertPoke(Zubat);
    table.insertPoke(Golbat);
    table.insertPoke(Oddish);
    table.insertPoke(Gloom);
    table.insertPoke(Vileplume);
    table.insertPoke(Paras);
    table.insertPoke(Parasect);
    table.insertPoke(Venonat);
    table.insertPoke(Venomoth);
    table.insertPoke(Diglett);
    table.insertPoke(Dugtrio);
    table.insertPoke(Meowth);
    table.insertPoke(Persian);
    table.insertPoke(Psyduck);
    table.insertPoke(Golduck);
    table.insertPoke(Mankey);
    table.insertPoke(Primeape);
    table.insertPoke(Growlithe);
    table.insertPoke(Arcanine);
    table.insertPoke(Poliwag);
    table.insertPoke(Poliwhirl);
    table.insertPoke(Poliwrath);
    table.insertPoke(Abra);
    table.insertPoke(Kadabra);
    table.insertPoke(Alakazam);
    table.insertPoke(Machop);
    table.insertPoke(Machoke);
    table.insertPoke(Machamp);
    table.insertPoke(Bellsprout);
    table.insertPoke(Weepinbell);
    table.insertPoke(Victreebel);
    table.insertPoke(Tentacool);
    table.insertPoke(Tentacruel);
    table.insertPoke(Geodude);
    table.insertPoke(Graveler);
    table.insertPoke(Golem);
    table.insertPoke(Ponyta);
    table.insertPoke(Rapidash);
    table.insertPoke(Slowpoke);
    table.insertPoke(Slowbro);
    table.insertPoke(Magnemite);
    table.insertPoke(Magneton);
    table.insertPoke(Farfetchd);
    table.insertPoke(Doduo);
    table.insertPoke(Dodrio);
    table.insertPoke(Seel);
    table.insertPoke(Dewgong);
    table.insertPoke(Grimer);
    table.insertPoke(Muk);
    table.insertPoke(Shellder);
    table.insertPoke(Cloyster);
    table.insertPoke(Gastly);
    table.insertPoke(Haunter);
    table.insertPoke(Gengar);
    table.insertPoke(Onix);
    table.insertPoke(Drowzee);
    table.insertPoke(Hypno);
    table.insertPoke(Krabby);
    table.insertPoke(Kingler);
    table.insertPoke(Voltorb);
    table.insertPoke(Electrode);
    table.insertPoke(Exeggcute);
    table.insertPoke(Exeggutor);
    table.insertPoke(Cubone);
    table.insertPoke(Marowak);
    table.insertPoke(Hitmonlee);
    table.insertPoke(Hitmonchan);
    table.insertPoke(Lickitung);
    table.insertPoke(Koffing);
    table.insertPoke(Weezing);
    table.insertPoke(Rhyhorn);
    table.insertPoke(Rhydon);
    table.insertPoke(Chansey);
    table.insertPoke(Tangela);
    table.insertPoke(Kangaskhan);
    table.insertPoke(Horsea);
    table.insertPoke(Seadra);
    table.insertPoke(Goldeen);
    table.insertPoke(Seaking);
    table.insertPoke(Staryu);
    table.insertPoke(Starmie);
    table.insertPoke(MrMime);
    table.insertPoke(Scyther);
    table.insertPoke(Jynx);
    table.insertPoke(Electabuzz);
    table.insertPoke(Magmar);
    table.insertPoke(Pinsir);
    table.insertPoke(Tauros);
    table.insertPoke(Magikarp);
    table.insertPoke(Lapras);
    table.insertPoke(Ditto);
    table.insertPoke(Eevee);
    table.insertPoke(Vaporeon);
    table.insertPoke(Jolteon);
    table.insertPoke(Flareon);
    table.insertPoke(Porygon);
    table.insertPoke(Omanyte);
    table.insertPoke(Omastar);
    table.insertPoke(Kabuto);
    table.insertPoke(Kabutops);
    table.insertPoke(Aerodactyl);
    table.insertPoke(Articuno);
    table.insertPoke(Zapdos);
    table.insertPoke(Moltres);
    table.insertPoke(Dratini);
    table.insertPoke(Dragonair);
    table.insertPoke(Mewtwo);
    table.insertPoke(Mew);
    
    table.insertPoke(Pichu);
    table.insertPoke(Igglybuff);
    table.insertPoke(Cleffa);
    table.insertPoke(Togepi);
    table.insertPoke(Togetic);
    table.insertPoke(Smoochum);
    table.insertPoke(Elekid);
    table.insertPoke(Magby);
    table.insertPoke(Chikorita);
    table.insertPoke(Bayleef);
    table.insertPoke(Meganium);
    table.insertPoke(Cyndaquil);
    table.insertPoke(Quilava);
    table.insertPoke(Typhlosion);
    table.insertPoke(Totodile);
    table.insertPoke(Croconaw);
    table.insertPoke(Feraligatr);
    table.insertPoke(Sentret);
    table.insertPoke(Furret);
    table.insertPoke(Hoothoot);
    table.insertPoke(Noctowl);
    table.insertPoke(Ledyba);
    table.insertPoke(Ledian);
    table.insertPoke(Spinarak);
    table.insertPoke(Ariados);
    table.insertPoke(Crobat);
    table.insertPoke(Chinchou);
    table.insertPoke(Lanturn);
    table.insertPoke(Natu);
    table.insertPoke(Xatu);
    table.insertPoke(Mareep);
    table.insertPoke(Flaaffy);
    table.insertPoke(Ampharos);
    table.insertPoke(Bellossom);
    table.insertPoke(Marill);
    table.insertPoke(Azumarill);
    table.insertPoke(Sudowoodo);
    table.insertPoke(Politoed);
    table.insertPoke(Hoppip);
    table.insertPoke(Skiploom);
    table.insertPoke(Jumpluff);
    table.insertPoke(Aipom);
    table.insertPoke(Sunkern);
    table.insertPoke(Sunflora);
    table.insertPoke(Yanma);
    table.insertPoke(Wooper);
    table.insertPoke(Quagsire);
    table.insertPoke(Espeon);
    table.insertPoke(Umbreon);
    table.insertPoke(Murkrow);
    table.insertPoke(Slowking);
    table.insertPoke(Misdreavus);
    table.insertPoke(Unown);
    table.insertPoke(Wobbuffet);
    table.insertPoke(Girafarig);
    table.insertPoke(Pineco);
    table.insertPoke(Forretress);
    table.insertPoke(Dunsparce);
    table.insertPoke(Gligar);
    table.insertPoke(Steelix);
    table.insertPoke(Snubbull);
    table.insertPoke(Granbull);
    table.insertPoke(Qwilfish);
    table.insertPoke(Scizor);
    table.insertPoke(Shuckle);
    table.insertPoke(Heracross);
    table.insertPoke(Sneasel);
    table.insertPoke(Teddiursa);
    table.insertPoke(Ursaring);
    table.insertPoke(Slugma);
    table.insertPoke(Magcargo);
    table.insertPoke(Swinub);
    table.insertPoke(Piloswine);
    table.insertPoke(Corsola);
    table.insertPoke(Remoraid);
    table.insertPoke(Octillery);
    table.insertPoke(Delibird);
    table.insertPoke(Mantine);
    table.insertPoke(Skarmory);
    table.insertPoke(Houndour);
    table.insertPoke(Houndoom);
    table.insertPoke(Kingdra);
    table.insertPoke(Phanpy);
    table.insertPoke(Donphan);
    table.insertPoke(Porygon2);
    table.insertPoke(Stantler);
    table.insertPoke(Smeargle);
    table.insertPoke(Tyrogue);
    table.insertPoke(Hitmontop);
    table.insertPoke(Miltank);
    table.insertPoke(Blissey);
    table.insertPoke(Raikou);
    table.insertPoke(Entei);
    table.insertPoke(Suicune);
    table.insertPoke(Larvitar);
    table.insertPoke(Pupitar);
    table.insertPoke(Tyranitar);
    table.insertPoke(Lugia);
    table.insertPoke(HoOh);
    table.insertPoke(Celebi);
    
    string attackPoke, defendPoke;
    Move *quick;
    Move *charge;
    
   // cout << "Which Pokemon? (Name with first capitalized)" << endl;
   // cin >> poke;
    attackPoke = "Machamp";
    defendPoke = "Tyranitar";
    
    Pokemon *attacker = table.getPokeByKey(attackPoke);
    Pokemon *raidBoss = table.getPokeByKey(defendPoke);
    /* BA = attacker->Attack; cout << "Base Attack = " << BA << endl;
    BD = attacker->Defense; cout << "Base Defense = " << BD << endl;
    BS = attacker->Stamina; cout << "Base Stamina = " << BS << endl; */
    
    // Select moveset of Raid Boss
    Move *defQMove = raidBoss->qMove2; // Bite
    Move *defCMove = raidBoss->cMove3; // Crunch
    
    cout << "Raid Boss Quick Move is " << defQMove->moveName << endl;
    cout << "Raid Boss Charge Move is " << defCMove->moveName << endl;
    
    for (int i = 0; i < 4; i++)
    {
        if (i == 0) quick = attacker->qMove1;
        else if (i == 1) quick = attacker->qMove2;
        else if (i == 2) quick = attacker->qMove3;
        else if (i == 3) quick = attacker->qMove4;
        if (quick->moveName != "NoMove")
        {
            for (int j = 0; j < 6; j++)
            {
                if (j == 0) charge = attacker->cMove1;
                else if (j == 1) charge = attacker->cMove2;
                else if (j == 2) charge = attacker->cMove3;
                else if (j == 3) charge = attacker->cMove4;
                else if (j == 4) charge = attacker->cMove5;
                else if (j == 5) charge = attacker->cMove6;
                
                if (charge->moveName != "NoMove")
                {
                    // Find STAB
                    float quickSTAB = 1, chargeSTAB = 1;
                    if (quick->type == attacker->type1 || quick->type == attacker->type2) quickSTAB = 1.2;
                    if (charge->type == attacker->type1 || charge->type == attacker->type2) chargeSTAB = 1.2;
                    cout << "Attacker Moveset is " << quick->moveName << " and " << charge->moveName << endl;
                    
                    // Find Attacker DPS
                    float attackerDPS = floor(0.5 * quick->damage / quick->duration * quickSTAB * attacker->Attack / raidBoss->Defense * typeEffectiveMultiplier(quick, raidBoss->type1) * typeEffectiveMultiplier(charge, raidBoss->type2) ) + 1 +  floor(0.5 * charge->damage / charge->duration * chargeSTAB * attacker->Attack / raidBoss->Defense * typeEffectiveMultiplier(quick, raidBoss->type1) * typeEffectiveMultiplier(charge, raidBoss->type2) ) + 1;
                    cout << "attackerDPS = " << attackerDPS << endl;
                    // cout << "TypeEffectiveMultiplier for " << quick->moveName << " is " << (typeEffectiveMultiplier(quick, raidBoss->type1) * typeEffectiveMultiplier(quick, raidBoss->type2) ) << endl;
                }
            }
        }
    }
    
    return 0;
}

float typeEffectiveMultiplier(Move *attackMove, string Type)
{
    if (attackMove->type == "N")
    {
        if (Type == "Rock" || Type == "Steel") return (5/7);
        else if (Type == "Ghost") return (25/49);
    }
    if (attackMove->type == "Fight")
    {
        if (Type == "N" || Type == "Rock" || Type == "Steel" || Type == "Ice" || Type == "Dark") return 1.4;
        else if (Type == "Fly" || Type == "Poi" || Type == "Bug" || Type == "Psy" || Type == "Fairy") return (5/7);
        else if (Type == "Ghost") return (25/49);
    }
    if (attackMove->type == "Fly")
    {
        if (Type == "Fight" || Type == "Bug" || Type == "Grs") return 1.4;
        else if (Type == "Rock" || Type == "Steel" || Type == "Ele") return (5/7);
    }
    if (attackMove->type == "Poi")
    {
        if (Type == "Grs" || Type == "Fairy") return 1.4;
        else if (Type == "Poi" || Type == "Grd" || Type == "Rock" || Type == "Ghost") return (5/7);
        else if (Type == "Steel") return (25/49);
    }
    if (attackMove->type == "Grd")
    {
        if (Type == "Poi" || Type == "Rock" || Type == "Steel" || Type == "Fire" || Type == "Ele") return 1.4;
        else if (Type == "Bug" || Type == "Grs") return (5/7);
        else if (Type == "Fly") return (25/49);
    }
    if (attackMove->type == "Rock")
    {
        if (Type == "Fly" || Type == "Bug" || Type == "Fire" || Type == "Ice") return 1.4;
        else if (Type == "Fight" || Type == "Grd" || Type == "Steel") return (5/7);
    }
    if (attackMove->type == "Bug")
    {
        if (Type == "Grs" || Type == "Psy" || Type == "Dark") return 1.4;
        else if (Type == "Fight" || Type == "Fly" || Type == "Poi" || Type == "Ghost" || Type == "Steel" || Type == "Fire" || Type == "Fairy") return (5/7);
    }
    if (attackMove->type == "Ghost")
    {
        if (Type == "Ghost" || Type == "Psy") return 1.4;
        else if (Type == "Dark") return (5/7);
        else if (Type == "N") return (25/49);
    }
    if (attackMove->type == "Steel")
    {
        if (Type == "Rock" || Type == "Ice" || Type == "Fairy") return 1.4;
        else if (Type == "Steel" || Type == "Fire" || Type == "W" || Type == "Ele") return (5/7);
    }
    if (attackMove->type == "Fire")
    {
        if (Type == "Bug" || Type == "Steel" || Type == "Grs" || Type == "Ice") return 1.4;
        else if (Type == "Rock" || Type == "Fire" || Type == "W" || Type == "Dragon") return (5/7);
    }
    if (attackMove->type == "W")
    {
        if (Type == "Grd" || Type == "Rock" || Type == "Fire") return 1.4;
        else if (Type == "W" || Type == "Grs" || Type == "Dragon") return (5/7);
    }
    if (attackMove->type == "Grs")
    {
        if (Type == "Grd" || Type == "Rock" || Type == "W") return 1.4;
        else if (Type == "Fly" || Type == "Poi" || Type == "Bug" || Type == "Steel" || Type == "Fire" || Type == "Grs" || Type == "Dragon") return (5/7);
    }
    if (attackMove->type == "Ele")
    {
        if (Type == "Fly" || Type == "W") return 1.4;
        else if (Type == "Grs" || Type == "Ele" || Type == "Dragon") return (5/7);
        else if (Type == "Grd") return (25/49);
    }
    if (attackMove->type == "Psy")
    {
        if (Type == "Fight" || Type == "Poi") return 1.4;
        else if (Type == "Steel" || Type == "Psy") return (5/7);
        else if (Type == "Dark") return (25/49);
    }
    if (attackMove->type == "Ice")
    {
        if (Type == "Fly" || Type == "Grd" || Type == "Grs" || Type == "Dragon") return 1.4;
        else if (Type == "Steel" || Type == "Fire" || Type == "W" || Type == "Ice") return (5/7);
    }
    if (attackMove->type == "Dark")
    {
        if (Type == "Ghost" || Type == "Psy") return 1.4;
        else if (Type == "Fight" || Type == "Dark" || Type == "Fairy") return (5/7);
    }
    if (attackMove->type == "Dragon")
    {
        if (Type == "Dragon") return 1.4;
        else if (Type == "Steel") return (5/7);
        else if (Type == "Fairy") return (25/49);
    }
    if (attackMove->type == "Fairy")
    {
        if (Type == "Fight" || Type == "Dark" || Type == "Dragon") return 1.4;
        else if (Type == "Poi" || Type == "Steel" || Type == "Fire") return (5/7);
    }
    return 1;
}

// Finds number of Power Ups, Stardust, and Candy required to power up to max level based on Trainer level
void findMaxReqs(int &pUps, int &cMax, int &sMax, double currLvl, double maxLvl)
{
    pUps = 0; sMax = 0; cMax = 0;
    while (currLvl < maxLvl)
    {
        if (currLvl >= 1 && currLvl <= 2.5) {pUps++; sMax += 200; cMax += 1;}
        else if (currLvl >= 3 && currLvl <= 4.5) {pUps++; sMax += 400; cMax += 1;}
        else if (currLvl >= 5 && currLvl <= 6.5) {pUps++; sMax += 600; cMax += 1;}
        else if (currLvl >= 7 && currLvl <= 8.5) {pUps++; sMax += 800; cMax += 1;}
        else if (currLvl >= 9 && currLvl <= 10.5) {pUps++; sMax += 1000; cMax += 1;}
        else if (currLvl >= 11 && currLvl <= 12.5) {pUps++; sMax += 1300; cMax += 2;}
        else if (currLvl >= 13 && currLvl <= 14.5) {pUps++; sMax += 1600; cMax += 2;}
        else if (currLvl >= 15 && currLvl <= 16.5) {pUps++; sMax += 1900; cMax += 2;}
        else if (currLvl >= 17 && currLvl <= 18.5) {pUps++; sMax += 2200; cMax += 2;}
        else if (currLvl >= 19 && currLvl <= 20.5) {pUps++; sMax += 2500; cMax += 2;}
        else if (currLvl >= 21 && currLvl <= 22.5) {pUps++; sMax += 3000; cMax += 3;}
        else if (currLvl >= 23 && currLvl <= 24.5) {pUps++; sMax += 3500; cMax += 3;}
        else if (currLvl >= 25 && currLvl <= 25.5) {pUps++; sMax += 4000; cMax += 3;}
        else if (currLvl >= 26 && currLvl <= 26.5) {pUps++; sMax += 4000; cMax += 4;}
        else if (currLvl >= 27 && currLvl <= 28.5) {pUps++; sMax += 4500; cMax += 4;}
        else if (currLvl >= 29 && currLvl <= 30.5) {pUps++; sMax += 5000; cMax += 4;}
        else if (currLvl >= 31 && currLvl <= 32.5) {pUps++; sMax += 6000; cMax += 6;}
        else if (currLvl >= 33 && currLvl <= 34.5) {pUps++; sMax += 7000; cMax += 8;}
        else if (currLvl >= 35 && currLvl <= 36.5) {pUps++; sMax += 8000; cMax += 10;}
        else if (currLvl >= 37 && currLvl <= 38.5) {pUps++; sMax += 9000; cMax += 12;}
        else if (currLvl >= 39 && currLvl <= 40.5) {pUps++; sMax += 10000; cMax += 15;}
        currLvl += 0.5;
    }
}

// Finds the starting level to try based on Stardust requirements
double findLevel(double levelSD)
{
    if (levelSD == 200) return 1;
    if (levelSD == 400) return 3;
    if (levelSD == 600) return 5;
    if (levelSD == 800) return 7;
    if (levelSD == 1000) return 9;
    if (levelSD == 1300) return 11;
    if (levelSD == 1600) return 13;
    if (levelSD == 1900) return 15;
    if (levelSD == 2200) return 17;
    if (levelSD == 2500) return 19;
    if (levelSD == 3000) return 21;
    if (levelSD == 3500) return 23;
    if (levelSD == 4000) return 25;
    if (levelSD == 4001) return 26; // 4000, 4 candy
    if (levelSD == 4500) return 27;
    if (levelSD == 5000) return 29;
    if (levelSD == 6000) return 31;
    if (levelSD == 7000) return 33;
    if (levelSD == 8000) return 35;
    if (levelSD == 9000) return 37;
    if (levelSD == 10000) return 39;
    return 0;
}

// Returns CpM for given level
double findCpM(double pokeLvl)
{
    if (pokeLvl == 1) return 0.094;
    if (pokeLvl == 1.5) return 0.135137432;
    if (pokeLvl == 2) return 0.16639787;
    if (pokeLvl == 2.5) return 0.192650919;
    if (pokeLvl == 3) return 0.21573247;
    if (pokeLvl == 3.5) return 0.236572661;
    if (pokeLvl == 4) return 0.25572005;
    if (pokeLvl == 4.5) return 0.273530381;
    if (pokeLvl == 5) return 0.29024988;
    if (pokeLvl == 5.5) return 0.306057377;
    if (pokeLvl == 6) return 0.3210876;
    if (pokeLvl == 6.5) return 0.335445036;
    if (pokeLvl == 7) return 0.34921268;
    if (pokeLvl == 7.5) return 0.362457751;
    if (pokeLvl == 8) return 0.37523559;
    if (pokeLvl == 8.5) return 0.387592406;
    if (pokeLvl == 9) return 0.39956728;
    if (pokeLvl == 9.5) return 0.411193551;
    if (pokeLvl == 10) return 0.42250001;
    if (pokeLvl == 10.5) return 0.432926419;
    if (pokeLvl == 11) return 0.44310755;
    if (pokeLvl == 11.5) return 0.4530599578;
    if (pokeLvl == 12) return 0.46279839;
    if (pokeLvl == 12.5) return 0.472336083;
    if (pokeLvl == 13) return 0.48168495;
    if (pokeLvl == 13.5) return 0.4908558;
    if (pokeLvl == 14) return 0.49985844;
    if (pokeLvl == 14.5) return 0.508701765;
    if (pokeLvl == 15) return 0.51739395;
    if (pokeLvl == 15.5) return 0.525942511;
    if (pokeLvl == 16) return 0.53435433;
    if (pokeLvl == 16.5) return 0.542635767;
    if (pokeLvl == 17) return 0.55079269;
    if (pokeLvl == 17.5) return 0.558830576;
    if (pokeLvl == 18) return 0.56675452;
    if (pokeLvl == 18.5) return 0.574569153;
    if (pokeLvl == 19) return 0.58227891;
    if (pokeLvl == 19.5) return 0.589887917;
    if (pokeLvl == 20) return 0.59740001;
    if (pokeLvl == 20.5) return sqrt(0.59740001 * 0.59740001 + 0.008924905903); // orig 0.604818814 I say .604824
    if (pokeLvl == 21) return 0.61215729;
    if (pokeLvl == 21.5) return sqrt(0.61215729 * 0.61215729 + 0.008924905903); // orig 0.619399365 I say .619404
    if (pokeLvl == 22) return 0.62656713;
    if (pokeLvl == 22.5) return sqrt(0.62656713 * 0.62656713 + 0.008924905903); // orig 0.633644533 I say .633649
    if (pokeLvl == 23) return 0.64065295;
    if (pokeLvl == 23.5) return sqrt(0.64065295 * 0.64065295 + 0.008924905903); // orig 0.647576426 I say .647581
    if (pokeLvl == 24) return 0.65443563;
    if (pokeLvl == 24.5) return sqrt(0.65443563 * 0.65443563 + 0.008924905903); // orig 0.661214806 I say .661219
    if (pokeLvl == 25) return 0.667934;
    if (pokeLvl == 25.5) return sqrt(0.667934 * 0.667934 + 0.008924905903);     // orig 0.674577537 I say .674582
    if (pokeLvl == 26) return 0.68116492;
    if (pokeLvl == 26.5) return sqrt(0.68116492 * 0.68116492 + 0.008924905903); // orig 0.687680648 I say .687685
    if (pokeLvl == 27) return 0.69414365;
    if (pokeLvl == 27.5) return sqrt(0.69414365 * 0.69414365 + 0.008924905903); // orig 0.700538673 I say .700543
    if (pokeLvl == 28) return 0.70688421;
    if (pokeLvl == 28.5) return sqrt(0.70688421 * 0.70688421 + 0.008924905903); // orig 0.713164996 I say .713169
    if (pokeLvl == 29) return 0.71939909;
    if (pokeLvl == 29.5) return sqrt(0.71939909 * 0.71939909 + 0.008924905903); // orig 0.725571552 I say .725576
    if (pokeLvl == 30) return 0.7317; // 0.7317 = sqrt(.725576^2 + 0.0089...)
    // This is the point where power ups are halved and CPMStep is 0.00445946079
    if (pokeLvl == 30.5) return 0.734741009;
    if (pokeLvl == 31) return 0.73776948;
    if (pokeLvl == 31.5) return 0.740785574;
    if (pokeLvl == 32) return 0.74378943;
    if (pokeLvl == 32.5) return 0.746781211;
    if (pokeLvl == 33) return 0.74976104;
    if (pokeLvl == 33.5) return 0.752729087;
    if (pokeLvl == 34) return 0.75568551;
    if (pokeLvl == 34.5) return 0.758630378;
    if (pokeLvl == 35) return 0.76156384;
    if (pokeLvl == 35.5) return 0.764486065;
    if (pokeLvl == 36) return 0.76739717;
    if (pokeLvl == 36.5) return 0.770297266;
    if (pokeLvl == 37) return 0.7731865;
    if (pokeLvl == 37.5) return 0.776064962;
    if (pokeLvl == 38) return 0.77893275;
    if (pokeLvl == 38.5) return 0.781790055;
    if (pokeLvl == 39) return 0.78463697;
    if (pokeLvl == 39.5) return 0.787473578;
    if (pokeLvl == 40) return 0.79030001;
    
    return 0;
}
