//includes
    #pragma once
    #include "tvector.h"



template <class elem>
class TMatrix : public TVector<TVector<elem>>
{
public:
    // конструкторы
    TMatrix(int n = 10);
    TMatrix(const TMatrix& mt);                    // копирование
    TMatrix(const TVector<TVector<elem> >& mt);    // преобразование типа

    //операторы
    bool operator==(const TMatrix& mt) const;      // сравнение
    bool operator!=(const TMatrix& mt) const;      // сравнение
    TMatrix& operator= (const TMatrix& mt);        // присваивание
    TMatrix  operator+ (const TMatrix& mt);        // сложение
    TMatrix  operator- (const TMatrix& mt);        // вычитание
    TMatrix  operator* (const TMatrix& mt);        // произведение

    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};

template <class elem>
TMatrix<elem>::TMatrix(int n) : TVector<TVector<elem> >(n)
{
    if (n <= 0) throw "SIZE MUST BE BIGGER THAT 0";
    for (int i = 0; i < n; ++i)
    {
        pVector[i] = TVector<elem>(n - i, i);
    }
} 

template <class elem> // конструктор копирования
TMatrix<elem>::TMatrix(const TMatrix<elem>& mt) : TVector<TVector<elem> >(mt) {}

template <class elem> // конструктор преобразования типа
TMatrix<elem>::TMatrix(const TVector<TVector<elem> >& mt) : TVector<TVector<elem> >(mt) {}

template <class elem> // сравнение
bool TMatrix<elem>::operator==(const TMatrix<elem>& matrix) const
{
    return TVector<TVector<elem>>::operator==(matrix);
} 

template <class elem> // сравнение
bool TMatrix<elem>::operator!=(const TMatrix<elem>& matrix) const
{
    return TVector<TVector<elem>>::operator!=(matrix);
} 

template <class elem> // присваивание
TMatrix<elem>& TMatrix<elem>::operator=(const TMatrix<elem>& mt)
{
    if (this != &mt)
    {
        if (size != mt.size)
        {
            delete[] pVector;
            pVector = new TVector<elem>[mt.size];
        }
        size = mt.size;
        start_index = mt.start_index;
        for (int i = 0; i < size; i++)
            pVector[i] = mt.pVector[i];
    }
    return *this;
} 

template <class elem> // сложение
TMatrix<elem> TMatrix<elem>::operator+(const TMatrix<elem>& mt)
{
    return TVector<TVector<elem>>::operator+(mt);
} 

template <class elem> // вычитание
TMatrix<elem> TMatrix<elem>::operator-(const TMatrix<elem>& mt)
{
    return TVector<TVector<elem>>::operator-(mt);
} 

template <class elem>
TMatrix<elem> TMatrix<elem>::operator*(const TMatrix& mt) {
    if (size != mt.size) throw "invalid size";
    TMatrix result(size);

    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            result[i][j - i] = 0;
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            for (int k = i; k <= j; ++k)
            {
                result[i][j - i] += (*this)[i][k - i] * mt[k][j - k];
            }
        }
    }


    return result;
}