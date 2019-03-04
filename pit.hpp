/****************************************
********************* Program:pit.hpp
*********************** Author:Kingsley C. Chukwu
********************* Date: 3/3/2019
********************* Description:contain all the prototype  function in the pit.hpp.
********************** Input: none
******************** Output: none
*********************************************************/

#ifndef PIT_H
#define PIT_H


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

class Pit : public Event {
    public:
    Pit(int x_co, int y_co);
    virtual int return_xco();
    virtual int return_yco();
    virtual void display_event();
};

#endif



