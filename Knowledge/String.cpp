#include<iostream>
#include<string> //string head
#include<cstring>
#include<sstream> //stringstream
#include<algorithm>
//test string
using namespace std;
int main()
{    
    
    char ch[] = "All in all";
    string str(ch); // struct by C-string

    stringstream ss(str); // string stream
    string word;
    while(! ss.eof()) // print every word
    {
        ss >> word;
        cout << word << endl;
    }

    str.append(" no"); // append
    cout << str << endl;

    str.assign(20, 'A'); // assign
    cout << str << endl;

    str.clear(); // clear

    getline(cin,str); // getline
    
    cout << (str.find("oh") == string::npos) << endl; // find
    
    int  a[] = { 1 , 2 , 3};
    cout << max_element(a, a + 3) - a << endl;

    int *p = new int(4);
    cout << *p <<endl;
    delete p;
    p = nullptr;
    system("pause");
    return 0;
}