 #include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<fstream>
 #include<cmath>
 #include<ctime>
 #include<iomanip>
 #include<string>
 using namespace std;
 //array order by iwaxi_dy 2022/9/25
 void trans(const int list1[], int list2[], int Size)
 {
    for(int i = 0, j = Size - 1; i < Size, j >= 0; i++, j--)
        list2[j] = list1[i];
 }

 void in(int list[], int Size)
 {
    for(int i = 0; i < Size; i++)
        cin >> list[i];
 }

 void out(int list[], int Size)
 {
    for(int i = 0; i < Size; i++)
        cout << list[i] <<" ";
 }

 void miniu(int list[], int Size, int min)
 {
    for(int i = 0; i < Size; i++)
        list[i] = min;
 }

 int mini(int list[], int Size, int num)
 {
    for(int i = 0; i <Size; i++)
        if(num >= list[i])
            num = list[i] - 1;
    return num;
 }

 int main()
 {
    const int Size = 5;
    int list[Size] = {};
    in(list, Size);
    
    int orderhigh[Size] = {};
    int orderlow[Size] = {};
    
    int min = 0;
    min = mini(list, Size, min);
    miniu(orderhigh, Size, min);
    
    for(int i = 0; i < Size; i++)
    {
        int a = 0;
        for(int j = 0; j < Size; j++)
        {
            if(orderhigh[i] <= list[j])
            {
                orderhigh[i] = list[j];
                a = j;
            }
        }
        list[a] = min;
    }
    
    trans(orderhigh, orderlow, Size);
    out(orderhigh, Size);
    cout<<endl;
    out(orderlow, Size);
    system("pause");
    return 0;
 }