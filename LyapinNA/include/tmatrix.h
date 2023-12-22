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
    TMatrix(const TVector<TVector<elem>>& mt);    // �������������� ����

    //���������
    bool operator==(const TMatrix& mt) const;      // ���������
    bool operator!=(const TMatrix& mt) const;      // ���������
    TMatrix& operator= (const TMatrix& mt);        // ������������
    TMatrix  operator+ (const TMatrix& mt);        // ��������
    TMatrix  operator- (const TMatrix& mt);        // ���������
    TMatrix  operator* (const TMatrix& mt);        // ������������

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
TMatrix<elem>::TMatrix(int n) : TVector<TVector<elem>>(n)
{
    if (n < 0) throw "invalid size";
    for (int i = 0; i < n; i++)
        pVector[i] = TVector<elem>(n - i, i);
} 

template <class elem> // ����������� �����������
TMatrix<elem>::TMatrix(const TMatrix& mtrx) : TVector<TVector<elem>>((TVector<TVector<elem>>)mtrx) {}

template <class elem>
TMatrix<elem>::TMatrix(const TVector<TVector<elem>>& mtrx) : TVector<TVector<elem>>(mtrx) {}

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
    return TVector<TVector<elem>>::operator=(mt);
} 

template <class elem> // ��������
TMatrix<elem> TMatrix<elem>::operator+(const TMatrix<elem>& mt)
{
    if (size != mt.size)
        throw "invalid size";
    return TVector<TVector<elem>>::operator+(mt);
}

template <class elem> // ���������
TMatrix<elem> TMatrix<elem>::operator-(const TMatrix<elem>& mt)
{
    if (size != mt.size)
        throw "invalid size";
    return TVector<TVector<elem>>::operator-(mt);
} 

template <class elem>
TMatrix<elem> TMatrix<elem>::operator*(const TMatrix& mt) {
    if (size != mt.size) throw "invalid size";
    TMatrix result(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            elem sum = 0;
            for (int k = 0; k < size; k++) {
                sum += (*this)[i][k] * mt[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}