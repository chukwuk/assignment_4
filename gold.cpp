/****************************************
********************** Program:Gold.hpp
************************ Author:Kingsley C. Chukwu
********************** Date: 2/10/2019
********************** Description:mplements all the function in the Gold.hpp.
*********************** Input: none
********************* Output: none
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
#include "gold.hpp"


using namespace std;


Gold::Gold(int x_co, int y_co) {
        this-> x_co = x_co;
        this->y_co =  y_co;
}


int Gold::return_xco() {
    return this->x_co;
}

int Gold::return_yco() {
    return this->y_co;
}

void Gold::display_event() {
    cout<<""<<endl; cout <<"You see a glimmer nearby!!!"<<endl; cout<<""<<endl;
}
