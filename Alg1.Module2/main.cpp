/*Напишите программу, печатающую набор строк в лексикографическом порядке.

Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n',

считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать

свою функцию сравнения строк.*/

#include <iostream>
#include <cstring>
#include <assert.h>


class CString {
public:
    CString();
    CString(char* str);
    CString(const CString& str);

    ~CString();

    void gets();
    void puts();

    //перегрузка операторов
    CString& operator = (const CString& str);
    bool operator<(const CString& str);



    const char& operator[](int i) const;
    char& operator[](int i);


private:
    char *Data;

    //функция сравнения
    int StrCompare (char* str1, char* str2);
};



CString::CString()
{
    Data = new char [2];
    strcpy(Data, "");
}

CString::CString(char *str)
{
    Data = new char [strlen(str) + 1];
    strcpy(Data, str);
}

CString::CString(const CString& str)
{
    Data = new char [strlen(str.Data) + 1];
    strcpy(Data, str.Data);
}

CString::~CString()
{
    delete[] Data;
}

//функция возвращает -1 если лексиграфически str1<str2 , 1 если больше и 0 если равны
int CString::StrCompare(char *str1, char *str2)
{
    int endcount = std::min(strlen(str1), strlen(str2) );
    int counter = 0;

    while ( counter != endcount + 1){
        if( str1[counter] == str2[counter] ){
            counter++;
        } else {
            if(str1[counter] < str2[counter]){
                return -1;
            } else{
                return 1;
            }
        }
    }

    return 0;
}

CString& CString::operator=(const CString& str)
{
    if ( this != &str ) {
        delete[] this->Data;
        this->Data = new char[strlen(str.Data) + 1];
        strcpy(this->Data, str.Data);
    }
    return *this;
}

bool CString::operator<(const CString& str) {
    return  StrCompare(Data, str.Data) == -1 ? true: false;
}

char& CString::operator[](int i)
{
    assert(i >= 0);
    assert(i < strlen(Data));
    return Data[i];
}

const char& CString::operator[](int i) const
{
    assert(i >= 0);
    assert(i < strlen(Data));
    return Data[i];
}

void CString::gets()
{
    char Buff[255];
    std::cin >> Buff;
    Data = new char [strlen(Buff) + 1];
    strcpy(Data, Buff);

}

void CString::puts()
{
    std::cout << Data;
}

template <class T>

void InsertionSort ( T *Input, int n )
{
    for (int i = 1; i < n; ++i) {
        T Temp = Input[i];
        int j = i - 1;
        while ( j >= 0 && Temp < Input[j] ){
            Input[j + 1] = Input[j];
            j--;
        }
        Input[j + 1] = Temp;
    }
}


int main()
 {
     int n = 0;
    std::cin >> n;

    CString *Input = new CString [n];

     for (int i = 0; i < n; ++i){
         Input[i].gets();
     }

     InsertionSort(Input, n);


     for (int i = 0; i < n; ++i) {
         Input[i].puts();
         std::cout << std::endl;
     }

     delete[] Input;

    return 0;
}