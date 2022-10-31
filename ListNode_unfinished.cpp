#include<iostream>
using namespace std;

#define Yes 1
#define No unsigned(-1)

template<class ElemType>
struct LNode
{
    ElemType value;
    LNode<ElemType>* next;
};

template<class ElemType>
LNode<ElemType>* createList(LNode<ElemType>* &newList, const ElemType* data, const int size){
    LNode *p = nullptr, *q = nullptr;
    try{
        if(size < 0)
            throw size;
        else{
            
        }
    }
    catch(int size){
        cout << "Invalid size.\n";
        return nullptr;
    }
}