//
// Created by Ga1ahad20 on 16/12/2020.
//

#include <cstdlib>
#include "thiscretematrix.h"
#include "thiscretevector.h"

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


