/*Дано число N < 106 и последовательность пар целых чисел из [-231, 231] длиной N.
 * Построить декартово дерево из N узлов, характеризующихся парами чисел (Xi, Yi).
 * Каждая пара чисел (Xi, Yi) определяет ключ Xi и приоритет Yi в декартовом дереве.
 * Добавление узла в декартово дерево выполняйте второй версией алгоритма,
 * рассказанного на лекции: При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом.
 * Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x,
 * а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y).
 * Новый узел вставьте на место узла P. Построить также наивное дерево поиска по ключам Xi.
 * Равные ключи добавляйте в правое поддерево. Вычислить количество узлов в самом широком слое декартового дерева
 * и количество узлов в самом широком слое наивного дерева поиска.
 * Вывести их разницу. Разница может быть отрицательна.*/


#include <iostream>
#include<stack>
#include <queue>


class CBinarySearchTree{
public:
    CBinarySearchTree();
    ~CBinarySearchTree();

    bool Add(size_t key);

    bool Delete(size_t key);


    size_t MaxLayerWidth();

private:
    struct CNode {
        size_t Key;
        CNode* Left;
        CNode* Right;
        CNode* Parrent;

        CNode(): Key(0), Left(NULL), Right(NULL), Parrent(NULL){};
    };

    CNode* root;

    void DeleteNode(CNode*& Del);
    CNode* Find(size_t key);
};

CBinarySearchTree::CBinarySearchTree()
{
    root = NULL;
}

CBinarySearchTree::~CBinarySearchTree()
{
    if (root == NULL){
        return;
    }
    CNode* node = root;
    std::stack<CNode*> S;

    while(S.size() != 0 || node != NULL){
        if (node != NULL){
            S.push(node);
            node = node->Left;
        } else {
            node = S.top();
            S.pop();
            CNode* Temp = node->Right;
            DeleteNode(node);
            node = Temp;
        }
    }
}

bool CBinarySearchTree::Add(size_t key)
{
    if( root == NULL ){
        root = new CNode;
        root->Key = key;
        return true;
    }

    CNode* Father = root;
    CNode* add = new CNode;
    add->Key = key;

    while (Father != NULL){
        if( add->Key > Father->Key){
            if (Father->Right != NULL){
                Father = Father->Right;
            } else {
                add->Parrent = Father;
                Father->Right = add;
                return true;
            }
        } else {
            if (Father->Left != NULL){
                Father = Father->Left;
            } else {
                add->Parrent = Father;
                Father->Left = add;
                return true;
            }
        }
    }

    return false;
}

bool CBinarySearchTree::Delete(size_t key)
{
    if (root == NULL){
        return false;
    }

    CNode* Del = Find(key);

    if(Del != NULL){
        DeleteNode(Del);
        return true;
    } else {
        return false;
    }

}

CBinarySearchTree::CNode * CBinarySearchTree::Find(size_t key)
{
    if( root == NULL){
        return NULL;
    }

    CNode* Node = root;

    while ( Node != NULL)
    {
        if(Node->Key == key){
            return Node;
        } else if(Node->Key > key){
            Node = Node->Right;
        } else {
            Node = Node->Left;
        }
    }

    return NULL;
}

void CBinarySearchTree::DeleteNode(CNode *&Del)
{

    if (Del->Right == NULL && Del->Left == NULL){// первый случай: удаляемый элемент - лист
        if (Del->Parrent != NULL) {
            if (Del->Parrent->Left == Del) {
                Del->Parrent->Left = NULL;
            } else {
                Del->Parrent->Right = NULL;
            }
        }
        delete Del;
    } else if (Del->Left == NULL){// второй случай: нет левого потомка
        CNode* right = Del->Right;
        right->Parrent = Del->Parrent;
        if (Del->Parrent != NULL) {
            if (Del->Parrent->Left == Del) {
                Del->Parrent->Left = right;
            } else {
                Del->Parrent->Right = right;
            }
        }
        delete Del;
        Del = right;
    } else if (Del->Right == NULL){// второй случай: нет правого потомка
        CNode* left = Del->Left;
        left->Parrent = Del->Parrent;
        if (Del->Parrent != NULL) {
            if (Del->Parrent->Left == Del) {
                Del->Parrent->Left = left;
            } else {
                Del->Parrent->Right = left;
            }
        }
        delete Del;
        Del = left;
    } else { //третий случай
        CNode* minParrent = Del;
        CNode* min = Del->Right;

        while(min->Left != NULL){
            minParrent = min;
            min = min->Left;
        }

        Del->Key = min->Key;

        (minParrent->Left == min ? minParrent->Left: minParrent->Right) = min->Right;
        delete min;
    }


}


