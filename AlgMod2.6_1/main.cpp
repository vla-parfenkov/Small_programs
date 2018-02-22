/*Дан массив строк. Количество строк не больше 100000.
 * Отсортировать массив методом поразрядной сортировки MSD по символам.
 * Размер алфавита - 256 символов. Последний символ строки = ‘
0’. */

#include <iostream>

#define k 256 //размер алфавита

template <class T>
//сортировка подсчетом
void CountingSort (T* A, int n, T* C, int byte)
{
    for (int i = 0; i < byte; ++i){
        C[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++C[A[i]];
    }
    int pos = 0;
    for (int i = 0; i < byte; ++i) {
        for (int j = 0; j < C[i]; ++j) {
                A[pos++] = i;
        }
    }
}


template <class T>
void MSDSort (T* A, int n, int byte)
{
    if(n <= 1){
        return;
    }
    T* C = new T[k];
    CountingSort(A, n, C, byte);
    if(byte > 0){
        for (int i = 0; i < k; ++i) {
            MSDSort(A + C[i], C[i + 1] - C[i], byte - 1);
        }
    }
    delete [] C;
 }



int main() {
    int n = 0;
    std::cin >> n;

    CString *Input = new CString [n];

    for (int i = 0; i < n; ++i){
        Input[i].gets();
    }




    for (int i = 0; i < n; ++i) {
        Input[i].puts();
        std::cout << std::endl;
    }

    delete[] Input;

    return 0;
}