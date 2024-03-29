//
// Created by lyuru on 10/21/2018.
//

#ifndef ZORK_CREATURE_H
#define ZORK_CREATURE_H

#define DEBUG 0
#include "header.h"
#include "trigger.h"
#include "Attack.h"

class creature {
public:
    string name;
    string status;
    string description;
    Attack* attack;
    vector<string> vulnerability;
    vector<Trigger*> trigger;

    creature(xml_node<>* node);
    virtual ~creature(){};


};


#endif //ZORK_CREATURE_H
