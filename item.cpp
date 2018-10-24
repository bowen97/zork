//
// Created by lyuru on 10/20/2018.
//

#include "item.h"
#define DEBUG 0

item::item(xml_node<>* node){
    ifturnon = false;
    xml_node<>* kid=node->first_node();
    while(kid){
        if(!strcmp(kid->name(),"trigger")) {
            Trigger *temp = new Trigger(kid);
            trigger.push_back(temp);
        }
        if(!strcmp(kid->name(), "name")){
            name = kid-> value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << name << endl;
                cout << endl;
            }

        }
        if(!strcmp(kid->name(),"status")){
            status = kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << status << endl;
                cout << endl;
            }
        }
        if(!strcmp(kid->name(), "description")){
            description = kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << description << endl;
                cout << endl;
            }
        }
        if(!strcmp(kid->name(), "writing")){
            writing = kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << writing << endl;
                cout << endl;
            }
        }
        if(!strcmp(kid->name(), "turnon")){
            ifturnon = true;
            string printmsg;
            string actionmsg;
            xml_node<>* kid2 = kid->first_node();
            while(kid2){
                if(!strcmp(kid2->name(), "print")){
                    printmsg = kid2->value();
                }
                if(!strcmp(kid2->name(), "action")){
                    actionmsg = kid2->value();
                }
                kid2 = kid2->next_sibling();
            }
            turnon.print = printmsg;
            turnon.action = actionmsg;

        }
        kid = kid->next_sibling();
    }

}


