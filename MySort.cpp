#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// Algorithm of Sort by iwaxi_dy 
// 2022/11/10

// Swap two elements
template<typename T>
void Swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort
template<typename T>
void QuickSort(T* elem, int low, int high){            // Quick Sort(random)
    if(low >= high)                                    // high = length - 1 !!
        return;     // end Recursive
    int index = low + rand() % (high - low + 1);       // random index
    T key = elem[index];
    int left = low, right = high;
    while(true){
        for( ; right > index; right--){ // right for lesser
            if(elem[right] < key){
                Swap(elem + right, elem + index);
                index = right;                         // swap instead of insert
                break;
            }
        }
        for( ; left < index; left++){   // left for larger
            if(elem[left] > key){
                Swap(elem + left, elem + index);
                index = left;
                break;
            }
        }
        if(right == left)  // end loop
            break;
    } 
    
    QuickSort(elem, low, right - 1);
    QuickSort(elem, right + 1, high);
}
/*if(elem[right] > key)      // in case of no swap on side-point [useless]
        Swap(elem + index, elem + right);*/

// Merge Sort
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

// Select Sort
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

// Bubble Sort
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

// Binary Search
template<typename T>
int BinarySearch(T find, T* array, int len){
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(array[mid] == find)
            return mid;
        else if(array[mid] < find)
            left = mid + 1;
        else
            right = mid - 1; 
    }
    return -1;
}

// Insertion Sort
template<typename T>
void InsertSort(T* array, int len){
    for(int i = 1; i < len; i ++){
        T temp = array[i];
        int j = i - 1;
        for(; j >= 0 && array[j] > temp; j --)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
}   

// Shell Sort
template<typename T>
void ShellSort(T* data, int len){
    for(int gap = len / 2; gap > 0; gap >>= 1){
        for(int i = gap; i < len; i ++){    // Insert Sort
            T temp = data[i];   int j = i - gap;
            for( ; j >= 0 && data[j] > temp; j -= gap)
                data[j + gap] = data[j];
            data[j + gap] = temp;
        }
    }
}

// bulid max_heap
template<typename T>
void max_heap(T* data, int start, int end){           // build max_heap from start to end
    for(int i = start, j = 2 * i + 1; j < end; ){
        if(j + 1 < end && data[j + 1] > data[j])  // i refers to parent, j refers to children
            j ++;                                 // compare 2 children, get the max
        if(data[i] > data[j])                     
            return;                               // if built, return
        else{
            Swap(&data[i], &data[j]);             // else, swap
            i = j;                              
            j = 2 * i + 1;                        // update i & j
        }
    }
}

// Heap Sort
template<typename T>
void HeapSort(T* data, int len){
    for(int i = len / 2 - 1; i >= 0; i--)
        max_heap(data, i, len);                   // build max_heap from bottom to top
    for(int i = len - 1; i > 0; i--){
        Swap(&data[i], &data[0]);                 // swap last[i] with first[0]
        max_heap(data, 0, i);                     // rebuild max_heap, be care of bottom[i]!!!
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
    QuickSort(d, 0, sizeof(d) / sizeof(*d) - 1);

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
    cout << endl;

    int c[10] = {10, 9, 7, 5, -4, 5, 1, 3, 0, 14}; 
    /*for(int i = 0; i < 10; i++){
        c[i] = rand() % 100 - 50;
    }*/
    InsertSort(c, sizeof(c) / sizeof(*c));
    for(auto &p: c)
        cout << p << ' ';
    cout << "\nposition: " << BinarySearch(14, c, 10) << " " << BinarySearch(3, c, 10) << endl;;
    system("pause");
    return 0;
}
