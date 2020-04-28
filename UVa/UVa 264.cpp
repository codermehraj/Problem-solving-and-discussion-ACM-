/*
UVa 264 ~ Count on Cantor

1/1 1/2 1/3 1/4 1/5 . . .
2/1 2/2 2/3 2/4
3/1 3/2 3/3
4/1 4/2
5/1

>>>  num = input and n= sum of 1 to n such that (sum<num) strictly less
>>>  e.g for num=27 , sum = 21 (1+2+3+4+5+6) which brings n = 6
>>>  if n=even y = num - n and x = n+2-y
>>>  if n=odd x = num - n  and y = n+2-x
>>>  for all case , x+y=n+2
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 20000000

int summ[50000];
// For storing Qumilative sum from 1 to N such that sum is less than MAX

int main()
{
	int i=1,indx,sum=0,found;
	while(sum<=MAX){
		sum+=i; // Calculating Qumilative sum
		summ[i] = sum;
		i++;
	}
	found=i;
	while(cin>>i){
		cout<<"TERM "<<i<<" IS ";
		indx= lower_bound(summ,summ+found,i)-summ;
		// Geting the value of n such that sum of 1 to n is strictly less than num(i)
		indx--;
		// In case of odd ans is x = n+2-y and y = num - n
		if(indx%2) cout<<i-summ[indx]<<"/"<<indx+2-(i-summ[indx])<<endl;
		else cout<<indx+2-(i-summ[indx])<<"/"<<i-summ[indx]<<endl;
		// In case of even x = num - n  and y = n+2-x
	}
	return 0;
}

// ~Codermehraj@gmail.com~SUST_SWE_19
