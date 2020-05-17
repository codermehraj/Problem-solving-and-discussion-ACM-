/* ~CoderMehRaj~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d,x,y,z;
    long long ans=0,countA,countC;
    cin>>a>>b>>c>>d;
    for(int xy=a+b;xy<=b+c;xy++){
    	countA = min(b,xy-b) - max(a,xy-c) + 1;
    	/*
    		Let, sides of the triangle ==>> (x , y , z)
    		countA = number of possible x , y
    			   = most possible value of x - least possible value of x + 1
    			   = min ( b,(x+y)-b ) - max ( a,(x+y)-c ) + 1
    		most possible value of x = current sum of x,y - minimum y
    					= (x+y) - b [which is <=b]
    		least posible value of x = current sum of x,y - maximum y
    					= (x+y) - c [which is >=a]
    		~~ Here min and max is used to keep the value unoverloaded ~~
    		countC = numbre of possible z(s) for given x+y
    			   = most possible value of z - least possible value of z + 1
    			   = min( xy-1, d ) - c + 1
    		most possible value of z = 1 less than current sum [which is <=d]
    		least posible value of z = c [as given]
			
    	*/
    	countC = min(xy-1, d) - c + 1;
    	if(countA<1 || countC<1) continue;
    	ans += countA * countC;
    }
    cout<<ans<<endl;
    return 0;
}
// fixed<<setprecision(1)
