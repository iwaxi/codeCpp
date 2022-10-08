#include<iostream>
using namespace std;

void ftoa(double f, char s[])
{
	int length = 0, point = 0;
	double g = f;
	const double EPSILON = 0.5;
	while(g - int(g) <= 1
	)
	{
		g = g *10;

		point++;
	}
	long long h = static_cast <long long> (g);
	long long t = static_cast <long long> (g);
	while(h >= 1)
	{
		h = (h - h % 10) / 10;

		length++;
	}
	for(int i = 0; i < length + 1; i++)
	{
		if(i == point)
			s[i] = '.';
		else
			{
				s[i] = char((t % 10) + int('0'));
				t = (t - t % 10) / 10;
			}
		
	}
	const int Size = length + 1;
	char a[Size] = "";
	for(int i = 0; i < Size; i++)
		a[i] = s[Size - i - 1];
	for(int i = 0; i < Size; i++)
		cout << a[i] << " ";
}

int main()
{
	double f = 0;
	cin >> f;

	double g = f;
	while(g - int(g) <= 1)
	{
		g = g * 10;
	
	}
	long long h = static_cast <long long> (g);
	int size = 0;
	while(h >= 10)
	{
		h = (h - h % 10) / 10;
	
		size++;
	}
	const int Size = size + 1;
	char str[Size] = " ";
	ftoa(f, str);
    system("pause");
	return 0;
}