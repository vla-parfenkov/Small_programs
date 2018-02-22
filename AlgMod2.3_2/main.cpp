/*Современники.

Группа людей называется современниками если был такой момент, когда они могли собраться
вместе. Для этого в этот момент каждому из них должно было уже исполниться 18 лет, но ещё не
исполниться 80 лет.
Дан список Жизни Великих Людей. Необходимо получить максимальное количество
современников. В день 18летия человек уже может принимать участие в собраниях, а в день
80летия и в день смерти уже не может.
Замечание. Человек мог не дожить до 18-летия, либо умереть в день 18-летия. В этих случаях
принимать участие в собраниях он не мог.*/


#include <iostream>
#include <cstring>


#define Born 1
#define Death 2


//класс событие(рождение или смерть)
struct CEvent {
public:

    CEvent(): Type(0), Day(0), Month(0), Year(0){};
    CEvent(int type, int day, int month, int year);

    //перегрузка операторов сравнения
    bool operator<(const CEvent& ev);
    bool operator>(const CEvent& ev);

    //перегрузка оператора равенства
    CEvent& operator = (const CEvent& ev);

    int Type;
    int Day;
    int Month;
    int Year;
};


CEvent::CEvent(int type, int day, int month, int year)
{
    Type = type;
    Day = day;
    Month = month;
    Year = year;

}

bool CEvent::operator<(const CEvent &ev)
{
    if( Year < ev.Year ){
        return true;
    } else if( Year == ev.Year ){
        if( Month < ev.Month ){
            return true;
        } else if ( Month == ev.Month ){
            if ( Day < ev.Day ){
                return true;
            }
        }
    }
    return false;
}

bool CEvent::operator>(const CEvent &ev)
{
    if( Year > ev.Year ){
        return true;
    } else if( Year == ev.Year ){
        if( Month > ev.Month ){
            return true;
        } else if ( Month == ev.Month ){
            if ( Day > ev.Day ){
                return true;
            }
        }
    }
    return false;
}

CEvent& CEvent::operator=(const CEvent &ev)
{
    if ( this != &ev ) {
        this->Type = ev.Type;
        this->Day = ev.Day;
        this->Month = ev.Month;
        this->Year = ev.Year;
    }
    return *this;
}


template <class T>
//проталкивает элемент вниз, в случае неправильного его расположения
void SiftDown(T* Array, int index, int Size)
{
    int left = 2 * index  + 1;
    int right = 2* index + 2;

    int LargestSon = index;

    if ( left < Size && Array[left] > Array[index] )
    {
        LargestSon = left;
    }
    if ( right < Size && Array[right] > Array[LargestSon] )
    {
        LargestSon = right;
    }

    if(LargestSon != index ){
        std::swap ( Array[index], Array[LargestSon] );
        SiftDown(Array, LargestSon, Size );
    }

}

template <class T>
//проталкивает элемент, в случае неправильного расположения
void SiftUp(T* Array, int index)
{
    while(index > 0){
        int Dad =  (index - 1) / 2;
        if( !(Array[index] > Array[Dad]))
            return;
        std::swap ( Array[index], Array[Dad] );
        index = Dad;
    }
}

template <class T>
//построение кучи
void BuildHeap(T* Array, int Size)
{
    for (int i = (Size / 2) - 1; i >= 0 ; --i) {
        SiftDown(Array, i, Size);
    }
}

template <class T>
//добавить элемент в кучу
void AddElement(T* Array, T Element, int Size)
{
    Array[Size] = Element;
    Size++;
    SiftUp(Array, Size - 1);

}

template <class T>
//извлекает максимум
T ExtractMax(T* Array, int Size)
{

    T result = Array[0];
    Array[0] = Array[Size - 1];
    Size--;
    SiftDown(Array, 0, Size);

    return result;

}

template <class T>
//пирамидальная сортировка
void HeapSort(T* Array, int Size)
{
    int HeapSize = Size;
    BuildHeap(Array, Size);
    while ( HeapSize > 1){
        std::swap (Array[0], Array[HeapSize - 1]);
        --HeapSize;
        SiftDown(Array, 0, HeapSize);
    }

}

//проверяем достиг ли человек совершенолетия
bool isAdult( CEvent &EventBorn, CEvent &EventDeath )
{
    if(EventDeath.Year - EventBorn.Year < 18 ){
        return false;
    } else if ( EventDeath.Year - EventBorn.Year == 18 ){
        if ( EventDeath.Month < EventBorn.Month ){
            return false;
        } else if  ( EventDeath.Month == EventBorn.Month ){
            if  (EventDeath.Day <= EventBorn.Day){
                return  false;
            }
        }
    }
    return true;
}

//если человек старше 80
bool isOld (CEvent &EventBorn, CEvent &EventDeath )
{
    if(EventDeath.Year - EventBorn.Year > 80 ){
        return true;
    } else if ( EventDeath.Year - EventBorn.Year == 80 ){
        if ( EventDeath.Month > EventBorn.Month ){
            return true;
        } else if  ( EventDeath.Month == EventBorn.Month ){
            if  (EventDeath.Day > EventBorn.Day){
                return true;
            }
        }
    }
    return false;
}


//функция считает количество современников
int Work (CEvent* Array, int Size)
{
    int CurentCount = 0;
    int MaxCount = 0;

    for (int i = 0; i < Size; ++i) {
        if( Array[i].Type == Born) {
            CurentCount++;
        } else  if ( Array[i].Type == Death ){
            CurentCount--;
        }

        if ( CurentCount > MaxCount ){
            MaxCount = CurentCount;
        }

    }

    return MaxCount;

}

int main() {

    int n = 0;
    std::cin >> n;
    CEvent* Array = new CEvent[2 * n];
    int Size = 0;

    for (int i = 0; i < n; ++i){
        int day = 0;
        int month = 0;
        int year = 0;
        std::cin >> day;
        std::cin >> month;
        std::cin >> year;

        CEvent TempBorn(Born, day , month , year );
        std::cin >> day;
        std::cin >> month;
        std::cin >> year;
        CEvent TempDeath(Death, day, month, year );
        if ( isOld (TempBorn, TempDeath)){
            //уберем лишние годы
            TempDeath.Year = TempBorn.Year + 80;
            TempDeath.Month = TempBorn.Month;
            TempDeath.Day = TempBorn.Day;
        }
        if (isAdult(TempBorn, TempDeath)){
            //убираем "детские" годы
            TempBorn.Year = TempBorn.Year + 18;
            Array[2 * i] = TempBorn;
            Array[2 * i + 1] = TempDeath;
            Size += 2;
        } else{
            --i;
            --n;
        }
    }

    HeapSort(Array,Size);

    std::cout << Work(Array, Size);

    delete[] Array;
    return 0;
}