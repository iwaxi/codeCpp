#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<string>
using namespace std;


int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a = 0;
        int v[6] = {};
        cin >> a;
        for(int j = 0; j < a; j++)
            cin >> v[j];
        int num =1, mul = 1;
        for(int j = 0; j < a; j++)
            {
                if(v[j] % 2 == 1)
                num = v[j];
                mul = mul * num;
            }
        cout << mul <<endl;
        mul = 1;
    }
    system("pause");
    return 0;
}