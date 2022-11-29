#ifndef __myStack
#define __myStack
template<typename ElemType>
class myStack
{
private:
    ElemType* elem;
    int sz;
    int space;
    void checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            ElemType* newElem = new ElemType[space]{};
            for(int i = 0; i < sz; i++)
                newElem[i] = elem[i];
            delete[] elem;
            elem = newElem;
        }
    }
public:
    myStack()
        :sz(0), space(16), elem(new ElemType[space]){}
    void push(ElemType data){
        checkSize();
        elem[sz++] = data;
    }
    ElemType get(){
        if(sz) return elem[sz - 1];
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