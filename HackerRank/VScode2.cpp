#include <bits/stdc++.h>

using namespace std;

int main()
{
	queue<int> q;
	q.push(12);
	q.push(2);
	q.push(122);
	q.push(12312);
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}