#include <bits/stdc++.h>
using namespace std;
#define MAX 20000000

// num = input
// if n=even y < num - n > x = n+2-y
// if n=odd x < num - n >  y = n+2-x
// for n , x+y=n+2

int summ[50000];

int main()
{
	int i=1,indx,sum=0,found;
	while(sum<=MAX){
		sum+=i;
		summ[i] = sum;
		//cout<<i<<" "<<summ[i]<<endl;
		i++;
	}
	found=i;
	while(cin>>i){
		cout<<"TERM "<<i<<" IS ";
		indx= lower_bound(summ,summ+found,i)-summ;
		indx--;
		//cout<<indx<<" ";
		if(indx%2) cout<<i-summ[indx]<<"/"<<indx+2-(i-summ[indx])<<endl;
		else cout<<indx+2-(i-summ[indx])<<"/"<<i-summ[indx]<<endl;
	}
	return 0;
}