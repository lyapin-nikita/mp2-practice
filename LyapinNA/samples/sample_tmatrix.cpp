#include <iostream>
#include "tmatrix.h"


int main()
{
	TMatrix<int> a(2), b(3), c(4);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;


	int size;
	cout << "Enter the size of the matrices: ";
	cin >> size;


	// ������� ��� ���������� ������ TMatrix
	TMatrix<int> matrix1(size);
	TMatrix<int> matrix2(size);

	cout << "Enter the elements of the first matrix:" << endl;
	cin >> matrix1; // ������������� �������� �����

	cout << "Enter the elements of the second matrix:" << endl;
	cin >> matrix2; // ������������� �������� �����

	// ������������ ������ ����������
	cout << "First matrix: " << endl;
	cout << matrix1 << endl; // ������������� �������� ������

	cout << "Second matrix: " << endl;
	cout << matrix2 << endl; // ������������� �������� ������

	TMatrix<int> result = matrix1 + matrix2; // ������������� �������� �������� ������
	cout << "Sum of matrices: " << endl;
	cout << result << endl;
	
	TMatrix<int> result2 = matrix1 - matrix2; // ������������� �������� ��������� ������
	cout << "Difference of matrices: " << endl;
	cout << result2 << endl;
	
	TMatrix<int> result3 = matrix1 * matrix2; // ������������� �������� ��������� ������
	cout << "Product of matrices: " << endl;
	cout << result3 << endl;
	
	return 0;
}
