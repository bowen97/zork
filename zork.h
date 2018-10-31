//
// Created by bowen fang on 10/23/18.
//


#ifndef ZORK_ZORK_H
#define ZORK_ZORK_H


#include "header.h"
#include "zork.h"
#include "room.h"
#include "item.h"
#include "container.h"
#include "creature.h"

/*vector<Room*> room_list;
vector<item*> item_list;
vector<container*> container_list;
vector<creature*> creature_list;
Room * nowRoom;
vector<string> inventory;

//void check_input(string input); //
void put(string input_item, string input_container); //
void turn_on(string input); // activate
void attack(string monster, string weapon); //
void take(string input); //
void drop(string input); //
void read_item(string input); //
bool GameFinish= false; //
void exit(); // game over
void open(string input);  //

void nextRoom(string input){
    int i = (nowRoom->border).size();
    int j = 0;
    while(j < i) {
        if (nowRoom->border[j]->direction == input) {
            string newRoom = nowRoom->border[j]->name;
            int k = 0;
            while (k < room_list.size()) {
                if (room_list[k]->name == newRoom) {
                    nowRoom = room_list[k];
                }
                k++;
            }
            break;
        }
        j++;
    }
    if(j == i){
        cout << " Can't go that way" << endl;
    }
    else{
        cout << nowRoom-> description << endl;
    }

}

void view_inventory(){
    int i = inventory.size();
    if(!i){
        cout << "Inventory: empty" << endl;
        return;
    }
    cout << "Inventory: ";
    int j = 0;
    for(j = 0; j < i-1; j++){
        cout << inventory[j] << ", ";
    }
    cout << inventory[j] << endl;
}

void parse_input(string input) {
    if(input == "s" || input == "w" || input == "n" || input == "e") {
        nextRoom(input);
        return;
    }
    if(input == "take") {
        cout<<"What do you want to take? ";
        getline(cin, input);
        take(input);
        return;
    }
    if(input == "i") {
        view_inventory();
        return;
    }
    if(input.find("take") != string::npos){
        input.erase(0,5);
        take(input);
        return;
    }
    if(input.find("drop") != string::npos){
        input.erase(0,5);
        drop(input);
        return;
    }

    if(input == "drop") {
        cout<<"What do you want to drop? ";
        getline(cin, input);
        drop(input);
        return;
    }
    if(input == "read") {
        cout<<"What do you want to read? ";
        getline(cin, input);
        read_item(input);
        return;
    }
    if(input.find("read") != string::npos){
        input.erase(0,5);
        read_item(input);
        return;
    }
    if(input == "open") {
        cout<<"What do you want to open? ";
        getline(cin, input);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    if(input.find("open") != string::npos){
        input.erase(0,5);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    if(input.find("put") != string::npos){
        input.erase(0,4);
        int space_pos = input.find(" ");
        string put_item = input.substr(0, space_pos);
        input.erase(0, space_pos + 4);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    if(input == "put") {
        cout << "What do you want to put? ";
        getline(cin, input);
        string put_item = input;
        cout << "Where do you want to put in? ";
        getline(cin, input);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    if(input == "turn on") {
        cout<<"What do you want to turn on? ";
        getline(cin, input);
        turn_on(input);
        return;
    }
    if(input.find("turn on") != string::npos){
        input.erase(0,8);
        turn_on(input);
        return;
    }
    if(input == "attack") {
        cout << "What do you want to attack? ";
        getline(cin, input);
        string monster = input;
        cout << "What do you want to attack with? ";
        getline(cin, input);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    if(input.find("attack") != string::npos){
        input.erase(0,7);
        int space_pos = input.find(" ");
        string monster = input.substr(0, space_pos);
        input.erase(0, space_pos + 6);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    cout << "Error" << endl;
}
/*void check_input(string input){
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
void Gameover(){
    GameFinish = true;
    cout << "Victory!" << endl;
    cout << "Game Over" << endl;
}



void exit(){
    if(nowRoom->type=="exit"){
        cout << "exit1" << endl;
        Gameover();
        return;
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
        long i = std::distance(inventory.begin(),it);
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

}*/
vector<Room*> room_list;
vector<container*> container_list;
vector<item*> item_list;
vector<creature*> creature_list;

