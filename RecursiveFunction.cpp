#include<iostream>//input/output stream
#include<cstdio>
#include<cstdlib>//rand
#include<cmath>//math
#include<ctime>
#include<string>//string
#include<cstring>//C-string
#include<cctype>
#include<iomanip>
#include<fstream>//file stream
#include<sstream>//string stream
#include<vector>//vector
#include<algorithm>//array_function

using namespace std;
//Recursive function 22/10/18 by iwaxi_dy
int trans(int n) // anti-order
{
    if(n)
    {
        cout << n % 10;
        trans(n / 10);
    }
    else
        return 0;
}

long long power(int a, int b) // a ** b
{
    if(b >= 1)
        return a * power(a, b - 1);
    else
        return 1;
}

int common(int a, int b) // the maximum common factor of a and b
{
    if(b)
        return common(b, a % b);
    else
        return a;
}

void print(int n)
{
    if(n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}

template<typename T>
void sort(T list[], int size) // bubble sort
{
    for(int i = 0; i < size; i++)  
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
    int a = 0;
    cin >> a;
    print(a);
    int number1 = 0, number2 = 0;
    cin >> number1 >> number2;
    long long pow = power(number1, number2);

    trans(number1);
    
    int com = common(number1, number2);
    cout << endl << com << endl;
    system("pause");
    return 0;
}