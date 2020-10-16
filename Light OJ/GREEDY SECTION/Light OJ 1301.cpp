/*
	LIGHT OJ 1301 - Monitoring Processes

	Let, 
	1 ~ starting of an event
	0 ~ ending of an event
	sort them and then simulate
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair< int , int > a, pair<int , int> b){
	if(a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main()
{
 	int t, n, ans, temp, u, v, cs=1;
 	scanf("%d",&t);
 	vector < pair < int , int > > lst;
 	while(t--){
 		scanf("%d",&n);
 		for(int i=0;i<n;i++){
 			scanf("%d%d",&u,&v);
 			lst.push_back({u,1});
 			lst.push_back({v,0});
 		}
 		sort(lst.begin(),lst.end(),cmp);
 		temp = ans = 0;
 		for(auto lol : lst){
 			if(lol.second == 1) temp++;
 			else temp--;
 			ans = max (ans , temp);
 		}
 		printf("Case %d: %d\n",cs++,ans);
 		lst.clear();
 	}
    return 0;
}
