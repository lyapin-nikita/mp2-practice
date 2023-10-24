#include <iostream>
#include "tbitfield.h"
using namespace std;

//testing the tbitfield class (its main functions: creating, getting length, setting and clearing bit, compare, adding, bit 'or', bit 'and', negation)


int main()
{
    cout << "TESTING THE TBitField CLASS..." << "\n\n\n\n";

    // creating
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Creating..." << "\n\n";
    size_t sz1, sz2;
    cout << "Length of first TBitField BF1: ";
    cin >> sz1;
    TBitField BF1(sz1);
    cout << "Length of second TBitField BF2: ";
    cin >> sz2;
    TBitField BF2(sz2);
    cout << "\n" << "BF1: " << BF1 << "BF2: " << BF2;
    cout << "\n\n\n\n";
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
   

        //                           
       //\\
      /*||\\
     ///||\*\
    //*/||\\\\
   /////||\\*\\
        ||


    // bit access
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Bit access..." << "\n\n";
    cout << "Length of BF1: " << BF1.GetLength() << endl;
    cout << "Length of BF2: " << BF2.GetLength() << endl;
    cout << "\n";
    size_t ind1, ind2;
    cout << "Index of bit that you want to set in BF1 (from 0 to its length " << BF1.GetLength() << "-1): ";
    cin >> ind1;
    BF1.SetBit(ind1);
    cout << "Now BF1 is: " << BF1;
    cout << "\n";
    cout << "For example, set all bits in BF2." << endl;
    for (size_t i(0); i < BF2.GetLength(); ++i) BF2.SetBit(i);
    cout << "Index of bit that you want to clear in BF2 (from 0 to its length " << BF2.GetLength() << "-1): ";
    cin >> ind2;
    BF2.ClrBit(ind2);
    cout << "Now BF2 is: " << BF2;
    cout << "\n\n\n\n";
    ////////////////////////////////////////////////////////////////////////////////////////////////////////


    //*//*//*/*//**///
    ////**//**//*///*/
    //*///*//*////*///
    //*//*/*//*///*///
    //*//*//*///*/**//
    //**//*/*/*//*/*//
    //*/*//*///*//**/*


    // operators
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Tets of operations..." << "\n\n";
    cout << "BF1: " << BF1 << "BF2: " << BF2 << endl;
    cout << "Recall that the function returns 1 if true and returns 0 if false!" << endl;
    cout << "BF1 == BF2  =>  " << (BF1 == BF2) << endl;
    cout << "BF1 != BF2  =>  " << (BF1 != BF2) << endl;
    cout << "~BF1  =>  " << (~BF1);
    cout << "BF1 | BF2  =>  " << (BF1 | BF2);
    cout << "BF1 & BF2  =>  " << (BF1 & BF2);
    BF1 = BF2;
    cout << "BF1 = BF2 and compare  =>  " << (BF1 == BF2);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "\n\n\n\n" << "END OF TESTING THE TBitField CLASS.";

}
