#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// class and module 22/10/23

class package
{
public:
    int n;
    package();
    package(int);
    void input(); // if parameters in datafield, just ignore
    void output();
};
package::package()
    : n(114514) // Initializer List
    {
   
    }
package::package(int New_n)
{
    n = New_n;
}
void package::input()
{
    cin >> n; // useful in class pointer
}
void package::output()
{
    cout << n << endl;
}  

//module

template <typename T>
void sort(T list[], int size)
{
    for(int i = 0; i < size; i++)  // bubble sort
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(list[j] >= list[j + 1])
            {
                T swap = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swap;
            }
        }
    }
}
int main()
{
    int n = 0;
    cin >> n;
    int a[10] = {10, 2, 4, 3, 5, 6, 7, 8, 9, 1};
    sort(a, 10);
    int *p = a;
    for( ; (p - a) <= 9 ; p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    for(auto pp : a)
    {
        cout << pp << " ";
    }
    //
    cout << endl;
    package* ans = new package[n]{};
    for(int j = 0; j < n; j++)
    {
        (ans+j)->output();
    }
    delete[] ans;
    ans = NULL;
    system("pause");
    return 0;
}