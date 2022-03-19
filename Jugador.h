#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>

using namespace std;

struct Player{
    
    string name = noName;
    int    points = 0;
    bool   state = false;
};


#endif