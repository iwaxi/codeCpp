#include<iostream>
using namespace std;

class myString
{
public:
    char* string;
    size_t length;
    myString(const char* ch){
        char* mystr = new char[100]{};
        length = 0;
        for(char* p = (char*)ch; *p ; p++){
            *(mystr + length) = *p;
            length ++;
        }
        mystr[length + 1] = 0;
        string = mystr;
    }
    size_t str_length(){
        return length;
    }
    int find(const char* str_to_find){
        bool find = 1;
        int str_length = sizeof(str_to_find) / sizeof(*str_to_find);
        for(size_t i = 0; i < length; i++){
            if(string[i] == *str_to_find){
                for(int j = 0; j < str_length && str_to_find[j] != 0; j++){
                    if(string[i + j] != str_to_find[j])
                        find = 0;   
                }
                if(find)    
                    return i;
            }
        }
        return -1;
    }
};
int main()
{
    char str[1000] = "";
    cin >> str;
    myString mystr(str);
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int number = 0;
        cin >> number;
        switch(number){
            case 1: cout << mystr.str_length() << endl; break;
            case 2:{
                char str_to_find[1000] = "";
                cin >> str_to_find;
                cout << mystr.find(str_to_find) << endl;
            }
            break;
        }
    }
    system("pause");
    return 0;
}
