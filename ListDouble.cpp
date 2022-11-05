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
    //NO!!!! IF YOU CAN NOT MAKE SURE, DO NOT WRITE YOUR OWN COPY OR DESTROY FUNCTION!!!!

    void insert(int, ElemType); // insert a new node
    void delNode(int);          // delete a node
    ListDouble<ElemType> copy();// create a different list-self-copy
    ListDouble<ElemType> operator+(ListDouble<ElemType>); // append two lists
    
    template<typename T>
    friend ostream& operator<<(ostream& o, ListDouble<T>);   // output


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
    cout << "Delete Successfully.\n";
}

template<typename ElemType>
void ListDouble<ElemType>::insert(int index_to_insert, ElemType newValue){
    try{
        if(index_to_insert > size || index_to_insert < 0)
            throw index_to_insert;
        else{
            LNode<ElemType>* New = new LNode<ElemType>;
            New->value = newValue;
            LNode<ElemType>* ptr = head->next;
            for(int i = 0; i < size; i++){
                if(i == index_to_insert){
                    New->prev = ptr->prev;  // in order!
                    ptr->prev->next = New;
                    ptr->prev = New;
                    New->next = ptr;
                    size ++;
                    return;
                }
                ptr = ptr->next;
            }
            tail->next = New;   // for tail only
            New->prev = tail;
            New->next = nullptr;
            tail = New;
            size ++;
            return;
        }
    }
    catch(int ex){
        cout << "Error, Invalid index_insert: " << ex << endl;
        return;
    }
}

template<typename ElemType>
void ListDouble<ElemType>::delNode(int index_to_del){
    try{
        if(index_to_del < 0 || index_to_del > size)
            throw index_to_del;
        else{
            LNode<ElemType> *ptr = head->next;
            for(int i = 0; i < size; i++){
                if(i == index_to_del){
                    ptr->prev->next = ptr->next;    // just that
                    ptr->next->prev = ptr->prev;
                    size --;
                    delete ptr;
                    ptr = nullptr;
                    return;
                }
                ptr = ptr->next;
            }
            tail = tail->prev;      // priority
            tail->next = nullptr;
            delete ptr;
            ptr = nullptr;
            size --;        // do not forget size
            return;
        }
    }
    catch(int ex){
        cout << "Error: Invalid index_delete: " << ex << endl;
        return;
    }
}

template<typename ElemType>
ListDouble<ElemType> ListDouble<ElemType>::copy(){
    LNode<ElemType> *ptrList = this->head->next, *New, *ptr;
    ListDouble<ElemType> list;

    list.head = new LNode<ElemType>;
    list.size = this->size;
    list.head->value = this->head->value;
    list.head->prev = list.head->next = nullptr;
    ptr = list.head;

    for( ; ptrList; ptrList = ptrList->next){
        New = new LNode<ElemType>;
        New->value = ptrList->value;
        New->prev = ptr;
        New->next = nullptr;

        ptr->next = New;
        ptr = New;
    }
    list.tail = ptr;
    return list;
}

template<typename ElemType>
ListDouble<ElemType> ListDouble<ElemType>::operator+(ListDouble<ElemType> list){
    ListDouble<ElemType> list1 = this->copy(), list2 = list.copy();
    list1.size += list2.size;
    list1.head->value = list1.size;
    list1.tail->next = list2.head->next;
    list2.head->next->prev = list1.tail;
    delete list2.head;
    list1.tail = list2.tail;
    return list1;
}

template<typename ElemType>
ostream& operator<<(ostream& o, ListDouble<ElemType> list){
    LNode<ElemType> *ptr = list.head->next;
    for( ; ptr; ptr = ptr->next)
        o << ptr->value << " ";
    o << "size: " << list.size << endl;
    return o;
}

// normal functions
template<typename ElemType>
ListDouble<ElemType> create(){
    ListDouble<ElemType> list1(5); // length-only
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
    
    ListDouble<int> list2 = create<int>(), list3 = 3;   // create & copy
    F<int>(2);          // stack object

    list.output();
    list.reserveout();

    cout << "\nInsert Test: \n";
    list.insert(5, 11);
    list.output();
    list.reserveout();

    cout << "\nDelete Test: \n";
    list.delNode(6);
    list.output();
    list.reserveout();

    cout << "\nCopy Test: \n";
    ListDouble<int> list4 = list.copy();
    list4.output();
    list4.reserveout();

    cout << "\nAppend Test: \n";
    ListDouble<int> list5 = list + list2;
    (list + list2).output();
    list5.output();
    list5.reserveout();

    cout << "\nOperator Test: \n";
    cout << list;

    cout << "\nOther Test: \n";
    list2.output();
    list3.output();

    system("pause");
    return 0;
}
