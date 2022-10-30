#include<iostream>
#include<sstream>
#include<string>
#include<cctype>
#include<cstdio>
using namespace std;
// if + add
void judgePositive(string& equation, stringstream& ss, int& index_ch, int& index_num, size_t& i, char& unknow, bool& equal)
{
    int ch = 0, num = 0;
    if(isalpha(equation[i])){
            index_ch += equal ? 1 : -1;
            unknow = equation[i];
        }
    if(isdigit(equation[i])){
        for( ; isdigit(equation[i]); i++){
                ss << equation[i];
            }
        if(isalpha(equation[i])){
            ss >> ch;
            ss.clear();
            index_ch += equal ? ch : 0 - ch;
            unknow = equation[i];
        }
        else{
            ss >> num;
            ss.clear();
            index_num += equal? 0 - num : num;
        }
    }
}
// if - neg
void judgeNegtive(string& equation, stringstream& ss, int& index_ch, int& index_num, size_t& i, char& unknow, bool& equal)
{
    int ch = 0, num = 0;
    if(isalpha(equation[i])){
                index_ch += equal ? -1 : 1;
                unknow = equation[i];
            }
    else if(isdigit(equation[i])){
        for( ; isdigit(equation[i]); i++){
            ss << equation[i];
        }
        if(isalpha(equation[i])){
            ss >> ch;
            ss.clear();
            index_ch += equal ? 0 - ch : ch;
            unknow = equation[i];
        }
        else{
            ss >> num;
            ss.clear();
            index_num += equal ? num : 0 - num;
        }
    }
}
int main()
{
    string equation;
    cin >> equation;
    int index_ch = 0, index_num = 0;
    stringstream ss;
    char unknow = 0;
    bool equal = 1;
    for(size_t i = 0; i < equation.length(); i++)
    {
        judgePositive(equation, ss, index_ch, index_num, i, unknow, equal); // so many parameters w
        if(equation[i] == '+'){
            i++;
            judgePositive(equation, ss, index_ch, index_num, i, unknow, equal);
        }
        if(equation[i] == '-'){
            i++;
            judgeNegtive(equation, ss, index_ch, index_num, i, unknow, equal);
            }
        if(equation[i] == '='){
            equal = 0;
        }
    }
    double answer = 0;
    if(index_ch != 0 && index_num != 0)
        answer = static_cast <double>  (index_num) / static_cast <double>  (index_ch);
    printf("%c=%.3f\n",unknow,answer);
    return 0;
}