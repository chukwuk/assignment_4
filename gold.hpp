/****************************************
********************* Program:gold.hpp
*********************** Author:Kingsley C. Chukwu
********************* Date: 3/3/2019
********************* Description:conatins all the function prototype  in the Gold.hpp.
********************** Input: none
******************** Output: none
*********************************************************/

#ifndef GOLD_H
#define GOLD_H


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

class Gold : public Event {
    public:
    Gold(int x_co, int y_co);
    virtual int return_xco();
    virtual int return_yco();
    virtual void display_event();
};

#endif

