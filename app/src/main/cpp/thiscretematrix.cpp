//
// Created by Ga1ahad20 on 16/12/2020.
//

#include <cstdlib>
#include "thiscretematrix.h"

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

thiscretematrix::thiscretematrix(uint8_t **x, uint8_t dim1, uint8_t dim2)
{
    this->x = x;
    this->dim1 = dim1;
    this->dim2 = dim2;
}

thiscretematrix thiscretematrix::operator+(thiscretematrix m)
{
      uint8_t i,j;

      auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

      for(i = 0; i < dim1; i++)
      {
            out[i] = (uint8_t*) malloc(dim2);

            for(j = 0; j < dim2; j++)
            {
                out[i][j] = this->x[i][j] + m.x[i][j];
            }
      }

      return thiscretematrix(out, dim1, dim2);
}

thiscretematrix thiscretematrix::operator+=(thiscretematrix m)
{
    uint8_t i,j;

    auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

    for(i = 0; i < dim1; i++)
    {
        out[i] = (uint8_t*) malloc(dim2);

        for(j = 0; j < dim2; j++)
        {
            out[i][j] = this->x[i][j] + m.x[i][j];
        }
    }

    this->x = out;

    return thiscretematrix(out, dim1, dim2);
}

thiscretematrix thiscretematrix::operator-(thiscretematrix m)
{
    uint8_t i,j;

    auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

    for(i = 0; i < dim1; i++)
    {
        out[i] = (uint8_t*) malloc(dim2);

        for(j = 0; j < dim2; j++)
        {
            out[i][j] = this->x[i][j] - m.x[i][j];
        }
    }

    return thiscretematrix(out, dim1, dim2);
}

thiscretematrix thiscretematrix::operator*(uint8_t s)
{
    uint8_t i,j;

    auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

    for(i = 0; i < dim1; i++)
    {
        out[i] = (uint8_t*) malloc(dim2);

        for(j = 0; j < dim2; j++)
        {
            out[i][j] = this->x[i][j]*s;
        }
    }

    return thiscretematrix(out, dim1, dim2);

}

thiscretematrix thiscretematrix::transposed()
{
    uint8_t i,j;

    auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

    for(i = 0; i < dim1; i++)
    {
        out[i] = (uint8_t*) malloc(dim2);

        for(j = 0; j < dim2; j++)
        {
            out[i][j] = this->x[i][i];
        }
    }

    return thiscretematrix(out, dim1, dim2);
}

thiscretematrix thiscretematrix::operator*(thiscretematrix m)
{
    uint8_t i,j;

    auto* out = (uint8_t**) malloc(dim1 * sizeof(uint8_t*));

    thiscretematrix mt = m.transposed();

    for(i = 0; i < dim1; i++)
    {
        out[i] = (uint8_t*) malloc(dim2);

        for(j = 0; j < dim2; j++)
        {
            out[i][j] = thiscretevector(this->x[i],dim2).dot(thiscretevector(mt.x[j],dim1));
        }
    }

    return thiscretematrix(out, dim1, dim2);
}


