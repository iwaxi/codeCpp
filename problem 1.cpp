#include<iostream>
#include<cmath>
using namespace std;

void in(char a[], int Size)
{
    for(int i = 0; i < Size; i++)
        cin >> a[i];
}

bool judge(char a[])
{
    bool i = int(a[0] - '0') && int(a[1] - '0') && int(a[2] - '0');
    return i;
}

void out(char a[],int Size)
{
    for(int i = 0; i < Size; i++)
        cout<< a[i] <<" ";
    cout<<endl;
}
void trans(char list1[], char list2[], int Size)
{
    for(int i = 0, j = Size - 1; i < Size, j >= 0; i++, j--)
        list2[j] = list1[i];
}
int main()
{
    const int Size = 3;
    char a[Size] = {};
    char b[Size] = {};
    in(a, Size);
    while(judge(a) )
    {
        char ch = '0';

        for(int i = 0; i < Size; i++)
        {    
            for(int j = i; j < Size; j++)
                if(ch < a[j])
                {
                    ch = a[i];
                    a[i] = a[j];
                    a[j] = ch;
                    ch = a[i];
                }
            ch = '0';
        }
        trans(a,b,Size);
        out(b,Size);
        in(a,Size);
    }
    system("pause");
    return 0;
}
