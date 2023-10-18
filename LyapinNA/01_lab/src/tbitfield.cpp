// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < BitLen) throw "the len of massive couldn't be less then 0";
    BitLen = len;
    MemLen = (BitLen - 1) / (sizeof(TELEM) * 8) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i) pMem[i]=0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i) pMem[i] = bf.pMem[i];
}

TBitField::~TBitField() { delete[] this->pMem; }

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if(n<0 || n>BitLen-1) throw "Method is not implemented";
    return n/sizeof(TELEM)*8;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n<0 || n>BitLen - 1) throw "Method is not implemented";
    size_t justnumforfirstlab = 1;
    return justnumforfirstlab << sizeof(TELEM) * 8 - n% (sizeof(TELEM) * 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{ 
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n > BitLen - 1) throw "Method is not implemented";
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n > BitLen - 1) throw "Method is not implemented";
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n > BitLen - 1) throw "Method is not implemented";

    if ((pMem[GetMemIndex(n)] & GetMemMask(n)) == GetMemMask(n)) return 1;
    else return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    //throw "Method is not implemented";
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    for (int i(0); i < MemLen; ++i) pMem[i] = bf.pMem[i];
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if ((BitLen != bf.BitLen) || (MemLen != bf.MemLen)) return false;
    for (int i(0); i < MemLen; ++i) if (pMem[i] != bf.pMem[i]) return false;
    return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    const int newBitLen = min(BitLen, bf.BitLen);
    TBitField result(newBitLen);
    for (int i(0); i < newBitLen; ++i)
    {
        if (GetBit(i) == bf.GetBit(i) == 0) result.ClrBit(i);
        else result.SetBit(i);
    }
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    //throw "Method is not implemented";
    const int newBitLen = min(BitLen, bf.BitLen);
    TBitField result(newBitLen);
    for (int i(0); i < newBitLen; ++i)
    {
        if (GetBit(i) == bf.GetBit(i) == 1) result.SetBit(i);
        else result.ClrBit(i);
    }
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    //throw "Method is not implemented";
    TBitField result(BitLen);
    for (int i(0); i < BitLen; ++i)
    {
        if (!GetBit(i)) result.SetBit(i);
    }
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    //throw "Method is not implemented";
    for (int i = 0; i < bf.GetLength(); ++i)
    {
        int tmp;
        istr >> tmp;
        if (tmp) bf.SetBit(i);
        else bf.ClrBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    //throw "Method is not implemented";
    for (int i = 0; i < bf.BitLen; ++i) ostr << bf.GetBit(i);
    ostr << endl;
    return ostr;
}
