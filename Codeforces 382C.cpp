/* ~ CoderMehraJ ~ */
/*
    Problem Name : Arithmetic Progression
*/
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

vector < long long > v;
int diff,n,x,extra;
bool done=1;

bool isok(){
    diff=v[1]-v[0];
    for(int i=2;i<n;i++){
        if(v[i]-v[i-1]!=diff) return 0;
    }
    return 1;
}

void how_many_needed(){
    diff=v[1]-v[0];
    extra=0;
    for(int i=2;i<n;i++){
        if(v[i]-v[i-1]!=diff){
            if((v[i]-v[i-1])==diff*2 && extra==0) extra=v[i-1]+diff;
            else {
                done=0;
                break;
            }
        }
        if(i==n-1) return;
    }
    diff=v[n-1]-v[n-2];
    //show(diff);
    extra=0;
    done=1;
    for(int i=1;i<n;i++){
        if(v[i]-v[i-1]!=diff){
            if((v[i]-v[i-1])==diff*2 && extra==0) extra=v[i-1]+diff;
            else {
                done=0;
                return ;
            }
        }
        if(i==n-1) return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(v.size()==1) cout<<"-1\n";
    else if(isok()){
        // If already ok
        // One in front and One in back
        if(diff==0) cout<<"1\n"<<v[0]<<endl;
        else if(v.size()==2 && diff>1 && diff%2==0){
            // One in the middle
            cout<<"3\n"<<v[0]-diff<<" "<<v[0]+diff/2<<" "<<v[n-1]+diff;
        }
        else cout<<"2\n"<<v[0]-diff<<" "<<v[n-1]+diff;
    }
    else{
        how_many_needed();
        if(!done) cout<<"0\n";
        else {
            // The extra one need to add in the sequence
            cout<<"1\n"<<extra<<endl;
        }
    }
    return 0;
}
