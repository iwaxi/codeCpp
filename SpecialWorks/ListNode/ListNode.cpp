#include"ListNode.h"
#include<iostream>
using namespace std;

int ListNode::size = 0;


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
}

ElemType ListNode::searchValue(ElemType Value_to_Find){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ptr = ptr->next)
        if(ptr->value == Value_to_Find)
            return ptr->index;
    return No;
}

int ListNode::searchIndex(int Index_to_Find){
    ListNode* ptr = this;
    for( ; ptr != nullptr; ptr = ptr->next)
        if(ptr->index == Index_to_Find)
            return ptr->value;
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
