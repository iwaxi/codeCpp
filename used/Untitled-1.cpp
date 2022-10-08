#include <iostream>
 
using namespace std;
 
int main()
{
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x = i;
        if(x % 3 == 0)
            cout << " " << i;
        else if(x % 10 == 3)
            cout << " " << i;
        else
        {
            x /= 10;
            while(x)
            {
                if(x % 10 == 3)
                {
                    cout << " " << i;
                    break;
                }
                else
                    x /= 10;
            }
        }
    }
    system("pause");
    return 0;
}
 