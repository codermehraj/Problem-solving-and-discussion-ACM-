/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';
/*
	x= number of rows
	y= number of collums
	z= number of slices
	position --> ( z, x, y )
*/

int X,Y,Z,mx, ux,uy,uz, vx,vy,vz, ulvl, nx,ny,nz, ans;
vector < vector < string > > grph;
int lvl[31][31][31];
string line;

struct node
{
	int x, y, z;

	void sett(int a, int b, int c){ x=a, y=b, z=c; }
};

bool ok(int xx, int yy, int zz)
{
    if(xx >= 0 && xx < X && yy >= 0 && yy < Y && zz >= 0 && zz < Z);
    else return 0;
	if((grph[zz][xx][yy]=='#' || grph[zz][xx][yy]=='S')) return 0;
    return 1;
}

node now,then;
queue < node > nxt_node;

int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

void bfs(){
	now.sett(ux,uy,uz);
	nxt_node.push(now);
	lvl[uz][ux][uy]=0;
	while(!nxt_node.empty()){
		now=nxt_node.front();
		nxt_node.pop();
		ulvl = lvl[now.z][now.x][now.y] + 1;
        for (int c = 0; c < 6; c++)
        {
            nx = now.x + dx[c];
            ny = now.y + dy[c];
            nz = now.z + dz[c];
            //show(nx); show(ny); show(nz);

            if (ok(nx, ny, nz) && ulvl < lvl[nz][nx][ny])
            {
                lvl[nz][nx][ny] = ulvl;
                //cout<<nz<<" "<<nx<<" "<<ny<<" ";
                //show(lvl[nz][nx][ny]);
                then.sett(nx,ny,nz);
		nxt_node.push(then);
            }
        }
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
    	cin>>Z>>X>>Y;
    	if(Z==0 || X==0 || Y==0) break;
    	mx=(Z*X*Y)+10;
    	grph.resize(Z+1);
    	for(int k=0;k<Z;k++){
    		for(int i=0;i<X;i++){
    			cin>>line;
    			grph[k].push_back(line);
    			for(int j=0;j<Y;j++){
    				if(line[j]=='S') ux=i,uy=j,uz=k;
    				if(line[j]=='E') vx=i,vy=j,vz=k;
    				lvl[k][i][j]=mx;
    			}
    		}
    	}
    	bfs();
    	ans=lvl[vz][vx][vy];
    	if(ans==mx) cout<<"Trapped!\n";
    	else cout << "Escaped in " << ans << " minute(s)." << '\n';
    	grph.clear();
    }
    return 0;
}

/*
for(int k=0;k<Z;k++){
    		for(int i=0;i<X;i++){
    			for(int j=0;j<Y;j++){
    				cout<<lvl[k][i][j]<<"\t";
    			}
    			cout<<endl;
    		}
    		cout<<endl;
    	}
*/
