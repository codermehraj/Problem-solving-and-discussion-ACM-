/*
	Codeforces Round #635 (Div. 2) Problem D
	Codeforces Round #635 (Div. 1) Problem B
	Problem Name: Xenia and Colorful Gems
	Problem Link: https://codeforces.com/contest/1337/problem/D
	
	# Problem Summery :
	>>>	Here You will be given some random sized red green blue gems.
	>>> You will have to chose 1 gem from each color such that:
			The value of (x−y)^2 + (y−z)^2 + (z−x)^2 is minimized...
			x = size of red    y = size of blue   z =  size of green
	
	# My aproach :
	>>>	As I have to minimize that equation so I need to minimize:
			The diffrence between (x,y) (y,z) (z,x)
	>>>	So I will first sort the whole list of gems for each Color
	>>>	Then I will choose the closest pair for a color using lower_bound()
	>>>	While doing that I need to also check for possible overflows and
			minimizing the diffrence of choosen pair for a color
	>>> repeat this for RGB , GRB , RBG and take the minimum value
	>>> that minimum value is the ans	

*/
#include <bits/stdc++.h>
using namespace std;

typedef vector< long long > vll;
typedef unsigned long long ull;

int t,r,g,b;
long long dx,dy,x,z,xx,zz;

//This function gives me the value for each combination of gems
ull value(long long x, long long y, long long z){
	ull ans=0;
	ans+=(max(x,y)-min(x,y))*(max(x,y)-min(x,y));
	ans+=(max(y,z)-min(y,z))*(max(y,z)-min(y,z));
	ans+=(max(x,z)-min(x,z))*(max(x,z)-min(x,z));
	return ans;
}

//Function for getting the min value for a color combination
ull get_min_value(vll red, vll green, vll blue, int gg){
	ull anss=999999999999999999999;
	vll::iterator it;
	for(int i=0;i<gg;i++) {
			it=lower_bound(red.begin(),red.end(),green[i]);
			//x is the lower bound for the color for that we are searching for
			if(it==red.end()){
				x=*(it-1);
			}
			else{
				dx=*it-green[i];
				if(it!=red.begin()) dy=green[i]-*(it-1);
				else dy=dx;
				x=min(dy,dx);
				if(x==dx) x=*it;
				else x=*(it-1);
			}
			it=lower_bound(blue.begin(),blue.end(),green[i]);
			//zz is for searching closest pair
			if(it==blue.end()){
				zz=*(it-1);
			}
			else{
				dx=*it-green[i];
				if(it!=blue.begin()) dy=green[i]-*(it-1);
				else dy=dx;
				zz=min(dy,dx);
				if(zz==dx) zz=*it;
				else zz=*(it-1);
			}
			it=lower_bound(blue.begin(),blue.end(),green[i]);
			//z x is the lower bound for the color for that we are searching for
			if(it==blue.end()){
				z=*(it-1);
			}
			else {
				dx=*it-green[i]+(max(x,*(it))-min(x,*(it)));
				if(it!=blue.begin()) dy=green[i]-*(it-1)+(max(x,*(it-1))-min(x,*(it-1)));
				else dy=dx;
				z=min(dy,dx);
				if(z==dx) z=*it;
				else z=*(it-1);
			}
			it=lower_bound(red.begin(),red.end(),green[i]);
			//xx is for searching closest pair
			if(it==red.end()){
				xx=*(it-1);
			}
			else {
				dx=*it-green[i]+(max(zz,*(it))-min(zz,*(it)));
				if(it!=red.begin()) dy=green[i]-*(it-1)+(max(zz,*(it-1))-min(zz,*(it-1)));
				else dy=dx;
				xx=min(dy,dx);
				if(xx==dx) xx=*it;
				else xx=*(it-1);
			}
			anss=min(anss,value(x,green[i],z));
			anss=min(anss,value(xx,green[i],zz));
		}
		return anss; // minimum of direct lower_bound and closest pair
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
	ull ans;
	
	cin>>t;
	while(t--){
		
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
