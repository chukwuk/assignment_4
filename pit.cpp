/****************************************
********************* Program:pit.hpp
*********************** Author:Kingsley C. Chukwu
********************* Date: 2/10/2019
********************* Description:implements all the function in the pit.hpp.
********************** Input: none
******************** Output: none
*********************************************************/


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
#include "pit.hpp"


using namespace std;


Pit::Pit(int x_co, int y_co) {
        this-> x_co = x_co;
        this->y_co =  y_co;
}


int Pit::return_xco() {
    return this->x_co;
}

int Pit::return_yco() {
    return this->y_co;
}

void Pit::display_event() {
    cout <<"You feel a breeze!!!"<<endl;
}


