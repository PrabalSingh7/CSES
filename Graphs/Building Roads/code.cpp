#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
typedef long long ll;
#define ull unsigned long long;
typedef pair<ll,ll> pl;
#define pb push_back;

int drow[4] = {0,-1,0,1}; 
int dcol[4] = {-1,0,1,0}; 


void dfs(int curr, int par, unordered_map<int,vector<int>> &adj,  vector<int> &vis)	{
	vis[curr] = par;

	for(auto it : adj[curr])	{
		if(vis[it]==-1)	{
			dfs(it,par,adj,vis);
		}
	}

	return;
}

 
void solve(int i )	{
 	int n, m;
 	cin >> n >> m;

	vector<int> vis (n+1, -1);
	unordered_map<int,vector<int>> adj;

	for(int i=0; i<m; i++)	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> util;

	for(int i=1; i<=n; i++)	{
		if(vis[i] == -1)	{
			util.push_back(i);
			dfs(i,i,adj,vis);
		}
	}

	cout << util.size() - 1<<"\n";
	for(int i=1; i<util.size(); i++)	{
		cout<<util[0]<<" "<<util[i]<<"\n";
	}

	return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	ll T = 1;
	// cin>>T;
 
	for(int ti=0; ti<T; ti++)	{ 
 
		solve(ti);
		cout<<"\n";
	}
 
	return 0; 
}