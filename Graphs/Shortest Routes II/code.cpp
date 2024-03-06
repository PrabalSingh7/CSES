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

// void computeLPSArray(string &pat, int M, vector<int> &lps);
 
// // Prints occurrences of pat[] in txt[]
// int KMPSearch(string &pat, string &txt)
// {
//     int M = (pat.size());
//     int N = (txt.size());

//     int res = 0 ;
 
//     // create lps[] that will hold the longest prefix suffix
//     // values for pattern
//     vector<int> lps (M,0) ;
    
//     // int lps[M];
 
//     // Preprocess the pattern (calculate lps[] array)
//     computeLPSArray(pat, M, lps);
 
//     int i = 0; // index for txt[]
//     int j = 0; // index for pat[]

//     while ((N - i) >= (M - j)) {
//         if (pat[j] == txt[i]) {
//             j++;
//             i++;
//         }
 
//         if (j == M) {
//             // printf("Found pattern at index %d ", i - j);
//             res += 1 ;
//             j = lps[j - 1];
//         }
 
//         // mismatch after j matches
//         else if (i < N && pat[j] != txt[i]) {
//             // Do not match lps[0..lps[j-1]] characters,
//             // they will match anyway
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i = i + 1;
//         }
//     }

//     return res ;
// }
 
// // Fills lps[] for given pattern pat[0..M-1]
// void computeLPSArray(string &pat, int M, vector<int> &lps)
// {
//     // length of the previous longest prefix suffix
//     int len = 0;
 
//     lps[0] = 0; // lps[0] is always 0
 
//     // the loop calculates lps[i] for i = 1 to M-1
//     int i = 1;
//     while (i < M) {
//         if (pat[i] == pat[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else // (pat[i] != pat[len])
//         {
//             // This is tricky. Consider the example.
//             // AAACAAAA and i = 7. The idea is similar
//             // to search step.
//             if (len != 0) {
//                 len = lps[len - 1];
 
//                 // Also, note that we do not increment
//                 // i here
//             }
//             else // if (len == 0)
//             {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }
// }

// bool rectangleDoOverlap(pair<ll,ll> l1, pair<ll,ll> r1, pair<ll,ll> l2, pair<ll,ll> r2)
// {
//     // if rectangle has area 0, no overlap
//     if (l1.first == r1.first || l1.second == r1.second || r2.first == l2.first || l2.second == r2.second)
//         return false;
   
//     // If one rectangle is on left side of other
//     if (l1.first > r2.first || l2.first > r1.first)
//         return false;
 
//     // If one rectangle is above other
//     if (r1.second > l2.second || r2.second > l1.second)
//         return false;
 
//     return true;
// }
  
void solve(int abcdefg )	{  
	int n, m, q ;
	cin >> n >> m >> q ;

	vector<vector<ll>> d (n+1, vector<ll> (n+1, 1e14)) ;

	for(int i=0; i<m; i++)	{
		ll u, v, w ;
		cin >> u >> v >> w ;
		d[u][u] = d[v][v] = 0 ;
		d[u][v] = min(d[u][v],w);
		d[v][u] = min(d[u][v],w);
	}
 
	for (int k = 1; k <= n; ++k) {
	    for (int i = 1; i <= n; ++i) {
	        for (int j = 1; j <= n; ++j) {
	            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
	        }
	    }
	}

	for(int i=0; i<q; i++)	{
		int u,v ;
		cin >> u >> v ;
        
        if(d[u][v]!=1e14)  cout << d[u][v] << "\n" ;
        else    cout << "-1\n" ;
	}
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    ll T = 1;
	// cin>>T;
    
	for(int ti=0; ti<T; ti++)	{ 
		solve(ti );
// 		cout<<"\n";
	}
 
	return 0; 
}