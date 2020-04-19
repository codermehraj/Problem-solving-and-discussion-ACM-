/*
UVa 101 ~ The Blocks Problem
	~ CoderMehraJ ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Problem Summery ::
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Initially there are n blocks on the table (numbered from 0 to n − 1)...
Description Of Bot commands for those blocks.

>>> move a onto b :
	~ It means to move a imidiate over the b Block.
	~ While doing this if any other block comes in the way just sent them to their initial Position.
	~ Which means any block over a and b will return to their initial positions...

>>> move a over b :
	~ Same as previous one
	~ Just in this case you have to put a over b stack you dont have to pop from B list of blocks
	~ But to get a you may need to pop from the list which contains a

>>> pile a onto b :
	~ Pile means take a and all other blocks over a
	~ while forming pile the sequence should be the same as before
	~ Take the Pile and put it exactly over b
	~ Any block over b will be sent to their initial position

>>> pile a over b :
	~ Same as previous one
	~ Just in this case you have to put a pile over b stack
	~ you dont have to pop from B list of blocks

>>> quit :
	~ Ends The Disaster

>>> Special Case ::
	~ From above four commands if a and b are in the same stack
	~ It is an invalid case
	~ Just ignore it :/

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
My Approach ::
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

>>>  So Here we se the functionality is more likly fimiliar to the stack DS.
     And Also we need N stacks....

>>>  So , I will use a vector of stacks :P which can eventually contain n stacks.

>>>  Then I will write four functions as it is described

>>>  To change the values of the vector easyly we need to declare that globally

>>>  To find and keep trace of any block I will use an array of n size :D Smart Move? xD
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
My Solution ::
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <bits/stdc++.h>
using namespace std;

bool debug=0;

vector< stack < int > > blocks;
vector < int > positn;
// Declaring my vector of stacks and their position containing list

// Function for Recursively printing any stack s
void Print_stack(stack < int > s){
	if(s.empty()) return;
	int x= s.top();
	s.pop();
	Print_stack(s);
	cout << " " << x ;
	return ;
}

void move_onto(int u, int v){
	int x,strt=positn[u],endd=positn[v];
	while(!blocks[strt].empty()){
		x=blocks[strt].top();
		if(x==u){
			if(debug) cout<<"Poping "<<x<<" from "<<strt<<endl;
			blocks[strt].pop();
			break;
		}
		else{
			if(debug) cout<<"Poping and pushing "<<x<<" To initial"<<endl;
			blocks[x].push(x);
			positn[x]=x;
			blocks[strt].pop();
		}
	}
	while(!blocks[endd].empty()){
		x=blocks[endd].top();
		if(x==v){
			if(debug) cout<<"Pushing "<<u<<" to "<<endd<<endl;
			blocks[endd].push(u);
			positn[u]=endd;
			break;
		}
		else{
			if(debug) cout<<"Poping "<<x<<" from "<<endd<<" To initial"<<endl;
			blocks[x].push(x);
			positn[x]=x;
			blocks[endd].pop();
		}
	}
	return ;
}

void move_over(int u, int v){
	int x,strt=positn[u],endd=positn[v];
	while(!blocks[strt].empty()){
		x=blocks[strt].top();
		if(x==u){
			if(debug) cout<<"Poping "<<x<<" from "<<strt<<endl;
			blocks[strt].pop();
			break;
		}
		else{
			if(debug) cout<<"Poping and pushing "<<x<<" To initial"<<endl;
			blocks[x].push(x);
			positn[x]=x;
			blocks[strt].pop();
		}
	}

	if(debug) cout<<"Pushing "<<u<<" to "<<endd<<endl;
	blocks[endd].push(u);
	positn[u]=endd;
	return ;
}

void pile_over(int u, int v){
	stack < int > make_pile;
	int x,strt=positn[u],endd=positn[v];
	while(!blocks[strt].empty()){
		x=blocks[strt].top();
		if(x==u){
			make_pile.push(x);
			if(debug) cout<<"Poping and pushing "<<x<<" To pile"<<endl;
			blocks[strt].pop();
			break;
		}
		else{
			if(debug) cout<<"Poping and pushing "<<x<<" To pile"<<endl;
			make_pile.push(x);
			blocks[strt].pop();
		}
	}
	while(!make_pile.empty()){
		if(debug) cout<<"Poping and pushing "<<x<<" To initial"<<endl;
		x=make_pile.top();
		blocks[endd].push(x);
		positn[x]=endd;
		make_pile.pop();
	}
	return ;
}

void pile_onto(int u, int v){
	stack < int > make_pile;
	int x,strt=positn[u],endd=positn[v];
	while(!blocks[strt].empty()){
		x=blocks[strt].top();
		if(x==u){
			make_pile.push(x);
			if(debug) cout<<"Poping and pushing "<<x<<" To pile"<<endl;
			blocks[strt].pop();
			break;
		}
		else{
			if(debug) cout<<"Poping and pushing "<<x<<" To pile"<<endl;
			make_pile.push(x);
			blocks[strt].pop();
		}
	}
	while(!blocks[endd].empty()){
		x=blocks[endd].top();
		if(x==v){
			break;
		}
		else{
			if(debug) cout<<"Poping "<<x<<" from "<<endd<<" To initial"<<endl;
			blocks[x].push(x);
			positn[x]=x;
			blocks[endd].pop();
		}
	}
	while(!make_pile.empty()){
		if(debug) cout<<"Poping and pushing "<<x<<" To initial"<<endl;
		x=make_pile.top();
		blocks[endd].push(x);
		positn[x]=endd;
		make_pile.pop();
	}
	return ;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n,u,v;
	string a,b;
	cin>>n;
	blocks.resize(n);
	positn.resize(n);
	for(int i=0; i<n; i++) blocks[i].push(i),positn[i]=i;
	while(cin>>a){
		if(a=="quit") break;
		cin>>u>>b>>v;
		if(positn[u]==positn[v]) continue;
		if(a=="move" && b=="onto") move_onto(u,v);
		else if(a=="move" && b=="over") move_over(u,v);
		else if(a=="pile" && b=="onto") pile_onto(u,v);
		else if(a=="pile" && b=="over") pile_over(u,v);
	}
	int cs=0;
	for(auto x: blocks){
		cout<<cs++<<":";
		Print_stack(x);
		cout<<endl;
	}
	return 0;
}