vector<string> inventory;
bool endGame = false;
Room * nowRoom;
void parse_input(string);
string getObjectType(string);

void Add(string obj) {
    string objname;
    string objloc;
    objname = obj.substr(0, obj.find(" to "));
    objloc = obj.substr(obj.find(" to ") + 4);
    int i = 0;
    string objType = getObjectType(objname);
    if (objType == "Item") {
        for (i = 0; i < room_list.size(); i++) {
            if (room_list[i]->name == objloc) {
                room_list[i]->item.push_back(objname);
                return;
            }
        }
        i = 0;
        for (i = 0; i < container_list.size(); i++) {
            if (container_list[i]->name == objloc) {
                container_list[i]->item.push_back(objname);
                return;
            }
        }
    }
    if (objType == "Creature") {
        i = 0;
        for (i = 0; i < room_list.size(); i++) {
            if (room_list[i]->name == objloc) {
                room_list[i]->creature.push_back(objname);
                return;
            }
        }
    }
    if (objType == "Container") {
        i = 0;
        for (i = 0; i < room_list.size(); i++) {
            if (room_list[i]->name == objloc) {
                room_list[i]->container.push_back(objname);
                return;
            }
        }
    }
}


void Delete(string objname){
    int i;
    int j;
    int k;
    for( i = 0; i < room_list.size(); i++){
        if(room_list[i]->name == objname){
            for( j = 0; j< nowRoom->border.size(); j++) {
                if (nowRoom->border[j]->name == objname) {
                    nowRoom->border.erase(nowRoom->border.begin()+j);
                    return;

                }
            }
        }
    }
    //i = 0;
    for(i = 0; i < container_list.size();i++){
        if(container_list[i]->name == objname){
            for(j = 0; j<room_list.size();j++){
                for(k = 0; k<room_list[j]->container.size();k++){
                    if(room_list[j]->container[k] == objname){
                        room_list[j]->container.erase(room_list[j]->container.begin()+k);
                        return;
                    }
                }
            }
        }
    }
    //i = 0;
    for(i = 0; i<item_list.size(); i++){
        if(item_list[i]->name == objname){
            for(j = 0; j<room_list.size(); j++){
                for(k = 0; k < room_list[j]->item.size(); k++){
                    if(room_list[j]->item[k] == objname){
                        room_list[j]->item.erase(room_list[j]->item.begin()+k);
                        return;
                    }
                }
            }
        }
    }
    //i = 0;
    for(i = 0; i<creature_list.size();i++){
        if(creature_list[i]->name == objname){
            for(j = 0; j < room_list.size(); j++){
                for(k = 0; k<room_list[j]->creature.size(); k++){
                    if(room_list[j]->creature[k] == objname){
                        room_list[j]->creature.erase(room_list[j]->creature.begin()+k);
                        return;
                    }
                }
            }
        }
    }

}

void Update(string obj){
    string objname;
    string next;
    int i;
    objname = obj.substr(0, obj.find(" to "));
    next = obj.substr(obj.find(" to ")+4);
    for(i = 0; i < room_list.size(); i++){
        if(room_list[i]->name == objname){
            room_list[i]->status = next;
            return;
        }
    }
    i = 0;
    for(i = 0; i < container_list.size(); i++){
        if(container_list[i]->name == objname){
            container_list[i]->status = next;
            return;
        }
    }
    i = 0;
    for(i = 0; i < item_list.size(); i++){
        if(item_list[i]->name == objname){
            item_list[i]->status = next;
            return;
        }
    }
    i = 0;
    for(i = 0; i < creature_list.size(); i++){
        if(creature_list[i]->name == objname){
            creature_list[i]->status = next;
            return;
        }
    }
}

void Gameover(){
    endGame = true;
    cout << "Victory!" << endl;
    cout << "Game Over" << endl;
}


