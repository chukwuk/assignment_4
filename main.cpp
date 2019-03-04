/****************************************
****************** Program:room.hpp
******************** Author:Kingsley C. Chukwu
****************** Date: 2/10/2019
****************** Description:implements all the function in the animal.hpp.
******************* Input: none
***************** Output: none
******************************************************/


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

int main( int argc, char* argv[] ) {
    srand(time(0));
    if (argc!=3) { cout <<"Invalid argument, Please input just two argument"<<endl; return 0;  }

    for (int j = 1; j<argc; j++) {
      for (int i = 0; i < (strlen(argv[j])); i++) {
        if (argv[j][i] < 48 || argv[j][i] > 57 ) { // using ASCII values
            cout <<"Invalid input, Please input a numeric argument"<<endl;  return 0;
         }
       }
    }
    int rows; int cols; rows=atoi(argv[1]); cols =atoi(argv[2]);    
    if (rows < 4 || cols < 4) { 
    cout <<"Low number of columns and rows. Please enter number of columns and rows that are greater than four"<<endl;
    return 0;
    }
    cout <<""<<endl; cout <<"Welcome to the Hunt the Wumpus game!!!"<<endl; cout<<""<<endl;
    int repeter = 1;
    while (repeter == 1 || repeter == 2) {
    if (repeter == 1) {
      Room game(rows,cols);
     game.roof();
    game.initializer();
    int game_decide = 0;
    int count = 0;
    while (1==1) {
    if (count == 0) {
    game.event_display(); }
    count++;
    game.display_grid();
    if (game.return_num_arr()>0) {
       int number_arrow = game.return_num_arr();
      cout <<""<<endl; cout<<"You have "<<number_arrow<<" arrows in your bag "<<endl; cout <<""<<endl;
      int play;
      play = check_err();
      if (play == 0) {
      int play_num = check_err2();
      game.shoot_arrow(play_num);
      }
      if (play == 1) {
      int play_num = check_err3();
      game.move_player(play_num);
      }

    } else {
     int play_num = check_err3();
     game.move_player(play_num);

    }
  //    cout <<""<<endl;    game.display_grid();
      game.event_display();
      game_decide = game.game_decider();
      if (game_decide == INT_MAX || game_decide == INT_MIN || game_decide == UINT_MAX) {
                     break;
       }
       }
    }

   
    if (repeter == 2) {
       int rows = 4 + (rand() % 7);
       int cols = 4 + (rand() % 7);
        Room game(rows,cols);
    
    game.roof();
    game.initializer();
    int game_decide = 0; 
    int count = 0;
    while (1==1) {
     if (count == 0) {
    game.event_display(); }
    count++;
    game.display_grid();
    if (game.return_num_arr()>0) {
      int number_arrow = game.return_num_arr();
      cout <<""<<endl; cout<<"You have "<<number_arrow<<" arrows in your bag "<<endl; cout <<""<<endl;
      int play;
      play = check_err();
      if (play == 0) {
      int play_num = check_err2();
      game.shoot_arrow(play_num);
      } 
      if (play == 1) {
      int play_num = check_err3();
      game.move_player(play_num);
      }

    } else {
     int play_num = check_err3(); 
     game.move_player(play_num);
       
    } 
//  cout <<""<<endl;  game.display_grid();    
    game.event_display(); 
    game_decide = game.game_decider();
    if (game_decide == INT_MAX || game_decide == INT_MIN || game_decide == UINT_MAX) {
        break;
   }
   }
   }
   repeter = check_err4();
   if (repeter == 3) {
      break;
   }
   }
   cout <<""<<endl; cout <<"Thank you for playing the game!!!"<<endl;

   return 0;
}
