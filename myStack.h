#ifndef __myStack
#define __myStack
template<typename ElemType>
class myStack
{
private:
    ElemType* elemStk;
    int sz;
    int space;
    void checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            ElemType* newElemStk = new ElemType[space]{};
            for(int i = 0; i < sz; i++)
                newElemStk[i] = elemStk[i];
            delete[] elemStk;
            elemStk = newElemStk;
        }
    }
public:
    myStack()
        :sz(0), space(16), elemStk(new ElemType[space]){}
    void push(ElemType data){
        checkSize();
        elemStk[sz++] = data;
    }
    ElemType get(){
        if(sz) return elemStk[sz - 1];
        else return 0;
    }
    void pop(){
        if(sz) sz--;
    }
    bool isEmpty(){
        return sz == 0;
    }
    ~myStack(){
        space = sz = 0;
    }
};
#endif