//
// Created by bowen fang on 10/16/18.
//
#define DEBUG 0
#include "trigger.h"
#include "header.h"

Trigger::Trigger(xml_node<>* node) {
    setupTrigger(node);
}

void Trigger::setupTrigger(xml_node<>* node) {
    has_print = false;
    has_action= false;
    has_command = false;

    type = "single";
    times = 0;
    xml_node<>* child = node -> first_node();
    while(child) {
        if(!strcmp(child->name(), "print")) {
            has_print = true;
            print = child->value();
        }
        if(!strcmp(child->name(), "action")) {
            has_action = true;
            action.push_back(child->value());
        }
        if(!strcmp(child->name(), "type")) {
            type = child->value();
        }
        if(!strcmp(child->name(), "command")) {
            has_command = true;
            command = child->value();
        }
        if(!strcmp(child->name(), "condition")) {
            condition = condition_count(child);
            if(condition == 3) {

                setupOwner(child);
            }
            else if(condition == 2){
                setupStatus(child);
            }
        }
        child = child -> next_sibling();
    }
}

int Trigger::condition_count(xml_node<>* node) {
    int conditionNumber = 0;
    for(xml_node<>* child = node -> first_node(); child; child = child -> next_sibling()){
        conditionNumber++;
    }
    return conditionNumber;
}

void Trigger::setupOwner(xml_node<>* node) {
    xml_node<>* child = node -> first_node();
    while(child) {
        if(!strcmp(child->name(), "has")) {
            owner.has = child->value();
        }
        if(!strcmp(child->name(), "owner")) {
            owner.owner = child->value();
        }
        if(!strcmp(child->name(), "object")) {
            owner.object = child->value();
        }
        child = child -> next_sibling();
    }
}

void Trigger::setupStatus(xml_node<>* node) {
    xml_node<>* child = node -> first_node();
    while(child) {
        if(!strcmp(child->name(), "status")) {
            status.status = child->value();
        }
        if(!strcmp(child->name(), "object")) {
            status.object = child->value();
        }
        child = child -> next_sibling();
    }
}
