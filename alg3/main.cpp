​/*Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго
возрастают, а на интервале [m, n-1] строго убывают. Найти m за O(log m).
2 ≤ n ≤ 10000.*/

#include <iostream>

int Searchm (int* ArrayA, int n)
{

    int left = 0;
    int right = n - 1;

//Сокращаем отрезок поиска
    for( int i = 2; i < n - 1; i *= 2){
        if ( ArrayA[i] < ArrayA[i+1] ){
            left = i;
        }
        if ( ArrayA[i] > ArrayA[i+1]){
            right = i;
            break;
        }
    }



    while ( left < right ){

        //Проверка граничных элементов
        if( (left - 1) == 0 && ArrayA[left - 1] > ArrayA[left] ){
            return left - 1;
        }
        if ( right == n - 1 && ArrayA[right] > ArrayA[right - 1]){
            return right;
        }

        int mid = (left + right) / 2;
        if ( ArrayA[mid] > ArrayA[mid + 1] ){
            right = mid;
        }
        if ( ArrayA[mid] < ArrayA[mid + 1] ){
            left = mid + 1;
        }

    }

    return  left;
}

int main()
{
    int n = 0;

    std::cin >> n;

    if( n <= 1){
        std::cout << "error";
        return 0;
    }

    int* A = new int[n];

    for(int i = 0; i < n; ++i){
        std::cin >> A[i];
    }

    std::cout << Searchm( A, n );

    delete[] A;

    return 0;
}
