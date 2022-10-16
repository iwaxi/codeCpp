#include<iostream>

using namespace std;
int main()
{
    typedef int * intPoint;//typedef
    intPoint p = nullptr;
    intPoint ppp = NULL;//NULL is a more C syntax
    int x = 0;
    int s[] = {1,2,3,4,5};
    intPoint s_point = s; // array is similar to a pointer
    char ss[] = {'a','b','d'};
    char* a[] = {"sap","c", ss};
    cout << *a <<" " <<*(a+1) << " " << *(a+2) <<endl;
    /*for( int i = 0; i < sizeof(s)/ sizeof(*s); i++)
    {
        cout << *s_point << " ";
        s_point ++;
    }      */ // to output an array 
    for(int i = 0; i < 5; i++)
    {
        cout << (s+i) <<endl;
    }
    int &c = x;//reference pass
    x++;
    cout << c << endl;
    cout << int(nullptr) <<endl;//use nullptr to initialize
    system("pause");
    return 0;
}