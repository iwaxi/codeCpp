#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int nega = 0, posi = 0, zero = 0;
    while(num)
    {
        double number = 0;
        for(int i = 0; i < num; i++)
        {
            cin >> number;
            bool Negative = (number < 0);
            bool Positive = (number > 0);
            bool Zero = (number == 0);
            if(Negative)
                nega++;
            else if(Positive)
                posi++;
            else if(Zero)
                zero++;
        }
        cout << nega <<" "<< zero <<" "<< posi <<endl;
        nega = 0, posi = 0, zero = 0;
        cin >> num;
    }
    system("pause");
    return 0;
}