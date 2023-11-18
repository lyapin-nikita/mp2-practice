//includes
    #pragma once
    #include "tvector.h"


template <class elem>
class TMatrix : public TVector<TVector<elem>>
{
public:
    // ������������
    TMatrix(int n = 10);
    TMatrix(const TMatrix& mt);                    // �����������
    TMatrix(const TVector<TVector<elem> >& mt);    // �������������� ����

    //���������
    bool operator==(const TMatrix& mt) const;      // ���������
    bool operator!=(const TMatrix& mt) const;      // ���������
    TMatrix& operator= (const TMatrix& mt);        // ������������
    TMatrix  operator+ (const TMatrix& mt);        // ��������
    TMatrix  operator- (const TMatrix& mt);        // ���������

    // ���� / �����
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

template <class elem> // ����������� �����������
TMatrix<elem>::TMatrix(const TMatrix<elem>& mt) : TVector<TVector<elem> >(mt) {}

template <class elem> // ����������� �������������� ����
TMatrix<elem>::TMatrix(const TVector<TVector<elem> >& mt) : TVector<TVector<elem> >(mt) {}

template <class elem> // ���������
bool TMatrix<elem>::operator==(const TMatrix<elem>& matrix) const
{
    return TVector<TVector<elem>>::operator==(matrix);
} 

template <class elem> // ���������
bool TMatrix<elem>::operator!=(const TMatrix<elem>& matrix) const
{
    return TVector<TVector<elem>>::operator!=(matrix);
} 

template <class elem> // ������������
TMatrix<elem>& TMatrix<elem>::operator=(const TMatrix<elem>& mt)
{
    if (this != &mt)
    {
        if (Size != mt.Size)
        {
            delete[] pVector;
            pVector = new TVector<ValType>[mt.Size];
        }
        Size = mt.Size;
        StartIndex = mt.StartIndex;
        for (int i = 0; i < Size; i++)
            pVector[i] = mt.pVector[i];
    }
    return *this;
} 

template <class elem> // ��������
TMatrix<elem> TMatrix<elem>::operator+(const TMatrix<elem>& mt)
{
    return TVector<TVector<>>::operator+(mt);
} 

template <class elem> // ���������
TMatrix<elem> TMatrix<elem>::operator-(const TMatrix<elem>& mt)
{
} /*-------------------------------------------------------------------------*/