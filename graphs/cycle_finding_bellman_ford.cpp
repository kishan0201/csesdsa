#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000


pair<bool,int> bellmanford_neg_cycle(vector<vector<pair<int,int>>> &adj, int n, int m, vector<ll> &dist, vector<int> &rel){
	dist[0]=0;
	pair<bool,int> ans = {false,-1};
	//n-1 relaxations -- shortest path
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<adj[j].size();k++){
				if(dist[adj[j][k].first] > dist[j]+(ll)adj[j][k].second){
					dist[adj[j][k].first] = dist[j]+(ll)adj[j][k].second;
					rel[adj[j][k].first] = j;
				}
			}
		}
	}
	//nth relaxation -- cycle detection
	for(int j=0;j<=n;j++){
		for(int k=0;k<adj[j].size();k++){
			if(dist[adj[j][k].first] > dist[j]+(ll)adj[j][k].second){
				ans = {true,j};
				rel[adj[j][k].first] = j;
			}
		}
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	int a,b,c;
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	for(int i=1;i<=n;i++) adj[0].push_back({i,0});
	vector<ll> dist(n+1,INF);
	vector<int> rel(n+1,0);
	pair<bool,int> ans = bellmanford_neg_cycle(adj,n,m,dist,rel);
	if(ans.first){
		int v=ans.second;
		int times=n;
		while(times--){
			v=rel[v];
		}
		vector<int> sol;
		int p=v;
		sol.push_back(v);
		v=rel[v];
		while(v!=p){
			sol.push_back(v);
			v=rel[v];
		}
		sol.push_back(p);
		cout<<"YES"<<endl;
		for(int i=sol.size()-1;i>=0;i--) cout<<sol[i]<<" ";
	}else cout<<"NO"<<endl;
}
