void switchAck(string action){
    if(action.find("Add") != string::npos){
        Add(action.erase(0,4));
        return;
    }
    if(action.find("Delete") != string::npos){
        Delete(action.erase(0,7));
        return;
    }
    if(action.find("Update") != string::npos){
        Update(action.erase(0,7));
        return;
    }
    if(action == "Game Over"){
        Gameover();
        return;
    }
    parse_input(action);
}

void next_room(string input){
    int i = (nowRoom -> border).size();
    int ind = 0;
    while(ind < i) {
        if(nowRoom -> border[ind] -> direction == input){
            string newroom = nowRoom -> border[ind] -> name;
            int j = room_list.size();
            int ind2 = 0;
            while(ind2 < j) {
                if(room_list[ind2] -> name == newroom){
                    nowRoom = room_list[ind2];
                }
                ind2++;
            }
            break;
        }
        ind++;
    }
    if(ind == i)
        cout << "Can't go that way" << endl;
    else
        cout << nowRoom -> description << endl;
}

void view_inventory(){
    int i = inventory.size();
    if(!i){
        cout << "Inventory: empty" << endl;
        return;
    }
    cout << "Inventory: ";
    int ind = 0;
    while(ind < i - 1) {
        cout << inventory[ind] << ", ";
        ind++;
    }
    cout << inventory[ind] << endl;
}

void take(string input){
    int i,j,k;
    for(i = 0; i < (nowRoom -> item).size(); i++){
        if(nowRoom -> item[i] == input){
            inventory.push_back(input);
            (nowRoom -> item).erase((nowRoom -> item).begin() + i);
            cout << "Item " << input << " added to inventory." << endl;
            return;
        }
    }

    for(i = 0; i < (nowRoom -> container).size(); i++){
        string container_name = nowRoom->container[i];
        for(j = 0; j < container_list.size(); j++){
            if(container_list[j]->name == container_name &&
               container_list[j]->status == "unlocked"){
                for(k = 0; k < container_list[j]->item.size();k++){
                    if(container_list[j]->item[k] == input){
                        (nowRoom -> item).push_back(container_list[j] -> item[k]);
                        container_list[j] -> item.erase(container_list[j]->item.begin()+k);
                        take(input);
                        return;
                    }
                }
            }
        }
    }
    cout << "Error" << endl;
}

void drop(string input){
    int i = 0;
    while(i < inventory.size()) {
        if(inventory[i] == input){
            (nowRoom -> item).push_back(input);
            inventory.erase(inventory.begin() + i);
            cout << input << " dropped." << endl;
            return;
        }
        i++;
    }
    cout << "Error" << endl;
}

void read(string input){
    int i = 0;
    int j;
    while(i < inventory.size()) {
        if(inventory[i] == input){
            j = 0;
            while(j < item_list.size()) {
                if(item_list[j] -> name == input){
                    if(item_list[j] -> writing.size() == 0)
                        cout << "Nothing written." << endl;
                    else
                        cout << item_list[j] -> writing << endl;
                }
                j++;
            }
            return;
        }
        i++;
    }
    cout << "Error" << endl;
}

void put(string a, string b){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < inventory.size()) {
        if(inventory[i] == a){
            if(nowRoom -> name == b){
                drop(a);
                return;
            }
            j = 0;
            while(j < nowRoom->container.size()) {
                if(nowRoom -> container[j] == b) { break; }
                j++;
            }
            if(j == nowRoom -> container.size()){
                cout<<"Error"<<endl;
                return;
            }
            j = 0;
            while(j < container_list.size()) {
                if(container_list[j] -> name == b){
                    if(container_list[j]->accept.size() == 0){
                        container_list[j] -> item.push_back(a);
                        inventory.erase(inventory.begin() + i);
                        cout << "Item " << a << " added to "<< b << "." << endl;
                        if(container_list[j]->status == ""){
                            container_list[j]->status = "unlocked";
                        }
                        return;
                    }
                    k = 0;
                    while(k < container_list[j]->accept.size()) {
                        if(container_list[j] -> accept[k] == a){
                            container_list[j] -> item.push_back(a);
                            inventory.erase(inventory.begin() + i);
                            cout << "Item " << a << " added to "<< b << "." << endl;
                            if(container_list[j]->status == ""){
                                container_list[j]->status = "unlocked";
                            }
                            return;
                        }
                        k++;
                    }
                    cout << b << " doesn't accept " << a << endl;
                    return;
                }
                j++;
            }
            return;
        }
        i++;
    }
    cout << "Error"<<endl;
}

