/*Дано число N < 106 и последовательность целых чисел из [-2^31..2^31] длиной N.
 * Требуется построить бинарное дерево, заданное наивным порядком вставки.
 * Т.е., при добавлении очередного числа K в дерево с корнем root,
 * если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
Выведите элементы в порядке in-order (слева направо). */

#include <iostream>
#include<stack>



class CBinarySearchTree{
public:
    CBinarySearchTree();
    ~CBinarySearchTree();

    bool Add(size_t key);

    bool Delete(size_t key);


    void InorderTraversal ();

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

void CBinarySearchTree::InorderTraversal()
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
            std::cout << node->Key << " ";
            node = node->Right;
        }
    }
}

int main()
{
    size_t Size = 0;
    std::cin >> Size;
    CBinarySearchTree Tree;
    size_t k = 0;

    for (size_t i = 0; i < Size; ++i) {
        std::cin >> k;
        Tree.Add(k);
    }

    Tree.InorderTraversal();

    return 0;
}