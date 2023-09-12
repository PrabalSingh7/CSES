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
#include <unordered_set>
#include <assert.h>
 
using namespace std;
 
typedef long long ll; 
typedef unsigned long long int ull;
typedef pair<ll,ll> pl;
#define pb push_back;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_no
 
int mod = 1000000007;
int drow[4] = {0,-1,0,1}; 
int dcol[4] = {-1,0,1,0}; 
 
// int bs_fun(vector<int> &arr, int tf)	{
// 	int l = 0;
// 	int h = arr.size() - 1;
// 	int ret = arr.size();
 
// 	while (l <= h)	{
// 		int mid = l + (h-l) / 2;
 
// 		if(arr[mid] >= tf)	{
// 			ret = min(ret,mid);
// 			h = mid - 1;
// 		}else {
// 			l = mid + 1;
// 		}
// 	}
 
// 	return ret;
// }
 
 
void solve(int abcdefg )	{ 
	int n, m;
	cin >> n >> m;
 
	unordered_map<int,vector<int>> adj;
	for(int i=1; i<=m; i++)	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	int par[n+1] = {-1};
	bool vis[n+1] = {false};
	queue<pair<int,int>> q;		//node, distance
	
	q.push({1,1});
	par[1] = -1;
	vis[1] = true;
	bool canReach = false;
 
	while(!q.empty())	{
		auto it = q.front();
		q.pop();
 
		int node = it.first;
		int dis = it.second;
 
		if(node == n)	{
			canReach = true;
			break;
		}
 
		for(auto it : adj[node])	{
			if(vis[it]==false)	{
				q.push({it,dis+1});
				vis[it] = true;
				par[it] = node;
			}
		}
	}
 
	if(canReach==false)	{
		cout<<"IMPOSSIBLE";
		return;
	}
 
	int curr = n;
	int cnt = 0;
	vector<int> path;
	
	while(curr != -1)	{
		cnt += 1;
		path.push_back(curr);
		curr = par[curr];
	}
	reverse(path.begin(), path.end());
	
	cout<<cnt<<"\n";
	for(auto it : path)	cout<<it<<" ";
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	ll T = 1;
// 	cin>>T;
    
	for(int ti=0; ti<T; ti++)	{ 
		solve(ti );
// 		cout<<"\n";
	}
 
	return 0; 
}