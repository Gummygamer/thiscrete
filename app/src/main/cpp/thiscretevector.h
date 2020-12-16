//
// Created by Ga1ahad20 on 16/12/2020.
//

#ifndef MY_APPLICATION_THISCRETEVECTOR_H
#define MY_APPLICATION_THISCRETEVECTOR_H


#include <cstdint>

class thiscretevector {
   private:
    uint8_t* x;
    uint8_t dim;
   public:
    thiscretevector(uint8_t* x,uint8_t dim);

    thiscretevector operator +(thiscretevector v);
    thiscretevector operator -(thiscretevector v);
    thiscretevector operator *(uint8_t s);

    thiscretevector operator +=(thiscretevector v);

    uint8_t dot (thiscretevector v);

};


#endif //MY_APPLICATION_THISCRETEVECTOR_H
