​/*Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество
таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
n, m ≤ 100000.*/

#include <iostream>
#include <assert.h>

int SpecificCounter (int* ArrayA, int n, int* ArrayB, int m, int k)
{
    int Counter = 0;
    int i = 0;
    int j = m-1;

    //двигаемся по массиву А слева направо, а по B справа налево
    while( (i < n) && (j >= 0) ){
            if ( (ArrayA[i] + ArrayB[j]) == k ){
                Counter++;
                j--;
            }
            if ( (ArrayA[i] + ArrayB[j]) > k ){
                j--;
            }
            if ( (ArrayA[i] + ArrayB[j]) < k ){
                i++;
            }
    }

    return Counter;

}

int main()
{
    int n = 0; //число элементов возрастающего массив

    std::cin >> n;
    if ( n <= 0){
        std::cout << "error";
        return 0;
    }

    int* A = new int[n];

    for (int i = 0; i < n; ++i){
        std::cin >> A[i];
    }


    int m = 0; // число элементов убывающего массива

    std::cin >> m;

    if ( m <= 0){
        std::cout << "error";
        return 0;
    }

    int* B = new int[m];

    for (int i = 0; i < m; ++i){
        std::cin >> B[i];
    }

    int k = 0; // искомое значение

    std::cin >> k;

    std::cout << SpecificCounter( A, n, B, m, k );

    delete[] A;
    delete[] B;

    return 0;
}
