#include <iostream>
#include "tset.h"
using namespace std;

//test of tset class

int main()
{
    cout << "Testing the TSet class..." << "\n\n\n\n";

    ///////////////////////////////////////////////////////////////////
    cout << "Creating..." << endl;
    size_t sz1, sz2;
    cout << "Length TSet1: ";
    cin >> sz1;
    cout << "Length TSet2: ";
    cin >> sz2;
    TSet TS1(sz1), TS2(sz2);
    cout << "TS1: " << TS1 << endl;
    cout << "TS2: " << TS2 << endl;
    cout << "\n\n\n\n";
    ///////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    cout << "Element access..." << "\n\n";
    size_t ind1, ind2;
    cout << "Adding the element in Univers TS1: ";
    cin >> ind1;
    TS1.InsElem(ind1);
    cout << "Now TS1 is: " << TS1 << endl;
    cout << "For example, set all elements in TS2." << endl;;
    for (size_t i(0); i < sz2; ++i) TS2.InsElem(i);
    cout << "TS2: " << TS2 << endl;
    cout << "Deleting the element in Univers TS2: ";
    cin >> ind2;
    TS2.DelElem(ind2);
    cout << "Now TS2 is: " << TS2 << endl;
    cout << "We also can find out the MaxPower of TS1: " << TS1.GetMaxPower() << endl;
    cout << "And we can find out if an element is included in a set." << endl;
    cout << "Inter the index of element from TS1: ";
    cin >> ind1;
    cout << TS1.IsMember(ind1);
    cout << "\n\n\n\n";
    //////////////////////////////////////////////////////////////////
    
    //////////////////////////////////////////////////////////////////
    cout << "Operations with TSet..." << "\n\n";
    cout << "TS1: " << TS1 << endl << "TS2: " << TS2 << endl;
    cout << "TS1 == TS2?  ==>  " << (TS1 == TS2) << endl;
    cout << "TS1 != TS2?  ==>  " << (TS1 != TS2) << endl;
    cout << "TS1 + TS2  ==>  " << (TS1 + TS2) << endl;
    cout << "TS1 * TS2  ==>  " << (TS1 * TS2) << endl;
    cout << "~TS2  ==>  " << (~TS2) << endl;
    cout << "Adding the element TS1 + Index: ";
    cin >> ind1;
    cout << (TS1 + ind1) << endl;
    cout << "Deleting the element TS2 - Index: ";
    cin >> ind2;
    cout << (TS2 - ind2) << endl;
    //////////////////////////////////////////////////////////////////

}
