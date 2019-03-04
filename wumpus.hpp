/****************************************
******************* Program:wumpus.hpp
********************* Author:Kingsley C. Chukwu
******************* Date: 3/3/2019
******************* Description:contain all the prototype function in the wumpus.hpp.
******************** Input: none
****************** Output: none
*******************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H


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

using namespace std;

class Wumpus : public Event {
    public:
    Wumpus(int x_co, int y_co);
    virtual int return_xco();
    virtual int return_yco();
    virtual void move_wumpus(int xx, int yy);
    virtual void display_event();

};

#endif

