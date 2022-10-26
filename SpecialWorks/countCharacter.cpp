#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
// count random character
int main()
{
    srand(time(0));
    int n = 0;
    cin >> n;
    int count[26] = {};
    char *s = new char[n] {};
    for(int i = 0; i < n; i++)
    {
        s[i] = 'a' + rand() % ('z' - 'a' + 1);
    }
    for( ; *s; s++)
    {
        count[*s - 'a'] ++;
    }
    
    for(int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << " : " << count[i] << endl;
    }
    delete[] s;
    system("pause");
    return 0;
}