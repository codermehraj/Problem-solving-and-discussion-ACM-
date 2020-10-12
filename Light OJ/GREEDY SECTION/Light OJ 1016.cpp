/*
    Here You need to consider the Y axis coordinates only
    You need to find out how many sections of "w" width do you need for filling all the points
    to do that I just used a set and iterated the elements and counted my answare along the way
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
 	int t, n, w, x, ans=0, last, cs=1;
 	cin >> t;
 	set < int > s;
 	while(t--){
 		ans = 0;
 		cin >> n >> w;
 		while(n--){
 			cin >> x >> x;
 			s.insert(x);
 		}

 		for(auto lol : s){
 			if(ans == 0) {
 				ans++; last = lol;
 			}
 			else if(lol-last > w){
 				ans++;
 				last = lol;
 			}
 		}
 		cout << "Case " << cs++ << ": " << ans << endl;
 		s.clear();
 	}   
    return 0;
}
