#include <iostream>


class CStack{
public:
    CStack(): head(0), size(0) {};
    ~CStack();

    //добавить элемент в конец
    void push(char element);

    //взять элемент из конца
    char pop();

    // посмотреть последний элемент
    char seehead(){ return head ==0 ? 0 : head->symbol;}

    //узнать количество элекментов в стеке
    int Size() { return  size; }

private:

    struct CNode {
        char symbol;
        CNode* next;

        CNode(): next(0), symbol(0){}
    };

    CNode* head;

    int size;
};

CStack::~CStack()
{
    while(head != 0){
        CNode* next = head->next;
        delete head;
        head = next;
        size--;
    }

}

void CStack::push(char element)
{
    CNode* NewEl = new(CNode);
    NewEl->symbol = element;
    NewEl->next = head;

    head = NewEl;

    size++;
}

char CStack::pop()
{
    if(head == 0){
        std::cout << "стэк пуст";
        return -1;
    }

    const char element = head->symbol;
    CNode* ToDelete = head;

    head = head->next;
    delete  ToDelete;
    size--;

    return element;
}

//Функция возвращает противоположную входной скобку
char AntiBkt(char Bkt)
{
    switch ( Bkt){
        case '(' :
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            //если символ не скобка, возвращаем символ
            return Bkt;

    }
}

std::string ReestablishSequence (std::string SeqIn)
{
    CStack RightPart;
    CStack LeftPart;
    std::string ERROR = "IMPOSSIBLE";


    for( int i = 0; i < SeqIn.length(); ++i){
        //Если скобка открывающая, то добавляем в правый массив
        if( SeqIn[i] == '(' || SeqIn[i] == '[' || SeqIn[i] == '{' ){
            RightPart.push( SeqIn[i] );
        }
        //если скобка закрывающая
        if ( SeqIn[i] == ')' || SeqIn[i] == ']' || SeqIn[i] == '}' ){
            // Если правый массив пуст, то добавляем ее в левый
            if ( RightPart.seehead() == 0){
                LeftPart.push( SeqIn[i] );
            } else {
                //Если последняя скобка в правом массиве соотносится, то извлекаеи ее
             if( AntiBkt( RightPart.seehead() ) == SeqIn [i])
             {
                 RightPart.pop();
             } else {
                 return ERROR;
             }
            }
        }
    }



    std::string SeqOut;

    //Записываем скобки из левого стека
    while( LeftPart.Size() != 0) {
        SeqOut += AntiBkt( LeftPart.seehead() );
        LeftPart.pop();
    }

    //Далее записываем данные из входной строки
    SeqOut += SeqIn;
    // Далее скобки из правого стека
    while ( RightPart.Size() != 0) {
        SeqOut += AntiBkt( RightPart.seehead() );
        RightPart.pop();
    }


    return SeqOut;
}


int main()
{
    std::string stringIn;

    std::cin >> stringIn;

    std::cout << ReestablishSequence(stringIn);


    return 0;

}