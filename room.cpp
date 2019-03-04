/****************************************
***************** Program:room.hpp
******************* Author:Kingsley C. Chukwu
***************** Date: 2/10/2019
***************** Description:implements all the function in the animal.hpp.
****************** Input: none
**************** Output: none
*****************************************************/


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
#include "room.hpp"


using namespace std;

/******************************************************
******************************** Function:Room
******************************** Description:it is parameterized constructor that initial the position of the different events in the room
********************************* Parameters: integers
********************************* Pre-Conditions: number of rows and columns
******************************** Post-Conditions: initiaizes the position of the different events in the room
************************************************************************************/


Room::Room(int rows, int cols) : rows(rows), cols(cols) {
      srand(time(0));
      this->x = rand() % this->cols;
      this->y = rand() % this->rows;
      this->start_x = this->x;
      this->start_y = this->y;
      this->cord_x = new int[4];
      this->cord_y = new int[4];
      do {
         this->cord_x[0] = rand() % this->cols;
         this->cord_y[0] =  rand() % this->rows; 
      } while((this->x==this->cord_x[0]) && (this->y == this->cord_y[0]));
//       cout << this->cord_x[0] << this->cord_y[0] <<endl;
      this->events_1 = new Wumpus(this->cord_x[0], this->cord_y[0]);
      do {
         this->cord_x[1] = rand() % this->cols;
         this->cord_y[1] =  rand() % this->rows;
      } while((this->x==this->cord_x[1]) && (this->y == this->cord_y[1]) || (this->cord_x[0]==this->cord_x[1]) && (this->cord_y[0] == this->cord_y[1]) );
      this->events_2 = new Pit(this->cord_x[1], this->cord_y[1]);
      do {
         this->cord_x[2] = rand() % this->cols;
         this->cord_y[2] =  rand() % this->rows;
      } while((this->x==this->cord_x[2]) && (this->y == this->cord_y[2]) || (this->cord_x[0]==this->cord_x[2]) && (this->cord_y[0] == this->cord_y[2]) || (this->cord_x[1]==this->cord_x[2]) && (this->cord_y[1] == this->cord_y[2]) );
      this->events_3 = new Bats(this->cord_x[2], this->cord_y[2]);
      do {
         this->cord_x[3] = rand() % this->cols;
         this->cord_y[3] =  rand() % this->rows;
      } while((this->x==this->cord_x[3]) && (this->y == this->cord_y[3]) || (this->cord_x[0]==this->cord_x[3]) && (this->cord_y[0] == this->cord_y[3]) || (this->cord_x[1]==this->cord_x[3]) && (this->cord_y[1] == this->cord_y[3]) || (this->cord_x[2]==this->cord_x[3]) && (this->cord_y[2] == this->cord_y[3]) );
      this->events_4 = new Gold (this->cord_x[3], this->cord_y[3]);
     this->gold_pick = 0;
     this->wumpus_dead = 0;
     this->number_arrows = 3;
}


/******************************************************
******************************** Function:game_decider
******************************** Description:it checks when the play losses the game or wins the game
********************************* Parameters: none
********************************* Pre-Conditions: none
******************************** Post-Conditions: return an UINT_MAX or INT_MAX or INT_MIN
************************************************************************************/


int Room::game_decider() {
    if ((this->gold_pick==1) && (this->x==this->start_x) && (this->y==this->start_y) && (this->wumpus_dead==1)) {
       cout <<""<<endl; cout <<"You have the gold, killed the wumpus  and also found your way out of the cave. hahahahah!!!. You win the game"<<endl; 
       return UINT_MAX;
    }
    if ((this->wumpus_dead==0) && (this->x==this->events_1->return_xco()) && (this->y==this->events_1->return_yco())) {
        cout <<""<<endl; cout <<"You have been killed by a wumpus. so sad!!!. Game over. You lose the game!!!" <<endl; 
       
        return INT_MAX;
    }
    if ( (this->x==this->events_2->return_xco()) && (this->y==this->events_2->return_yco())) {
         cout <<""<<endl; cout <<"You just fell into the bottomless pit. so sad!!!. Game over. You lose the game !!!"<<endl;
        return INT_MIN;
    }

    
}

/******************************************************
******************************* Function:data_to_explore
******************************* Description:print out the number that corresponds to the two option the player can play
******************************** Parameters: none
******************************** Pre-Conditions: none
******************************* Post-Conditions: none
***********************************************************************************/


void data_to_explore() {
   cout <<" "<<endl; cout<<"Enter between 0-1 to choose to either a shoot an arrow or move to another room"<<endl; cout <<" "<<endl;
   cout <<"Enter (0) if you want to shoot an arrow"<<endl; cout <<" "<<endl;
   cout <<"Enter (1) if you want to move to another room"<<endl; cout <<" "<<endl;
}


