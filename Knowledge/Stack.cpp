#include<iostream>
using namespace std;

template<typename T>
class stack
{
public:
    T* data;
    int head;
    int capacity;
    stack(): data(nullptr), head(-1), capacity(16){}
    stack(T* dataNew, size_t size): data(nullptr), head(-1), capacity(16){
        data = new T[capacity]{};
        for( ; head + 1 < size; ){
            checkSize();
            head ++;
            data[head] = dataNew[head];
        }
    }
    stack(stack& copy): data(nullptr), head(copy.head), capacity(copy.capacity){
        data = new T[capacity]{};
        for(int i = 0; i < head + 1; i++)
            data[i] = copy.data[i];
    }
    ~stack(){
        delete[] data;
        data = nullptr;
        head = -1; capacity = 0;
    }
    void push_back(T value){
        checkSize();
        data[++head] = value;
    }
    T pop_back(){
        return head >= 0 ? data[head--]: -10086;
    }
    T pop(){
        return head >= 0 ? data[head] : -10086;
    }
    bool empty(){
        return head == -1;
    }
    void checkSize(){
        if(head + 1 >= capacity){
            capacity *= 2;
            T* value = new T[capacity]{};
            for(int i = 0; i < head + 1; i++)
                value[i] = data[i];
            delete[] data;
            data = value;
        }
        return;
    }
};

template<typename T>
ostream& operator<<(ostream& o, stack<T>& Stk){
        for(int i = 0; i < Stk.head + 1; i++)
            o << Stk.data[i] << " ";
        return o;
    }

int main()
{
    int a[20] = {};
    for(auto &p : a)
        p = 10;
    char ch[] = {'a', 'b', 'c'};
    stack<char> stkChar(ch, sizeof(ch) / sizeof(*ch));
    stack<int> stkInt(a, sizeof(a) / sizeof(*a));
    cout << stkChar.empty() << "\n";
    cout << stkInt.pop() << "\n";
    stkInt.pop_back();
    stkInt.push_back(55);
    cout << stkInt << endl << stkChar << endl;
    return 0;
}