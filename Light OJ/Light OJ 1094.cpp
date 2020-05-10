/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    Problem name : Farthest Nodes in a Tree < undirected + weighted >
    n = total number of nodes
    >>> input format for n lines:
        u v w
        An edge between u and v with weight w
    Lets store the graph in a 2D vector of pairs nammed "edge"
    each pair in u-th "edge" ~ vector contains (v,w)
    which means connecton betwene u & v of w weight
    We will teverse twice in the tree
    In the first visit from 0:
        The max distant node will be stored at node
        And the max distance will be stored at mx_dist
*/

int n, u, v, w, node, mx_dist, curr_node, indx;
vector< vector < pair < int , int > > > edge;
queue < int > nxt_node;

void dijkstra(int source){
    mx_dist=0;
    //show(source);
    vector < int > distances(n+5,0), vis(n+5,0);
    nxt_node.push(source);
    distances[source]=0;
    vis[source]=1;
    while(!nxt_node.empty()){
        curr_node=nxt_node.front();
        nxt_node.pop();
        //show(curr_node);
        for(auto child: edge[curr_node]){
            if(vis[child.first]==0){
                vis[child.first]=1;
                //if((distances[curr_node]+child.second)>=distances[child.first]) 
                    distances[child.first]=distances[curr_node]+child.second;
                    //show(child.first);
                    //show(distances[child.first]);
                if(mx_dist<distances[child.first]){
                    mx_dist=distances[child.first];
                    node=child.first;
                    //show(mx_dist);
                }
                nxt_node.push(child.first);
            }
        }
    }
    return ;
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        edge.clear();
        edge.resize(n+5);
        indx=n-1;
        for(int i=1;i<n;i++) {
            cin>>u>>v>>w;
            if(i==1) node=u;
            edge[u].push_back(make_pair(v,w));
            edge[v].push_back(make_pair(u,w));
        }
        dijkstra(node);
        dijkstra(node);
        cout<<"Case "<<cs++<<": "<<mx_dist<<endl;
    }
    return 0;
}