/******************************************************
****************************** Function:data_to_explore2
****************************** Description:print out the numbers that correspnds to various location when the player want to shoot an arrow
****************************** Parameters: none
****************************** Pre-Conditions: none
****************************** Post-Conditions: none
*********************************************************************************/


void data_to_explore2() {
   cout <<" "<<endl; cout<<"Enter between 1-4 to choose to shoot an arrow"<<endl; cout <<" "<<endl;
   cout <<"Enter (1) if you want to shoot an arrow in the south direction"<<endl; cout <<" "<<endl;
   cout <<"Enter (2) if you want to shoot an arrow in the north direction"<<endl; cout <<" "<<endl;
   cout <<"Enter (3) if you want to shoot an arrow in the east direction"<<endl; cout <<" "<<endl;
   cout <<"Enter (3) if you want to shoot an arrow in the west direction"<<endl; cout <<" "<<endl;


}

/******************************************************
 * ***************************** Function:data_to_explore3
 * ***************************** Description:print out the number that corresponds to various location when the player want to move to another room
 * ****************************** Parameters: none
 * ****************************** Pre-Conditions: none
 * ****************************** Post-Conditions: none
 * *********************************************************************************/


void data_to_explore3() {
   cout <<" "<<endl; cout<<"Enter between 1-4 to choose a direction you want the player to move"<<endl; cout <<" "<<endl;
   cout <<"Enter (1) if you want to move south"<<endl; cout <<" "<<endl;
   cout <<"Enter (2) if you want to move north"<<endl; cout <<" "<<endl;
   cout <<"Enter (3) if you want to move east"<<endl; cout <<" "<<endl;
   cout <<"Enter (4) if you want to move west"<<endl; cout <<" "<<endl;

}

void data_to_explore4() {
   cout <<" "<<endl; cout<<"Enter between 1-3 to choose if you want to continue playing the game"<<endl; cout <<" "<<endl;
   cout <<"Enter (1) if you want to continue with same number of grid"<<endl; cout <<" "<<endl;
   cout <<"Enter (2) if you want to continue with a random number of grid"<<endl; cout <<" "<<endl;
   cout <<"Enter (3) if you want to end the game"<<endl; cout <<" "<<endl;

}



/******************************************************
**************************** Function:check_err
**************************** Description:checks for input errors
**************************** Parameters: none
***************************** Pre-Conditions: none
**************************** Post-Conditions: returns the input
*******************************************************************************/

int check_err() {
   int r_w = 0; string uzo; int num_input;
   do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore();
       getline (cin, uzo);
    }  while  ((uzo != "0") && (uzo != "1"));
    num_input = atoi(uzo.c_str());
    return num_input;
}

/******************************************************
***************************** Function:check_err
**************************** Description:checks for input errors
***************************** Parameters: none
****************************** Pre-Conditions: none
***************************** Post-Conditions: returns the input
********************************************************************************/


int check_err2() {
   int r_w = 0; string uzo; int num_input;
   do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore2();
       getline (cin, uzo);
    }  while  ((uzo != "1") && (uzo != "2") && (uzo != "3") && (uzo != "4")  );
    num_input = atoi(uzo.c_str());
    return num_input;
}


/******************************************************
***************************** Function:check_err3
****************************** Description:checks for input errors
***************************** Parameters: none
******************************* Pre-Conditions: none
****************************** Post-Conditions: returns the input
*********************************************************************************/


int check_err3() {
   int r_w = 0; string uzo; int num_input;
   do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore3();
       getline (cin, uzo);
    }  while  ((uzo != "1") && (uzo != "2") && (uzo != "3") && (uzo != "4"));
    num_input = atoi(uzo.c_str());
    return num_input;
}

/******************************************************
****************************** Function:check_err4
******************************* Description:checks for input errors
****************************** Parameters: none
******************************** Pre-Conditions: none
******************************* Post-Conditions: returns the input
**********************************************************************************/


int check_err4() {
   int r_w = 0; string uzo; int num_input;
   do {
       if (r_w > 0) {
          cout << " " << endl;
          cout << "Oops!, Invalid Input, Please enter a valid input"<<endl;
       }
       r_w++;
       cout << " " <<endl;
       data_to_explore4();
       getline (cin, uzo);
    }  while  ((uzo != "1") && (uzo != "2") && (uzo != "3") );
    num_input = atoi(uzo.c_str());
    return num_input;
}



