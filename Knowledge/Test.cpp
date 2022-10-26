#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
    vector <string> v{"Hello","World","from","Cpp","by","VScode"};
    for(auto &p : v){
        cout << p << " ";
    }
    size_t a = v.size();
    cout << "\n";
    system("pause");
    return 0;
}