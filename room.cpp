//
// Created by bowen fang on 10/16/18.
//
#include "room.h"

Room::Room(xml_node<> *node) {
    xml_node<>* kid=node->first_node();
    while(kid){
        if(!strcmp(kid->name(),"trigger")){
            Trigger* temp=new Trigger(kid);
            trigger.push_back(temp);
        }






        kid=kid->next_sibling();
    }
}