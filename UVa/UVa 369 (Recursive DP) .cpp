/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    We are using a combinatorics formula to calculate nCr
    The formula is :
        nCr = (n-1)C(r-1) + (n-1)C(r)
        So, The recursive formula will be: 
        nCr(n,r) = nCr(n-1,r-1) + nCr(n-1,r)
        Lets find out :D
        Releted Problem : UVa 369
*/

unsigned long long dp[100+5][100+5];

int nCr(int n, int r){
    // As nCn = 1
    if(n==r) return 1;
    // As nC1 = n
    if(r==1) return n;
    if(dp[n][r]!=-1) return dp[n][r];
    else dp[n][r]=nCr(n-1,r-1)+nCr(n-1,r); 
    return dp[n][r];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<105;i++){
    for(int j=0;j<105;j++){
        dp[i][j]=-1;
        }
    }
    int n,r;
    while(cin>>n>>r && (n!=0 && r!=0))
    // Using recursion to get nCr
    cout<<n<<" things taken "<<r<<" at a time is "<<nCr(n,r)<<" exactly."<<endl;
    return 0;
}
