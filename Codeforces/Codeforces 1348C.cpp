/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << #x << " = " << x << '\n';
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,k,num;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        sort(s.begin(), s.end());
        if(s[0]!=s[k-1]) cout<<s[k-1]<<endl;
        if(s[0]!=s[k-1]) continue;
        cout<<s[k-1];
        num=(n-1)/k;
        if(s[k]!=s[n-1]) for(int i=k;i<n;i++) cout<<s[i];
        else for(int i=0;i<num;i++) cout<<s[k];  
        cout<<'\n'; 
    }
    return 0;
}
