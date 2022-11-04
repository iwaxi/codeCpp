#include<iostream>
using namespace std;

template<typename ElemType>     // basic datafield
struct LNode
{
    ElemType value;
    LNode<ElemType>* next;
    LNode<ElemType>* prev;
};

template<typename ElemType>
class ListDouble
{
public:
    ListDouble();               // default Construct
    ListDouble(ElemType*, int); // parameter Construct
    ListDouble(int);            // value Construct
    void output();              // output from head to tail
    void reserveout();          // output from tail to head
    ~ListDouble();              // destroy the whole list
private:
    LNode<ElemType> *head; // head
    LNode<ElemType> *tail; // tail
    static int size;       // size

};


template<typename ElemType>         // default Construct
ListDouble<ElemType>::ListDouble(){
    head = tail = nullptr;
}

template<typename ElemType>
ListDouble<ElemType>::ListDouble(ElemType* data, int n): head(0),tail(0){ // parameter Construct
    LNode<ElemType> *ptr = nullptr, *New = nullptr;

    head = new LNode<ElemType>;
    head->next = head->prev = nullptr;

    ptr = head;
    for(int i = 0; i < n; i ++){
        New = new LNode<ElemType>; // create a new node
        New->prev = ptr;
        New->value = data[i];
        New->next = nullptr;

        ptr->next = New;           // add the node to list
        ptr = New;
        size ++;
    }
    head->value = size;            // "Initialize" head value
    tail = ptr;                    // tail create
}

template<typename ElemType>
ListDouble<ElemType>::ListDouble(int n): head(0),tail(0){ // parameter Construct
    LNode<ElemType> *ptr = nullptr, *New = nullptr;

    head = new LNode<ElemType>;
    head->next = head->prev = nullptr;

    ptr = head;
    for(int i = 0; i < n; i ++){
        ElemType a = i;
        New = new LNode<ElemType>; // create a new node
        New->prev = ptr;
        New->value = a;
        New->next = nullptr;

        ptr->next = New;           // add the node to list
        ptr = New;
        size ++;
    }
    head->value = size;            // "Initialize" head value
    tail = ptr;                    // tail create
}

template<typename ElemType>
void ListDouble<ElemType>::output(){
    LNode<ElemType> *ptr = head->next;
    for( ; ptr; ptr = ptr->next)
        cout << ptr->value << " ";
    cout << endl;
}

template<typename ElemType>
void ListDouble<ElemType>::reserveout(){
    LNode<ElemType> *ptr = tail;
    for( ; ptr->prev; ptr = ptr->prev)
        cout << ptr->value << " ";
    cout << endl;
}

template<typename ElemType>
ListDouble<ElemType>::~ListDouble(){
    if(head){
        LNode<ElemType> *ptr = head->next;
        for( ; ptr; ptr = ptr->next){
            delete ptr->prev;
            ptr->prev = 0;
        }    
    }
    cout << "Delete Successfully.\n";
}

template<typename ElemType>
int ListDouble<ElemType>::size = 0;

template<typename ElemType>
ListDouble<ElemType> create(){
    ListDouble<ElemType> list1(5);
    return list1;
}

template<typename ElemType>
void F(ListDouble<ElemType> b){
    return;
}
int main()
{
    int *a = new int[5]{1, 2, 3, 4, 5};
    ListDouble<int> list(a, 5);
    
    ListDouble<int> list2 = create<int>(), list3 = 3;
    F<int>(2);

    list.output();
    list.reserveout();
    list2.output();
    list3.output();

    system("pause");
    return 0;
}