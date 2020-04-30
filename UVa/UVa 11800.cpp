Problem Link >>  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=226&page=show_problem&problem=2900

Elementary Area calculation Algorithm >> https://www.mathopenref.com/coordpolygonarea.html

Here is the solution for UVa 11800. 
The tricky part of this problem was to sort the points in a clockwise / anticlockwise manner. 
So, I just checked it using the elementary area calculating algorithm for which we need to sort the co-ordinates in a clockwise or anticlockwise manner. 
If we sort clockwise the area will be positive and if anticlockwise then the area will be negative. 
Else the area will be equal to zero. So for each 6 permutations of the points, I checked whether the area is positive or negative. 
If so I just took that on a final array of my point structure. 
Then just normally implement the rest.

Just be care full while calculating the slope…

#include <bits/stdc++.h>
using namespace std;

typedef struct point{
    int x,y;
};

point ar[4],final[4];
int bahu_a,bahu_b,bahu_c,bahu_d,korno_ac,korno_bd;

int area(point a, point b, point c, point d){
    int plus, minus;
    plus=(a.x*b.y)+(b.x*c.y)+(c.x*d.y)+(d.x*a.y);
    minus=(b.x*a.y)+(c.x*b.y)+(d.x*c.y)+(a.x*d.y);
    return plus-minus;
}

void khela_shuru(){
    for(int i=0;i<4;i++){
        cin>>ar[i].x>>ar[i].y;
    }
    if(area(ar[0],ar[1],ar[2],ar[3])!=0){
        final[0]=ar[0];
        final[1]=ar[1];
        final[2]=ar[2];
        final[3]=ar[3];
    }
    else if(area(ar[0],ar[1],ar[3],ar[2])!=0){
        final[0]=ar[0];
        final[1]=ar[1];
        final[2]=ar[3];
        final[3]=ar[2];
    }
    else if(area(ar[0],ar[2],ar[1],ar[3])!=0){
        final[0]=ar[0];
        final[1]=ar[2];
        final[2]=ar[1];
        final[3]=ar[3];
    }
    else if(area(ar[0],ar[2],ar[3],ar[1])!=0){
        final[0]=ar[0];
        final[1]=ar[2];
        final[2]=ar[3];
        final[3]=ar[1];
    }
    else if(area(ar[0],ar[3],ar[2],ar[1])!=0){
        final[0]=ar[0];
        final[1]=ar[3];
        final[2]=ar[2];
        final[3]=ar[1];
    }
    else if(area(ar[0],ar[3],ar[1],ar[2])!=0){
        final[0]=ar[0];
        final[1]=ar[3];
        final[2]=ar[1];
        final[3]=ar[2];
    }
    return ;
}

int durutto(point a, point b){
    int dell_x,dell_y;
    dell_x = a.x - b.x;
    dell_y = a.y - b.y;
    return (dell_x*dell_x) + (dell_y*dell_y) ;
}

void bahu_bali(){
    bahu_a= durutto(final[0],final[1]);
    bahu_b= durutto(final[1],final[2]);
    bahu_c= durutto(final[2],final[3]);
    bahu_d= durutto(final[3],final[0]);
    korno_ac= durutto(final[0],final[2]);
    korno_bd= durutto(final[1],final[3]);
    return ;
}

point getdhal(point a, point b){
    int dell_x,dell_y;
    point ans;
    dell_x=max(a.x,b.x)-min(a.x,b.x);
    dell_y=max(a.y,b.y)-min(a.y,b.y);
    if(dell_y==0) {
        ans.y=0;
        ans.x=-1;
        return ans;
    }
    if(dell_x==0){
        ans.x=0;
        ans.y=-1;
        return ans;
    }
    ans.x=dell_x/__gcd(dell_x,dell_y);
    ans.y=dell_y/__gcd(dell_x,dell_y);
    dell_x=a.x-b.x;
    dell_y=a.y-b.y;
    if(dell_x<0 && dell_y<0);
    else if(dell_y<0 || dell_x<0) ans.x=ans.x*(-1);
    //cout<<ans.x<<" "<<ans.y<<endl;
    return ans;
}

bool soman_kina(point a, point b){
    if(a.x==b.x && a.y==b.y) return 1;
    else if(a.y==0 && b.y==0) return 1;
    else if(a.x==0 && b.x==0) return 1;
    else return 0;
}

bool chksqr(){
    if(bahu_a==bahu_b && bahu_d==bahu_c && bahu_a==bahu_c)
        if(korno_bd==korno_ac)
            return 1;
    return 0;
}

bool chkrech(){
    if(bahu_a==bahu_c && bahu_b==bahu_d)
        if(korno_bd==korno_ac)
            return 1;
    return 0;
}

bool chkrombh(){
    if(bahu_a==bahu_b && bahu_d==bahu_c && bahu_a==bahu_c)
            return 1;
    return 0;
}

bool chksaman(){
    if(bahu_a==bahu_c && bahu_b==bahu_d)
            return 1;
    return 0;
}

bool chktrap(){
    if(soman_kina(getdhal(final[0],final[1]),getdhal(final[3],final[2]))){
        return 1;
    }
    else if(soman_kina(getdhal(final[1],final[2]),getdhal(final[0],final[3]))){
        return 1;
    }
    else return 0; 
}

int main()
{
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        khela_shuru();
    bahu_bali();
    if(chksqr()){
        cout<<"Case "<<cs<<": Square\n";
    }
    else if(chkrech()){
        cout<<"Case "<<cs<<": Rectangle\n";
    }
    else if(chkrombh()){
        cout<<"Case "<<cs<<": Rhombus\n";
    }
    else if(chksaman()){
        cout<<"Case "<<cs<<": Parallelogram\n";
    }
    else if(chktrap()){
        cout<<"Case "<<cs<<": Trapezium\n";
    }
    else {
        cout<<"Case "<<cs<<": Ordinary Quadrilateral\n";
      }
    }
    return 0;
}
