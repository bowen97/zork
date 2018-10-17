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
    cout<<doc.first_node()->name()<<endl;

    for(xml_node<>* kid= roomxml[0]->first_node();kid; kid=kid->next_sibling()){
        cout<<kid->name()<<endl;
        cout<<kid->value()<<endl;
        cout<<endl;

    }

}
