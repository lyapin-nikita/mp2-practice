// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    //BitField = TBitField(mp);
    MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength())
{
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if ((Elem < MaxPower) || (Elem >= MaxPower)) throw "Method is not implemented";
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if ((Elem < MaxPower) || (Elem >= MaxPower)) throw "Method is not implemented";
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem < MaxPower || Elem > MaxPower - 1) throw "Method is not implemented";
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (MaxPower != s.MaxPower) return false;
    if (BitField != s.BitField) return false;
    return true;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    //throw "Method is not implemented";
    TSet result(max(MaxPower, s.MaxPower));
    result.BitField = BitField | s.BitField;
    return result;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem < MaxPower || Elem > MaxPower - 1) throw "Method is not implemented";
    TSet result(*this);
    result.BitField.SetBit(Elem);
    return result;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem < MaxPower || Elem > MaxPower - 1) throw "Method is not implemented";
    TSet result(*this);
    result.BitField.ClrBit(Elem);
    return result;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    //throw "Method is not implemented";
    TSet result(max(MaxPower, s.MaxPower));
    result.BitField = BitField & s.BitField;
    return result;
}

TSet TSet::operator~(void) // дополнение
{
    //throw "Method is not implemented";
    TSet result(*this);
    result.BitField = ~BitField;
    return result;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    //throw "Method is not implemented";
    TELEM tmp;
    istr >> tmp;
    if (tmp < 0 || tmp >= s.GetMaxPower())
        throw "ERROR_IN_CIN_NUMBER_IS_OUT_OF_RANGE";
    s.InsElem(tmp);
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    //throw "Method is not implemented";
    for (int i = 0; i < s.GetMaxPower(); ++i)
        if (s.IsMember(i))
            ostr << i << " ";
    return ostr;
}

