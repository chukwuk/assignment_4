/****************************************
******************** Program:bats.hpp
********************** Author:Kingsley C. Chukwu
******************** Date: 3/3/2019
******************** Description:contains all the function protoype in bats.hpp.
********************* Input: none
******************* Output: none
********************************************************/

#ifndef BATS_H
#define BATS_H


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

class Bats : public Event {
    public:
    Bats(int x_co, int y_co);
    virtual int return_xco();
    virtual int return_yco();
    virtual void display_event();
};

#endif







