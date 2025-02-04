#include <iostream>
#include <windows.h>
using namespace std;

double* allocateArray(const int size) { return new double[size]; }

void fillArray(double* arr, const int size) {
    cout << "Введите " << size << " элементов массива: ";
    for (int i = 0; i < size; i++) { cin >> arr[i]; }
}

void displayArray(const double* arr, const int size) {
    cout << "Элементы массива: ";
    for (int i = 0; i < size; i++) { cout << arr[i] << " "; }
    cout << endl;
}

void freeArray(const double* arr) { delete[] arr; }

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char choice;
    do {
        int size;
        cout << "Введите размер массива: ", cin >> size;

        if (size <= 0) {
            cout << "Размер массива должен быть больше 0!\n";
            continue;
        }

        double* arr = allocateArray(size);
        fillArray(arr, size);

        displayArray(arr, size);

        freeArray(arr);

        cout << "Создать новый массив? (y/n): ", cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Программа завершена.\n";
}
