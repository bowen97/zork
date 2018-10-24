//
// Created by bowen fang on 10/15/18.
//
#include "main.h"

int main(int argc, char*argv[]){
    if(argc!=2){
        cout<<"Game usage: ./Zork filename.xml"<<endl;
        return 1;
    }


    file<> xmlFile(argv[1]);
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<>*node=doc.first_node();

    //setup xml lists
    vector<xml_node<>*> roomxml;
    vector<xml_node<>*> itemxml;
    vector<xml_node<>*> containerxml;
    vector<xml_node<>*> creaturexml;

    for(xml_node<>*top = node->first_node(); top; top=top->next_sibling()){
        if(string(top->name())==string("room")){

            roomxml.push_back(top);
        }
        if(string(top->name())==string("item")){
            itemxml.push_back(top);
        }
        if(string(top->name())==string("container")){
            containerxml.push_back(top);
        }
        if(string(top->name())==string("creature")){
            creaturexml.push_back(top);
        }
    }
    //setup for room class

    for(int i=0;i<roomxml.size();i++){
//        cout<<string(roomxml[i]->first_node()->next_sibling()->name())<<endl;

        room_list.push_back(new Room(roomxml[i]));
    }
    // set up for item class
    for(int j = 0; j < itemxml.size(); j++) {

        item_list.push_back(new item(itemxml[j]));
    }

    // set up for container class
    for(int j = 0; j < containerxml.size(); j++) {

        container_list.push_back(new container(containerxml[j]));
    }
    // set up for creature class
    for(int j = 0; j < creaturexml.size(); j++) {

        creature_list.push_back(new creature(creaturexml[j]));
    }



}
