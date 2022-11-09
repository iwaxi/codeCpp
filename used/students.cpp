#include<list>
#include<algorithm>
#include<iostream>

using namespace std;
int main()
{
    list<int> students = {1};
    int n = 0;
    cin >> n;
    for(int i = 1; i < n; i ++){
        int ID_find = 0;
        bool condition = 0;
        cin >> ID_find >> condition;
        if(condition)
            students.insert(find(students.begin(),students.end(), ID_find)++, i + 1);
        else
            students.insert(find(students.begin(),students.end(), ID_find), i + 1);
    }
    int m = 0;
    cin >> m;
    int *del = new int[n]{};
    for(int i = 0; i < m; i++){
        int ID_del;
        cin >> ID_del;
        if(!del[ID_del - 1]){
            students.erase(find(students.begin(),students.end(), ID_del));
            del[ID_del - 1] = 1;
        }
        else
            continue;
    }
    for(auto &p: students){
        if(p != students.back())
            cout << p << " ";
        else
            cout << p;
    }
    cout << endl;
    system("pause");
    return 0;
}