/* ~ CoderMehraJ ~ */
#include<bits/stdc++.h>
#define MAX 100

using namespace std;

unsigned long long arr[MAX + 3][MAX + 3];

void pascal(int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			//cout << arr[i][j] << " ";
		}
		//cout << endl;
	}
	return ;
}

int main()
{
	pascal(MAX);
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a << " things taken " << b << " at a time is " << arr[a][b] << " exactly.\n";
	}
	return 0;
}
