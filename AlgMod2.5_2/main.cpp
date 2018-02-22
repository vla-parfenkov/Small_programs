/*Дана последовательность целых чисел a1...an и натуральное число k,
 * такое что для любых i, j: если j >= i + k, то a[i] <= a[j].
 * Требуется отсортировать последовательность.
 * Последовательность может быть очень длинной. Время работы O(n * log(k)).
 * Доп. память O(k). Использовать слияние.*/

#include <iostream>
#include <cstring>

//слияние
template<class T>
void Merge(T* A, int left, int right, int pivot) {
    int bufLen = right - left + 1;
    T* buffer = new T[bufLen];
    int k = 0;
    int i = left;
    int j = pivot + 1;
    while (i <= pivot && j <= right) { //пока один из массивов не кончился
        if (A[i] < A[j])          //в вывод добавляем меньший
            buffer[k++] = A[i++];
        else
            buffer[k++] = A[j++];
    }

    while (j <= right)                 //добавляем все элементы из оставшегося массива
        buffer[k++] = A[j++];
    while (i <= pivot)
        buffer[k++] = A[i++];

    std::memcpy(A + left, buffer, bufLen * sizeof(T));
    delete[] buffer;
}



//сортировка слиянием иттеративный алгоритм
template <class T>
void MergeSort (T* A, int left, int right)
{

    if (left < right) {
        int pivot = left + (right - left) / 2;
        MergeSort(A, left, pivot);      //левая половина
        MergeSort(A, pivot + 1, right); //правая половина
        Merge(A, left, right, pivot);    //слияние
    }
}

template <class T>
void SortAlmostOrderSeq (T* A, int Alen, int Key)
{
    int SortLen = (Key > Alen) ? Alen : Key;
    int left = 0;
    MergeSort(A, left, SortLen - 1); //сортируем первые k элементов
    SortLen += Key;                           //делаем диапазон в 2*k
    bool notLast = (SortLen < Alen);
    while (notLast) {                       //пока не дошли до конца
        int pivot = left + Key - 1;
        if (SortLen > Alen) {
            SortLen = Alen;
            notLast = false;
        }
        MergeSort(A, left + Key, SortLen - 1);          //сортируем вторые k
        Merge(A, left, SortLen - 1, pivot);            //сливаем с предыдущими k
        left += Key;
        SortLen += Key;
    }

}

int main() {

    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    int * A = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    SortAlmostOrderSeq(A, n, k);


    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << ' ';
    }

    delete[] A;
    return 0;
}