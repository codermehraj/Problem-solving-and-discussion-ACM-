 /*
	LIGHT OJ 1198 - Karate Competition
	
	First I will sort both values
	then first I will find for wininng duo(s)
	then the draw one(s)
	
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(int a , int b){ return a > b; }

int main()
{
 	int t, n, ans, cs=1;
 	cin >> t;
 	while(t--){
 		
 		ans = 0;
 		cin >> n;
 		int a[n], b[n];
 		vector < int > mark(n,0), maark(n,0);

 		for(int i=0;i<n;i++) cin >> a[i];
 		for(int i=0;i<n;i++) cin >> b[i];
 		
 		sort(a,a+n);
 		sort(b,b+n,cmp);

 		// check for win
 		for(int i=0;i<n;i++){
 			for(int j=0;j<n;j++){
 				if(b[i] < a[j] && mark[i]==0 && maark[j]==0){
 					mark[i] = 1;
 					maark[j] = 1;
 					ans += 2;
 					break;
 				}
 			}
 		}

 		// check for draw
 		for(int i=0;i<n;i++){
 			for(int j=0;j<n;j++){
 				if(b[i] == a[j] && mark[i]==0 && maark[j]==0){
 					maark[j] = 1;
 					mark[i] = 1;
 					ans++;
 					break;
 				}
 			}
 		}

 		cout << "Case " << cs++ << ": " << ans << endl;

 		mark.clear(); maark.clear();
 	}
    return 0;
}
