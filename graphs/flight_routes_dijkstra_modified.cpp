#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000

void dijkstra(vector<vector<pair<ll,ll>>> &adj, vector<vector<ll>> &dist, vector<bool> &vis, int k){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	dist[1][0]=0;
	pq.push({0,1});
	ll v,u,w,d;
	while(!pq.empty()){
		u = pq.top().second;
		d = pq.top().first;
		pq.pop();
		if(d>dist[u][k-1]) continue;
			vis[u]=true;
			for(int j=0;j<adj[u].size();j++){
				v = adj[u][j].first;
				w = adj[u][j].second;
				if(dist[v][k-1]>d+w){
					dist[v][k-1] = d+w;
					pq.push({dist[v][k-1],v});
					sort(dist[v].begin(),dist[v].end());
				}
			}
			
	}
	return;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pair<ll,ll>>> adj(n+1);
	ll a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	vector<vector<ll>> dist(n+1,vector<ll> (k,INF));
	vector<bool> vis(n+1,false);
	dijkstra(adj,dist,vis,k);
	for(int i=0;i<k;i++) cout<<dist[n][i]<<" ";
}