//
//  aghMatrix.h
//  Szablon klas
//
//  Created by Wojtek on 5/11/13.
//  Copyright (c) 2013 Wojtek. All rights reserved.
//
 
#ifndef __Szablon_klas__aghMatrix__
#define __Szablon_klas__aghMatrix__
 
#include <iostream>
#include "aghException.h"
 
template <class T>
class aghMatrix {
public:
    /*
     * @brief Default constructor for class template aghMatrix.
     * @param Default parameter values set to 0.
     */
    aghMatrix();
    aghMatrix(int r , int c);
     
    /*
     * @brief Copy constructor for class template aghMatrix.
     * @param Matrix 
     */
    aghMatrix(const aghMatrix<T> & A);
     
    /*
     * @brief Destructor for class template aghMatrix.
     */
    ~aghMatrix();
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    void setItem(int r, int c, T val);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    void setItems(T * valVect);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    void setItems(int r, int c, ...);
     
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    const aghMatrix operator+ (const aghMatrix<T> & A);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    const aghMatrix operator* (const aghMatrix<T>  & A);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    bool operator== (const aghMatrix<T>  & A) const;
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    bool operator!= (const aghMatrix<T>  & A) const;
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    const aghMatrix & operator=(const aghMatrix<T> & A);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    T& operator()(int numerWiersza, int numerKolumny);
     
    void wypisz ()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cout << values[i][j] << " ";
            }
        std::cout << std::endl;
        }
    }
    int rows, columns;
private:
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    void alloc (int r, int c);
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    void dealloc ();
    /*
     * @brief Default constructor for class template aghMatrix.
     */
     
    /*
     * @brief Default constructor for class template aghMatrix.
     */
    T ** values;
};
 
 
 
 
 
/************** DEFINICJE ***************/
 
template <class T>
void aghMatrix<T>::alloc(int r, int c)
{
    if ((r < 0) || (c < 0))
    {
        throw aghException(0, "Index out of range.", __FILE__, __LINE__);
    }
    else if (values != NULL)
    {
        throw aghException(4, "Memory alocated.", __FILE__, __LINE__);
    }
    else
    {
        values = new T * [rows];
     
        for (int i = 0; i < rows; i++)
        {
            values[i] = new T [columns];
             
            for(int j = 0; j < columns; j++)
            {
                values[i][j] = T();
            }
        }
    }
}
 
template <class T>
void aghMatrix<T>::dealloc()
{
    for (int i = 0; i < rows; i++)
    {
        delete [] values[i];
    }
    delete [] values;
     
    values = NULL;
}
 
template <class T>
aghMatrix<T>::aghMatrix()
{
    values = NULL;
    rows = 0;
    columns = 0;
}
 
template <class T>
aghMatrix<T>::aghMatrix(int r, int c):rows(r), columns(c)
{
    values = NULL;
    alloc(r, c);
}
 
template <class T>
aghMatrix<T>::aghMatrix(const aghMatrix<T> & A):rows(A.rows), columns(A.columns)
{
    *this = A;
    /*values = NULL;
    alloc(rows, columns);
     
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            values[i][j] = A.values[i][j];
        }
    }
     */
}
 
 
template <class T>
aghMatrix<T>::~aghMatrix()
{
    dealloc();
    rows = 0;
    columns = 0;
}
 
 
template <class T>
void aghMatrix<T>::setItem(int r, int c, T val)
{
    if ((r < 0) || (r >= rows) || (c < 0) || (c >= columns))
    {
        throw aghException(0, "Index out of range.", __FILE__, __LINE__);
    }
    else
    {
        values[r][c] = val;
    }
}
 
 
template <class T>
void aghMatrix<T>::setItems(T * valVect)
{
    if (valVect == NULL)
        throw aghException(1, "Function received NULL pointer.", __FILE__, __LINE__);
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                values[i][j] = *(valVect++);
            }
        }
    }
}
 
// Definicja funkcji setItems (lista arg).
template <class T>
void aghMatrix<T>::setItems(int r, int c, ...)
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
                values[i][j] = va_arg(argList, T);
            }
        }
        va_end(argList);
    }
}
 
template<>
void aghMatrix<char>::setItems(int r, int c, ...);
 
 
 
/**************** OPERATORY **************/
 
 
// PrzeÅ‚adowanie operatora+
template <class T>
const aghMatrix<T> aghMatrix<T>::operator+(const aghMatrix<T> & A)
{
    if (A.rows != rows || A.columns != columns)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<T> sum(A.rows, A.columns);
     
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.columns; j++)
            {
                sum.values[i][j] = A.values[i][j] + values[i][j];
            }
        }
        return sum;
    }
}
 
 
/*
 * @brief Default constructor for class template aghMatrix.
 */
template<>
const aghMatrix<char> aghMatrix<char>::operator+(const aghMatrix<char> & A);
 
/*
 * @brief Default constructor for class template aghMatrix.
 */
template<>
const aghMatrix<char *> aghMatrix<char *>::operator+(const aghMatrix<char *> & A);
 
 
// Specjalizacja przeÅ‚adowania operatora.
template <class T>
const aghMatrix<T> aghMatrix<T>::operator*(const aghMatrix<T> & A)
{
    if (A.columns != rows)
    {
        throw aghException(2, "Nonconformant arguments.", __FILE__, __LINE__); 
    }
    else
    {
        aghMatrix<T> product(A.rows, columns);
     
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                for (int k = 0; k < A.columns; k++)
                {
                    product.values[i][j] += A.values[i][k] * values[k][j];
                }
            }
        }
        return product;
    }    
}
 
/*
 * @brief Default constructor for class template aghMatrix.
 */
template<>
const aghMatrix<char> aghMatrix<char>::operator*(const aghMatrix<char> & A);
 
/*
 * @brief Default constructor for class template aghMatrix.
 */
template<>
const aghMatrix<char *> aghMatrix<char *>::operator*(const aghMatrix<char *> & A);
 
 
template <class T>
bool aghMatrix<T>::operator== (const aghMatrix<T>  & A) const
{
    bool flag = true;
     
    if ((A.rows == rows) && (A.columns == columns))
    {
        for(int i = 0; (i  < A.rows) && flag; i++)
        {
            for(int j = 0; (i  < A.columns) && flag; j++)
            {
                if (A.values[i][j] != values[i][j])
                {
                    std::cout << "A: " << A.values[i][j] << std::endl;
                    std::cout << "B: " << values[i][j] << std::endl;
                    flag = false;
                }
            }
        }
    }
    else
    {
        flag = false;
    }
    return flag;
}
 
template <class T>
bool aghMatrix<T>::operator!=(const aghMatrix<T> & A) const
{
    return !(*this == A);
}
 
template <class T>
const aghMatrix<T> & aghMatrix<T>::operator=(const aghMatrix<T> & A)
{
    if (this != &A)
    {
        if (values != NULL)
            dealloc();
         
        rows = A.rows;
        columns = A.columns;
        alloc(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                values[i][j] = A.values[i][j];
            }
        }
    }
     
    return *this;
}
 
template <class T>
T & aghMatrix<T>::operator()(int r, int c)
{
    if ((r < 0) || (c < 0))
    {
        throw aghException(0, "Index out of range.", __FILE__, __LINE__);
    }
    else
    {
        return values[r][c];
    }
}
 
#endif /* defined(__Szablon_klas__aghMatrix__) */
