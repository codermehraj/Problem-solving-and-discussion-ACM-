/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

long long xD(long long  noob){
	if(noob<2) return 0;
	noob--;
	return (noob*(noob+1))/2;
}

int main()
{
	int t,n;
	long long ans;
	cin>>t;
	map < long long  , long long  > mp;
	while(t--){
		cin>>n;
		int ar[n],sm[n];
		for(int i=0;i<n;i++) cin>>ar[i];
		sm[0]=ar[0];
		ans=0;
		for(int i=1;i<n;i++) sm[i]=sm[i-1]+ar[i];
		for(int i=0;i<n;i++) mp[sm[i]]++;
		for(auto lol: mp){
			if(lol.first==0) ans+=lol.second;
			ans+=xD(lol.second);
		}
		cout<<ans<<endl;
		mp.clear();
	}
	return 0;
}
// fixed<<setprecision(1)