size_t CBinarySearchTree::MaxLayerWidth()
{
    size_t MaxWidht = 0;
    std::queue<CNode*> layer;
    layer.push(root);
    while (!layer.empty()){
        size_t CurrentWidht = layer.size();
        if (CurrentWidht > MaxWidht)
            MaxWidht = CurrentWidht;
        for (int i = 0; i < CurrentWidht; ++i)
        {
            CNode* Temp = layer.front();
            layer.pop();
            if (Temp->Left)
                layer.push(Temp->Left);
            if (Temp->Right)
                layer.push(Temp->Right);
        }
    }
    return MaxWidht;
}


///-----------------------------------------------------------------



class CTreap {
public:
    CTreap();
    ~CTreap();

    void Add(size_t key, size_t priority);

    bool Delete(size_t key);

    size_t MaxLayerWidth();

private:
    struct CTreapNode {
        size_t Key;
        size_t Priority;
        CTreapNode* Left;
        CTreapNode* Right;
        CTreapNode* Parrent;

        CTreapNode(): Key(0), Priority(0), Left(NULL), Right(NULL), Parrent(NULL){};
    };

    CTreapNode* root;

    void Split (CTreapNode* Current, size_t key, CTreapNode* left, CTreapNode* right);
    CTreapNode* Merge( CTreapNode* left, CTreapNode* right );

};

CTreap::CTreap()
{
    root = NULL;
}

CTreap::~CTreap()
{
    delete root;
}

void CTreap::Split(CTreapNode* current, size_t key, CTreapNode* left, CTreapNode* right)
{
    if( current == NULL ) {
        left = NULL;
        right = NULL;
    } else if( current->Key <= key ) {
        Split( current->Right, key, current->Right, right );
        left = current;
    } else {
        Split( current->Left, key, left, current->Left );
        right = current;
    }
}

CTreap::CTreapNode * CTreap::Merge(CTreapNode *left, CTreapNode *right)
{
    if( left == 0 || right == 0 ) {
        return left == 0 ? right : left;
    }

    if( left->Priority > right->Priority ) {
        left->Right = Merge( left->Right, right );
        return left;
    }

    right->Left = Merge( left, right->Left );
    return right;
}

void CTreap::Add(size_t key, size_t priority)
{
    CTreapNode* newNode = new CTreapNode;
    newNode->Key = key;
    newNode->Priority = priority;

    if( root == NULL){
        root = newNode;
        return;
    }

    CTreapNode* Current = root;
    CTreapNode* Father = root;

    //Сначала спускаемся по дереву (как в обычном бинарном дереве поиска по k.x),
    // но останавливаемся на первом элементе, в котором значение приоритета оказалось меньше k.y.
    while ( Current && Current->Priority >= priority)
    {
        Father = Current;
        if(key >= Current->Key){
            Current = Current->Right;
        } else {
            Current = Current->Left;
        }
    }

    //Теперь разрезаем поддерево найденного элемента на T1 и T2.

    //Полученные T1 и T2 записываем в качестве левого и правого сына добавляемого элемента.
    Split(Current, key, newNode->Left, newNode->Right);

    //Полученное дерево ставим на место элемента, найденного в первом пункте.
    if (Current == root){
        root = newNode;
    } else {
        if(key >= Father->Key){
            Father->Right = newNode;
        } else {
            Father->Left = newNode;
        }
    }

}

bool CTreap::Delete(size_t key)
{
    if (root == NULL){
        return false;
    }

    CTreapNode* Father = root;
    CTreapNode* Current = root;

    while(Current && Current->Key != key ){
        Father = Current;
        if(key > Current->Key){
            Current = Current->Right;
        } else {
            Current = Current->Left;
        }
    }

    if(Current == NULL || Current->Key != key){
        return false;
    }

    CTreapNode* Result = Merge(Current->Left,Current->Right);

    if (Current == root){
        root = Result;
        delete Current;
        return true;
    } else {
        if(key > Father->Key){
            Father->Right = Result;
            delete Current;
            return true;
        } else {
            Father->Left = Result;
            delete Current;
            return true;
        }
    }

}


size_t CTreap::MaxLayerWidth()
{
    size_t MaxWidht = 0;
    std::queue<CTreapNode*> layer;
    layer.push(root);
    while (!layer.empty()){
        size_t CurrentWidht = layer.size();
        if (CurrentWidht > MaxWidht)
            MaxWidht = CurrentWidht;
        for (int i = 0; i < CurrentWidht; ++i)
        {
            CTreapNode* Temp = layer.front();
            layer.pop();
            if (Temp->Left)
                layer.push(Temp->Left);
            if (Temp->Right)
                layer.push(Temp->Right);
        }
    }
return MaxWidht;
}


int main() {

    size_t Size = 0;
    std::cin >> Size;
    size_t K = 0;
    size_t Pr = 0;
    CBinarySearchTree BinaryTree;
    CTreap Treap;

    for (int i = 0; i < Size; ++i) {
        std::cin >> K >> Pr;
        BinaryTree.Add(K);
        Treap.Add(K,Pr);
    }

    std::cout << Treap.MaxLayerWidth() - BinaryTree.MaxLayerWidth();

    return 0;
}