#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//just to calculate elements in a column
int main()
{
    int T = 0;
    cin >> T;
    double answer[200] = {};
    for(int k = 0; k < T; k++)
    {
        int m = 0, n = 0;
        cin >> m >> n;
        long long matrix [300][300] = {};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        for(int j = 0; j < n; j++)
        {
            long long sum = 0;
            for(int i = 0; i < m; i++)
            {
                sum += matrix[i][j];
                double number = static_cast <double> (matrix[i][j]);
                double value = sum / number;
                if(value >= answer[k])
                    answer[k] = value;
            }
        }
    }
    for(int i = 0; i < T; i++)
    {
        cout << fixed << setprecision(8) << answer[i] << endl;
    }
    system("pause");
    return 0;
}