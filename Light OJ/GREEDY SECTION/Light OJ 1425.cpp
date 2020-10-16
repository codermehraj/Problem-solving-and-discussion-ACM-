/*
	LIGHT OJ 1425 - The Monkey and the Oiled Bamboo
	
	easy one ...
	just simulate and try to get the ans
	Think from where you will start simulating :/
	
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
 	int t, n, cs = 1, pos, ans, temp;
 	scanf("%d",&t);

 	while(t--){

 		scanf("%d",&n);
 		int ar[n];
 		temp = 0;
 		for(int i = 0 ; i < n ; i++) {
 			scanf("%d",&ar[i]);
 			if(i>0) temp = max(temp , ar[i]-ar[i-1]);
 		}

 		pos = 0;
 		ans = max(temp, ar[0]);
 		
 		// pos will reach to n when the whole process will be done
 		while(pos < n){
 			temp = ans;
 			for(pos=1;pos<n;pos++){
 				if(ar[pos-1]+temp == ar[pos]) temp--;
 				else if((ar[pos-1]+temp) < ar[pos]) break;
 			}
 			ans++;
 		}

 		printf("Case %d: %d\n",cs++,ans-1);
 	}

    return 0;
}
