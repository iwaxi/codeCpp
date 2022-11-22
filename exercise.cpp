#include<iostream>
using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    bool isPrime[10001] = {};
    for(int i = 0; i < 10001; i++)
        isPrime[i] = 1;
    for(int i = 2; i < 10001; i++){
        if(isPrime[i]){
            for(int j = 2; i * j < 10001; j++)
                isPrime[i * j] = 0;
            }
    }

    for(int i = 0; i < n; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        int number = 0;
        for(int j = a; j <= b; j++){
            if(!isPrime[j]){
                int sum = 0;
                for(int k = 1; k < j; k++){
                    if(j % k == 0) sum += k;
                    if(sum > j) break;}
                if(sum == j) number ++;
                }
        }
        cout << number << endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

void mySwap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int dice[6] = {};
    for(int i = 0; i < 6; i++){
        cin >> dice[i];
    }
    char s[200] = {};
    cin >> s;
    for(char* p = s; *p; p++){
        if(*p == 'E'){
            mySwap(&dice[0], &dice[3]);
            mySwap(&dice[2], &dice[3]);
            mySwap(&dice[5], &dice[3]);
        }
        else if(*p == 'W'){
            mySwap(&dice[3], &dice[0]);
            mySwap(&dice[5], &dice[0]);
            mySwap(&dice[2], &dice[0]);
        }
        else if(*p == 'S'){
            mySwap(&dice[1], &dice[5]);
            mySwap(&dice[1], &dice[4]);
            mySwap(&dice[1], &dice[0]);
        }
        else if(*p == 'N'){
            mySwap(&dice[0], &dice[4]);
            mySwap(&dice[0], &dice[5]);
            mySwap(&dice[0], &dice[1]);
        }
    }
    cout << dice[0] << endl;
    return 0;
}

