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
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// void myerase(ordered_set &t, int v){
//     int rank = t.order_of_key(v);//Number of elements that are less than v in t
//     ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
//     t.erase(it);
// }
 
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
// void myerase(ordered_multiset &t, int v){
//     int rank = t.order_of_key(v);//Number of elements that are less than v in t
//     ordered_multiset::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
//     t.erase(it);
// }
 
 
const int mod = 1000000007;
// int drow[4] = {0,-1,0,1}; 
// int dcol[4] = {-1,0,1,0}; 
 
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
 
 
// void dijkstra (int n, int src, vector<ll> &dis, unordered_map<int,vector<pair<int,int>>> &adj)	{ 
// 	priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
// 	pq.push({0,src});	
 
// 	// int vis[n+1] = {0};
// 	dis[src] = 0;
 
// 	while(!pq.empty())	{
// 		auto it = pq.top();
// 		pq.pop();
// 		ll prevDist = it.first;
// 		ll node = it.second;
 
// 		// if(vis[node]==1)	continue;
// 		// vis[node] = 1;
 
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
// }
 
 
// void primeFactors(int n, vector<ll> &vec )	{ 
//     while (n % 2 == 0)	    {
//     	vec.push_back(2);
//         n = n/2;
//     } 
    
//     for (int i = 3; i <= sqrt(n); i = i + 2)    { 
//         while (n % i == 0)	{
//         	vec.push_back(i);
//             n = n/i;
//         }
//     }
  
//     if (n > 2)	{
//     	vec.push_back(n); 
//     }
// }
 
// ll modpow(int x, int n, int m ) {
// 	if (n == 0) 
// 		return 1%m;
	
// 	ll u = modpow(x,n/2,m);
// 	u = (u*u)%m;
	
// 	if (n%2 == 1) 
// 		u = (u*x)%m;
	
// 	return u;
// }
 
 
// void SieveOfEratosthenes(  vector<bool> &pf, vector<int> &primes)	{  
// 	pf[0] = pf[1] = false;
 
//     for (int p = 2; p * p <= 1000000; p++) {
//         if (pf[p] == true) {
//             for (int i = p * p; i <= 1000000; i += p)
//                 pf[i] = false;
//         }
//     }
  
//     for (int p = 2; p <= 1000000; p++)
//         if (pf[p])
//             primes.push_back(p);
// }
 
// ll modBinExp (int base, int exp)	{
// 	if(exp == 0)
// 		return 1;
 
// 	ll res = modBinExp(base, exp/2);
 
// 	if(exp%2 == 1)
// 		return ( ((res*res)  % mod) * base) %mod;
// 	else 
// 		return ( (res*res)  % mod);
// }
 
// int geometricSum(int base, int exp)	{
// 	ll num = (modBinExp(base,exp+1)-1+mod) % mod;
// 	ll denomInv = modBinExp(base-1, mod-2);
 
// 	return (num * denomInv) % mod;
// }
 
// pair<bool,vector<int>> twoSum(vector<pair<int,int>> &arr, int findSum, int idxA1, int idxA2, int n) 	{
// 	int l = 0, h = n-1;
// 	while(h==idxA1 || h==idxA2)
// 	    h -= 1;
// 	while(l==idxA1 || l==idxA2)
// 		l += 1; 

// 	vector<int> res ;
// 	res.push_back(arr[idxA1].second);
// 	res.push_back(arr[idxA2].second);

// 	while (l < h)	{
// 	   // cout << l << " " << h << "\n";
// 		ll cs = (ll)arr[l].first + (ll)arr[h].first;

// 		if(cs == findSum)	{
// 			res.push_back(arr[l].second);
// 			res.push_back(arr[h].second);
// 			pair<bool, vector<int>> retP = {true, res};
// 			return retP;
// 		}

// 		else if(cs > findSum)	{
// 			h -= 1;
// 			while(h==idxA1 || h==idxA2)
// 				h -= 1;
// 		}
// 		else {
// 			l += 1;
// 			while(l==idxA1 || l==idxA2)
// 				l += 1;
// 		}
// 	}

// 	pair<bool, vector<int>> retP = {false, res};
// 	return retP;
// }
  
  
void solve(int abcdefg )	{    
	int n;
	cin >> n;

	int arr[n];
	int mx = -1;
	for(int i=0; i<n; i++)	{
		cin >> arr[i];
		mx = max(mx,arr[i]);
	}

	ll dp[mx+1][2];
	dp[0][0] = 0;
	dp[0][1] = 0;

	dp[1][0] = 1;
	dp[1][1] = 1;

	//searched on google for why this dp relation :	[constructing paterns by using prev state]
	 // _ _ 		   _ _ 		 _ _ 	   _ _		
	// |   |	<=    |_ _|	 ,  |_ _|  ,  |   |
	 // 			  | | |		|   |	  |   |
     //  _ _  		   _ _		 _ _       _ _       _ _       _ _ 
	//  | | |	<=    |_|_|	 ,  | | |  ,  | |_|  ,  |_| |  ,  |_|_|
	 // 			  | | |		| | |	  | | |     | | |     |   |
	 // 	 _ _ 
	// 0 -> |_ _|
	// 	     _ _ 
	// 1 -> |_|_|

	for(int i=2; i<=mx; i++)	{
		dp[i][0] = ( (dp[i-1][1]%mod)+(2*dp[i-1][0])%mod )%mod;
		dp[i][1] = ( (4*dp[i-1][1])%mod + dp[i-1][0]%mod )%mod;
	}

	for(int i=0; i<n; i++)	{
		int cv = arr[i];
		cout << (dp[cv][0]+dp[cv][1])%mod;
		cout << "\n";
	}
}

 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    ll T = 1;
	// cin>>T;
	 
	for(int ti=0; ti<T; ti++)	{  
		solve(ti );
		cout<<"\n";
	}
 
	return 0; 
}