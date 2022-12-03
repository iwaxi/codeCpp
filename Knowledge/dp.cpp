#include<iostream>
using namespace std;

const int Max = 100;
int Data[Max] = {};
int Sum[Max][1000] = {};
int n = 0;
// @iwaxi

// / return max in (a, b) \author{@iwaxi}
int myMax(int a, int b){
    return (a > b) ? a : b;
}
int times = 0;

// return maxSum
int SumMax(int i, int height){
    times++;
    if(Sum[i][height] != -1)
        return Sum[i][height];
    if(i == n - 1){
        if(Data[i] <= height) Sum[i][height] = 1;
        else Sum[i][height] = 0;
    }
    else{
        if(height >= Data[i]){
            int a = SumMax(i + 1, height);
            int b = SumMax(i + 1, Data[i]) + 1;
            Sum[i][height] = myMax(a, b);
        }
        else{
            Sum[i][height] = SumMax(i + 1, height);
        }
    }
    return Sum[i][height];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> Data[i];
        for(int j = 0; j < 1000; j++)
            Sum[i][j] = -1;
    }
    int maxHeight = Data[0];
    for(int i = 0; i < n; i++)
        maxHeight = (maxHeight < Data[i]) ? Data[i] : maxHeight;
    cout << SumMax(0, maxHeight) << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1000; j++){
            if(Sum[i][j] != -1) cout << Sum[i][j] << " " << j << endl;
        }
        cout << endl;
    }
    cout << endl <<  times << endl;
    system("pause");
    return 0;
}

// 8 389 207 155 300 299 170 158 65



/*
int myMax(int a, int b){
    return (a > b) ? a : b;
}
int times = 0;
int numPush(int* elem, int i, int N, int height){
    times ++;
    if(i == N - 1){
        if(height >= elem[i]){
            return 1;
        }
        else return 0;
    }
    else{
        if(height >= elem[i]){
          if((numPush(elem, i + 1, N, height) <= (numPush(elem, i + 1, N, elem[i])) + 1)){
                return numPush(elem, i + 1, N, elem[i]) + 1;
            }
            else
                return numPush(elem, i + 1, N, height);
            return myMax(numPush(elem, i + 1, N, height), numPush(elem, i + 1, N, elem[i]) + 1);
        }
        else
            return numPush(elem, i + 1, N, height);
    }
    
}
*/
/*int numNeed(int* elem, int N, int height){
    int number = 0, times = 1;
    number = numPush(elem, 0, N, height, -1);
    cout << number << endl;
    while(number < N - 1){
        number += numPush(elem, 0, N, height, -1);
        times ++;
    }
    return times;
}*/
/*
int main()
{
    int n = 0;
    cin >> n;
    int* data = new int[n]{};
    for(int i = 0; i < n; i++)
        cin >> data[i];
    int maxHeight = data[0];
    for(int i = 0; i < n; i++){
        if(maxHeight < data[i]) 
            maxHeight = data[i];
    }
    cout << numPush(data, 0, n, maxHeight) << endl;
    cout << times << endl;
    system("pause");
    return 0;
}
*/



/*int SumMax(int elem[100][100], int i, int j, int N){
    if(i == N - 1)
        return elem[i][j];
    else{
        return myMax(SumMax(elem, i + 1, j, N), SumMax(elem, i + 1, j + 1, N)) + elem[i][j];
    }
}*/