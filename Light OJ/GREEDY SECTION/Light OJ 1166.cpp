/*
	LIGHT OJ 1166 : Old Sorting

	The whole idea is simple
	>> just swap for any mismatch
	>> if swapping values are complementary it takes 1 step (4 2 3 1) < swap(1,4) >
	>> CORNER CASE : 
		4 2 1 3 5 6
	 Here swap(4,1),(3,4) which means 2 swaps for 3 mismatch
	>> for any other type of mismatch there will be 1 swap

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
 	int t,n,x,ans,temp,a,b,cs=1,p;
 	cin >> t;
 	while(t--){
 		x = ans = p = 0;
 		cin >> n;
 		int ar[n+1],mp[n+1];
 		ar[0] = -1;
 		for(int i=1;i<=n;i++) {
 			cin >> ar[i];
 			mp[ar[i]] = i; // storing the index of each element
 		}
 		for(int i=1;i<=n;i++) {
 			// corner case : 4 2 1 3 5 6
 			if(ar[i] != i){
 				a = mp[i]; // mp[1] =  3
 				b = ar[ar[i]]; // ar[4] = 3 
 				
 				if(mp[i]==ar[i]){
 					x--; p++;
 					temp = ar[i];
 					ar[i] = i;
 					ar[temp] = temp;
 				}
 				
 				else if(a==b){
 					x--; p+=2;
 					a = ar[i]; // a = ar[1] = 4 
 					b = mp[i]; // b = mp[1] = 3
 					ar[i] = i;
 					ar[a] = a;
 					ar[b] = b;
 				}
 				
 				else{
 					p++;
 					ar[mp[i]] = ar[i]; // ar[mp[1]] = ar[1]
 					mp[ar[i]] = mp[i];
 					ar[i] = i;
 				}
 			} 
 		}
 		cout << "Case " << cs++ << ": " << p << endl;
 	}
    return 0;
}
