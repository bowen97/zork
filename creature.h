//
// Created by lyuru on 10/21/2018.
//

#ifndef ZORK_CREATURE_H
#define ZORK_CREATURE_H

#define DEBUG 1
#include "header.h"
#include "trigger.h"

class creature {
public:
    string name;
    string status;
    string description;
    string attack;
    vector<string> vulnerability;
    vector<Trigger*> trigger;

    creature(xml_node<>* node);
    virtual ~creature(){};


};


#endif //ZORK_CREATURE_H
