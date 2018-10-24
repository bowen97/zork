//
// Created by lyuru on 10/23/2018.
//

#ifndef ZORK_ATTACK_H
#define ZORK_ATTACK_H

#define DEBUG 0

#include "header.h"


typedef  struct _condition{
    string object;
    string status;
}Condition;


class Attack {
public:
    Condition condition;
    string print;
    vector<string> action;

    bool triggerCondition;
    bool triggerPrint;
    bool triggerAction;

    Attack(xml_node<>* node);
    virtual ~Attack(){};

};


#endif //ZORK_ATTACK_H
