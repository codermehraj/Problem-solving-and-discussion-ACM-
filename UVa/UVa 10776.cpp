/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

string s;
int k,sz;

void subset(string a, int indx){
	int n=a.size();
	if(n==k){
		cout<<a<<endl;
		return ;
	}
	for(int i=indx;i<sz;i++){
		subset(a+s[i],i+1);
		while(s[i]==s[i+1]) i++;
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	while(cin>>s>>k){
		sort(s.begin(), s.end());
		sz=s.size();
		subset("",0);
	}
	return 0;
}
