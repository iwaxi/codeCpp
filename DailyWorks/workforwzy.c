#include<stdio.h>

int main()
{
    int number[10][10] = {};
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    for( ; i < n; i++)
        number[0][i] = i + 1; // row 1
 
    int turn = 1;
    int row = 1, column = n - 1;
    while(turn <= 2 * (n - 1)){
        int arc = turn / 4;
        switch (turn % 4)
        {
        case 1:
            for(int j = row; j < n - arc; j++){     // from up to down
                number[j][column] = i + 1;
                i ++;
            }
            row = n - arc - 1;
            column --;
            turn ++;
            break;
        case 2:
            for(int j = column; j > arc - 1; j--){  // from right to left
                number[row][j] = i + 1;
                i++;
            }
            row --;
            column = arc;
            turn ++;
            break;
        case 3:
            for(int j = row; j > arc; j--){          // from down to up
                number[j][column] = i + 1;
                i ++;
            }
            column ++;
            row = arc + 1;
            turn ++;
            break;
        case 0:
            for(int j = column; j < n - arc; j++){      // from left to right
                number[row][j] = i + 1;
                i ++;
            }
            row ++;
            column = n - arc - 1;
            turn ++;
            break;
        }   
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != n - 1 || j != n - 1)
                printf("%2d ", number[i][j]);
            else
                printf("%2d", number[i][j]);
        }
        printf("\n");
    }
    return 0;
}