/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

map < int , vector < int > > mp;
vector < bool > vis;
int ans=0;

/*
  UVa 280 : Vertex 
	num of nodes = n
	some lines which ends with zero
	take untill starts with zero
	each line's 1st num is parent and other is directed child
	Take number of querries
	take the node numbers from 1 to n 
	REPEAT untill num of nodes != 0
*/

void dfs(int source){
	for(auto child: mp[source]){
		if(!vis[child-1]){
			vis[child-1]=1;
			dfs(child);
			ans++;
		}
	}
}

int main()
{
	int n,q,x,u,v;
	while(1){
		cin>>n;
		if(n==0) break;
		while(1){
			cin>>u;
			if(u==0) break;
			while(1){
				cin>>v;
				if(v==0) break;
				mp[u].push_back(v);
				// edge from u to v
			}
		}
		cin>>q;
		while(q--){
			cin>>x;
			// reset vis and ans
			ans=0;
			vis.clear();
			for(int i=0; i<n; i++) vis.push_back(0);
			dfs(x); 
			ans=n-ans;
			cout<<ans;
			for(int i=0; i<n; i++) if(!vis[i]) cout<<" "<<i+1;
			cout<<endl;
		}
		mp.clear();
	}
    return 0;
}
// fixed<<setprecision(1)
