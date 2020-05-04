/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << #x << " = " << x << '\n';
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int ans=0, openings=0, n=s.size();
    for(int i=0;i<n;i++){
    	if(s[i]=='(') openings++;
    	// '(' thakle etar pore arekta ')' ashle ans+=2
    	if(s[i]==')' && openings>0) openings--,ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}
//fixed<<setprecision(1)
