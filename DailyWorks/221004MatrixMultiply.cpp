#include<iostream>
#include<cstring>

using namespace std;
void call(int n){
  int i = 1;
 CHECK_NUM:
  int x = i;
  if ( x % 3 == 0 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
 INCLUDE3:
  if ( x % 10 == 3 ){
    cout << " " << i;
    goto END_CHECK_NUM;
  }
  x /= 10;
  if ( x ) goto INCLUDE3;
 END_CHECK_NUM:
  if ( ++i <= n ) goto CHECK_NUM;

  cout << endl;
}//another function

void input( char s[], int size )
{
    int element = 0;
    for( int i = 0;i < size; i++ )
    {
        cin >> element;
        s[i] = char(element + '0');
    }
}
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    char A[20000] = "";
    char b[200] = "";
    int numA = n * m;
    input( A , numA );
    input( b , m );
    for( int i = 0; i < n; i++ )
    {
        long long mul = 0;
        for( int j = 0; j < m; j++ )
        {
            mul += int(A[m * i + j] - '0') * int(b[j] - '0');
        }
        cout << mul <<endl;
    }
    system("pause");
    return 0;
}

