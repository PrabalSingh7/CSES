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


bool dfs(int node, int prev, vector<int> &col, unordered_map<int,vector<int>> &adj)	{
    // cout<<node<<" "<<prev<<"\n";
	if(col[node] == prev)	{
		return false;
	}
	if( (col[node] == 1 && prev == 2) || (col[node] == 2 && prev == 1) )    {
	    return true;
	}

	if(prev==1)	{
		col[node] = 2;
		bool val = true;

		for(auto it : adj[node])	{
			bool curr = dfs(it,2,col,adj);
			val &= curr;
		}

		return val;
	}
	else {
		col[node] = 1;
		bool val = true;

		for(auto it : adj[node])	{ 
			bool curr = dfs(it,1,col,adj);
			val &= curr; 
		}

		return val;
	}
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

	vector<int> col (n+1, -1);
	
	for(int i=1; i<=n; i++) {
	    if(col[i]==-1)  {
	       // cout<<"called => "<<i<<"\n";
	        bool val = dfs(i,2,col,adj);
	        if(val==false)  {
	            cout<<"IMPOSSIBLE";
	            return;
	        }
	    }
	}
	
    for(int i=1; i<=n; i++)  {
        cout<<col[i]<<" ";
    }
    
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