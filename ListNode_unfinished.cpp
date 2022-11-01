#include<iostream>
using namespace std;

#define Yes 1
#define No unsigned(-1)

template<typename ElemType>
struct LNode
{
    ElemType value;
    int index;
    LNode<ElemType>* next;
};

template<typename ElemType>
LNode<ElemType>* createList(const ElemType* data, const int size){
    LNode<ElemType> *head = new LNode<ElemType>, *p = new LNode<ElemType>;
    head->index = 0; head->value = data[0]; head->next = nullptr;
    p = head;
    try{
        if(size < 0)
            throw size;
        else{
            for(int i = 1;  i < size; i++){
                LNode<ElemType> *q = new LNode<ElemType>;
                q->value = data[i];
                q->index = i;
                q->next = nullptr;
                p->next = q;
                p = q;
            }
            return head;
        }
    }
    catch(int size){
        cout << "Invalid size.\n";
        return nullptr;
    }
}

template<typename ElemType>
void output(LNode<ElemType>* list)
{
    LNode<ElemType>* ptr = list;
    for( ; ptr; ptr = ptr->next){
        cout << ptr->index << " " << ptr->value << endl;
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    LNode<int>* list = createList(a, 5);
    output(list);
    system("pause");
    return 0;
}