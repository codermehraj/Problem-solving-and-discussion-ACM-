#include <bits/stdc++.h>
using namespace std;
 
bool flag = 0;
 
bool ok(string a, string b){
    int n = a.size(), m = b.size();
    for(int i=0; i < n; i++){
        if(a[i]!=b[i%m]) return 0;
    }
    return 1;
}
 
bool boro(string a, string b, int k){
    int bb = b.size();
    for(int i=0;i<k;i++){
        if(bb==i) break;
        if(b[i] > a[i]) return 0;
        else if(a[i] > b[i]) return 1;
    }
    return 1;
}
 
string change(string s){
    int q = s.size();
    for(int i=q-1;i>=0;i--){
        if(s[i]=='9') s[i] = '0';
        else {
            s[i] = (char)((int)s[i] + 1);
            break;
        }
    }
    if(s[0]=='0') {
        flag = 1;
        return "1"+s;
    }
    else return s;
}
 
int main(){
    int n , k, pos=0, cnt;
    cin >> n >> k;
    string s, trgt="", seed="";
    cin >> s;
    for(int i=0;i<k;i++) trgt += s[i];
    if(ok(s,trgt)) cout << n << endl << s << endl; 
    else {
        for(int i=k;i<n;i++) {
            if(i==2*k) break;
            seed += s[i];
        }
        pos = 2*k;
        while(seed==trgt){
            seed = ""; cnt = 0;
            for(;pos<n;pos++) {
                if(cnt==k) break;
                seed += s[pos];
                cnt++;
            }
        }
        if(boro(trgt,seed,k)){
            cout << n << endl;
            for(int i=0;i<n;i++) cout << trgt[i%k];
            cout << endl;
        }
        else {
            trgt = change(trgt);
            cout << n << endl;
            for(int i=0;i<n;i++) cout << trgt[i%k];
        }
    }
    return 0;
}
