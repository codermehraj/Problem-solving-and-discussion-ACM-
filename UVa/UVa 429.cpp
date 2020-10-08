#include <bits/stdc++.h>

using namespace std;

vector < string > words;
unordered_map < int , vector < int > > mp;
unordered_map < string , int > indx;
queue < int > Q;

bool ok(string a, string b){
	if(a.size()!=b.size()) return 0;
	int n = a.size(), c=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]) c++;
		if(c==2) return 0;
	}
	return 1;
}

int bfs(string u, string v){
	int uu = indx[u], vv = indx[v], cur=words.size()+2;
	vector < int > lvl(cur,-1), vis(cur,0);
	Q.push(uu);
	lvl[uu] = 0;
	vis[uu] = 1;
	while(!Q.empty()){
		cur = Q.front(); Q.pop();
		//cout << endl << words[cur] << " : ";
		for(auto lol : mp[cur]){
			if(vis[lol]==0){
				//cout << words[lol] << " ";
				vis[lol] = 1;
				lvl[lol] = lvl[cur] + 1;
				Q.push(lol);
			}
		}
	}
	cur = lvl[vv];
	lvl.clear();
	vis.clear();
	return cur;
}

int main()
{
    int t, n, ans;
    string s, a, b, x; 
    cin >> t;
    while(t--){
    	while(cin >> s){
    		// makes the connections 
    		if(s == "*") break;
    		words.push_back(s);
    	}
    	n = words.size();
    	for(int i=0; i<n ; i++){
    		indx[words[i]] = i;
    		for(int j=i+1; j<n; j++){
    			if(ok(words[i],words[j])){
    				// make an edge
    				mp[i].push_back(j);
    				mp[j].push_back(i);	
    			}
    		}
    	}
    	getchar();
    	while(1){
    		a = b = "";
    		getline(cin,x);
    		if(x.size()==0) break;
    		n = x.size();
    		for(int i=0; i<n ; i++){
    			if(x[i] == ' '){
    				ans = i+1;
    				break;
    			}
    			a+= x[i];
    		}
    		for(int i=ans; i<n ; i++) b+= x[i];
    		ans = bfs(a,b);
    		cout << a << " " << b << " " << ans << endl;
    	}/*
    	for(auto lol : mp){
    		cout << lol.first << " : " << endl;
    		for(auto hehe : lol.second){
    			cout << hehe << " ";
    		}
    		cout << endl;
    	}*/
    	indx.clear();
    	words.clear();
    	mp.clear();
    	if(t) cout << endl;
    }
    return 0;
}