/******************************************************
******************************* Function:return_num_arr
******************************** Description:returns the number of arrows the user have
******************************* Parameters: none
********************************* Pre-Conditions: none
******************************** Post-Conditions: returns the number of arrows
***********************************************************************************/


int Room::return_num_arr() {
    return this->number_arrows;
}

/******************************************************
******************************** Function:shoot_arrow
********************************* Description:allows the user to shoot an arrow and decide whether the arrow killed the wumpus or not
******************************** Parameters: an integer indicating the direction the user want to shoot the arrow
********************************** Pre-Conditions: none
********************************* Post-Conditions: shoot an arrow and decide whether the arrow killed the wumpus or not. if the user did not kill the wumpus, the wumpus will have 75 percent chances of been moved to another room 
************************************************************************************/


void Room::shoot_arrow(int num) {
    this->number_arrows--;
    srand(time(0));
    if (num==1) {
       if ((this->events_1->return_yco() <= this->y+3 && this->events_1->return_yco() > this->y ) && this->wumpus_dead == 0 && (this->events_1->return_xco() == this->x )) {
          this->wumpus_dead = 1;
          cout <<"You just killed the wumpus!!!! hahhahahahahahah"<<endl;  
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
       }  else {
       int x = rand() % 4;
       if ((x==0) || (x==1) || (x==2)) {
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
          do {
         this->cord_x[3] = rand() % this->cols;
         this->cord_y[3] =  rand() % this->rows;
      } while((this->x==this->cord_x[3]) && (this->y == this->cord_y[3]) || (this->cord_x[0]==this->cord_x[3]) && (this->cord_y[0] == this->cord_y[3]) || (this->cord_x[1]==this->cord_x[3]) && (this->cord_y[1] == this->cord_y[3]) || (this->cord_x[2]==this->cord_x[3]) && (this->cord_y[2] == this->cord_y[3]) );
       this->events_1->move_wumpus(this->cord_x[3], this->cord_y[3]);
       }
       }
    }    
    if (num==2) {
       if ((this->events_1->return_yco() >= this->y-3 && this->events_1->return_yco() < this->y ) && this->wumpus_dead == 0 && (this->events_1->return_xco() == this->x)) {
          this->wumpus_dead = 1;
          cout <<"You just killed the wumpus!!! hahhahahhahahah"<<endl;
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
       }  else {
       int x = rand() % 4;
       if ((x==0) || (x==1) || (x==2)) {
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
          do {         
         this->cord_x[3] = rand() % this->cols;
         this->cord_y[3] =  rand() % this->rows;
      } while((this->x==this->cord_x[3]) && (this->y == this->cord_y[3]) || (this->cord_x[0]==this->cord_x[3]) && (this->cord_y[0] == this->cord_y[3]) || (this->cord_x[1]==this->cord_x[3]) && (this->cord_y[1] == this->cord_y[3]) || (this->cord_x[2]==this->cord_x[3]) && (this->cord_y[2] == this->cord_y[3]) );
       this->events_1->move_wumpus(this->cord_x[3], this->cord_y[3]);
       }
       }
    }
    if (num==3) {
       if ((this->events_1->return_xco() <= this->x+3 && this->events_1->return_xco() > this->x ) && this->wumpus_dead == 0 && (this->events_1->return_yco() == this->y )) {
          this->wumpus_dead = 1;
          cout <<"You just killed the wumpus!!!  hahahhahaahah"<<endl;
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
       }  else {
       int x = rand() % 4;
       if ((x==0) || (x==1) || (x==2)) {
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
          do {
         this->cord_x[3] = rand() % this->cols;
         this->cord_y[3] =  rand() % this->rows;
      } while((this->x==this->cord_x[3]) && (this->y == this->cord_y[3]) || (this->cord_x[0]==this->cord_x[3]) && (this->cord_y[0] == this->cord_y[3]) || (this->cord_x[1]==this->cord_x[3]) && (this->cord_y[1] == this->cord_y[3]) || (this->cord_x[2]==this->cord_x[3]) && (this->cord_y[2] == this->cord_y[3]) );
       this->events_1->move_wumpus(this->cord_x[3], this->cord_y[3]);
       }
       }
    }
    if (num==4) {
       if ((this->events_1->return_xco() >= this->x-3 && this->events_1->return_xco() < this->x ) && this->wumpus_dead == 0 && (this->events_1->return_yco() == this->y )) {
          this->wumpus_dead = 1;
          cout <<"You just killed the wumpus!!!. hahahahahahah. "<<endl;
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
       }  else {
       int x = rand() % 4;
       if ((x==0) || (x==1) || (x==2)) {
//          this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = "   ";
          do {
         this->cord_x[3] = rand() % this->cols;
         this->cord_y[3] =  rand() % this->rows;
      } while((this->x==this->cord_x[3]) && (this->y == this->cord_y[3]) || (this->cord_x[0]==this->cord_x[3]) && (this->cord_y[0] == this->cord_y[3]) || (this->cord_x[1]==this->cord_x[3]) && (this->cord_y[1] == this->cord_y[3]) || (this->cord_x[2]==this->cord_x[3]) && (this->cord_y[2] == this->cord_y[3]) );
       this->events_1->move_wumpus(this->cord_x[3], this->cord_y[3]);
       }
       }
    }


}

