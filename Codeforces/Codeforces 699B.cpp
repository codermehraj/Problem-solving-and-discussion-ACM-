/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, y, mxx = 0, mxy = 0, k = 0;
	bool flag = 0;
	cin >> n >> m;
	char ar[n][m];
	map<int, int> row, col;
	// to store which row/col has how many walls
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
			if (ar[i][j] == '*')
			{
				row[i + 1]++; // calculating number of wall for each row
				col[j + 1]++; // calculating number of wall for each col
				k++; // how many walls?
				mxx = max(mxx, row[i + 1]); // storing maximum wall for a row
				mxy = max(mxy, col[j + 1]); // storing maximum wall for a col
			}
		}
	if (mxx + mxy < k)
	{
		// maximum row col cant even destroy k walls so ans=no
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> ar[i][j];
			if (ar[i][j] == '.' && row[i + 1] + col[j + 1] == k)
			{
				// if there is no wall in the cell
				// and the cell's row and col has combined k walls 
				// Then it is the ans
				flag = 1;
				x = i, y = j;
			}
			else if (ar[i][j] == '*' && k + 1 == row[i + 1] + col[j + 1])
			{
				// if there is wall in the cell
				// so in this cell there is 1 overlaping wall
				// we need total k+1 walls
				// thats why the cell's row and col has combined k+1 walls 
				// Then it is the ans
				flag = 1;
				x = i, y = j;
			}
		}
	if (flag)
	{
		cout << "YES\n"
			 << x + 1 << " " << y + 1 << endl;
	}
	else
		cout << "NO\n";
	return 0;
}
//fixed<<setprecision(1)
