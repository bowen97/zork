//
// Created by bowen fang on 10/16/18.
//
#define DEBUG 0
#include "trigger.h"
Trigger::Trigger(xml_node<> *node) {
    times=0;
    type="single";
    has_command=false;
    has_action= false;
    has_print= false;

    xml_node<>* kid=node->first_node();
    while(kid){
        if(!strcmp(kid->name(),"print")){
            has_print=true;
            print=kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << print << endl;
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"type")){
            type=kid->value();
            if(DEBUG) {
                cout << kid->name() << endl;
                cout << type << endl;
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"action")){
            has_action=true;
            action.push_back(kid->value());
            if(DEBUG) {
                cout << kid->name() << endl;
                for (int i = 0; i < action.size(); i++) {
                    cout << action[i] << endl;
                }
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"command")){
            has_command=true;
            command=kid->value();

            if(DEBUG) {
                cout << kid->name() << endl;
                cout << command << endl;
                cout << endl;
            }
        }
        else if(!strcmp(kid->name(),"condition")){

            if(condition_det(kid)){//status
                if(DEBUG) {
                    cout << kid->name() << endl;
                }
                for(xml_node<>*temp=kid->first_node();temp;temp=temp->next_sibling()){
                    if(!strcmp(temp->name(),"status")){
                        status.status=temp->value();
                        if(DEBUG) {
                            cout << temp->name() << endl;
                            cout << status.status << endl;
                            cout << endl;
                        }
                    }
                    if(!strcmp(temp->name(),"object")){
                        status.object=temp->value();
                        if(DEBUG) {
                            cout << temp->name() << endl;
                            cout << status.object << endl;
                            cout << endl;
                        }
                    }
                }

            }
            else{//owner
                if(DEBUG) {
                    cout << kid->name() << endl;
                }
                for(xml_node<>*temp=kid->first_node();temp;temp=temp->next_sibling()){
                    if(!strcmp(temp->name(),"has")){
                        owner.has=temp->value();
                        if(DEBUG) {
                            cout << temp->name() << endl;
                            cout << owner.has << endl;
                            cout << endl;
                        }
                    }
                    if(!strcmp(temp->name(),"owner")){
                        owner.owner=temp->value();
                        if(DEBUG) {
                            cout << temp->name() << endl;
                            cout << owner.owner << endl;
                            cout << endl;
                        }
                    }
                    if(!strcmp(temp->name(),"object")) {
                        owner.object = temp->value();
                        if (DEBUG) {
                            cout << temp->name() << endl;
                            cout << owner.object << endl;
                            cout << endl;
                        }
                    }
                }

            }
        }

        kid=kid->next_sibling();

    }
}

bool Trigger::condition_det(xml_node<> *node) {
    int count=0;
    for(xml_node<>* kid=node->first_node();kid;kid=kid->next_sibling()){
        count++;
    }
    if(count==2){ //status
        return true;
    }
    else if (count==3){//owner
        return false;
    }
}
