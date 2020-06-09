/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

vector < string > Grph;
map< pair < int , int > , bool > vis;
bool black_wins;
int n;

int dx[] = {-1 , -1 ,  0 , 0 , 1 , 1};
int dy[] = {-1 ,  0 , -1 , 1 , 0 , 1};

/*
  UVa 260 : Il Gioco dell'X  
	Adjacency Criteria: (6 cells adjacent)
		 1 1 0 ~ [i-1][j-1] , [i-1][j]
		 1 x 1 ~ [i][j-1] , [i][j+1]
		 0 1 1 ~  [i+1][j] , [i+1][j+1]
	where Moves can be done from x to 1
	So, dfs from all the Black nodes in the first row
	If any black node leads to the last row black wins
	Otherwise White is the winner... GG
*/

bool valid_edge(int x, int y){
	if(x>=n || y>=n || x<0 || y<0) return 0;
	return 1;
}

void dfs(int x, int y){
	// visit from x to y
	if(x+1==n){
		//show(x);
		//show(y);
		black_wins = 1;
		return ;
	}
	for(int i=0;i<6;i++){
		if(black_wins) return;
		if(valid_edge(x+dx[i],y+dy[i]) && Grph[x+dx[i]][y+dy[i]]=='b' &&!vis[make_pair(x+dx[i],y+dy[i])]){
			vis[make_pair(x+dx[i],y+dy[i])] = 1;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}

int main()
{
	int cs=1;
	string x;
	while(cin>>n){
		if(n==0) break;
		black_wins = 0; // Assuming black will not win
		for(int i=0;i<n;i++){
			cin>>x;
			Grph.push_back(x);
		}
		for(int i=0;i<n;i++){
			if(Grph[0][i]=='b') dfs(0,i);
			if(black_wins) break;
		}
		cout<<cs++;
		if(black_wins) cout<<" B\n";
		else cout<<" W\n";
		vis.clear();
		Grph.clear();
	}
    return 0;
}
// fixed<<setprecision(1)
