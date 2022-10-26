#include<iostream>
using namespace std;

int base2(int n){
    if(n)
        return 2 * base2(n - 1);
    else    
        return 1;
}
int main()
{
    int n = 0;
    cin >> n;
    for(int k = 0; k < n; k ++){
        int data[4] = {};
        for(int i = 0; i < 4; i ++){
            char ch = 0;
            cin >> ch;
            data[i] = ch - 'a' + 1;
        }
        int base[4][8] = {{0, 1, 1},{0, 1, 1},{0, 1, 1},{0, 1, 1}};
        for(int i = 0; i < 4; i ++){
            int a = data[i];
            for(int j = 1; a; j ++){
                base[i][8 - j] = a % 2;
                a /= 2;
            }
        }
        long long sum = 0;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 8; j ++){
                sum += (base[3 - i][7 - j]) * base2(8 * i + j);
            }
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
}
 /*int chart[9][9] = {}, n = 0;
    cin >> n;
    int row = 0, column = 0, number = 0;
    while(cin >> row >> column >> number, row || column || number){
        chart[row][column] = number;
    }*/