/*
	LIGHT OJ 1396 - Palindromic Numbers (III)

	what a problem :)

	case 1 : 
	98711 => 98789
	9811 => 9889

	case 2 : 
	11798 => 11811
	11998 => 12021
	1198 => 1221
	1998 => 2002

	case 3 :
	11811 : 11911
	11911 : 12021
	1221 : 1331
	1991 : 2002

	corner :
	9 => 11
	0 to 8 => (+1)
	
*/

#include <bits/stdc++.h>

using namespace std;

bool palin(string x){
	string tmp = x;
	reverse(tmp.begin(), tmp.end());
	return tmp == x;
}

bool typeONE(string x){
	int n = x.size(), mid = (n/2)-1;
	for(int i=mid;i>=0;i--){
		if(x[i] < x[n-i-1]) return 0;
		else if(x[i] > x[n-i-1]) return 1;
	}
	return 1;
}

string Type1(string x){
	int n = x.size(), mid = (n/2);
	if(n%2==0) mid--;
	string ans = "" , tmp = "";
	for(int i=0;i<=mid;i++) ans += x[i];
	if(n%2) mid--;
	for(int i=0;i<=mid;i++) tmp += x[i];
	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	return ans;
}

string Type2(string x){
	int n = x.size(), mid = (n/2);
	if(n%2==0) mid--;
	string ans = "" , tmp = "";
	for(int i=0;i<=mid;i++) ans += x[i];
	for(int i=mid;i>=0;i--){
		if(ans[i]=='9') ans[i] = '0';
		else {
			ans[i] = (char)((int)ans[i]+1);
			break;
		}
	}
	if(n%2) mid--;
	for(int i=0;i<=mid;i++) tmp += ans[i];
	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	return ans;
}

string palinTYPE(string x){
	int n = x.size(), mid = (n/2)-1;
	string ans = "" , tmp = "";
	for(int i=0;i<=mid;i++) ans += x[i];
	for(int i=mid;i>=0;i--){
		if(ans[i]=='9') ans[i] = '0';
		else {
			ans[i] = (char)((int)ans[i]+1);
			break;
		}
	}
	for(int i=0;i<=mid;i++) tmp += ans[i];
	reverse(tmp.begin(), tmp.end());
	ans += tmp;
	return ans;
}

string see(string x){
	for(auto lol : x) if(lol != '0') return x;
	int n = x.size();
	x[0] = '1';
	x += "1";
	return x;
}

int main()
{
 	int t, sz, cs=1;
 	string s;
 	cin >> t;
 	while(t--){
 		cin >> s;
 		cout << "Case " << cs++ << ": ";
 		sz = s.size();
 		if(s.size()==1 && s[0] != '9') cout << (char)((int)s[0]+1) << endl;
 		else if(s.size()==1 && s[0] == '9') cout << "11" << endl;
 		else if(palin(s)) {
 			// case 3 : 
 			if(sz%2){
				// 11911 : 12021 , 1599951 : 1600061
 				// 11811 : 11911
				if(s[sz/2]=='9'){
					s[sz/2] = '0';
					for(int i = (sz/2)-1 ; i >= 0 ; i--){
						if(s[i]=='9') {
							s[i] = s[sz-i-1] = '0';
						}
						else {
							s[i] = s[sz-i-1] = (char)((int)s[i]+1);
							break;
						}
					}
				}				
				else s[sz/2] = (char)((int)s[sz/2]+1);
				cout << see(s) << endl;
 			}
 			else {
 				// 1221 : 1331
				// 1991 : 2002
				cout << see(palinTYPE(s)) << endl;
 			}
 		}
 		else if(typeONE(s)){
 			/*  case 1 : 
				98711 => 98789
				9811 => 9889 		*/
 			cout << see(Type1(s)) << endl;
 		}
 		else{
 			/*  case 2 : 
				11798 => 11811
				11998 => 12021
				1198 => 1221
				1998 => 2002 	*/
 			cout << see(Type2(s)) << endl;
 		}
 	}
    return 0;
}
