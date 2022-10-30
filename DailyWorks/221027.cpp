#include<iostream>
#include<string>
using namespace std;

class student
{
public:
    string name;
    int Chinese, Math, English;
    void getdata()
    {
        cin >> name >> Chinese >> Math >> English;
    }
    int total()
    {
        return Chinese + Math + English;
    }
    void print()
    {
        cout << name << " " << Chinese << " " << Math << " " << English << endl;
    }
};
int main()
{
    int n = 0;
    cin >> n;
    student* students = new student[n];
    int index = 0, max = 0;
    for(int i = 0; i < n; i++)
    {
        (students + i)->getdata();
        index = (max < (students + i)->total()) ? i : index;
        max = (max < (students + i)->total()) ? (students + i)->total() : max; // index then compare!
    }
    (students + index)->print();
    delete[] students;
    system("pause");
    return 0;
}