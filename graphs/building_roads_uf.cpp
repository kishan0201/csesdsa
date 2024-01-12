#include<bits/stdc++.h>
using namespace std;
#define ll long long

int findFunc(int a,vector<int> &parent){
	if(parent[a]!=a)
		return findFunc(parent[a], parent);
	else
		return a;
}

void unionFunc(int a, int b, vector<int> &parent){
	int x = findFunc(b, parent);
	parent[b] = x;

	int y = findFunc(a, parent);
	parent[a] = y;

	parent[x] = y;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> v(m);
	for(int i=0;i<m;i++){
		cin>>v[i].first;
		cin>>v[i].second;
	}
	vector<int> parent(n+1);
	for(int i=1;i<=n;i++) parent[i]=i;

	for(int i=0;i<m;i++){
		unionFunc(v[i].first,v[i].second,parent);
	}

	set<int> ans;
	for(int i=1;i<=n;i++){
		ans.insert(findFunc(i,parent));
	}
	vector<int> ans1(ans.begin(),ans.end());
	int cnt = ans1.size();
	cout<<cnt-1<<endl;
	for(int i=0;i+1<cnt;i++){
		cout<<ans1[i]<<" "<<ans1[i+1]<<endl;
	}
}