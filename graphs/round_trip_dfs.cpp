#include<bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(int a, vector<vector<int>> &gr, vector<int> &vis, 
	vector<int> &par,int b,int* start){
	vis[a]=1;
	for(int i=0;i<gr[a].size();i++){
		
		if(vis[gr[a][i]]==0){
			par[gr[a][i]]=a;
			dfs(gr[a][i],gr,vis,par,a,start);
		} 
		else if(gr[a][i]!=b && *start==-1){
			par[gr[a][i]]=a;
			*start = gr[a][i];
		} 
	}
	
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> gr(n+1);
	int x,y;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	vector<int> vis(n+1,0);
	vector<int> par(n+1,0);
	int start=-1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
			dfs(i,gr,vis,par,-1,&start);
		if(start!=-1) break;
	}
	if(start==-1) cout<<"IMPOSSIBLE"<<endl;
	else{
		vector<int> ans;
		int k = start;
		ans.push_back(k);
		k = par[k];
		while(k!=start){
			ans.push_back(k);
			k = par[k];
		}
		ans.push_back(k);
		cout<<ans.size()<<endl;
		for(auto i:ans) cout<<i<<" ";
	}
	
}