/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

bool cmp(int a, int b) { return a>b; }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    unsigned long long ans, n;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        n--;
        n/=2;
        ans=(1+n)*n*(2*n+1);
        ans/=6;
        cout<<ans*8<<endl;
    }
    return 0;
}
