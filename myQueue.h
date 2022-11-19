#ifndef __myQueue
#define __myQueue
template<typename ElemType>
struct LNode
{
    ElemType elem;
    LNode* next;
};

template<typename ElemType>
class myQueue
{
private:
    LNode<ElemType>* front;
    LNode<ElemType>* rear;
public:
    myQueue(): front(new LNode<ElemType>), rear(new LNode<ElemType>){
        front->elem = rear->elem = 0;
        front->next = rear;
        rear->next = front;
    }
    void push_back(ElemType data){
        rear->elem = data;
        LNode<ElemType>* ptr = new LNode<ElemType>;
        rear->next = ptr;
        ptr->elem = 0;
        rear = ptr;
        rear->next = front;
    }
    ElemType frontElem(){
        return front->next->elem;
    }
    void pop(){
        if(front->next != rear){
            LNode<ElemType>* del = front->next;
            front->next = del->next;
            delete del;
        }
    }
    bool isEmpty(){ return front->next == rear;}
};
#endif
