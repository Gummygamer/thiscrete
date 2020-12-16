//
// Created by Ga1ahad20 on 16/12/2020.
//

#ifndef MY_APPLICATION_THISCRETEMATRIX_H
#define MY_APPLICATION_THISCRETEMATRIX_H

#include "thiscretevector.h"

class thiscretematrix {
 private:
    uint8_t** x;
    uint8_t dim1,dim2;
 public:
    thiscretematrix(uint8_t ** x, uint8_t dim1, uint8_t dim2);

    thiscretematrix operator +(thiscretematrix m);
    thiscretematrix operator -(thiscretematrix m);
    thiscretematrix operator *(thiscretematrix m);

    thiscretematrix operator +=(thiscretematrix m);

    thiscretematrix transposed();

    thiscretematrix operator *(uint8_t s);

};


#endif //MY_APPLICATION_THISCRETEMATRIX_H
