#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int base = 0;
    cin >> base;
    string num1, num2, outcome;
    cin >> num1 >> num2;
    int length1 = num1.length(), length2 = num2.length();
    int length = min(length1, length2);
    int add = 0;
    for(int i = 0; i < length; i++)
    {
        int a = isdigit(num1[length1 - i -1]) ?  num1[length1 - i -1] - '0' + add: num1[length1 - i -1] - 'a' + 10 + add;
        int b = isdigit(num2[length2 - i -1]) ?  num2[length2 - i -1] - '0': num2[length2 - i -1] - 'a' + 10;
        int sum = a + b;
        add = int(sum >= base);
        sum = (add) ? sum - base : sum;
        char out = (sum > 9) ? char('a' + sum - 10) : char('0' + sum);
        outcome.append(1, out);
    }
    if(length1 - length2 > 0)
    {
        for(int i = length; i < length1; i++)
        {
            int sum = isdigit(num1[length1 - i -1]) ?  num1[length1 - i -1] - '0' + add: num1[length1 - i -1] - 'a' + 10 + add;
            add = int(sum >= base);
            sum = (add) ? sum - base : sum;
            char out = (sum > 9) ? char('a' + sum - 10) : char('0' + sum);
            outcome.append(1, out);
        }
        if(add)
            outcome.append(1, '1');
    }
    else if(length1 - length2 < 0)
    {
        for(int i = length; i < length2; i++)
        {
            int sum = isdigit(num2[length2 - i -1]) ?  num2[length2 - i -1] - '0' + add: num2[length2 - i -1] - 'a' + 10 + add;
            add = int(sum >= base);
            sum = (add) ? sum - base : sum;
            char out = (sum > 9) ? char('a' + sum - 10) : char('0' + sum);
            outcome.append(1, out);
        }
        if(add)
            outcome.append(1, '1');
    }
    else
    {
        if(add)
            outcome.append(1, '1');
    }
    string answer;
    for(size_t i = 0; i < outcome.length(); i++)
    {
        answer.append(1, outcome[outcome.length() - i - 1]);
    }
    cout << answer << endl;
    system("pause");
    return 0;

}