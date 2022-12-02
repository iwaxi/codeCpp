#include<iostream>
using namespace std;
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int* Data = new int[n]{};
    for(int i = 0; i < 3 * m + 1; i++){
        int a = 0;
        cin >> a;
        if(a >= 1 && a <= n) Data[a - 1]++;
    }
    int* Copy = new int[n]{};
    int index = 0;
    int* ans = new int[n]{};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            Copy[j] = Data[j];
        Copy[i] ++;
        for(int j = 0; j < n; j++){
            bool judge = true;
            if(Copy[j] >= 2) 
                Copy[j] -= 2;
            else
                continue;
            for(int k = 0; k < n && judge; k++){
                while(Copy[k]){
                    if(Copy[k] >= 3){
                        Copy[k] -= 3;
                    }
                    else if(k + 2 < n && Copy[k] > 0 && Copy[k + 1] > 0 && Copy[k + 2] > 0){
                        Copy[k] --;
                        Copy[k + 1] --;
                        Copy[k + 2] --;
                    }
                    else{
                        judge = false;
                        break;
                    }
                }
            }
            for(int k = 0; k < n; k++)
                Copy[k] = Data[k];
            Copy[i] ++;
            if(judge){
                ans[index++] = i + 1;
                break;
            }
        }
    }
    if(index){
        for(int i = 0; i < index; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
    delete[] Data;
    delete[] Copy;
    system("pause");
    return 0;
}