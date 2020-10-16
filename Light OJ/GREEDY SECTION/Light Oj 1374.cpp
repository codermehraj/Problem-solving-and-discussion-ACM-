/*
	LIGHT OJ 1374 - Confusion in the Problemset
	
	Just assign them all using an marking array
	remember complemnetary elements of each case
	 can be used in any of the 2 slots it does not matter

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
 	
  int t, n, cs=1;
 	bool flag;
 	cin >> t;
 	
  while(t--){
 		
    flag = 1;
    cin >> n;
 		
    vector< int > mark(n,-1);
 		int ar[n];
    
 		for(int i=0;i<n;i++){
 			cin >> ar[i];
 			if(mark[ar[i]] == -1) mark[ar[i]] = ar[i];
 			else if(mark[n-ar[i]-1] == -1) mark[n-ar[i]-1] = ar[i];
 			else flag = 0;
 		}
    
 		if(flag) cout << "Case " << cs++ << ": yes" << endl;
 		else cout << "Case " << cs++ << ": no" << endl;
 		mark.clear();
 	
  }
    return 0;
}
