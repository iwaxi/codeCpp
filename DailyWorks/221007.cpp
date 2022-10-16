#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
/*Ah, struct*/
typedef struct Student
{
    int Age;
    string Name;
};
/*Test for pointer & array*/
int main()
{
    typedef char* char_p;
    typedef long long long_long_double;
    typedef long long lbc;
    typedef void* void_p;
    char_p city[] = {"Beijing","Tianjin","Rizhao","Nanjing","Chongqing","Harbin"}, temp;
    int n = sizeof(city) / sizeof(*city);
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(*city[i] <= *city[j])
            {
                temp = city[i];
                city[i] = city[j];
                city[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << *(city+i) <<" ";
    }
    cout << "\n";

    Student s1 = { 20, "David"};
    Student s2;
    s2.Age = 18; s2.Name = "John";
    cout << s1.Age << " "<< s2.Name << endl;
    system("pause");
    return 0;
}