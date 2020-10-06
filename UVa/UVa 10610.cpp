#include <bits/stdc++.h>

using namespace std;

pair < double , double > u , v, temp;
vector < pair < double , double > > vp;
int speed, tle, n, mx_dis, ans, tmp;
unordered_map < int , vector < int > > mp;
queue < int > Q;

bool isOK(pair<double , double> a , pair < double , double> b ){
	double dis = (a.first-b.first)*(a.first-b.first);
	dis += (a.second-b.second)*(a.second-b.second);
	dis = sqrt(dis);
	return dis < mx_dis;
}

void bfs(){
	vector < int > lvl(n,-1), vis(n,0);
	Q.push(0);
	lvl[0] = 0;
	vis[0] = 0;
	while(!Q.empty()){
		tmp = Q.front(); Q.pop();
		for(auto lol : mp[tmp]){
			if(vis[lol] == 0){
				vis[lol] = 1;
				lvl[lol] = lvl[tmp] + 1;
				Q.push(lol);
			}
		}
	}
	ans = lvl[1];
	lvl.clear();
	vis.clear();
}

int main()
{
    char s[1000];
    while(1){
    	cin >> speed >> tle;
    	tle *= 60;
    	mx_dis = (speed*tle);
    	if(speed == 0 && tle==0) break;
    	cin >> u.first >> u.second;
    	cin >> v.first >> v.second;
    	vp.push_back(u);
    	vp.push_back(v);
    	getchar();
    	while(gets(s)){
    		if(strlen(s)==0) break;
    		sscanf(s,"%lf %lf",&temp.first, &temp.second);
    		vp.push_back(temp);
    	}
    	n = vp.size();
    	for(int i=0;i<n;i++){
    		for(int j=i+1;j<n;j++){
    			if(isOK(vp[i],vp[j])){
    				mp[i].push_back(j);
    				mp[j].push_back(i);
    			}
    		}
    	}
    	bfs();
    	if(ans == -1) cout << "No.\n";
    	else cout << "Yes, visiting " << ans-1 << " other holes.\n";
    	vp.clear();
    	mp.clear()
    }
    return 0;
}
