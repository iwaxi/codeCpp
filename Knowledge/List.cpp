#include<iostream>
using namespace std;

// ListNode by iwaxi_dy
// 2022/10/29

typedef int Status;   // Temporarily useless
typedef int ElemType; // Datatype of elements, can be changed
#define No unsigned(-1)
#define Yes 1

class ListNode
{
public:
    ElemType value;                         //datafield
    ListNode* next;
    static int size;
    int index;

    ListNode(ElemType, ListNode*);          // construct
    void output();                          // output
    unsigned delMember(int);                // delete a member
    unsigned insertMemeber(int, ElemType);  // insert a member
    int searchValue(ElemType);              // search by value
    ElemType searchIndex(int);              // search by index
    unsigned changeMember(int, ElemType);   // change a member
    void clear();                           // clear the List
};

ListNode::ListNode(ElemType newValue, ListNode* newNext = nullptr){
    value = newValue;
    next = newNext;
    index = next != nullptr ? (next->index) + 1 : 0;
    size ++;
}

void ListNode::output(){
    ListNode* ptr = this;
    if(size == 0)
        return;
    if(ptr != nullptr){
        ptr->next->output();
        cout << "element " << ptr->index << ": " << ptr->value << "\n";
    }
    else
        return;
    if(ptr->index == size - 1)
        cout << "The size of List is " << size << endl;
}

unsigned ListNode::delMember(int indexDel){
    ListNode* ptr = this;
    if(indexDel >= size || indexDel < 0)
        return No;
    else if(size == 1){
        size = 0;
        return Yes;
    }
    else if(indexDel == size - 1)
        *this = *ptr->next;
    else{
        for( ; ptr->index > indexDel; ptr = ptr->next){
            if(ptr->index == indexDel + 1)
                ptr->next = ptr->next->next;
            ptr->index --;
            if(ptr->next == nullptr)
                break;
        }
    }
    size --;
    return Yes;
}

unsigned ListNode::insertMemeber(int indexInsert, ElemType newValue){
    ListNode* ptr = this;
    if(indexInsert > size)
        return No;
    if(indexInsert == size)
        return 0;
    for( ; ptr != nullptr; ptr = ptr->next){
        if(ptr->index == indexInsert){
            ListNode* newlist = new ListNode(newValue, ptr->next);
            ptr->next = newlist;
            ptr->index ++;
            return Yes;
        }
        ptr->index ++;
    }
    return Yes;
}

int ListNode::searchValue(ElemType Value_to_Find){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ptr = ptr->next)
        if(ptr->value == Value_to_Find)
            return ptr->index;
    return No;
}

ElemType ListNode::searchIndex(int Index_to_Find){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ptr = ptr->next)
        if(ptr->index == Index_to_Find)
            return ptr->value;
    return No;
}

unsigned ListNode::changeMember(int Index_to_change, ElemType newValue){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ptr = ptr->next)
        if(ptr->index == Index_to_change){
            ptr->value = newValue;
            return Yes;
        }
    return No;
}

void ListNode::clear(){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ){
        ListNode* r = ptr;
        ptr = ptr->next;
        delete r;
        size --;
    }
}

int ListNode::size = 0;

int main()
{
    cout << "Welcome to the ListNode by iwaxi_dy.\n\n";
    ListNode* numberList = nullptr;
    int number = 0;
    int n = 0; // length
    cout << "Input size of List: ";
    cin >> n;
    cout << "\nNow you can fill the List, input 114514 to exit any time.\n";
    cout << "tips: Default datatype is integer, if need, you can change element type in line 8.\n\n";
    for(int i = 0; i < n; i++){
        cout << "Input element " << i << " : ";
        cin >> number;
        if(number == 114514)
            break;
        numberList = new ListNode(number, numberList);
    }
    
    cout << "\nThe List has been created.\n   Press 1 to output.\n   Press 2 to delete a member.\n";  
    cout << "   Press 3 to insert a new member.\n   Press 4 to search by value.\n   Press 5 to search by index.\n";
    cout << "   Press 6 to change a member.\n";
    cout << "   Press 0 to exit\nWarning: Remember Not To Enter ANY Character!\n\nInput: ";
    int key = 0;
    while(cin >> key, key){
        if(numberList == nullptr || numberList->size == 0){
            cout << "Oh, it seems like you have created a zero-length List, so cool.\n  BUT I HAVE TO KILL IT!!!\n";
            cout << "  Error: 0-length List is illegal.\n";
            system("pause");
            return 0;
        }
        switch (key){
        case 1: numberList->output();break;

        case 2:{
            int indexDel = 0; 
            cout << "Input the index to be deleted: ";  
            cin >> indexDel;
            numberList->delMember(indexDel) == Yes ? cout << " Delete successfully.\n" : cout << " Error: Invalid index.\n";
        } break;

        case 3:{
            int indexInsert = 0; ElemType newValue = 0;
            cout << "Input the insertIndex and newValue: ";
            cin >> indexInsert >> newValue;
            if(numberList->insertMemeber(indexInsert, newValue) == Yes)
                cout << " Insert successfully.\n";
            else if(numberList->insertMemeber(indexInsert, newValue) == 0){
                numberList = new ListNode(newValue, numberList);
                cout << " Insert successfully.\n";
            }
            else
                cout << " Error: Invalid index.\n";
        } break;

        case 4:{
            ElemType Value_to_Find = 0;
            cout << "Input the value to search: ";  cin >> Value_to_Find;
            if(numberList->searchValue(Value_to_Find) != (int)No)
                cout << "The position of value " << Value_to_Find << " is " << numberList->searchValue(Value_to_Find) << endl;
            else
                cout << " Nops = No position to find.\n";
        } break;

        case 5:{
            int Index_to_Find = 0;
            cout << "Input the index to search: "; 
            cin >> Index_to_Find;
            if(numberList->searchIndex(Index_to_Find) != (int)No)
                cout << "The value of index " << Index_to_Find << " is " << numberList->searchIndex(Index_to_Find) << endl;
            else
                cout << " Error: Invalid index.\n";
        } break;
        
        case 6:{
            int Index_to_change = 0, newValue = 0;
            cout << "Input the index to change and new value: ";
            cin >> Index_to_change >> newValue;
            numberList->changeMember(Index_to_change, newValue) == Yes ? cout << "Change successfully.\n" : cout << " Error: Invalid index.\n";
        }break;

        default: cout << " Error: Invalid operation.\n";  break;
        }
        cout << "\nNext? Input: ";
    }
    numberList->clear();
    numberList = nullptr;
    cout << "Exit safely.\n";
    system("pause");
    return 0;
}