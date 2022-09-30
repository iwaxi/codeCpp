#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

void out(char s[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << s[i];
    }
    cout << "\n\n";
}
int main()
{
    const int size = 10;
    int m = 0, n = 0;
    char str[size] = "oh";
    cin.getline(str, size);
   
    out(str,size);
    for(int i = 0; i < size; i++)
    {
        if(str[i] == 32)
            str[i] = '0';
    }
    out(str,size);

    int a = strlen(str);
    cout << a <<"\n";
    for(int i = 0; i < a; i++)
    {
        for(int j = i + 1; j < a; j++) // (j = i + 1) is of VITAL SIGNIFICANCE!
        {
            if(str[i] == str[j])
                str[j] = '0';
        }
    }
    cout <<"\n";
    out(str,size);
    for(int i = 0; i < size; i++)
    {
        if(int(str[i] - '0') % 2 != 0)
        {
            m = int(str[i] - '0');
            n += m;
        }
    }
    cout << "The prime mul is = "<< n <<endl;
    system("pause");
    return 0;
}
