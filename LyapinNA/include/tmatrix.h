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
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
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
    const TMatrix<elem>& mt)
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
        return (*this);

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