/******************************************************
******************************** Function:event_display
********************************* Description:displays the events that happens whenever the player moves to another room
******************************** Parameters: none
********************************** Pre-Conditions: none
********************************* Post-Conditions: 
************************************************************************************/


void Room::event_display() {
     if ((this->x==this->events_4->return_xco()) && (this->y==this->events_4->return_yco()) && this->gold_pick == 0 ) {
         this->gold_pick = 1;
//         this->room_grid.at(this->events_4->return_yco()).at(this->events_4->return_xco()) = " * ";
         cout <<"You got the gold!!! hahahaha. You have to find  a way out of the cave"<<endl;
     }
     if ((this->x==this->events_3->return_xco()) && (this->y==this->events_3->return_yco())  ) {
         this->room_grid.at(this->y).at(this->x) = "   ";
         do {
             this->x = rand() % this->cols;
             this->y = rand() % this->rows;
         }   while (this->x == this->events_2->return_xco() && this->y==this->events_2->return_yco());
             this->room_grid.at(this->y).at(this->x) = " * ";
     }

     
     if ((this->x-1==this->events_1->return_xco()) && (this->y==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
     }
     if ((this->x+1==this->events_1->return_xco()) && (this->y==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
     }
     if ((this->x==this->events_1->return_xco()) && (this->y+1==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
     }
     if ((this->x==this->events_1->return_xco()) && (this->y-1==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
     }
    if ((this->x-1==this->events_2->return_xco()) && (this->y==this->events_2->return_yco())  ) {
         this->events_2->display_event();
     }
     if ((this->x+1==this->events_2->return_xco()) && (this->y==this->events_2->return_yco())  ) {
         this->events_2->display_event();
     }
     if ((this->x==this->events_2->return_xco()) && (this->y+1==this->events_2->return_yco())  ) {
         this->events_2->display_event();
     }
     if ((this->x==this->events_2->return_xco()) && (this->y-1==this->events_2->return_yco())  ) {
         this->events_2->display_event();
     }
     if ((this->x-1==this->events_3->return_xco()) && (this->y==this->events_3->return_yco())  ) {
         this->events_3->display_event();
     }
     if ((this->x+1==this->events_3->return_xco()) && (this->y==this->events_3->return_yco())  ) {
         this->events_3->display_event();
     }
     if ((this->x==this->events_3->return_xco()) && (this->y+1==this->events_3->return_yco())  ) {
         this->events_3->display_event();
     }
     if ((this->x==this->events_3->return_xco()) && (this->y-1==this->events_3->return_yco())  ) {
         this->events_3->display_event();
     }

     
     if ((this->x-1==this->events_4->return_xco()) && (this->y==this->events_4->return_yco()) && this->gold_pick == 0 ) {
         this->events_4->display_event();
     }
     if ((this->x+1==this->events_4->return_xco()) && (this->y==this->events_4->return_yco()) && this->gold_pick == 0 ) {
         this->events_4->display_event();
     }
     if ((this->x==this->events_4->return_xco()) && (this->y+1==this->events_4->return_yco()) && this->gold_pick == 0 ) {
         this->events_4->display_event();
     }
     if ((this->x==this->events_4->return_xco()) && (this->y-1==this->events_4->return_yco()) && this->gold_pick == 0 ) {
         this->events_4->display_event();
     }



}

/******************************************************
********************************* Function:event_display
********************************** Description:displays the events that happens whenever the player moves to another room
********************************* Parameters: none
*********************************** Pre-Conditions: none
********************************** Post-Conditions:
*************************************************************************************/


int Room::ai_decider() {
     if ((this->x-1==this->events_1->return_xco()) && (this->y==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
         return INT_MAX;
     }
     if ((this->x+1==this->events_1->return_xco()) && (this->y==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
         return INT_MAX;
     }
     if ((this->x==this->events_1->return_xco()) && (this->y+1==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
         return INT_MAX;
     }
     if ((this->x==this->events_1->return_xco()) && (this->y-1==this->events_1->return_yco()) && this->wumpus_dead == 0 ) {
         this->events_1->display_event();
         return INT_MAX;
     }

}


/******************************************************
******************************** Function:roof
********************************* Description:creates some part of the grid
******************************** Parameters: none
********************************** Pre-Conditions: none
********************************* Post-Conditions: creates the grid
************************************************************************************/


void Room::roof () {
     this->grid_array = "+";
     for (int i = 0; i < this->cols; i++) {
         this->grid_array += "---+";
     }
  
}

/******************************************************
******************************** Function:initializer
********************************* Description:initialize the grids representing the rooms
******************************** Parameters: none
********************************** Pre-Conditions: none
********************************* Post-Conditions: initialize the grids representing the rooms
************************************************************************************/


void Room::initializer () {
   /*  string grid_array;
     grid_array = "+";
     for (int i = 0; i < cols; i++) {
         grid_array += "---+";
     } */
    string anoda;
    string you;
    anoda = "|";
    you = "   ";
   for (int i = 0; i < this->rows; i++) {
      std::vector<string> num_cols;
      for (int j = 0; j < this->cols; j++) {
          num_cols.push_back("   ");
        }
       this->room_grid.push_back(num_cols);
    }

    
    this->room_grid.at(this->y).at(this->x) = " * ";
     
/*    cout << grid_array << endl;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols+1; j++) {
         cout << anoda;
        if (j < cols) {
           cout << room_grid.at(i).at(j);
        }
    }
    cout <<endl;
    cout << grid_array << endl;
    }  */

}

/******************************************************
********************************* Function:display_grid
********************************** Description:display the rooms
********************************* Parameters: none
*********************************** Pre-Conditions: none
********************************** Post-Conditions: display the rooms
*************************************************************************************/



void Room::display_grid() {
//     int temp1 = this->events_1->return_yco();
//     cout << temp1 << endl;
/*   if (this->wumpus_dead == 0) {
   this->room_grid.at(this->events_1->return_yco()).at(this->events_1->return_xco()) = " w ";
   }
   this->room_grid.at(this->events_2->return_yco()).at(this->events_2->return_xco()) = " p ";
   this->room_grid.at(this->events_3->return_yco()).at(this->events_3->return_xco()) = " b ";
   if (this->gold_pick==0) {
   this->room_grid.at(this->events_4->return_yco()).at(this->events_4->return_xco()) = " g ";
   } */
    cout << this->grid_array << endl;
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->cols+1; j++) {
         cout << "|";
        if (j < this->cols) {
           cout << this->room_grid.at(i).at(j);
        }
    }
    cout <<endl;
    cout << this->grid_array << endl;
    }

}

/******************************************************
********************************* Function:move_player
********************************** Description:moves the player to a different room depending on the input of the player
********************************* Parameters: none
*********************************** Pre-Conditions: none
********************************** Post-Conditions: moves the player to a different  room
*************************************************************************************/



void Room::move_player(int num) {
     if (num == 1) {
        if ((this->y+1)<=(this->rows-1)) {
           this->room_grid.at(this->y).at(this->x) = "   ";
           this->y+=1;
           this->room_grid.at(this->y).at(this->x) = " * ";
     }
     }
     if (num == 2) {
        if ((this->y-1)>=0) {
        this->room_grid.at(this->y).at(this->x) = "   ";
        this->y-=1;    
        this->room_grid.at(this->y).at(this->x) = " * ";
        } 
     }
     if (num == 3) {
        if ((this->x+1)<=(this->cols-1)) {
        this->room_grid.at(this->y).at(this->x) = "   ";
        this->x+=1;
        this->room_grid.at(this->y).at(this->x) = " * ";
        }
     }
     if (num == 4) {
        if ((this->x-1)>=0) {
        this->room_grid.at(this->y).at(this->x) = "   ";
        this->x-=1;
       this->room_grid.at(this->y).at(this->x) = " * ";
     }
     }
}

/******************************************************
********************************** Function:~Room
*********************************** Description:frees up the memory
********************************** Parameters: none
************************************ Pre-Conditions: none
*********************************** Post-Conditions: frees up the memory
**************************************************************************************/


Room::~Room() {
    cout <<"Destructor called from Room"<<endl;
    delete this->cord_x;
    delete this->cord_y;
    delete this->events_1;
    delete this->events_2;
    delete this->events_3;
    delete this->events_4;
}

/*int main() {
    string grid;
    vector<vector<string> > room_grid;
    grid = roof(3,6);    
    room_grid = initializer(3, 6);
    display_grid(3, 6, room_grid, grid); 
}*/
