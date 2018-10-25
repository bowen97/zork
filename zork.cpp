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
    return;
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


