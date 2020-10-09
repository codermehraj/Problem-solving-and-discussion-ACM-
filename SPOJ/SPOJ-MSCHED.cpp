#include <bits/stdc++.h>

using namespace std;

struct cow
{
	int deadline, profit;
};

bool hamba(cow a, cow b){
	if(a.profit == b.profit)
		return a.deadline < b.deadline;
	else
		return a.profit > b.profit;
}

int main()
{
    int n, w, d, ans = 0, mx=0;
    cin >> n;
    cow ar[n];
    for(int i=0;i<n;i++){
    	cin >> ar[i].profit >> ar[i].deadline;
    	mx = max( mx , ar[i].deadline );
    }
    vector < int > mp(mx+1,0);
    sort(ar,ar+n,hamba);
    for(int i=0;i<n;i++) {
    	for(int j=ar[i].deadline;j>0;j--){
    		if(mp[j]==0) {
    			mp[j] = 1;
    			ans += ar[i].profit;
    			//cout << ar[i].profit << endl;
    			break;
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}
