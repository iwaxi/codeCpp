#include<iostream>
using namespace std;

// DIY STL - Vector by iwaxi_dy
// 2022/11/10

template<typename T>
class vector
{
private:
    int sz;
    T* elem;
    int space;
public:
    vector(): sz(0), elem(new T[16]), space(16){}
    vector(int size): sz(size), elem(new T[2 * size]), space(2 * size){}
    vector(std::initializer_list<T> list): 
    sz{(int)list.size()}, elem{new T[2 * sz]{}}, space{2 * sz}{
        std::copy(list.begin(), list.end(), elem);
    }
    vector(const vector&);
    ~vector();

    void checkSize();
    void push_back(T);
    void set(T, int);
    T get(int);
    vector& operator=(const vector&);
    template<typename E>
    friend ostream& operator<<(ostream&, const vector<E>&);
    T& operator[](int);
};

template<typename T>
vector<T>::vector(const vector<T>& a):
sz(a.sz), elem(new T[a.space]), space(a.space){
    for(int i = 0; i < sz; i++)
        elem[i] = a.elem[i];
}
template<typename T>
vector<T>::~vector(){
    if(elem)
        delete[] elem;
    elem = nullptr;
    sz = space = 0;
    cout << "Delete.\n";
}
template<typename T>
void vector<T>::checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            T* New = new T[space]{};
            for(int i = 0; i < sz; i++)
                New[i] = elem[i];
            delete[] elem;
            elem = New;
        }
}
template<typename T>
void vector<T>::push_back(T data){
    checkSize();
    elem[sz++] = data; 
}
template<typename T>
void vector<T>::set(T data, int n){
    try{
        if(n >= sz)
            throw n;
        elem[n] = data;
    }
    catch(int ex){
        cout << "Error, Invalid index: " << ex << endl;
    }
}
template<typename T>
T vector<T>::get(int n){
    try{
        if(n >= sz)
            throw n;
        return elem[n];
    }
    catch(int ex){
        cout << "Error, Invalid index:  " << ex << endl;
        return NULL;
    }
}
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& a){
    T p = new T[a.space];
    sz = a.sz;  space = a.space;
    for(int i = 0; i < sz; i++)
        p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    return *this;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>& a){
    for(int i = 0; i < a.sz; i++)
        o << a.elem[i] << " ";
    return o << endl;
}
template<typename T>
T& vector<T>::operator[](int n){
    if(n < space)
        return elem[n];
    else
        cout << "Error: Invalid index." << endl;
    T* i = new T(0);
    return *i;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    cout << v;
    v.push_back(20);
    cout << v;
    v[25] = 10;
    cout << v[2] << endl;
    cout << v[20] << endl;
    vector<int> v1 = v;
    cout << v1;
    system("pause");
    return 0;
}