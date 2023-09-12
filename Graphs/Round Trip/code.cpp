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

int startNode = -1,endNode = -1;


bool dfs(int node, int prev, vector<int> &par, unordered_map<int,vector<int>> &adj )	{
    // cout<<node<<" "<<prev<<"\n"; 
	par[node] = prev;
	bool retVal = false;

	for(auto it : adj[node])	{
		if(it != prev)	{
			if(par[it]==-1)	{ 
				bool curr = dfs(it,node,par,adj );
				retVal = retVal || curr; 
			}
			//found cycle
			else {
			 //   cout<<"cycle found \n";
			    if(startNode==-1 && endNode==-1)    {
			     //   cout<<"got in cycle "<<node<<" "<<it<<"\n";
			        startNode = node;
    				endNode = it;
			    } 
				return true;
			}
		}
	}

	return retVal;
}


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
	
// 	for(auto it : adj)  {
// 	    cout<<it.first<<" => ";
// 	    for(auto i : it.second) cout<<i<<" ";
// 	    cout<<"\n";
// 	}

	vector<int> par (n+1, -1);
	
	for(int i=1; i<=n; i++) {
	    if( par[i] == -1 )  { 
	        bool val = dfs(i,i,par,adj );
	        
	        if(val==true)  { 
	            
	            vector<int> path;
	            int trev = startNode;
	            
	            path.push_back(startNode);
	            while(1)	{
	            	trev = par[trev];
	            	path.push_back(trev);
	            	if(trev==endNode)   break;
	            }
	            path.push_back(startNode);

	            cout<<path.size()<<"\n";
	            for(auto it : path)	cout<<it<<" ";	cout<<"\n";

	            return;
	        }
	    }
	}
	
    cout<<"IMPOSSIBLE";
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