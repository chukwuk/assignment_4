/****************************************
****************** Program:event.hpp
******************** Author:Kingsley C. Chukwu
****************** Date: 3/3/2019
****************** Description:contains  all the prototype function in the event.hpp.
******************* Input: none
***************** Output: none
******************************************************/

#ifndef EVENT_H
#define EVENT_H



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


using namespace std;

class Event {
  protected:
  int x_co;
  int y_co;
  public:
  virtual int return_xco() = 0;
  virtual int return_yco() = 0;
  virtual void display_event() { cout <<""<<endl; };
  virtual void move_wumpus(int xx, int yy) {cout <<""<<endl; }
};

#endif

