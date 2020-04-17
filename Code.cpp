#include <bits/stdc++.h>
using namespace std;

typedef vector< long long > vll;
typedef unsigned long long ull;
int t,r,g,b,x,z;

ull value(long long x, long long y, long long z){
	ull ans=0;
	ans+=(max(x,y)-min(x,y))*(max(x,y)-min(x,y));
	//cout<<ans<<endl;
	ans+=(max(y,z)-min(y,z))*(max(y,z)-min(y,z));
	//cout<<ans<<endl;
	ans+=(max(x,z)-min(x,z))*(max(x,z)-min(x,z));
	//cout<<ans<<endl;
	return ans;
}

ull get_min_value(vll red, vll green, vll blue, int gg){
	ull anss=999999999999999999999;
	vll::iterator it;
	for(int i=0;i<gg;i++) {
			it=lower_bound(red.begin(),red.end(),green[i]);
			if(it==red.end()){
				x=*(it-1);
			}
			else x=*it;
			it=lower_bound(blue.begin(),blue.end(),green[i]);
			if(it==blue.end()){
				z=*(it-1);
			}
			else z=*it;
			anss=min(anss,value(x,green[i],z));
			//cout<<x<<" "<<green[i]<<" "<<z<<" "<<ans<<endl;
		}
		//cout<<anss<<endl;
		return anss;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	ull ans;
	cin>>t;
	while(t--){
		//ans=999999999999999999999;
		cin>>r>>g>>b;
		vll red(r),green(g),blue(b);
		for(int i=0;i<r;i++) cin>>red[i];
		for(int i=0;i<g;i++) cin>>green[i];
		for(int i=0;i<b;i++) cin>>blue[i];
		sort(red.begin(),red.end());
		sort(blue.begin(),blue.end());
		sort(green.begin(),green.end());
		ans=get_min_value(red,green,blue,g);
		ans=min(ans,get_min_value(green,red,blue,r));
		ans=min(ans,get_min_value(red,blue,green,b));
		cout<<ans<<endl;
	}
	return 0;
}

