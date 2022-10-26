#include<iostream>
using namespace std;

int main()
{
    const int length = 1500;
    int Prime[length] = {};  // Euler  
    for(int i = 0; i < length; i++)
        Prime[i] = i + 1;
    for(int i = 0; i < length / 2; i++){
        if(Prime[i] >= 2){
            for(int j = 2; j <= length / Prime[i]; j++)
                Prime[(Prime[i] * j) - 1] = 0;
        }}
    int n = 0;
    cin >> n;
    int sum = 0, num = 0;
    for(int i = 1; i < length; i++){
        sum += Prime[i];
        if(sum > n)
            break;
        if(Prime[i] >= 2){    
            cout << Prime[i] << endl;
            num ++;
        }}
    cout << num << endl;
    system("pause");
    return 0;
}