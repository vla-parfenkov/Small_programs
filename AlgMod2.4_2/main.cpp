/*Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется
найти k­ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k
(0..n­1) в отсортированном массиве. Напишите нерекурсивный алгоритм.
Требования к дополнительной памяти: O(n). Требуемое среднее время работы: O(n).

4_2. ​Реализуйте стратегию выбора опорного элемента “медиана трёх”. Функцию Partition реализуйте
методом прохода двумя итераторами от конца массива к началу.*/
#include <iostream>

//медиана трех
template <class T>
int MedianOfThree(T* a, int one, int two, int three) {
    const bool comp12 = a[one] < a[two];
    const bool comp13 = a[one] < a[three];
    const bool comp23 = a[two] < a[three];

    if (comp12 && comp23) return two;               // 1  < 2  < 3
    if (comp12 && !comp23 && comp13) return three;  // 1  < 3 <= 2
    if (!comp12 && comp13) return one;              // 2 <= 1  < 3
    if (!comp12 && !comp13 && comp23) return three; // 2 <  3 <= 1
    if (comp12 && !comp13) return one;              // 3 <= 1  < 2
    return two;
}

//идем с конца к началу
template <class T>
int Partition(T* a, int left, int right) {
    int pivot = MedianOfThree(a, left, left + (right - left) / 2, right - 1);
    std::swap(a[pivot], a[left]); //опорный элемент меняем с крайним левым

    int i = right - 1, j = i;
    while (j > left) { //слева опорного элемента меньше или равные, справа строго большие
        if (a[j] < a[left])
            --j;
        else
            std::swap(a[i--], a[j--]);
    }

    std::swap(a[i], a[left]); //меняем опорный элемент обратно
    return i;
}


//находит key-порядковую статистику
template <class T>
int KStatisticsc(T* a, int n, int key) {
    int left = 0, right = n, mid;
    while (true) {
        mid = Partition(a, left, right); //ищем середину в a[left,right)

        if (mid == key) { //пока ключ не равен mid сужаем границы
            return a[mid];
        }
        else if (key < mid) { //сужаем справа
            right = mid;
        }
        else {
            left = mid + 1; //сужаем слева
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;
   int* a = new int[n];

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << KStatisticsc(a, n, k);

    delete[] a;
    return 0;
}