//
// Created by bowen fang on 10/16/18.
//

#ifndef ZORK_ROOM_H
#define ZORK_ROOM_H

#include "header.h"
#include "trigger.h"
typedef struct _border{
    string name;
    string direction;
} Border;

class Room{
    public:
    string name;
    string status;
    string type;
    string description;
    vector<Border*> border;
    vector<string> container;
    vector<string> item;
    vector<string> creature;
    vector<Trigger*> trigger;

    Room(xml_node<>* node);

    virtual ~Room(){};



};

#endif //ZORK_ROOM_H
