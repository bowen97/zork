//
// Created by bowen fang on 10/23/18.
//
#include "header.h"
#include "zork.h"

void check_input(string input){
    if(input == "n" || input=="s" || input=="w"|| input=="e"){
        bool flag=false;
        for(int i=0; i < (nowRoom->border).size();i++){
//            cout<<(nowRoom->border).size()<<endl;
            if(nowRoom->border[i]->direction==input){
//                cout<<nowRoom->border[i]->direction<<endl;
//                cout<<nowRoom->border[i]->name<<endl;
                flag=true;
                for(int j=0; j< room_list.size();j++){
//                    cout<<"room list:"<<room_list[j]->name<<endl;
//                    cout<<"border name:"<<nowRoom->border[i]->name<<endl;
                    if(room_list[j]->name==nowRoom->border[i]->name){

                        nowRoom=room_list[j];
                        break;
                    }


                }
                break;
            }
        }
        if(!flag){
            cout<<"Can't go that way."<<endl;
        }
        else{

            cout<<nowRoom->description<<endl;
        }
    }
    else if(input=="i"){
        if(inventory.size()==0){
            cout<<"Inventory: empty"<<endl;
        }
        else{
            cout << "Inventory: ";
            int i;
            for(i=0;i<inventory.size()-1;i++){
                cout<< inventory[i]<<", ";

            }
            cout<<inventory[i]<<endl;
        }
    }
    else if(input=="take"){
        cout<<"What do you want to take?"<<endl;
        string newin;
        getline(cin,newin);
        take(newin);

    }
    else if(input.find("take")!= string::npos){
        input.erase(0,5);
        take(input);
    }
    else if(input=="drop"){
        cout<<"What do you want to drop?"<<endl;
        string newin;
        getline(cin,newin);
        drop(newin);

    }
    else if(input.find("drop")!=string::npos){
        input.erase(0,5);
        drop(input);
    }
    else if(input=="read"){
        cout<<"What do you want to read?"<<endl;

        getline(cin,input);
        read_item(input);

    }
    else if(input.find("read") != string::npos){
        input.erase(0,5);
        read_item(input);
    }
    else if(input=="open"){
        cout<<"What do you want to open? ";
        getline(cin, input);
        if(input == "exit"){
            exit();
        }
        else{
            open(input);
        }

    }
    else if(input.find("open") != string::npos){
        input.erase(0,5);
        if(input == "exit"){
            exit();
        }
        else{
            open(input);
        }
    }
    else if(input.find("put") != string::npos){
        input.erase(0,4);
        string input_item=input.substr(0, input.find(" "));
        string input_container=input.substr(input.find(" ")+4,input.size());

        put(input_item,input_container);

    }
    else if(input =="turn on"){
        cout<<"What do you want to turn on?"<<endl;
        getline(cin,input);
        turn_on(input);

    }
    else if(input.find("turn on") != string::npos){
        input.erase(0,8);
        turn_on(input);
    }
    else if(input == "attack"){
        string monster,weapon;
        cout<<"Whom do you want to attack?"<<endl;
        getline(cin,monster);
        cout << "What do you want to attack with?"<<endl;
        getline(cin,weapon);
        attack(monster,weapon);
    }
    else if(input.find("attack") != string::npos){
        input.erase(0,7);
        string monster = input.substr(0,input.find(" "));
        string weapon = input.substr(input.find(" ")+6, input.size());
        attack(monster,weapon);
    }
    else{
        cout<<"There is no such command"<<endl;
    }

    return;
}
void attack(string monster, string weapon){
    vector<string>::iterator it = find(nowRoom->creature.begin(),nowRoom->creature.end(),monster);
    if(it==nowRoom->creature.end()){
        cout<<"There is no such monster in the room."<<endl;
        return;
    }
    it = find(inventory.begin(),inventory.end(),weapon);
    if(it == inventory.end()){
        cout<<"You don't have this weapon"<<endl;
        return;
    }
    int m_i = 0;//creature index;
    for(int i=0;i<creature_list.size();i++){
        if(creature_list[i]->name==monster){
            m_i=i;
        }
    }
    it = find(creature_list[m_i]->vulnerability.begin(),creature_list[m_i]->vulnerability.end(),weapon);
    if(it != creature_list[m_i]->vulnerability.end()){
        cout<<"You assault the "<< monster<<" with the "<< weapon<<"."<<endl;
    }
    else{
        cout<<monster<<" cannot be killed by "<<weapon<<"."<<endl;
    }
    if(creature_list[m_i]->attack==NULL){
        return;
    }
    //need to do more checking
    if(creature_list[m_i]->attack->triggerCondition){
        string object = creature_list[m_i]->attack->condition.object;
        string status = creature_list[m_i]->attack->condition.status;
        bool flag = true;
        bool flag2 = false;
        for(int i=0; i<item_list.size();i++){
            if(item_list[i]->name==object){
                flag=false;
                flag2=item_list[i]->status==status;
                break;
            }
        }
        if(flag){
            for(int i =0;i<room_list.size();i++){
                if(room_list[i]->name==object){
                    flag= false;
                    flag2=room_list[i]->status==status;
                    break;
                }
            }
        }
        if(flag){
            for(int i =0;i<container_list.size();i++){
                if(container_list[i]->name==object){
                    flag= false;
                    flag2=container_list[i]->status==status;
                    break;
                }
            }
        }
        if(flag){
            for(int i =0;i<creature_list.size();i++){
                if(creature_list[i]->name==object){
                    flag= false;
                    flag2=creature_list[i]->status==status;
                    break;
                }
            }
        }
        if(!flag2){
            cout<<"Error"<<endl;
            return;
        }

    }
    if(creature_list[m_i]->attack->triggerPrint){
        cout << "2You assault the " << monster << " with the " << weapon << "." << endl;
        cout << creature_list[m_i]->attack->print<<endl;
    }

    if(creature_list[m_i]->attack->triggerAction){
        for(int j = 0; j<creature_list[m_i]->attack->action.size();j++){
           // switchAck(creature_list[m_i]->attack->action[j]);
           cout<<"";

        }
    }
}

