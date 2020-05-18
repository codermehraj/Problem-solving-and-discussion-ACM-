#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

bool not_ok(double a, double b, double c){
	double s=(a+b+c)/2.0;
  // cheking if area formula will work or not
	if(s<=c || s<=b || s<=a) return 1;
	return 0;
}

double area(double a, double b, double c){
	double s=(a+b+c)/2.0;
	return 4.0*sqrt(s*(s-a)*(s-b)*(s-c))/3.0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a,b,c,ans=0;
    while(cin>>a>>b>>c){
    	if(not_ok(a,b,c)) cout<<"-1.000\n";
    	else cout<<fixed<<setprecision(3)<<area(a,b,c)<<endl;
    }
    return 0;
}
