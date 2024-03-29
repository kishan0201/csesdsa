#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000

void dijkstra(vector<vector<pair<ll,ll>>> &adj, vector<ll> &dist, vector<bool> &vis){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	dist[1]=0;
	pq.push({0,1});
	ll v,u,w;
	while(!pq.empty()){
		u = pq.top().second;
		pq.pop();
		if(!vis[u]){
			vis[u]=true;
			for(int j=0;j<adj[u].size();j++){
				v = adj[u][j].first;
				w = adj[u][j].second;
				if(dist[v]>dist[u]+w){
					dist[v] = dist[u]+w;
					pq.push({dist[v],v});
				}
			}
		}
			
	}
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adj(n+1);
	ll a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	vector<ll> dist(n+1,INF);
	vector<bool> vis(n+1,false);
	dijkstra(adj,dist,vis);
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}