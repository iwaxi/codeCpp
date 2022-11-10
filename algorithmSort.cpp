#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Algorithm of Sort by iwaxi_dy 
// 2022/11/10

template<typename T>
void QuickSort(T* data, int begin, int end){    // Quick Sort
    if(begin >= end)
        return;
    else{
        int random = rand() % (end - begin + 1);// random base(or key)
        T base = data[begin + random];
        int i = 0, j = end;
        while(true){
            while(data[i] <= base){             // left -> larger
                i ++;
                if(i >= end)
                    break;
            }
            while(data[j] >= base){             // right -> lesser
                j --;
                if(j <= begin)
                    break;
            }
            if(i >= j)                          // end compare
                break;
            T temp = data[i];                   // swap
            data[i] = data[j];
            data[j] = temp;
        }
        data[begin + random] = data[j];         // insert key into middle position
        data[j] = base;
        QuickSort(data, begin, j - 1);          // take apart
        QuickSort(data, j + 1, end);
    }
}

template<typename T>
void MergeSort(T* array, int length){                           // Merge Sort
    T* a = array;                                               // def two pointers
    T* b = new T[length]{};                                     
    for(int seg = 1; seg < length; seg *= 2){                   // length of domain
        for(int start = 0; start < length; start += 2 * seg){   // sort start
            int begin = start, mid = min(start + seg, length),  // seperate domain
            end = min(start + 2 * seg, length);
            int k = begin;                                      
            int start1 = begin, end1 = mid;                     // left pointer
            int start2 = mid, end2 = end;                       // right pointer
            while(start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? 
                a[start1++] : a[start2++];
            while(start1 < end1)
                b[k++] = a[start1++];
            while(start2 < end2)
                b[k++] = a[start2++];
        }
        T* temp = a;                                            // swap a with b
        a = b;
        b = temp;
    }
    if(a != array){                                             // check outcome
        for(int i = 0; i < length; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

int main()
{
    srand(time(0));
    int a[] = {1, 55, 34, 484, 40, 1, -114514};
    char ch[] = {'a', 'b', '2', '\n'};
    QuickSort(a, 0, sizeof(a) / sizeof(*a) - 1);
    QuickSort(ch, 0, sizeof(ch) / sizeof(*ch) - 1);

    int b[] = {11, 22, 33, -114, -514, 12};
    MergeSort(b, sizeof(b) / sizeof(*b));

    for(auto &p: a)
        cout << p << ' ';
    for(auto &p: ch)
        cout << p << ' ';
    cout << endl;

    for(auto &p: b)
        cout << p << ' ';

    return 0;
}