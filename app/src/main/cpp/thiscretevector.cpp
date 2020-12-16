//
// Created by Ga1ahad20 on 16/12/2020.
//

#include <cstdlib>
#include "thiscretevector.h"

thiscretevector::thiscretevector(uint8_t *x,uint8_t dim)
{
    this->x = x;
    this->dim = dim;
}

thiscretevector thiscretevector::operator+(thiscretevector v)
{
    uint8_t i = 0;
    auto* out = (uint8_t*) malloc(dim);
    for(i = 0; i < dim;i++)
    {
        out[i] = (this->x)[i] + (v.x)[i];
    }

    return thiscretevector(out,dim);
}

thiscretevector thiscretevector::operator+=(thiscretevector v)
{
    uint8_t i = 0;
    auto* out = (uint8_t*) malloc(dim);
    for(i = 0; i < dim;i++)
    {
        out[i] = (this->x)[i] + (v.x)[i];
    }

    this->x = out;

    return thiscretevector(out,dim);
}

thiscretevector thiscretevector::operator-(thiscretevector v)
{
    uint8_t i = 0;
    auto* out = (uint8_t*) malloc(dim);
    for(i = 0; i < dim;i++)
    {
        out[i] = (this->x)[i] - (v.x)[i];
    }

    return thiscretevector(out,dim);
}

thiscretevector thiscretevector::operator*(uint8_t s)
{
    uint8_t i = 0;
    auto* out = (uint8_t*) malloc(dim);

    for(i = 0; i < dim;i++)
    {
        out[i] = (this->x)[i]*s;
    }

    return thiscretevector(out,dim);
}

uint8_t thiscretevector::dot (thiscretevector v)
{
    uint8_t i = 0;
    uint8_t acum = 0;

    for(i = 0; i < dim;i++)
    {
        acum += this->x[i]*v.x[i];
    }

    return acum;

}


