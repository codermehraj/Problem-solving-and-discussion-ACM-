/* ~ CoderMehraJ ~ */
// UVa 352 : The Seasonal War

#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

char ar[30][30];

void visit(int n, int i, int j){
    ar[i][j]='0';
    if(i>0 && j>0 && ar[i-1][j-1]=='1') visit(n,i-1,j-1);
    if(i>0 && ar[i-1][j]=='1') visit(n,i-1,j);
    if(i>0 && j+1<n && ar[i-1][j+1]=='1') visit(n,i-1,j+1);
    if(j>0 && ar[i][j-1]=='1') visit(n,i,j-1);
    if(j+1<n && ar[i][j+1]=='1') visit(n,i,j+1);
    if(i+1<n && j>0 && ar[i+1][j-1]=='1') visit(n,i+1,j-1);
    if(i+1<n && ar[i+1][j]=='1') visit(n,i+1,j);
    if(i+1<n && j+1<n && ar[i+1][j+1]=='1') visit(n,i+1,j+1);
    return ; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans,cs=1;
    while(cin>>n){
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ar[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ar[i][j]=='1'){
                    visit(n,i,j);
                    ans++;
                }
            }
        }
        cout<<"Image number "<<cs++<<" contains "<<ans<<" war eagles.\n";
    }
    return 0;
}
