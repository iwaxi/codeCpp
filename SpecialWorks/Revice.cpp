/*#include<iostream>
using namespace std;

int power(int n)
{
    if(n)
        return 2 * power(n - 1);
    else
        return 1;
}
int judge(int a, int b, int n)
{
    int return_a = n, return_b = n;
    for(int i = power(n); i > 0; i /= 2)
    {
        if(a % i != 0)
            return_a --;
        else
            break;
    }
    for(int i = power(n); i > 0; i /= 2)
    {
        if(b % i != 0)
            return_b --;
        else
            break;
    }
    return (return_a < return_b) ? return_a : return_b;
}
void erase(int **p, int m, int i, int j)
{
    for(int a = 0; a < power(m - 1); a++)
    {
        for(int b = 0; b < power(m - 1); b++)
            p[i + a][j + b] = 0;
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    int** p = new int* [power(n)];
    for(int i = 0; i < power(n); i++)
    {
        p[i] = new int [power(n)]{};
    }
    for(int i = 0; i < power(n); i++)
    {
        for(int j = 0; j < power(n); j++)
        {
            p[i][j] = 1;
        }
    }
    for(int i = 0; i < power(n); i += 2)
    {
        for(int j = 0; j < power(n); j += 2)
        {
            erase(p, judge(i, j ,n), i, j);
        }
    }
    for(int i = 0; i < power(n); i++)
    {
        for(int j = 0; j < power(n); j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    delete[] p;
    p = nullptr;
    system("pause");
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	int a = time(0);
    scanf("%d", &n);
	for(int i = 0; i < (1 << n); i++)
    {
		for(int j = 0; j < (1 << n); j++)
        {
			printf("%d ",(i | j) != ((1 << n) - 1)? 0 : 1);
        }
		printf("\n");
    }
    int b = time(0);
    cout << " time is " << b - a << endl;
    system("pause");
	return 0;
}