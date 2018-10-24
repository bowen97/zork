//
// Created by lyuru on 10/23/2018.
//

#include "Attack.h"
#define DEBUG 0


Attack::Attack(xml_node<>* node){
    triggerCondition = false;
    triggerPrint = false;
    triggerAction = false;

    xml_node<>* kid = node->first_node();
    while(kid){
        if(!strcmp(kid->name(), "condition")){
            triggerCondition = true;
            xml_node<>* kid2 = kid->first_node();
            while(kid2){
                if(!strcmp(kid2->name(), "object")){
                    condition.object = kid2->value();

                }
                if(!strcmp(kid2->name(), "status")){
                    condition.status = kid2->value();

                }
                kid2 = kid2->next_sibling();
            }

        }
        if(!strcmp(kid->name(), "print")){
            triggerPrint = true;
            print = kid->value();
        }
        if(!strcmp(kid->name(), "action")){
            triggerAction = true;
            action.push_back(kid->value());
        }

        kid = kid->next_sibling();

    }

};