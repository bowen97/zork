//
// Created by lyuru on 10/21/2018.
//

#include "container.h"
#define DEBUG 0

container::container(xml_node<> *node) {
    xml_node<>* kid = node->first_node();
    while(kid){
        if(!strcmp(kid->name(),"trigger")) {
            Trigger *temp = new Trigger(kid);
            trigger.push_back(temp);
        }
        if(!strcmp(kid->name(),"name")){
            name = kid->value();
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
        if(!strcmp(kid->name(),"item")){
            item.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < item.size(); i++) {
                    cout << item[i] << endl;
                }
                cout << endl;
            }
        }
        if(!strcmp(kid->name(),"accept")){
            accept.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < accept.size(); i++) {
                    cout << accept[i] << endl;
                }
                cout << endl;
            }
        }
        kid = kid->next_sibling();
    }
}