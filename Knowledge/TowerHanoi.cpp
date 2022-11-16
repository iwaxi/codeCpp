#include<iostream>
using namespace std;

// Tower Hanoi by iwaxi_dy 2022/11/16
static long long number = 0;

void hanoi(int n, char from, char by, char to){
    if(n <= 1){
        cout << "move number " << n << " from " << from << " to " << to << endl;
        number ++;      // move single one lastly
    }
    else{
        hanoi(n - 1, from, to, by);  // move (n - 1) from (from) to (by), with (to)
        cout << "move number " << n << " from " << from << " to " << to << endl;
        number ++;                   // move    n    from (from) to (to), with (by)
        hanoi(n - 1, by, from, to);  // move (n - 1) from (by) to (to), with (from)
    }
}

int main()
{
    int n = 0;
    cout << "Input tower number: ";
    cin >> n;
    hanoi(n, 'a', 'b', 'c');
    cout << "\nTotal Move Number: " << number << endl;
    system("pause");
    return 0;
}