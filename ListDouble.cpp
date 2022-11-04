#include<iostream>
using namespace std;

// by iwaxi_dy 2022/11/4

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
    void insert(int, ElemType); // insert a new node 
private:
    LNode<ElemType> *head; // head
    LNode<ElemType> *tail; // tail
    int size;       // size

};


template<typename ElemType>         // default Construct
ListDouble<ElemType>::ListDouble(){
    size = 0;
    head = tail = nullptr;
}

template<typename ElemType>
ListDouble<ElemType>::ListDouble(ElemType* data, int n): size(0),head(0),tail(0){ // parameter Construct
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
ListDouble<ElemType>::ListDouble(int n): size(0),head(0),tail(0){ // parameter Construct
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
    cout << "size: " << size << endl;
}

template<typename ElemType>
void ListDouble<ElemType>::reserveout(){
    LNode<ElemType> *ptr = tail;
    for( ; ptr->prev; ptr = ptr->prev)
        cout << ptr->value << " ";
    cout << "size: " << size << endl;
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
    size = 0;
    cout << "Delete Successfully.\n";
}

template<typename ElemType>
void ListDouble<ElemType>::insert(int index_to_insert, ElemType newValue){
    try{
        if(index_to_insert > size || index_to_insert < 0){
            throw index_to_insert;
        }
        else{
            LNode<ElemType>* New = new LNode<ElemType>;
            New->value = newValue;
            LNode<ElemType>* ptr = head->next;
            for(int i = 0; i < size; i++){
                if(i == index_to_insert){
                    New->prev = ptr->prev;
                    ptr->prev->next = New;
                    ptr->prev = New;
                    New->next = ptr;
                    size ++;
                    return;
                }
                ptr = ptr->next;
            }
            tail->next = New;
            New->prev = tail;
            size ++;
            New->next = nullptr;
        }
    }
    catch(int ex){
        cout << "Error, Invalid index: " << ex << endl;
    }
}


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

    list.insert(5, 11);
    list.output();

    list2.output();
    list3.output();

    system("pause");
    return 0;
}
