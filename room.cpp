//
// Created by bowen fang on 10/16/18.
//
#include "room.h"
#define DEBUG 0


Room::Room(xml_node<> *node) {
    xml_node<>* kid=node->first_node();
    while(kid){
        if(!strcmp(kid->name(),"trigger")){
            Trigger* temp=new Trigger(kid);
            trigger.push_back(temp);

        }
        else if(!strcmp(kid->name(),"name")){
            name=kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << name << endl;
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"description")){
            description=kid->value();

            if(DEBUG) {
                cout << kid->name() << endl;
                cout << description << endl;
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"item")){
            item.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < item.size(); i++) {
                    cout << item[i] << endl;
                }
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"border")){
            Border* newBorder=new Border();
            for(xml_node<>* temp=kid->first_node();temp;temp=temp->next_sibling()){
                if(!strcmp(temp->name(),"name")){
                    newBorder->name=temp->value();

                }
                else if(!strcmp(temp->name(),"direction")){
                    if(!strcmp(temp->value(),"north")){
                        newBorder->direction="n";
                    }
                    if(!strcmp(temp->value(),"south")){
                        newBorder->direction="s";
                    }
                    if(!strcmp(temp->value(),"west")){
                        newBorder->direction="w";
                    }
                    if(!strcmp(temp->value(),"east")){
                        newBorder->direction="e";
                    }
                }
            }
            border.push_back(newBorder);
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < border.size(); i++) {
                    cout << border[i]->direction << endl;
                    cout << border[i]->name << endl;
                }
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"container")){
            container.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < container.size(); i++) {
                    cout << container[i] << endl;
                }
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"creature")){
            creature.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < creature.size(); i++) {
                    cout << creature[i] << endl;
                }
                cout << endl;
            }

        } else if(!strcmp(kid->name(),"status")){
            status=kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << status << endl;
                cout << endl;
            }
        } else if(!strcmp(kid->name(),"type")){
            type=kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << type << endl;
                cout << endl;
            }
        }

        kid=kid->next_sibling();
    }
}
