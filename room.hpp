/****************************************
***************** Program:room.hpp
******************* Author:Kingsley C. Chukwu
***************** Date: 3/3/2019
***************** Description:contains all the function prototype in the room.hpp.
****************** Input: none
**************** Output: none
*****************************************************/

#ifndef ROOM_H
#define ROOM_H



#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include "event.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "bats.hpp"
#include "wumpus.hpp"

using namespace std;


class Room {
    private:
    int rows;
    int cols; 
    vector<vector<string> > room_grid;
    string grid_array;
    int x;
    int y;
    int* cord_x; 
    int* cord_y;
    Event* events_1;
    Event* events_2;
    Event* events_3;
    Event* events_4;
   int gold_pick;
   int wumpus_dead;
   int number_arrows;
   int start_x;
   int start_y;
  
   public:
   Room(int rows, int cols);
   void roof ();  
   void initializer ();
   void display_grid(); 
   void move_player(int num);
   void event_display();
   int ai_decider();
   int game_decider();
   void shoot_arrow(int num);
   int return_num_arr();
   ~Room();

};
int check_err();
void data_to_explore();
void data_explore2();
int check_err2();
void data_explore3();
int check_err3();
void data_explore4();
int check_err4();


#endif
 
