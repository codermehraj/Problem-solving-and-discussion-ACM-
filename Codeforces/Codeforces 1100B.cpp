/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << #x << " = " << x << '\n';
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 	
    int n,x,m;
    cin>>n>>m;
    map < int , int > mp;
    while(m--){
    	cin>>x;
    	mp[x]++;
    	if(mp.size()==n){
    		cout<<"1";
    		for(int i=1;i<=n;i++){
    			mp[i]--;
    			if(mp[i]==0) mp.erase(i);
    		}
    	}
    	else cout<<"0";
    }
    cout<<endl;
    return 0;
}
//fixed<<setprecision(1)
