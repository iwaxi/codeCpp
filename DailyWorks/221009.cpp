#include<iostream>

using namespace std;

int* swap(int s[],int size)
{
    int *left = s;
    int templeft = 0;
    int tempright = 0;
    int *right = & s[size - 1];
    for(int i = 0; left < right; i++)
    {
        tempright = * right;
        right --;
        templeft = * left;
        left++;
        s[i] = tempright;
        s[size - i - 1] = templeft;
        
    }
    return s;
}

    
void out(int* p, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << *(p + i) << " ";
    }   
}

int main()
{
    int list[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(list) / sizeof(*list);
    int *list_p = swap(list , n);
    out(list_p, n);
    system("pause");
    return 0;
} 