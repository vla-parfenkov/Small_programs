#include <assert.h>
#include <iostream>


class CIntVector{

public:

    CIntVector() : data(0), bufferSize(0), size(0){}
    ~CIntVector() { delete  data; }

    //размер
    int Size() const { return  size;}


    //доступ по индексу
    int operator[] ( int index ) const;

    int& operator[] (int index);

    //добавление нового элемента
    void Add (int element);

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






CIntVector Factorization (int n)
{
    assert(n>0);

    //Выделим массив под решето Эратосфена
    bool* sieve = new bool[n+1];
    for (int i = 0; i <= n; ++i){

        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;

    int primesCount = 0;

    //находим простые числа до n
    for( int p = 2; p <= n; ++p){
        if(!sieve[p]) {
            continue;
        }
        ++primesCount;
        for(int k = 2; k*p <= n; ++k){
            sieve[k*p] = false;
        }

    }

    CIntVector fact;

    //делим на простые числа, получаем вектор разложений
    for(int i = 2; i <= n;){
        if( sieve[i] && (n % i == 0) ){
            fact.Add(i);
            n = n / i;
        } else {
            i++;
        }
    }

    delete[] sieve;

    return fact;
}


int main()
{

    int n = 0;

    std::cin >> n;


    const CIntVector fact =  Factorization(n);

    for (int i = 0; i < fact.Size(); ++i){
        std::cout << fact[i] << " ";
    }


    return 0;
}