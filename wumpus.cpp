/****************************************
******************** Program:wumpus.cpp
********************** Author:Kingsley C. Chukwu
******************** Date: 2/10/2019
******************** Description:implements all the function in the animal.hpp.
********************* Input: none
******************* Output: none
********************************************************/




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
#include "wumpus.hpp"

using namespace std;

Wumpus::Wumpus(int x_co, int y_co) {
        this-> x_co = x_co; 
        this->y_co =  y_co; 
}


int Wumpus::return_xco() {
    return this->x_co;
}

int Wumpus::return_yco() {
    return this->y_co;
}

void Wumpus::move_wumpus(int xx, int yy) {
    this->x_co = xx;
    this->y_co = yy;
}

void Wumpus::display_event() {
   cout <<"You smell a terrible stench!!!"<<endl;
}

