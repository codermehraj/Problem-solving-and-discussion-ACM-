/*
	Problem Name : Light OJ 1076 – Get the Containers
	Problem Link : http://www.lightoj.com/volume_showproblem.php?problem=1076

	This one is solvable by simple binary search...
	You just search in the range [0:999999999] and write a checking function
	The checking function will take a "x" and tells :
	if it is possible to pour all the milks with maximum capacity of "x"

*/

/* CoderMehRaj */
#include <bits/stdc++.h>

using namespace std;

vector<int> milks; // for storing the vessels informations
int n, m;

bool valid(int x)
{
    int need = 1, used = 0;
    for (auto a_vessel : milks)
    {
        if (a_vessel > x)
            return 0;
        if (used + a_vessel <= x)
            used += a_vessel;
        else
        {
            used = a_vessel;
            need++;
        }
    }
    if (need <= m)
        return 1;
    return 0;
}

int get_ans()
{
    int lo = 0, hi = 999999999, loop = 200, ans;
    while (loop--)
    {
        ans = (hi + lo) / 2;
        if (valid(ans))
            hi = ans;
        else
            lo = ans + 1;
    }
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        cin >> n >> m;
        // n = number of milks
        // m = number of containers need to be poured
        milks.resize(n);
        for (int j = 0; j < n; j++)
            cin >> milks[j];
        cout << "Case " << i << ": " << get_ans() << endl;
        milks.clear();
    }
    return 0;
}
