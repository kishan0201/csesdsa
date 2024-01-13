#include<bits/stdc++.h>
using namespace std;
#define ll long long


int bfs(int a,vector<vector<int>> &gr, vector<int> &vis){
	queue<pair<int,int>> qu;
	qu.push({a,1});
	int x,y;
	while(!qu.empty()){
		x = qu.front().first;
		y = qu.front().second;
		qu.pop();
		vis[x]=y;
		for(int i=0;i<gr[x].size();i++){
			if(vis[gr[x][i]]==0){
				qu.push({gr[x][i],-1*y});
			}
			else if(vis[gr[x][i]]==y){
				return -1;
			}
		}
	}
	return 1;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> gr(n+1);
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x;
		cin>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	vector<int> vis(n+1,0);
	int k;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			k = bfs(i,gr,vis);
		}
		if(k==-1) break;
	}
	if(k==-1) cout<<"IMPOSSIBLE"<<endl;
	else{
		for(int i=1;i<=n;i++){
			if(vis[i]==-1) cout<<2<<" ";
			else cout<<vis[i]<<" ";
		}
	}
}