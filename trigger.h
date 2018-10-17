//
// Created by bowen fang on 10/16/18.
//

#ifndef ZORK_TRIGGER_H
#define ZORK_TRIGGER_H

#include "header.h"
typedef struct _owner{
    string has;
    string object;
    string owner;
}Owner;

typedef struct _status{
    string object;
    string status;
}Status;

class Trigger{
public:
    string type;
    string command;
    string print;
    Status status;
    Owner owner;
    vector<string> action;
    bool condition;//0 is owner 1 is status
    bool has_command;
    bool has_print;
    bool has_action;
    Trigger(xml_node<>* node);
    virtual ~Trigger();
    int times;
private:
    bool condition_det(xml_node<>* node);

};



#endif //ZORK_TRIGGER_H
