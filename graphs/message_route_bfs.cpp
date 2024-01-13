#include<bits/stdc++.h>
using namespace std;
#define ll long long

int bfs(int start, vector<vector<int>> &gr, vector<int> &vis, int target,
	vector<int> & par){
	queue<pair<int,int>> qu;
	qu.push({start,1});
	vis[start]=1;
	int ans = -1;
	int x,y;
	while(!qu.empty()){
		x = qu.front().first;
		y = qu.front().second;
		qu.pop();
		for(int i=0;i<gr[x].size();i++){
			if(vis[gr[x][i]]==0){
				vis[gr[x][i]]=1;
				par[gr[x][i]]=x;
				if(gr[x][i]==target){
					ans = y+1;
					return ans;
				}
				qu.push({gr[x][i],y+1});
			}
		}
	}
	return ans;
}

void func(vector<int> &sol,int t,vector<int> &par){
	if(par[t]!=t){
		sol.push_back(par[t]);
		return func(sol,par[t],par);
	}else return;
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
	vector<int> par(n+1,-1);
	par[1]=1;
	int cnt = bfs(1,gr,vis,n,par);
	if(cnt==-1) cout<<"IMPOSSIBLE"<<endl;
	else{
		vector<int> sol;
		sol.push_back(n);
		func(sol,n,par);
		cout<<sol.size()<<endl;
		for(int i=sol.size()-1;i>=0;i--)
			cout<<sol[i]<<" ";
	}
	
			
}