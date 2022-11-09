#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

template<typename T>
void QuickSort(T* data, int begin, int end){  // Quick Sort
    if(begin >= end)
        return;
    else{
        int random = rand() % (end - begin);  // random base(or key)
        T base = data[begin + random];
        int i = 0, j = end;
        while(true){
            while(data[i] <= base){           // left -> larger
                i ++;
                if(i >= end)
                    break;
            }
            while(data[j] >= base){           // right -> lesser
                j --;
                if(j <= begin)
                    break;
            }
            if(i >= j)                        // end compare
                break;
            T temp = data[i];                 // swap
            data[i] = data[j];
            data[j] = temp;
        }
        data[begin + random] = data[j];       // insert key into middle position
        data[j] = base;
        QuickSort(data, begin, j - 1);        // take apart
        QuickSort(data, j + 1, end);
    }
}

int main()
{
    srand(time(0));
    int a[] = {1, 55, 34, 484, 40, 1, -114514};
    char ch[] = {'a', 'b', '2', '\n'};
    QuickSort(a, 0, sizeof(a) / sizeof(*a) - 1);
    QuickSort(ch, 0, sizeof(ch) / sizeof(*ch) - 1);
    for(auto &p: a)
        cout << p << ' ';
    for(auto &p: ch)
        cout << p << ' ';
    cout << endl;
    system("pause");
    return 0;
}