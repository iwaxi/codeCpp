#include<iostream>
using namespace std;

template<typename ElemType>
struct LNode
{
    ElemType value;
    LNode<ElemType>* next;
};

template<typename ElemType>
LNode<ElemType>* create(const ElemType* data, int size){
    LNode<ElemType> *prev, *head, *tail;
    head = new LNode<ElemType>;
    head->value = size; head->next = nullptr; // value of head : size
    prev = head;    
    for(int i = 0; i < size; i++){
        tail = new LNode<ElemType>;
        tail->next = nullptr;
        tail->value = data[i];
        prev->next = tail;
        prev = tail;
    }
    return head;
}
template<typename ElemType>
void output(LNode<ElemType>* list){
    LNode<ElemType>* p = list->next;
    for( ; p; p = p->next){
        cout << p->value << endl;
    }
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    LNode<int>* list = create(a, 5);
    output(list);
    system("pause");
    return 0;
}