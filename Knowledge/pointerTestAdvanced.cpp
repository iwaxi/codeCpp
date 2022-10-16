#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
// test pointer*
using namespace std;
int main()
{
// column pointer
    int a[5][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int (*p) [3] = a;
    cout << sizeof(a) << " " << sizeof(p) << " " << sizeof(*p) << " " << *p << " " << **(p + 1)  << " " << *(a[1]) << endl;
    /* output: 60 (array_size)  4 (default_address_size)  12(one row)  0x(a[0]_address_value)  4(*a[1])      4(a[1][0]) */

// heap: new & delete
    int b = 10;
    int *int_p = new int(0);
    int *pp = &b; // address
    cout << int_p << " " << *int_p << endl;
    *int_p = b; // only value
    (*int_p) ++;
    cout << int_p << " " << &b << " " << *int_p << " " << b << endl;
    (*pp) ++;
    cout << pp << " " << &b << " " << *pp << " " << b << endl;
    delete int_p;
    cout << int_p << " " << *int_p << endl;
    int_p = NULL; // to avoid illegally visit 

    int *num = new int[10];
    for(int i = 0; i < 10; i++)
        cout << *(num + i) << " ";
    cout << endl;
    
    system("pause");
    return 0;
}