void turn_on(string input){
    vector<string>::iterator it = find(inventory.begin(),inventory.end(),input);
    if(it!=inventory.end()) {

        for(int j=0; j<item_list.size(); j++){

            if(item_list[j]->name==input){

                if(item_list[j]->ifturnon== false){
                    cout<<"This item cannot be turned on."<<endl;
                }
                else{
                    cout<<"You activate the "<< item_list[j]->name<<"."<<endl;
                    cout<<item_list[j]->turnon.print<<endl;
                    //call switchAck function;
                }
            }
        }
    }
    else{
        cout<<"You don't have such item."<<endl;
    }


}


void put(string input_item, string input_container){

    bool flag= true;
    for(int i =0; i<inventory.size();i++){
        if(inventory[i]==input_item){//choose right item
            //cout<<"right: "<<inventory[i]<<endl;

            for(int j=0;j<nowRoom->container.size();j++){
                if(nowRoom->container[j]==input_container){
                    flag=false;
                }
            }
            if(flag){
                cout<<"This room has no such container."<<endl;
                return;
            }

            for(int j=0; j< container_list.size();j++){
                if(container_list[j]->name==input_container){//chose right container


                    if(container_list[j]->accept.size()==0){
                        container_list[j]->item.push_back(input_item);
                        inventory.erase(inventory.begin()+i);
                        cout<<"Item "<< input_item<<" added to "<<input_container<<"."<<endl;
                        return;
                    }
                    else{
                        for(int k=0; k<container_list[j]->accept.size();k++){
                            if(container_list[j]->accept[k]==input_item){
                                container_list[j]->item.push_back(input_item);

                                inventory.erase(inventory.begin()+i);
                                cout<<"Item "<< input_item<<" added to "<<input_container<<"."<<endl;
                                //not sure if we need to status of the container here.
                                return;
                            }
                        }
                        cout<<container_list[j]->status<<endl;
                        cout<<"This item cannot be accepted"<<endl;
                        return;
                    }
                }
            }

        }


    }
    cout<<"There is no such item"<<endl;
}
void open(string input){
    for(int k=0;k < (nowRoom->container).size();k++) {
        if(nowRoom->container[k]==input) {

            for (int i = 0; i < container_list.size(); i++) {
                if (container_list[i]->name == input) {
                    if (container_list[i]->status == "locked") {
                        cout << container_list[i]->name << " is locked." << endl;
                        return;

                    } else if ((container_list[i]->item).size() == 0) {
                        cout << container_list[i]->name << " is empty." << endl;
                        return;
                    } else {
                        cout << container_list[i]->name << " contains ";
                        int j;
                        for (j = 0; j < (container_list[i]->item).size() - 1; j++) {
                            cout << container_list[i]->item[j] << ", ";

                        }
                        cout << container_list[i]->item[j] << "." << endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"Error"<<endl;
}
void exit(){
    if(nowRoom->type=="exit"){
        GameFinish=true;
        cout<<"Game Over"<<endl;
    }
    else {
        cout << "Error" << endl;
    }
}

void read_item(string input){
    vector<string>::iterator it = find(inventory.begin(),inventory.end(),input);
    if(it!=inventory.end()){
        for(int i =0; i<item_list.size();i++){
            if(item_list[i]->name==input){
                if(item_list[i]->writing.size()!=0){
                    cout<<item_list[i]->writing<<endl;
                }
                else{
                    cout<<"Nothing written."<<endl;
                }
            }
        }
    }
    else{
        cout<<"Error"<<endl;
    }


}
void drop(string input){
    vector<string>::iterator it = find(inventory.begin(),inventory.end(),input);
    if(it!=inventory.end()){
        int i = std::distance(inventory.begin(),it);
        (nowRoom->item).push_back(input);
        inventory.erase(inventory.begin()+i);
        cout<<input<<" dropped."<<endl;

    }
    else{
        cout<<"Error"<< endl;
    }


}
void take(string input){

    for(int i=0; i<(nowRoom->item).size();i++){
        if(nowRoom->item[i]==input){

            inventory.push_back(input);
            (nowRoom->item).erase((nowRoom->item).begin()+i);
            cout<<"Item "<<input<<" added to inventory."<<endl;
            return;
        }
    }
    for(int i=0; i<(nowRoom->container).size();i++){
//        cout<<"container: "<<nowRoom->container[i]<<endl;
        for(int j=0; j<container_list.size();j++){
//            cout<<"status:"<<container_list[j]->status<<endl;

            if(nowRoom->container[i]==container_list[j]->name && container_list[j]->status!="locked"){
//                cout<<"match and unlock"<<endl;
                for(int k=0; k<container_list[j]->item.size();k++){
                    if(container_list[j]->item[k]==input){
                        inventory.push_back(input);
                        cout<<"Item "<<input<<" added to inventory."<<endl;
                        container_list[j]->item.erase(container_list[j]->item.begin()+k);
                        return;
                    }
                }
            }
        }
    }
    cout<<"Error"<<endl;

}


