#include <iostream>
#include <assert.h>
#include <algorithm>

class CIntVector{

public:

    CIntVector() : data(0), bufferSize(0), size(0){}
    ~CIntVector() { delete[]  data; }

    //размер
    int Size() const { return  size;}


    //доступ по индексу
    int operator[] ( int index ) const;

    int& operator[] (int index);

    //добавление нового элемента
    void Add (int element);

    //сортировка
    void sort(){
        std::sort(data, data + size);
    }

private:

    int *data;
    int size;
    int bufferSize;

    //рост буффера
    void grow ();
};



int CIntVector::operator[]( int index ) const
{
    assert( index >= 0 );
    assert( index < size );
    assert( data != 0 );
    return data[index];
}

int& CIntVector::operator[]( int index )
{
    assert( index >= 0 );
    assert( index < size );
    assert( data != 0 );
    return data[index];
}


void CIntVector::Add (int element)
{
    if (size == bufferSize){
        grow();
    }

    assert (size < bufferSize);
    assert (data != 0);

    data[size++] = element;
}

void CIntVector::grow()
{
    //2 начальный размер буффера
    int newBufferSize = std::max( bufferSize*2, 2);
    int* newdata = new int [newBufferSize];
    if ( data != 0) {
        for (int i = 0; i <= size; ++i) {
            newdata[i] = data[i];
        }
        delete[] data;
    }
    data = newdata;
    bufferSize = newBufferSize;

}


int Result (CIntVector &Mass, CIntVector &Power)
{
    //отсортруем сначала по массе, чтобы сохранить соответствие массы и силы у одного спортсмена
    Mass.sort();
    Power.sort();

    int CurentMass = 0;
    int CurentHigh = 0;


    for (int i = 0; i < Power.Size(); ++i) {
        if( Power[i] >= CurentMass){
            CurentMass += Mass[i];
            CurentHigh++;
        }
    }

    return CurentHigh;
}

int main()
{
    CIntVector Mass;
    CIntVector Power;

    //переменные считываемые
    int m = 0;
    int p = 0;

    while ( std::cin >> m >> p ){
        Mass.Add(m);
        Power.Add(p);
    }




    /*for (int k = 0; k < Mass.Size(); ++k) {
        std::cout << Mass[k] << " " << Power[k] << std::endl;
    }*/

    std::cout << Result( Mass, Power );

    return 0;
}