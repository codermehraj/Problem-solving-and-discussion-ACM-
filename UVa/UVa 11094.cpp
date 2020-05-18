#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

char ar[30][30];
int cs=0,m;
char ch,popo;



void visit(int n, int i, int j){
    ar[i][j]=popo;
    cs++;
    //cout<<"("<<i<<","<<j<<")"<<endl;
    //cout<<ans<<endl;
    //if(i>0 && j>0 && ar[i-1][j-1]=='.') visit(n,i-1,j-1);
    if(i>0 && ar[i-1][j]==ch) visit(n,i-1,j);
    //if(i>0 && j+1<m && ar[i-1][j+1]=='.') visit(n,i-1,j+1);
    if(j>0 && ar[i][j-1]==ch) visit(n,i,j-1);
    if(j+1<m && ar[i][j+1]==ch) visit(n,i,j+1);
    //if(i+1<n && j>0 && ar[i+1][j-1]=='.') visit(n,i+1,j-1);
    if(i+1<n && ar[i+1][j]==ch) visit(n,i+1,j);
    //if(i+1<n && j+1<m && ar[i+1][j+1]=='.') visit(n,i+1,j+1);
    if(j==m-1 && ar[i][0]==ch) visit(n,i,0);
    //if(i==n-1 && ar[0][j]==ch) visit(n,0,j);
    //if(i==0 && ar[n-1][j]==ch) visit(n,n-1,j);
    if(j==0 && ar[i][m-1]==ch) visit(n,i,m-1);
    return ;
}

char print(int n, int m){
	for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]!=ch) return ar[i][j];
            }
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,u,v,ans;
    while(cin>>n>>m){
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>ar[i][j];
            }
        }
        cin>>u>>v;
        //show(u);
        ch=ar[u][v];
        popo=print(n,m);
        //show(ch);
        visit(n,u,v);
        //print(n,m);
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ar[i][j]==ch){
                    cs=0;
                    visit(n,i,j);
                    //cout<<endl;
                    //print(n,m);
                    ans=max(ans,cs);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
