#include<iostream>
#include<queue>
using namespace std;

template<typename ElemType>     // basic datafield
struct LNode
{
    ElemType value;
    LNode<ElemType>* next;
    LNode<ElemType>* prev;
    LNode<ElemType>* Tail;
};

template<typename ElemType>     // create a list
LNode<ElemType>* create(const ElemType* data, int size){
    LNode<ElemType> *ptr, *head, *tail;
    head = new LNode<ElemType>;
    head->value = size;
    head->next = head->prev = nullptr;// value of head : size
    head->Tail = nullptr; 
    ptr = head;
    for(int i = 0; i < size; i++){
        tail = new LNode<ElemType>;
        tail->prev = ptr;
        tail->next = nullptr;
        tail->value = data[i];
        
        ptr->next = tail;
        head->Tail = tail; // head !
        ptr = tail;
    }
    return head;
}

template<typename ElemType>
void insert(LNode<ElemType>* list, ElemType data, int index){
    LNode<ElemType>* p = list->next;
    
}

template<typename ElemType>     // output the list
void output(LNode<ElemType>* list){
    LNode<ElemType>* p = list->next;
    for( ; p; p = p->next)
        cout << p->value << endl;
}

template<typename ElemType>
void reserveout(LNode<ElemType>* list){
    LNode<ElemType>* ptr = list->Tail;
    for( ; ptr; ptr = ptr->prev){
        cout << ptr->value << endl;
    }
}


int main()
{
    int* a = new int[10]{1, 2, 3, 4, 5, 6};
    LNode<int>* list = create(a, 6);
    output(list);
    reserveout(list);
    system("pause");
    return 0;
}