#include <iostream>
#include <assert.h>

class CDeque {
public:
    CDeque();
    ~CDeque();


    void PushBack(int element);
    void PushFront(int element);
    int PopBack();
    int PopFront();

    bool IsEmpty() const {return dsize == 0;}

    int size() { return  dsize;}

private:

    int* buffer;
    int buffersize;
    int head;
    int tail;
    int dsize;

    //увеличение буффера
    void grow();
    //первоначальное выделение памяти
    void init_buffer();
};


CDeque::CDeque()
{
    buffersize = 0;
    buffer = nullptr;
    head = 0;
    tail = 0;
    dsize = 0;
}

CDeque::~CDeque()
{
    if(buffer) {
        delete[] buffer;
    }
}

void CDeque::grow()
{
    int newbuffersize = buffersize * 2;
    int* newbuffer = new int [newbuffersize];
    for(int i = 0; i < buffersize; ++i){
        newbuffer[i] = buffer[head];
        head = ( head + 1 ) % buffersize;
    }

    delete[] buffer;

    buffer = newbuffer;
    head = 0;
    tail = buffersize - 1;
    buffersize = newbuffersize;


}

void CDeque::init_buffer()
{
    buffersize = 2;//первоначальный размер буффера 2
    buffer = new int[buffersize];
}

void CDeque::PushBack(int element)
{
    if (IsEmpty()){
        init_buffer();
        head = 0;
        buffer[head] = element;
        tail = 1;
    }else {

        if (dsize + 1 == buffersize) {
            grow();
        }

        buffer[tail] = element;
        tail = (tail + 1) % buffersize;

    }
    dsize++;

}


void CDeque::PushFront(int element)
{
    if (IsEmpty()){
        init_buffer();
        head = 0;
        buffer[head] = element;
        tail = 1;
    }else {
        if (dsize + 1 == buffersize) {
            grow();
        }

        if(head == 0){
            head = buffersize;
        }

        head--;
        buffer[head] = element;

    }
    dsize++;
}

int CDeque::PopBack()
{
    assert( head != tail);
    if(tail == 0){
        tail = buffersize;
    }
    tail--;
    dsize--;

    return buffer[tail];
}


int CDeque::PopFront()
{
    assert( head != tail);
    int result = buffer[head];
    head = (head + 1) % buffersize;
    dsize--;

    return  result;
}







int main()
{
    int requestsCount = 0;
    std::cin >> requestsCount;

    CDeque deque;


    for(int i = 0; i < requestsCount; ++i){
        int requestType = 0;
        int requestValue = 0;
        std::cin >> requestType >> requestValue;
        switch(requestType){
            case 1:
                deque.PushFront( requestValue );
                break;
            case 2:
                if ( deque.IsEmpty() ) {
                    if ( requestValue != -1){
                        std::cout << "NO";
                        return 0;
                    }
                } else {
                    if ( deque.PopFront() != requestValue){
                        std::cout << "NO";
                        return 0;
                    }
                }
                break;
            case 3:
                deque.PushBack( requestValue );
                break;
            case 4:
                if ( deque.IsEmpty() ) {
                    if ( requestValue != -1){
                        std::cout << "NO";
                        return 0;
                    }
                } else {
                    if ( deque.PopBack() != requestValue){
                        std::cout << "NO";
                        return 0;
                    }
                }
                break;
            default:
                assert (false);
        }
    }

    std::cout << "YES";

    return 0;
}
/*5
3 44
1 45
1 34
4 44
2 34*/