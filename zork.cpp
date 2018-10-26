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



    return;
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


