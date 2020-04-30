/*
	UVa 156 - Ananagrams
	
	This one is a basic Implementation Problem
	Very easy to do using Standard Template Library
	Just be careful about uppercase and lowercase
	So Bang and gnab do not have any anagram
	To print just use default sort from std::sort
	
*/

/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

vector< string > v,ans;

bool same(string a, string b){
	int A=a.size(),B=b.size();
	if(A!=B) return 0;
	map < char , int > aa , bb;
	for(int i=0;i<A;i++) aa[tolower(a[i])]++;
	for(int i=0;i<B;i++) bb[tolower(b[i])]++;
	bool ans=(aa==bb);
	aa.clear(); bb.clear();
	return ans;
}

bool anagram(string s){
	bool paisi=0;
	for(auto x: v){
		if(same(x,s)){
			if(paisi) return 0;
			else paisi=1;
		}
	}
	return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	string word;
	while(cin>>word){
		if(word=="#") break;
		v.push_back(word);
	}
	for(auto x: v){
		if(anagram(x)){
			ans.push_back(x);
		}
	}
	sort(ans.begin(), ans.end());
	for(auto x: ans){
		cout<<x<<endl;
	}
	return 0;
}
