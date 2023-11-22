// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля
// Реализация оболочки TSet (множества) битового поля TBitField

#include "tset.h"
#include <conio.h>

//TODO нужно переделать функции ввода, вывода(возможно), сравнения




//METODS AND CONSTRUCTS

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//default
TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
}

//copy
TSet::TSet(const TSet& s) : BitField(s.BitField), MaxPower(s.MaxPower)
{
}

//converting
TSet::TSet(const TBitField& bf) : BitField(bf), MaxPower(bf.GetLength())
{
}

//return maxpower
int TSet::GetMaxPower(void) const 
{
    return MaxPower;
}

//return bit
int TSet::IsMember(const int Elem) const 
{
    if (Elem < 0 || Elem >= MaxPower)
        throw "Method is not implemented";

    return BitField.GetBit(Elem);
}

//set bit in bitfield
void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem < 0 || Elem >= MaxPower)
        throw "Method is not implemented";
    BitField.SetBit(Elem);
}

//
void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem < 0 || Elem >= MaxPower)
        throw "Method is not implemented";
    BitField.ClrBit(Elem);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////












//OPERATORS

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TSet::operator TBitField()
{
    return BitField;
}

const TSet& TSet::operator=(const TSet& s)
{
    if (this == &s)
        return *this;
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet& s) const
{
    if (MaxPower != s.MaxPower)
        return 0;
    if (BitField != s.BitField)
        return 0;
    return 1;
}

int TSet::operator!=(const TSet& s) const
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet& s) 
{
    TSet tmp(max(MaxPower, s.GetMaxPower()));
    tmp.BitField = BitField | s.BitField;
    return tmp;
}

TSet TSet::operator+(const int Elem)
{
    if (Elem < 0 || Elem >= MaxPower)
        throw "Method is not implemented";
    TSet tmp(*this);
    tmp.BitField.SetBit(Elem);
    return tmp;
}

TSet TSet::operator-(const int Elem)
{
    if (Elem < 0 || Elem >= MaxPower)
        throw "Method is not implemented";
    TSet tmp(*this);
    tmp.BitField.ClrBit(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet& s) 
{
    TSet tmp(max(MaxPower, s.GetMaxPower()));
    tmp.BitField = BitField & s.BitField;
    return tmp;
}

TSet TSet::operator~(void) 
{
    TSet tmp(*this);
    tmp.BitField = ~tmp.BitField;
    return tmp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////














//OVERFLOWS

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//in
istream& operator>>(istream& istr, TSet& s) // ввод
{
    TELEM tmp;
    for (int i = 0; i < s.GetMaxPower(); ++i)
    {
        tmp = _getch();
        _getch();
        if (tmp == 101) break;
        cout << tmp - 48 << " ";
        s.InsElem(tmp - 48);
    }
    return istr;
}

//out
ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    ostr << "{";
    bool haveMembers = false;
    for (int i = 0; i < s.GetMaxPower(); ++i)
    {
        if (s.IsMember(i) == 1)
        {
            ostr << " " << i;
            
            haveMembers = true;
        }
    }

    if (haveMembers == false) ostr << " empty";
    ostr << " }";
    return ostr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////