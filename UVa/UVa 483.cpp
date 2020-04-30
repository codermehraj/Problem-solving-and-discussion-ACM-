/*
		UVa 483 : Word Scramble
		
		This is also another implementation problem
		Here you need to reverse every single word from the input
		You also have to keep the correct spacing as input
		Rest is simple...
		
*/

/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

void show_rev(string s){
	int nn=s.size();
	for(int i=nn-1;i>=0;i--)
		cout<<s[i];
	return ;
}

void To_the_Hell(string a){
	string s="";
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]==' '){
			show_rev(s);
			cout<<" ";
			s="";
		}
		else s+=a[i];
	}
	show_rev(s);
	return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	string line, word;
	bool space=0;
	while(getline(cin,line)){
		To_the_Hell(line);
		cout<<endl;
	}
	return 0;
}
