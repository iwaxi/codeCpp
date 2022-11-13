#include<iostream>
using namespace std;

int main()
{
    typedef long long ll;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m = 0;
        cin >> m;
        ll* data = new ll[m + 1]{};
        for(int j = 1; j < m + 1; j++){
            cin >> data[j];
            data[j] += data[j - 1];
        }
        ll* each_min = new ll[m]{};
        int* each_min_index = new int[m]{};
        ll this_min = 0;
        int this_min_index = 1;
        for(int j = 0; j < m; j++){
            if(data[j] < this_min){
                this_min = data[j];
                this_min_index = j + 1;
            }
            each_min[j] = this_min;
            each_min_index[j] = this_min_index;
        }
        ll ans = data[1] - each_min[0];
        int max_index = 1, min_index = 1;
        for(int j = 1; j < m + 1; j++){
            if(data[j] - each_min[j - 1] > ans){
                ans = data[j] - each_min[j - 1];
                max_index = j;
                min_index = each_min_index[j - 1];
            }
        }
        cout << "Case " << i + 1 << ":" << endl;
        cout << ans << " " << min_index << " " << max_index;
        i == n - 1 ? cout << endl : cout << endl << endl;
        delete[] data, each_min, each_min_index;
    }
    system("pause");
    return 0;
}