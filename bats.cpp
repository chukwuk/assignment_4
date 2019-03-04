/****************************************
********************* Program:bats.cpp
*********************** Author:Kingsley C. Chukwu
********************* Date: 2/10/2019
********************* Description:implements all the function in the animal.hpp.
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
#include "wumpus.hpp"
#include "bats.hpp"

using namespace std;

Bats::Bats(int x_co, int y_co) {
        this-> x_co = x_co;
        this->y_co =  y_co;
}


int Bats::return_xco() {
    return this->x_co;
}

int Bats::return_yco() {
    return this->y_co;
}

void Bats::display_event() {
    cout <<"You hear wings flapping!!!"<<endl;
}