void Activate(string input){
    int i = 0;
    int j = 0;
    while(i < inventory.size()) {
        if(inventory[i] == input){
            j = 0;
            while(j < item_list.size()) {
                if(item_list[j] -> name == input){
                    if(item_list[j] -> ifturnon == false){
                        cout<<"Item is not able to be turned on." << endl;
                    } else {
                        cout<<"You activate the "<< item_list[j]->name<<"."<<endl;
                        cout << item_list[j] -> turnon.print << endl;
                        switchAck(item_list[j] -> turnon.action);
                    }
                }
                j++;
            }
            return;
        }
        i++;
    }
    cout << "Error" << endl;
}

void open(string input){
    int var = 0;
    while(var < nowRoom->container.size()) {
        if(nowRoom -> container[var] == input){ break; }
        var++;
    }
    if(var == nowRoom -> container.size()){
        cout << "Error" << endl;
        return;
    }
    int i = 0;
    while(i < container_list.size()) {
        if(container_list[i] -> name == input){
            if(container_list[i] -> status == "locked"){
                cout << container_list[i] -> name << " is locked." << endl;
                return;
            }
            if((container_list[i] -> item).size() == 0){
                cout <<container_list[i] -> name << " is empty." << endl;
                return;
            }
            container_list[i] -> status = "unlocked";
            cout << container_list[i] -> name << " contains ";
            int j = 0;
            while(j < (container_list[i] -> item).size() - 1) {
                cout << container_list[i] -> item[j] << ", ";
                j++;
            }
            cout << container_list[i] -> item[j] << "." << endl;
            return;
        }
        i++;
    }
}

void exit() {
    if(nowRoom -> type == "exit"){
        Gameover();
        return;
    }
    cout << "Error" << endl;
}

void attack(string creature, string weapon){
    int i = 0;
    int j = 0;
    while(i < nowRoom->creature.size()) {
        if(nowRoom -> creature[i] == creature) { break; }
        i++;
    }
    if(i == nowRoom -> creature.size()){
        cout << "Error" << endl;
        return;
    }
    i = 0;
    while(i < inventory.size()) {
        if(inventory[i] == weapon) { break; }
        i++;
    }
    if(i == inventory.size()){
        cout << "Error" << endl;
        return;
    }
    i = 0;
    while(i < creature_list.size()) {
        if(creature_list[i]->name == creature){ break; }
        i++;
    }
    j = 0;
    while(j < creature_list[i]->vulnerability.size()) {
        if(creature_list[i]->vulnerability[j] == weapon){
            cout << "You assault the " << creature << " with the " << weapon << "." << endl;
            break;
        }
        j++;
    }
    if(j == creature_list[i]->vulnerability.size()) {
        cout << "Error" << endl;
        return;
    }
    if(creature_list[i]->attack == NULL) {
        return;
    }
    if(creature_list[i]->attack->triggerCondition){
        string object = creature_list[i]->attack->condition.object;
        string status = creature_list[i]->attack->condition.status;
        bool itemFound = false;
        bool itemMatch = false;
        j = 0;
        while(j < item_list.size()) {
            if(item_list[j]->name == object){
                itemFound = true;
                itemMatch = item_list[j]->status == status;
                break;
            }
            j++;
        }
        if(!itemFound) {
            j = 0;
            while(j < room_list.size()) {
                if(room_list[j]->name == object){
                    itemFound = true;
                    itemMatch = room_list[j]->status == status;
                    break;
                }
                j++;
            }
        }
        if(!itemFound) {
            j = 0;
            while(j < container_list.size()) {
                if(container_list[j]->name == object){
                    itemFound = true;
                    itemMatch = container_list[j]->status == status;
                    break;
                }
                j++;
            }
        }
        if(!itemFound) {
            j = 0;
            while(j < creature_list.size()) {
                if(creature_list[j]->name == object){
                    itemFound = true;
                    itemMatch = creature_list[j]->status == status;
                    break;
                }
                j++;
            }
        }
        if(!itemMatch) {
            cout << "Error" << endl;
            return;
        }
    }
    if(creature_list[i]->attack->triggerPrint){
        cout << "2You assault the " << creature << " with the " << weapon << "." << endl;
        cout << creature_list[i]->attack->print<<endl;
    }
    if(creature_list[i]->attack->triggerAction){
        for(j = 0; j<creature_list[i]->attack->action.size();j++){
            switchAck(creature_list[i]->attack->action[j]);
        }
    }
}

