
//include
	#pragma once
	#include <iostream>

using namespace std;



template <typename elem>
class TVector
{
protected:
    elem* pVector;
    int size;       // размер вектора
    int start_index; // индекс первого элемента вектора


public:
    // конструкторы и деструктор
    TVector (int size = 10, int sizeindex = 0);
    TVector (const TVector& vector);                // конструктор копирования
    ~TVector (); 

    // геттеры и сеттеры
    int GetSize () { return size; } // размер вектора
    int GetStartIndex () { return start_index; } // индекс первого элемента

    // перегрузки операторов
    elem& operator [](int position);             // доступ
    elem& operator [](int position) const;       // доступ
    TVector& operator= (const TVector& vector);     // присваивание
    bool operator== (const TVector& vector) const;  // сравнение
    bool operator!= (const TVector& vector) const;  // обратное сравнение

    // скалярные операции
    TVector  operator* (const elem& val);   // умножить на число

    // векторные операции
    TVector operator+ (const elem& val);
    TVector operator- (const elem& val);
    TVector  operator+ (const TVector& vector);     // сложение
    TVector  operator- (const TVector& vector);     // вычитание
    elem  operator* (const TVector& vector);     // скалярное произведение

    // перегрузка ввода вывода
    friend istream& operator>>(istream& in, TVector& vector)
    {
        for (int i = 0; i < vector.size; i++) in >> vector.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& vector)
    { 
        out << "{ ";
        for (int i = 0; i < vector.size; i++) out << vector.pVector[i] << ' ';
        out << '}';
        return out;
    }
};


template <typename elem>
TVector<elem>::TVector(int size = 10, int sizeindex = 0)
{
    this->size = size;
    this->start_index = sizeindex;
    pVector = new elem[size];  
    for (int i = 0; i < size; ++i) pVector[i] = 0;
}

template <typename elem> //конструктор копирования
TVector<elem>::TVector(const TVector<elem>& other)
{
    size = other.size;
    start_index = other.start_index;
    pVector = new elem[size];
    for (int i = 0; i < size; i++)
    {
        pVector[i] = other.pVector[i];
    }
} 

template <typename elem>
TVector<elem>::~TVector()
{
    delete[] pVector;
} 

template <typename elem> // доступ
elem& TVector<elem>::operator[](int position)
{
    return pVector[position];
} 

template <typename elem> // доступ
elem& TVector<elem>::operator[](int position) const
{
    return pVector[position];
}

template <typename elem> // сравнение
bool TVector<elem>::operator==(const TVector& vector) const
{
    if (vector.size != size) return false;
    for (int i = 0; i < size; ++i)
    {
        if (pVector[i] != vector.pVector[i]) return false; 
    }
    return true;
} 

template <typename elem> // сравнение
bool TVector<elem>::operator!=(const TVector& vector) const
{
    return !(vector == (*this));
} 

template <typename elem> // присваивание
TVector<elem>& TVector<elem>::operator=(const TVector& vector)
{
    if (this != &vector)
    {
        if (size != vector.size)
        {
            delete[] pVector;
            pVector = new elem[vector.size];
            size = vector.size;
            
        }
        start_index = vector.start_index;
        for (int i = 0; i < this->GetSize(); i++) pVector[i] = vector.pVector[i];
    }
    return (*this);
} 

template <typename elem> // умножить на скаляр
TVector<elem> TVector<elem>::operator*(const elem& val)
{
    for (int i = 0; i < size; ++i)
    {
        pVector[i] *= val;
    }
    return (*this);
} 

template <typename elem> 
TVector <elem> TVector <elem>::operator+(const elem& val)
{
    TVector<elem> result(*this);
    for (int i = 0; i < size; ++i)
    {
        result[i] += val;
    }
    return result;
}

template <typename elem>
TVector <elem> TVector <elem>::operator-(const elem& val)
{
    TVector<elem> result(*this);
    for (int i = 0; i < size; ++i)
    {
        result[i] -= val;
    }
    return result;
}

template <typename elem> // сложение
TVector<elem> TVector<elem>::operator+(const TVector<elem>& vector)
{
    if (size != vector.size) throw "SIZES MUST BE EQUAL";
    TVector<elem> result(*this);
    for (int i = 0; i < size; ++i)
    {
        result[i] = result[i] + vector[i];
    }
    return result;
} 

template <typename elem> // вычитание
TVector<elem> TVector<elem>::operator-(const TVector<elem>& vector)
{
    if (size != vector.size) throw "SIZES MUST BE EQUAL";
    TVector<elem> result(*this);
    for (int i = 0; i < size; ++i)
    {
        result[i] = result[i] - vector[i];
    }
    return result;
} 

template <typename elem> // скалярное произведение
elem TVector<elem>::operator*(const TVector<elem>& vector)
{
    elem result = 0;
    TVector<elem> operand1(*this);
    int minsize = min(size, vector.size);
    for (int i = 0; i < minsize; ++i)
    {
        result += operand1[i] * vector[i];
    }

    return result;
} 

