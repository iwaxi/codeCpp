#ifndef ListNode_h
#define ListNode_h

typedef int Status;
typedef int ElemType;
#define No unsigned(-1)
#define Yes 1

class ListNode
{
public:
    ElemType value;
    ListNode* next;
    static int size;
    int index;

    ListNode(ElemType, ListNode*);          // construct
    void output();                          // output
    unsigned delMember(int);                // delete a member
    unsigned insertMemeber(int, ElemType);  // insert a member
    int searchValue(ElemType);              // search by value
    ElemType searchIndex(int);              // search by index
    void clear();                           // clear the List
};
#endif