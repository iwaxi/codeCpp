#include<iostream>
#include<cstring>
using namespace std;
int that(char num1[], char num2[], int len1, int len2){
    int base = 0;
    for(int i = 0; i < len2; i++){
        int number1 = num1[len1 - i - 1] - '0';
        int number2 = num2[len2 - i - 1] - '0';
        int number = number1 + number2 + base;
        num1[len1 - i - 1] = number < 10 ? number + '0' : number - 10 + '0';
        base = number < 10 ? 0 : 1;
    }
    return base;
}
void add(char num1[], char num2[], int len1, int len2){
    if(len1 == 1){
        cout << num1[0] - '0' + num2[0] - '0';
        return;
    }
    else if(that(num1, num2, len1, len2)){
            char ch[] = "1", num[1000] = "";
            strncpy(num, num1, len1- len2);
            add(num, ch, len1 - len2, 1);
            for(int i = len1 - len2; i < len1; i++)
                cout << num1[i];
    }
    else
        cout << num1;
}
int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        char num1[2000] = "", num2[2000] = "";
        cin >> num1 >> num2;        
        int len1 = strlen(num1), len2 = strlen(num2);
        cout << "Case " << i + 1 << ":"<< endl;
        cout << num1 << " + " << num2 << " = ";
        if(len1 > len2)
            add(num1, num2, len1, len2);
        else
            add(num2, num1, len2, len1);
        i == n - 1 ? cout << endl : cout << endl << endl;
    }
    system("pause");
    return 0;
}