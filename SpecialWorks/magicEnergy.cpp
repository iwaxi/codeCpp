#include<iostream>
using namespace std;

// magic energy by iwaxi_dy 22/10/15
int main()
{
    long long n = 0;
    cin >> n;
    long long* magic = new long long[n];
    long long* magic_s = new long long [n];
    long long circle = 0; 
    long long length = 0;

    for(long long i = 0; i < n; i++)
    {
        cin >> length;
        circle += length;
        magic[i] = length;
        magic_s[i] = circle;
    }

    long long *left = magic, *right = 0;
    long long right_i = 0;
    long long distance = 0;
    long long point = 0, energy = 0;
    long long per = circle / 2;

    if(circle % 2 != 0)
        cout << energy << endl;
    else
    {
        for(long long i = 0; i < n; i++)
        {
            if(magic_s[i] >= per)
            {
                right = magic + i;
                distance = magic_s[i] - per;
                right_i = i;
                break;
            }
        }
        // be careful of the diffenrence between left and right! (according to index)
        while(left - magic <= right_i && right - magic <= n)
        {
            if(distance == 0)
            {
                point ++;
                distance -= *left;   // left : add then move
                left ++;
            }
            else if(distance > 0)
            {
                distance -= *left;
                left ++;
            }
            else if(distance < 0)
            {
                right ++;
                distance += *right; // right : move then add
            }
        }
    energy = (point > 0) ? (point * (point - 1) / 2) : 0;
    cout << energy << endl;
    }
    delete[] magic, magic_s;
    system("pause");
    return 0;
}