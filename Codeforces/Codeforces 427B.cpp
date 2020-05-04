/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << #x << " = " << x << '\n';
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 	
    int n,t,c,ans=0, tana_koyta=0;
    bool flag;
    cin>>n>>t>>c;
    int ar[n];
    for(int i=0;i<n;i++){
    	cin>>ar[i]; 	
    }
    for(int i=0;i<n;i++){
    	//if(i+c>n) break;
    	if(ar[i]>t) tana_koyta=0;
    	else{
    		tana_koyta++;
    		//show(tana_koyta);
    		if(tana_koyta>=c) ans++;
    	}
    }
    cout<<ans<<endl;
    return 0;
}
//fixed<<setprecision(1)
