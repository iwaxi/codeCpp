#include<iostream>
using namespace std;

// K-M-P algorithm in str comparison

int kmp[10001][26] = {};

void setKmp(string cmp){
    // _init_
    kmp[0][cmp[0] - 'a'] = 1;
    int prefix = 0;

    // build as dp
    for(int i = 1; i < cmp.size(); i++){
        for(int j = 0; j < 26; j++){
            // for right key, get through
            if(j == cmp[i] - 'a') 
                kmp[i][j] = i + 1;
            // for wrong key, fix with prefix
            else
                kmp[i][j] = kmp[prefix][j];
        }
        // next_prefix = this_prefix & this_cmp
        prefix = kmp[prefix][cmp[i] - 'a'];
    }
}

int KMP(string str, string cmp){
    setKmp(cmp);
    int index = 0;
    for(int i = 0; i < str.size(); i++){
        index = kmp[index][str[i] - 'a'];
        if(index == cmp.size()) 
            return i + 1 - cmp.size();
    }
    return -1;
}

int main()
{
    system("pause");
    return 0;
}