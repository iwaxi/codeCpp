#include<iostream>
using namespace std;

class myString
{
private:
    char* str;
    int len;
public:
    myString(const char* ch){
        len = 0;
        for(char* p = (char*)ch; *p; p++)
            len ++;
        str = new char[len]{};
        for(int i = 0; i < len; i++)
            str[i] = ch[i];
    }
    int length(){
        return len;
    }
    int find(const char* find_str){
        int str_len = 0;
        for(char* p = (char*)find_str; *p; p++)
            str_len ++;
        if(len < str_len)
            return -1;
        else{
            for(int i = 0; i < len; i++){
                if(str[i] == find_str[0]){
                    bool isFind = 1;
                    for(int j = 0; j < str_len; j++){
                        if(str[i + j] != find_str[j]){
                            isFind = 0;
                            break;
                        }
                    }
                    if(isFind)
                        return i;
                }
            }
        }
        return -1;
    }
    ~myString(){
        if(str) delete[] str;
        len = 0;
    }
};

int main()
{
    string str;
    cin >> str;
    myString mystr(str.c_str());
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m = 0;
        cin >> m;
        switch (m){
            case 1: cout << mystr.length() << endl; break;
            case 2:{
                string str_find;    cin >> str_find;
                cout << mystr.find(str_find.c_str()) << endl;
            } break;
        }
    }
    system("pause");
    return 0;
}