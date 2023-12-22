

#include <iostream>
#include "TVector.h" // Подключаем заголовочный файл с определением класса TVector

int main()
{
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;

    // Создаем два экземпляра класса TVector
    TVector<int> vector1(size);
    TVector<int> vector2(size);

    cout << "Enter the elements of the first vector:" << endl;
    cin >> vector1; // Перегруженный оператор ввода

    cout << "Enter the elements of the second vector:" << endl;
    cin >> vector2; // Перегруженный оператор ввода

    // Демонстрация работы операторов
    cout << "First vector: " << vector1 << endl; // Перегруженный оператор вывода
    cout << "Second vector: " << vector2 << endl; // Перегруженный оператор вывода

    TVector<int> result = vector1 + vector2; // Перегруженный оператор сложения
    cout << "Sum of vectors: " << result << endl;

    result = vector1 - vector2; // Перегруженный оператор вычитания
    cout << "Difference of vectors: " << result << endl;

    double scalarProduct = vector1 * vector2; // Перегруженный оператор скалярного произведения
    cout << "Scalar product of vectors: " << scalarProduct << endl;

    result = vector1 * 2; // Перегруженный оператор умножения на число
    cout << "Vector1 multiplied by 2.0: " << result << endl;

    return 0;
}