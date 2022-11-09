#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class stack
{
public:
    T* data;
    int capacity;
    stack(): data(nullptr), head(-1), capacity(0){}
    stack(T* value): data(new T[sizeof(value) / sizeof(*value)]{}), head(sizeof(value) / sizeof(*value) - 1){
        capacity = head + 1;
        for(int i = 0; i <= head; i++)
            data[i] = value[i];
    }
    stack(stack& stackThis): data(new T[stackThis.head + 1]{}), head(stackThis.head){
        capacity = head + 1;
        for(int i = 0; i <= head; i++)
            data[i] = stackThis.data[i];
        sort(data,data + head);
    }

    bool check(){
        if(head + 2 <= capacity)
            return 1;
        else
            return 0;
    }
};

int main()
{

}