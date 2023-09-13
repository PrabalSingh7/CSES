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
typedef pair<int,int> pii;
#define pb push_back;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_no
 
int mod = 1000000007;
int drow[4] = {0,-1,0,1}; 
int dcol[4] = {-1,0,1,0}; 
 
// string pathTrace(int starti, int startj, int endi, int endj, vector<vector<int>> &pathVec)  {
//     string path;
//     int i = starti;
//     int j = startj;
 
//     while(1)	{
//         // cout<<i<<" "<<j<<" "<<pathVec[i][j]<<"\n";
//     	int curr = pathVec[i][j];
 
//     	if(curr==0)	{
//     		j += 1;
//     		path += 'L';
//     	}
//     	else if(curr==1)	{
//     		i += 1;
//     		path += 'U';
//     	}
//     	else if(curr==2)	{
//     		j -= 1;
//     		path += 'R';
//     	}
//     	else if(curr==3)	{
//     		i -= 1;
//     		path += 'D';
//     	}
 
//     	if(i==endi && j==endj)	{break;}
//     }
 
//     reverse(path.begin(), path.end());
//   	return path;
// }
 
 
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
 
 
 
// bool dfs(int node, int prev, vector<int> &par, unordered_map<int,vector<int>> &adj )	{
//     // cout<<node<<" "<<prev<<"\n"; 
// 	par[node] = prev;
// 	bool retVal = false;
 
// 	for(auto it : adj[node])	{
// 		if(it != prev)	{
// 			if(par[it]==-1)	{ 
// 				bool curr = dfs(it,node,par,adj );
// 				retVal = retVal || curr; 
// 			}
// 			//found cycle
// 			else {
// 			 //   cout<<"cycle found \n";
// 			    if(startNode==-1 && endNode==-1)    {
// 			     //   cout<<"got in cycle "<<node<<" "<<it<<"\n";
// 			        startNode = node;
//     				endNode = it;
// 			    } 
// 				return true;
// 			}
// 		}
// 	}
 
// 	return retVal;
// }
 
 
// void bfs(int mi, int mj, vector<vector<int>> &arr, vector<vector<int>> &monDis)	{
//     int n = arr.size();
//     int m = arr[0].size();
// 	queue<pair<int,pair<int,int>>> q;
// 	q.push({0,{mi,mj}});
 
// 	while(!q.empty())	{
// 		auto it = q.front();
// 		q.pop();
// 		int dis = it.first;
// 		int r = it.second.first;
// 		int c = it.second.second;
 
// 		for(int ki=0; ki<4; ki++)	{
// 			int dr = r + drow[ki];
// 			int dc = c + dcol[ki];
 
// 			if(dr>=0 && dr<n && dc>=0 && dc<m && arr[dr][dc]!=-2 && arr[dr][dc]!=-3 )	{
// 				if(monDis[dr][dc] > dis+1)	{
// 					monDis[dr][dc] = dis+1;
// 					q.push({dis+1,{dr,dc}});
// 				}
// 			}
// 		}
// 	}
// }
 
 
void dijkstra (int n, int src, vector<ll> &dis, unordered_map<int,vector<pair<int,int>>> &adj)	{ 
	priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,src});	
 
	int vis[n+1] = {0};
	dis[src] = 0;
 
	while(!pq.empty())	{
		auto it = pq.top();
		pq.pop();
		ll prevDist = it.first;
		ll node = it.second;
 
		if(vis[node]==1)	continue;
		vis[node] = 1;
 
		for(auto it : adj[node])	{
			ll newNode = it.first;
			ll newDist = it.second;
			ll totalDist = prevDist + newDist;
 
			if(totalDist < dis[newNode])	{
				dis[newNode] = totalDist;
				pq.push({totalDist,newNode});	
			}
		}
	}
}
 
 
void solve(int abcdefg )	{ 
	int n, m;
	cin >> n >> m;
 
	unordered_map<int,vector<pair<int,int>>> adj;
	for(int i=1; i<=m; i++)	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v,c});
// 		adj[v].push_back({u,c});
	}
	
// 	for(auto it : adj)  {
// 	    cout<<it.first<<" => ";
// 	    for(auto i : it.second) cout<<i.first<<","<<i.second<<" ; ";
// 	    cout<<"\n";
// 	}  
 
	vector<ll> dis (n+1, 1e18);
 
	dijkstra(n,1,dis,adj);
 
 
// 	ll dis[n+1] ;
// 	for(int i=0; i<=n ;i++)	dis[i] = 100000000000000000;
 
// 	int vis[n+1] = {0};
 
// 	priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
 
// 	pq.push({0,1});
// 	dis[1] = 0;
 
// 	while(!pq.empty())	{
// 		auto it = pq.top();
// 		pq.pop();
// 		ll prevDist = it.first;
// 		ll node = it.second;
 
// 		if(vis[node]==1)	continue;
// 		vis[node] = 1;
 
// 		for(auto it : adj[node])	{
// 			ll newNode = it.first;
// 			ll newDist = it.second;
// 			ll totalDist = prevDist + newDist;
 
// 			if(totalDist < dis[newNode])	{
// 				dis[newNode] = totalDist;
// 				pq.push({totalDist,newNode});	
// 			}
// 		}
// 	}
 
	for(int i=1; i<=n ;i++)	cout<<dis[i]<<" ";
 
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