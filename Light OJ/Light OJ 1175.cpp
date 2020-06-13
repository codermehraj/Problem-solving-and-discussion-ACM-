/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';
#define mx 99999

int X,Y,ans;
char G[210][210];
int lvl[210][210];
pair < int , int > u,v,init;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

void getGraph(){
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++)
			cin>>G[i][j];
}			

bool is_okay(pair < int , int > node){
	if(lvl[node.first][node.second]==-1 || node.first<0 || node.second<0 || node.first>=X || node.second>=Y) return 0;
	return 1;
}

bool is_safe_zone(pair < int , int > pos){
	if(pos.first==0 || pos.second==0 || pos.first==X-1 || pos.second==Y-1) return 1;
	return 0;  
}

void bfs_in_fire(){
	queue < pair < int , int > > nxt_node_q;
	for(int i=0;i<X;i++)
		for(int j=0;j<Y;j++){
			lvl[i][j]=0;
			if(G[i][j]=='F') nxt_node_q.push(make_pair(i,j));
			else if(G[i][j]=='J') init=make_pair(i,j);
			else if(G[i][j]=='#') lvl[i][j]=-1;
			else lvl[i][j]=mx;
			// Pushing the fires
		}
	while(!nxt_node_q.empty()){
		u=nxt_node_q.front();
		nxt_node_q.pop();
		for(int i=0;i<4;i++){
			v.first  = u.first  + dx[i];
			v.second = u.second + dy[i];
			if(is_okay(v) && lvl[v.first][v.second]>lvl[u.first][u.second]+1){
				lvl[v.first][v.second]=lvl[u.first][u.second]+1;
				nxt_node_q.push(v);
			}
		}
	}
}

void bfs_to_escape(){
	ans=0;
	queue < pair < int , int > > nxt_node_q;
	if(is_safe_zone(init)){
		ans=0;
		return ;
	}
	nxt_node_q.push(init);
	lvl[init.first][init.second]=0;
	while(!nxt_node_q.empty()){
		u=nxt_node_q.front();
		nxt_node_q.pop();
		for(int i=0;i<4;i++){
			v.first  = u.first  + dx[i];
			v.second = u.second + dy[i];
			if(is_okay(v) && lvl[v.first][v.second]>lvl[u.first][u.second]+1){
				//show(v.first);
				//show(v.second);
				lvl[v.first][v.second]=lvl[u.first][u.second]+1;
				if(is_safe_zone(v)){
					ans= lvl[v.first][v.second];
					return ;
				}
				nxt_node_q.push(v);
			}
		}
	}
	ans=-1;
}

int main()
{
	int t,cs=1;
	cin>>t;
	while(t--){
		cin>>X>>Y;
		getGraph();
		bfs_in_fire();
		bfs_to_escape();
		cout<<"Case "<<cs++<<": ";
		if(ans>=0) cout<<ans+1<<endl;
		else cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
// fixed<<setprecision(1)
