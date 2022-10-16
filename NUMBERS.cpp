#include<iostream>
#include<algorithm>
using namespace std;
 
void input(int *num, long long size)
{
    for(long long i = 0; i < size; i++)
    {
        cin >> *(num + i);
    }
}
void trans(int *num1, int *num2, long long size)
{
    for(long long i = 0; i < size; i++)
        num1[i] = num2[size - i - 1];
}

int main()
{
    long long n = 0, m = 0;
    cin >> n >> m;
    int *aat = new int[n];
    int *b = new int[m];
    int *aa = new int[n];
    input(aat, n);    input(b, m);
    long long nn = 0;
    for(long long i = 0; i < n; i++)
    {
        if(aat[i] < 0)
        {
            *(aa + nn) = 0 - aat[i]; // take negative apart from positive and 0
            nn ++;
            aat[i] = 1;
        }
    }
     
    sort(aat, aat + n);
     
    sort(aa,aa + nn);
     
    int *a = new int[n];
    trans(a, aat, n); // ALL ABOVE IS JUST SORTING(sigh)
     
    for(long long i = 0; i < nn; i++)
    {
        a[n - nn + i] = 0 - aa[i]; // add negative below
    }
     
    int *frequency = new int[m]; // number of strictly mucher
    for(long long i = 0; i < m; i++)
    {
        int *right = a + n - 1; // left & right
        int *left = a;
        long long length = right - left + 1;
        if(b[i] > a[0])
            frequency[i] = n;
        else if(b[i] <= a[n - 1])
            frequency[i] = 0;
        else
        {
            while(right - left > 1)
            {
                long long per = length / 2;
                left += (*(left + per) > b[i]) ? per : 0;
                right = (*(left + per) <= b[i]) ? left + per : right; // move
                length = right - left + 1;
            }
            frequency[i] = (*right == b[i]) ? n - (right - a) - 1 : n - (right - a); // if equal!!!
        } 
    }
    for(long long i = 0; i < m; i++)
    {
        cout << *(frequency + i) << " ";
    }
    delete[] a, b, frequency, aa, aat;
    cout << endl;
    system("pause");
    return 0;
}