/**
 *    author:   aditya_raj        
**/
// Graphs- bfs and dfs
#include<bits/stdc++.h>
using namespace std;

const int max_n = (int)1e5 + 5;
vector<vector<int>> G;
vector<bool> vis(max_n) ,Vis(max_n);

vector<int> dist(max_n);


void dfs(int u){
	vis[u] = true;
	for(auto v: G[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

int connected_componenets(int n){
	int num = 0;
	for(int i=1; i<=n; i++){
	  if(!vis[i]){
		dfs(i);
		num++;
	  }
	}
	return num;
}

void read_graph(int n){
	int m;
	cin >> m;
	G.resize(n+1);
	vis.resize(n+1);
	dist.resize(n+1);
	for(int i=0; i<m; i++){
		int x, y;  cin>> x>> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
}
	

void bfs(int u){
	queue<int> q;
	q.push(u);
	Vis[u] = true;
	dist[u] = 0;
	
	while( !q.empty()){
		int v = q.front();
		q.pop();
		
		for(auto vv: G[v]){
		  if(!Vis[vv])
		  {
			q.push(vv);
			Vis[vv] = true;
			dist[vv] = dist[v] + 1;
		  }
	   }
	}
}
	
int main(){
	int n; cin>>n;
	read_graph(n);
	cout << connected_componenets(n) << endl;
	bfs(1);
}
	
	
// 6 5
// 4 2    1 6  	2 5 	2 6		3 1
//connected_componenets() = 1;
//[dist] = {0,2,1,3,3,1,0};