#include<iostream>
#include<cstring>
using namespace std;

class MyString
{
public:
    MyString(){
        s = nullptr; n = 0;
    }
    MyString(const char* a): s(0), n(0){
        n = strlen(a);
        s = new char[n + 1]{};
        strcpy(s, a);
    }
    MyString(const MyString& str): s(0), n(0){
        n = strlen(str.s);
        s = new char[n + 1]{};
        strcpy(s, str.s);
    }
    ~MyString(){
        if(s)
            delete[] s;
        s = nullptr; n = 0;
    }
    friend ostream& operator<<(ostream& o, const MyString str){
        return o << str.s; 
    }
private:
    char* s;
    int n;
};

int main(){
    MyString str1 = "ABCD";
    MyString str2 = str1;
    cout << str1;
    system("pause");
    return 0;
}