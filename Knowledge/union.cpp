#include <iostream>
using namespace std;

union code
{
    short a[2]; // 2 * 2 Bytes
    int b; // 4 Bytes
};

int main()
{
    code x;
    x.b = 0;
    cout << x.a[0] << " " << x.a[1] << " " << x.b << endl; //  0 0 0    

    x.a[0] = -1;
    cout << x.a[0] << " " << x.a[1] << " " << x.b << endl; // -1 0 65535

    x.b ++;
    cout << x.a[0] << " " << x.a[1] << " " << x.b << endl; //  0 1 65536
    // a[i] read from tail to head, and data is saved as 2-complement.
                                                                     
    system("pause");
    return 0;
}
