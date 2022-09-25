#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<iomanip>
#include<string>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
//rebuild order for array
int main()
{
	const int ArraySize = 5;//can be changed simply
	int a[ArraySize] = {};//array
	for(int i = 0; i < ArraySize; i++)//input
		cin >> a[i];
	int order[ArraySize] = {};//order
	
	int min = 0;//Add minimum
	for(int t = 0; t < ArraySize; t++)
		{	
			if(min >= a[t])
				min = a[t]-1;
		}
	
	for(int n = 0; n < ArraySize; n++)//reload value
		order[n] = min;
	
	for(int i = 0; i < ArraySize; i++)//for order 
	{
		int b = 0;
		for(int j = 0; j < ArraySize; j++)//for array
		{
			if(order[i] <= a[j])//compare
			{
				order[i] = a[j];
				b = j;//VERY IMPORTANT
			}
		}
		a[b] = min;//clear the biggest number
	}
	
	for(int k = 0; k < ArraySize; k++)//output
		cout << order[k] <<" ";
	system("pause");
    return 0;
}
//2022/9/22 by iwaxi_dy