/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,b,h,w,cost,ans,mx,x;
    while(cin>>n>>b>>h>>w){
        ans=-1;
        for(int i=1;i<=h;i++){
            cin>>cost; mx=0;
            for(int j=1;j<=w;j++){
                cin>>x;
                mx=max(mx,x);
            }
            if(mx>=n && cost*n<=b){
                if(ans==-1) ans=cost*n;
                else ans=min(cost*n,ans);
            }
        }
        if(ans==-1) cout<<"stay home\n";
        else cout<<ans<<endl;
    }
    return 0;
}
