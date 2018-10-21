//
// Created by lyuru on 10/20/2018.
//

#ifndef ZORK_ITEM_H
#define ZORK_ITEM_H

#define DEBUG 1
#include "header.h"
#include "trigger.h"


typedef struct _turnon{
    string print;
    string action;
}Turnon;

class item {
public:
    string name;
    string status;
    string description;
    string writing;
    Turnon turnon;
    bool ifturnon;     // will be use later too check if we can turn on the item
    vector<Trigger*> trigger;
    item(xml_node<>* node);
    virtual ~item(){};


};


#endif //ZORK_ITEM_H