void parse_input(string input) {
    if(input == "s" || input == "w" || input == "n" || input == "e") {
        next_room(input);
        return;
    }
    if(input == "take") {
        cout<<"What do you want to take? ";
        getline(cin, input);
        take(input);
        return;
    }
    if(input == "i") {
        view_inventory();
        return;
    }
    if(input.find("take") != string::npos){
        input.erase(0,5);
        take(input);
        return;
    }
    if(input.find("drop") != string::npos){
        input.erase(0,5);
        drop(input);
        return;
    }

    if(input == "drop") {
        cout<<"What do you want to drop? ";
        getline(cin, input);
        drop(input);
        return;
    }
    if(input == "read") {
        cout<<"What do you want to read? ";
        getline(cin, input);
        read(input);
        return;
    }
    if(input.find("read") != string::npos){
        input.erase(0,5);
        read(input);
        return;
    }
    if(input == "open") {
        cout<<"What do you want to open? ";
        getline(cin, input);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    if(input.find("open") != string::npos){
        input.erase(0,5);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    if(input.find("put") != string::npos){
        input.erase(0,4);
        int space_pos = input.find(" ");
        string put_item = input.substr(0, space_pos);
        input.erase(0, space_pos + 4);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    if(input == "put") {
        cout << "What do you want to put? ";
        getline(cin, input);
        string put_item = input;
        cout << "Where do you want to put in? ";
        getline(cin, input);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    if(input == "turn on") {
        cout<<"What do you want to turn on? ";
        getline(cin, input);
        Activate(input);
        return;
    }
    if(input.find("turn on") != string::npos){
        input.erase(0,8);
        Activate(input);
        return;
    }
    if(input == "attack") {
        cout << "What do you want to attack? ";
        getline(cin, input);
        string monster = input;
        cout << "What do you want to attack with? ";
        getline(cin, input);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    if(input.find("attack") != string::npos){
        input.erase(0,7);
        int space_pos = input.find(" ");
        string monster = input.substr(0, space_pos);
        input.erase(0, space_pos + 6);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    cout << "Error" << endl;
}


















string getObjectType(string ob){
   // cout << "name of input object is " << ob << endl;
    int i = 0;
    for( i = 0; i<room_list.size(); i++ ){
        if((room_list[i])->name == ob){
            //cout << "Room" << endl;
            return "Room";

        }
    }
    i = 0;
    for(i = 0; i<item_list.size(); i++){
        if((item_list[i])->name == ob){
            //cout << "Item" << endl;
            return "Item";

        }
    }
    i = 0;
    for(i = 0; i<container_list.size(); i++ ){
        if((container_list[i])->name == ob){
            //cout << "Container" << endl;
            return "Container";

        }
    }
    i = 0;
    for(i = 0; i<creature_list.size(); i++ ){
        if((creature_list[i])->name == ob){
            //cout << "Creature" << endl;
            return "Creature";

        }
    }
    //cout << "NULL" << endl;
    return NULL;

}




bool trig_own(Trigger* t){
    string owner = t->owner.owner;
    string has = t->owner.has;
    string object = t->owner.object;
    int i;
    int j;
    int k;
    i = 0;
    if(owner == "inventory"){
        //cout << "lol" << endl;
        for(i = 0; i < inventory.size(); i++) {
            if (inventory[i] == object) {
                if (has == "yes") {
                    if (t->has_print) {
                        cout << t->print << endl;
                    }
                    if (t->has_action) {
                        k = 0;
                        while (k < t->action.size()) {
                            switchAck(t->action[k]);
                            k++;
                        }
                    }
                    return true;
                } else {
                    return false;
                }
            }
        }
        //cout << i << endl;
        if(i == inventory.size()){
            if(has == "no"){
                if(t->has_print){
                    cout <<t->print<<endl;
                }
                if(t->has_action){
                    k = 0;
                    while(k < t->action.size()){
                        switchAck(t->action[k]);
                        k++;
                    }
                }
                //cout << i << endl;
                return true;
            }
            else{
                return false;
            }
        }
    }
    //cout << " see if run to this line in trig_own" << endl;
    string ownerType = getObjectType(owner);
    //cout << "call getObjectType in trig_own" << endl;
    string objType = getObjectType(object);
    if(ownerType == "Room"){
        i = 0;
        for(i = 0 ; i < room_list.size(); i++){
            if(room_list[i]->name == owner){
                if(objType == "Item"){
                    j = 0;
                    for(j = 0;j < room_list[i]->item.size();j++){
                        if(room_list[i]->item[j] == object){
                            if(has == "yes"){
                                if(t->has_print){
                                    cout << t->print << endl;
                                }
                                if(t->has_action){
                                    k = 0;
                                    while(k < t->action.size()){
                                        switchAck(t->action[k]);
                                        k++;
                                    }
                                }
                                return true;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                    if(j == room_list[i]->item.size()){
                        if(has == "no"){
                            if(t->has_print){
                                cout << t->print<<endl;
                            }
                            if(t->has_action){
                                k = 0;
                                while(k < t->action.size()){
                                    switchAck(t->action[k]);
                                    k++;
                                }
                            }
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                }
                if(objType == "Container"){
                    j = 0;
                    for(j = 0; j < room_list[i]->container.size();j++){
                        if(room_list[i]->container[j] == object){
                            if(has == "yes"){
                                if(t->has_print){
                                    cout << t->print<<endl;
                                }
                                if(t->has_action){
                                    k = 0;
                                    while(k < t->action.size()){
                                        switchAck(t->action[k]);
                                        k++;
                                    }
                                }
                                return true;
                            } else{return false;}
                        }
                    }
                    if(j == room_list[i]->container.size()){
                        if(has == "no"){
                            if(t->has_print){
                                cout << t->print<<endl;
                            }
                            if(t->has_action){
                                k = 0;
                                while(k < t->action.size()){
                                    switchAck(t->action[k]);
                                    k++;
                                }
                            }
                            return true;
                        } else{return false;}
                    }
                }
                if(objType == "Creature"){
                    j = 0;
                    for(j = 0; j < room_list[i]->creature.size(); j++){
                        if(room_list[i]->creature[j] == object){
                            if(has == "yes"){
                                if(t->has_print){
                                    cout << t->print << endl;
                                }
                                if(t->has_action){
                                    k = 0;
                                    while(k < t->action.size()){
                                        switchAck(t->action[k]);
                                        k++;
                                    }
                                }
                                return true;
                            } else{return false;}
                        }
                    }
                    if(j == room_list[i]->creature.size()){
                        if(has == "no"){
                            if(t->has_print){
                                cout << t->print << endl;
                            }
                            if(t->has_action){
                                k = 0;
                                while(k < t->action.size()){
                                    switchAck(t->action[k]);
                                    k++;
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                }
            }
        }
    }
    if(ownerType == "Container"){
        i = 0;
        for(i = 0; i < container_list.size(); i++){
            if(container_list[i]->name == owner){
                j = 0;
                while( j < container_list[i]->item.size()){
                    if(container_list[i]->item[j] == object){
                        if(has == "yes"){
                            if(t->has_print){
                                cout<<t->print<<endl;
                            }
                            if(t->has_action){
                                k = 0;
                                while(k < t->action.size()){
                                    switchAck(t->action[k]);
                                    k++;
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                    j++;
                }
                if(j == container_list[i]->item.size()){
                    if(has == "no"){
                        if(t->has_print){
                            cout << t->print << endl;
                        }
                        if(t->has_action){
                            k = 0;
                            while(k < t->action.size()){
                                switchAck(t->action[k]);
                                k++;
                            }
                        }
                        return true;
                    } else{return false;}
                }
            }
        }
    }
    return false;

}

bool trig_stat(Trigger* t){
    string object = t->status.object;
    string status = t->status.status;
    //cout << "print: " << t->print << endl;
    //cout << "object: " << object << endl;
    int i;
    int j;
    //cout << "see if runs to this line in trig_stat" << endl;
    string objType = getObjectType(object);
    //cout << "call getObjectType in trig_stat" << endl;
    if(objType == "Room"){
        i = 0;
        for(i = 0; i < room_list.size(); i++){
            if(room_list[i]->name == object){
                if(room_list[i]->status == status){
                    if(t->has_print){
                        cout << t->print<<endl;
                    }
                    if(t->has_action){
                        j = 0;
                        while(j < t->action.size()){
                            switchAck(t->action[j]);
                            j++;
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objType == "Item"){
        i = 0;
        for(i = 0; i < item_list.size(); i++){
            if(item_list[i]->name == object){
                if(item_list[i]->status == status){
                    if(t->has_print){
                        cout << t->print << endl;
                    }
                    if(t->has_action){
                        j = 0;
                        while(j < t->action.size()){
                            switchAck(t->action[j]);
                            j++;
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objType == "Container"){
        i = 0;
        for(i = 0; i <container_list.size(); i++){
            if(container_list[i]->name == object){
                if(container_list[i]->status == status){
                    if(t->has_print){
                        cout << t->print << endl;
                    }
                    if(t->has_action){
                        j = 0;
                        while(j < t->action.size()){
                            switchAck(t->action[j]);
                            j++;
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objType == "Creature"){
        i = 0;
        for(i = 0; i < creature_list.size(); i++){
            if(creature_list[i]->name == object){
                if(creature_list[i]->status == status){
                    if(t->has_print){
                        cout << t->print << endl;
                    }
                    if(t->has_action){
                        j = 0;
                        while(j < t->action.size()){
                            switchAck(t->action[j]);
                            j++;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;

}

bool checkTrigNoArg(){
    int i;
    int j;
    int k;
    bool roomOut = false;
    bool itemOut = false;
    bool containerOut = false;
    bool creatureOut = false;
    Trigger* t;
    if(nowRoom->trigger.size() != 0){
        j = 0;
        for(j = 0; j < nowRoom->trigger.size();j++){
            t = nowRoom->trigger[j];
            if(!t->has_command){
                if(t->type == "permanent" ||(t->type == "single" && t->times == 0)){
                    if(t->condition == 3){
                        roomOut = trig_own(t);
                    }
                    else if(t->condition == 2){
                        roomOut = trig_stat(t);
                    }
                    if(roomOut == true){
                        t->times++;
                    }
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < nowRoom->item.size(); i++){
        string target = nowRoom->item[i];
        j = 0;
        for(j = 0; j < item_list.size();j++){
            if(item_list[j]->name == target){
                k = 0;
                while(k < item_list[j]->trigger.size()){
                    t = item_list[j]->trigger[k];
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" &&t -> times == 0)){
                            if(t->condition == 3){
                                itemOut = trig_own(t);
                            }
                            else if(t->condition == 2){
                                itemOut = trig_stat(t);
                            }
                            if(itemOut == true){
                                t->times++;
                            }
                        }
                    }
                    k++;
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < nowRoom->container.size(); i++){
        string target = nowRoom->container[i];
        //cout << "The container 's name in the room is (target)" << target<<endl;
        j = 0;
        for(j = 0; j < container_list.size(); j++){
            if(container_list[j]->name == target){
                //cout << "The container 's name in the room is (target)" << target<<endl;
                k = 0;
                while(k < container_list[j]->trigger.size()){
                    t = container_list[j]->trigger[k];
                    //cout << "t: " << t->print;
                    //cout << t->has_command << endl;
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){
                                containerOut = trig_own(t);
                            }
                            else if(t->condition == 2){
                                containerOut = trig_stat(t);
                            }
                            if(containerOut == true){
                                t->times++;
                            }
                        }
                    }
                    k++;
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < nowRoom->creature.size(); i++){
        string target = nowRoom->creature[i];
        j = 0;
        for(j = 0; j < creature_list.size(); j++){
            if(creature_list[j] -> name == target){
                k = 0;
                while(k < creature_list[j]->trigger.size()){
                    t = creature_list[j]->trigger[k];
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){
                                creatureOut =  trig_own(t);
                            }
                            else if(t->condition == 2){
                                creatureOut = trig_stat(t);
                            }
                            if(creatureOut == true){
                                t->times++;
                            }
                        }
                    }
                    k++;
                }
            }
        }
    }
    return (roomOut||itemOut||containerOut||creatureOut);

}
bool checkTrigArg(string input){
    int i;
    int j;
    int k;
    bool roomOut = false;
    bool itemOut = false;
    bool containerOut = false;
    bool creatureOut = false;
    Trigger* t;
    if(nowRoom -> trigger.size() != 0){
        j = 0;
        for(j = 0; j < nowRoom->trigger.size(); j++){
            t = nowRoom->trigger[j];
            if(t->has_command && input == t->command){
                if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                    if(t->condition == 3){
                        roomOut = trig_own(t);
                    }
                    else if(t->condition == 2){
                        roomOut = trig_stat(t);
                    }
                    if(roomOut == true){
                       // cout << "roomOut is:" << roomOut << endl;
                        t->times++;
                    }
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < inventory.size(); i++){
        string target = inventory[i];
        j = 0;
        for(j = 0; j < item_list.size(); j++){
            if(item_list[j]->name == target){
                k = 0;
                for(k = 0; k < item_list[j]->trigger.size();k++){
                    t = item_list[j]->trigger[k];
                    if(t->has_command && input == t->command){
                        if(t->type == "permanent"||(t->type == "single" && t->times == 0)){
                            if(t->condition == 3){
                                itemOut = trig_own(t);
                            }
                            else if(t->condition == 2){
                                itemOut = trig_stat(t);
                            }
                            if(itemOut == true){
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < nowRoom->container.size(); i++){
        string target = nowRoom->container[i];
        j = 0;
        for(j = 0; j < container_list.size(); j++){
            if(container_list[j]->name == target){
                k = 0;
                for(k = 0; k < container_list[j]->trigger.size();k++){
                    t = container_list[j]->trigger[k];
                    if(t->has_command && input == t->command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){
                                containerOut = trig_own(t);
                            }
                            else if(t->condition == 2){
                                containerOut = trig_stat(t);
                            }
                            if(containerOut == true){
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    i = 0;
    for(i = 0; i < nowRoom->creature.size(); i++){
        string target = nowRoom->creature[i];
        j = 0;
        for(j = 0; j < creature_list.size(); j++){
            if(creature_list[j]->name == target){
                k = 0;
                for(k = 0; k < creature_list[j]->trigger.size(); k++){
                    t = creature_list[j]->trigger[k];
                    if(t->has_command && input == t->command){
                        if(t->type == "permanent" || ( t->type =="single" &&t->times == 0)){
                            if(t->condition == 3){
                                creatureOut = trig_own(t);
                            }
                            else if(t->condition == 2){
                                creatureOut = trig_stat(t);
                            }
                            if(creatureOut == true){
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    //cout << roomOut << endl;
    return (roomOut||itemOut||containerOut||creatureOut);
}


#endif //ZORK_ZORK_H
