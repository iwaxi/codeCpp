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
        int random = 0;                         // random base(or key) is BAD!
        T base = data[begin + random];
        int i = begin, j = end;
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
        for(int low = 0; low < length; low += 2 * seg){         // sort start
            int begin = low, mid = min(low + seg, length),      // seperate domain
            end = min(low + 2 * seg, length);
            int k = low;
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
    if(a != array){                                             // check out
        for(int i = 0; i < length; i++)                         // if b == array, swap
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}


template<typename T>
void QuickSort1(T* data, int low, int high){     // Quick Sort
    if(low >= high)                             
        return;                                 // end Recursion

    int index = low;
    T key = data[index];                        // compare base
    int left = low, right = high;
    while(true){
        for( ; left < high; left++){            // left  -> for larger
            if(data[left] > key)
                break;
        }
        for( ; right > low; right--){           // right -> for lesser
            if(data[right] < key)
                break;
        }
        if(left >= right)                       // end loop
            break;
        
        T temp = data[left];                    // swap
        data[left] = data[right];
        data[right] = temp;
    }

    data[index] = data[right];                  // insert key
    data[right] = key;

    QuickSort1(data, low, right - 1);            // Recursion
    QuickSort1(data, right + 1, high);
}


template<typename T>
void SelectSort(T* data, int len){
    for(int i = 0; i < len; i++){
        T temp = data[i]; int index = 0;
        for(int j = i; j < len; j++){
            if(temp <= data[j]){
                temp = data[j];
                index = j;
            }
        }
        T trans = data[i];
        data[i] = data[index];
        data[index] = trans;
    }
}


template<typename T>
void BubbleSort(T* data, int len){
    bool isSort = true;
    for(int i = 0; i < len && isSort; i++){
        isSort = false;
        for(int j = 0; j + 1 < len - i; j++){
            if(data[j] <= data[j + 1]){
                isSort = true;
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(0));
    
    int a[] = {1, 55, 34, 484, 40, 1, -114514};
    char ch[] = {'a', 'b', '2', '\n'};
    QuickSort(a, 0, sizeof(a) / sizeof(*a) - 1);    
    QuickSort(ch, 0, sizeof(ch) / sizeof(*ch) - 1);

    int d[20] = {};
    for(int i = 0; i < 20; i++){
        d[i] = rand() % 100 - 50;
    }    
    QuickSort1(d, 0, sizeof(d) / sizeof(*d) - 1);

    int b[20] = {};
    for(int i = 0; i < 20; i++){
        b[i] = rand() % 100;
    }
    MergeSort(b, sizeof(b) / sizeof(*b));

    for(auto &p: a)
        cout << p << ' ';
    cout << endl;
    for(auto &p: d)
        cout << p << ' ';
    cout << endl;

    for(auto &p: b)
        cout << p << ' ';

    system("pause");
    return 0;
}