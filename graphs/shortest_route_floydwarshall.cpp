#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000

void floydWarshall(vector<vector<pair<ll,ll>>> &adj, int n, vector<vector<ll>> &dist){
	
	for(int i=1;i<=n;i++) dist[i][i]=0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<adj[i].size();j++){
			if(dist[i][adj[i][j].first] > adj[i][j].second)
			dist[i][adj[i][j].first] = adj[i][j].second;
		}
	}	

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j] )
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}

}


int main(){
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<pair<ll,ll>>> adj(n+1);
	ll a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	vector<vector<ll>> dist(n+1,vector<ll> (n+1,INF));
	floydWarshall(adj,n,dist);
	for(int i=0;i<q;i++){
		cin>>a>>b;
		cout<<((dist[a][b]==INF)?-1:dist[a][b])<<" ";
	}	
}