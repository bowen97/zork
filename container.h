//
// Created by lyuru on 10/21/2018.
//

#ifndef ZORK_CONTAINER_H
#define ZORK_CONTAINER_H

#define DEBUG 0
#include "header.h"
#include "trigger.h"

class container {
public:
    string name;
    string status;
    string description;
    vector<Trigger*> trigger;
    vector<string> item;
    vector<string> accept;

    container(xml_node<>* node);
    virtual ~container(){};

};


#endif //ZORK_CONTAINER_H
