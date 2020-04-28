/* ~ CoderMehraJ ~ */
// UVa 10038 :: Jolly Jumpers

#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ekhn, agerta, x;
	bool hoise = 1, shuru = 0;
	vector<int> s;
	while (cin >> n)
	{
		shuru = 0;
		hoise = 1;
		agerta = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> ekhn;
			if (shuru)
				s.push_back(max(ekhn, agerta) - min(ekhn, agerta));
			else
				shuru = 1;
			agerta = ekhn;
		}
		sort(s.begin(), s.end());
		x = 1;
		for (auto y : s)
		{
			if (x != y)
			{
				hoise = 0;
			}
			x++;
		}
		if (hoise)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		s.clear();
	}
	return 0;
}
