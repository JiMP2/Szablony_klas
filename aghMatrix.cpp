#include "aghInclude.h"
 
 
template <>
void aghMatrix<char>::setItems(int r, int c, ...)
{
    if ((r < 0) || (c < 0))
    {
        throw aghException(0, "Index out of range.", __FILE__, __LINE__);
    }
    else
    {
        if (values != NULL)
            dealloc();
         
        rows = r;
        columns = c;
        alloc(rows, columns);
         
        va_list argList;
        va_start(argList, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                values[i][j] = va_arg(argList, int);
            }
        }
        va_end(argList);
    }
}
 
template<>
const aghMatrix<char> aghMatrix<char>::operator+(const aghMatrix<char> & A)
{
    if (A.rows != rows || A.columns != columns)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<char> sum(A.rows, A.columns);
         
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.columns; j++)
            {
                sum.values[i][j] = 'a' + (A.values[i][j] + values[i][j] - 194) % 26;
 
            }
        }
        return sum;
    }
}
 
template<>
const aghMatrix<char *> aghMatrix<char *>::operator+(const aghMatrix<char *> & A)
{
    if (A.rows != rows || A.columns != columns)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<char *> sum(A.rows, A.columns);
         
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.columns; j++)
            {
                //sum.values[i][j] = 'a' + (A.values[i][j] == B.values[i][j] - 194) % 26;
            }
        }
        return sum;
    }
}
 
template<>
const aghMatrix<char> aghMatrix<char>::operator*(const aghMatrix<char> & A)
{
    if (A.columns != rows)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<char> product(A.rows, columns);
         
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < A.columns; k++)
                {
                    product.values += (A.values[i][k] - 97) * (values[k][j] - 97);
                }
            }
        }
        return product;
    }
}
 
 
template<>
const aghMatrix<char *> aghMatrix<char *>::operator*(const aghMatrix<char *> & A)
{
    if (A.columns != rows)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<char *> product(A.rows, columns);
         
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < A.columns; k++)
                {
                    //product.values[i][j] += A.values[i][k] * B.values[k][j];
                }
            }
        }
        return product;
    }
}
