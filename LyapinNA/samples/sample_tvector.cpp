

#include <iostream>
#include "TVector.h" // ���������� ������������ ���� � ������������ ������ TVector

int main()
{
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;

    // ������� ��� ���������� ������ TVector
    TVector<int> vector1(size);
    TVector<int> vector2(size);

    cout << "Enter the elements of the first vector:" << endl;
    cin >> vector1; // ������������� �������� �����

    cout << "Enter the elements of the second vector:" << endl;
    cin >> vector2; // ������������� �������� �����

    // ������������ ������ ����������
    cout << "First vector: " << vector1 << endl; // ������������� �������� ������
    cout << "Second vector: " << vector2 << endl; // ������������� �������� ������

    TVector<int> result = vector1 + vector2; // ������������� �������� ��������
    cout << "Sum of vectors: " << result << endl;

    result = vector1 - vector2; // ������������� �������� ���������
    cout << "Difference of vectors: " << result << endl;

    double scalarProduct = vector1 * vector2; // ������������� �������� ���������� ������������
    cout << "Scalar product of vectors: " << scalarProduct << endl;

    result = vector1 * 2; // ������������� �������� ��������� �� �����
    cout << "Vector1 multiplied by 2.0: " << result << endl;

    return 0;
}