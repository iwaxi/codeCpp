#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1, str2;
    //char * str1 = new char[10];
    const char * key = "WXYZABCDEFGHIJKLMNOPQRSTUV"; // code password
    cin >> str1 >> str2;
    for(const char *s = str1.c_str(); *s; s++) // pointer s
    {
        *(char*)s = key[*s - 'A'];
    }
    for(auto &p: str2) // auto 
    {
        p = key[p - 'A'];
    }
    cout << string::npos << endl;
    cout << str1 << endl << str2 << endl;
    system("pause");
    return 0;
}
