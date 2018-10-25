//
// Created by bowen fang on 10/23/18.
//

#ifndef ZORK_ZORK_H
#define ZORK_ZORK_H


#include "header.h"
#include "room.h"
#include "item.h"
#include "container.h"
#include "creature.h"

vector<Room*> room_list;
vector<item*> item_list;
vector<container*> container_list;
vector<creature*> creature_list;
Room * nowRoom;

void check_input(string input);
vector<string> inventory;
void take(string input);
void drop(string input);
void read_item(string input);
bool GameFinish= false;
void exit();
void open(string input);
#endif //ZORK_ZORK_H
