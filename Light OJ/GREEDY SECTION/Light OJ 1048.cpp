
/*
 	 n = number of campsite where you can stay
 	 k = number of nights that you need to stay
 	 Terget = Mimimizing the maximum walk length 

 	 We will use binary search to get the result
 	 we will set some limits of the ans then search for the optimal ans
 	 >> This is a YES / NO binary search
*/

#include <bits/stdc++.h>

using namespace std;

vector < int > v;
int n , k;

bool valid(int x){
	int found = 0, csum=0;
	for(auto lol : v){
		if(found == 0 || csum + lol > x) {
			found++;
			csum = 0;
		}
		csum += lol;
	}
	return (found <= k+1);
}

void printans(int x){
	int found = 0, csum=0, left=v.size();
	for(auto lol : v){
		left--;
		if(found == 0 || csum + lol > x || (k)-found==left) {
			found++;
			if(found>1) cout << csum << endl;
			csum = 0;
		}
		csum += lol;
	}
	cout << csum << endl;
}

int main()
{
 	int t, mx=0, mxx, hi , lo, mid, x, cs=1;
 	cin >> t;
 	while(t--){
 		mx = mxx = 0;
 		cin >> n >> k;
 		for(int i=0;i<=n;i++){
 			cin >> x; v.push_back(x);
 			mx = max( mx , x );
 			mxx += x;
 		}

 		hi = mxx;
 		lo = mx;
 		while(hi > lo){
 			mid = (hi + lo) / 2;
 			if(valid(mid)){
 				hi = mid;
 			}
 			else {
 				lo = mid+1;
 			}
 		}
 		cout << "Case " << cs++ << ": " << hi << endl;
 		printans(hi);
 		v.clear();
 	}
    return 0;
}
