#include<iostream>
using namespace std;

// A \to B, find the largest sum.
int main()
{
    int chart[9][9] = {};
    int n = 0, row = 0, col = 0, num = 0, index = 0;
    cin >> n;
    int *rows = new int[n * n], *columns = new int[n * n];
    while(cin >> row >> col >> num, row || col || num){
        chart[row][col] = num;
        rows[index] = row; columns[index] = col;
        index ++;
    }
    for(; ;){
        
    }
    system("pause");
    return 0;
}

/*for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        cout << chart[i][j] << " ";
    } @iwaxi
    cout << endl;
}*/