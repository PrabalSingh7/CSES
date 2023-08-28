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

// void dfs (int i, int j, int n, int m, vector<vector<int>> &arr, int count)	{
// 	if(arr[i][j] == -1 || arr[i][j] > 0)	
// 		return;

// 	arr[i][j] = count;

// 	for(int k=0; k<4; k++)	{
// 		int di = i + drow[k];
// 		int dj = j + dcol[k];

// 		if(di>=0 && di<n && dj>=0 && dj<m && arr[di][dj]==0 )	{
// 			dfs(di,dj,n,m,arr,count);
// 		}
// 	}
	
// 	return;
// } 


void pathTraceDFS(int i, int j, vector<vector<int>> &vis) {
    string res;
    
    while(vis[i][j] != 0)   {
        if(vis[i][j] == 1)  {
            res += 'L';
            j += 1;
        }
        else if(vis[i][j] == 2)  {
            res += 'U';
            i += 1;
        }
        else if(vis[i][j] == 3)  {
            res += 'R';
            j -= 1;
        }
        else if(vis[i][j] == 4)  {
            res += 'D';
            i -= 1;;
        }
        else {
            break;
        }
    }
    
    reverse(res.begin(), res.end());
    cout<<res;
    return;
}   


void bfs (int srci, int srcj, int destI, int destJ, int n, int m, vector<vector<int>> &arr)	{

	queue<pair<int,pair<int,int>>> q;
	q.push({0,{srci,srcj}});

	vector<vector<int>> vis (n, vector<int> (m, -1));
	vis[srci][srcj] = 0;

	while(!q.empty())	{
		auto it = q.front();
		q.pop();
		int dis = it.first;
		int i = it.second.first;
		int j = it.second.second;
            
        // cout<<dis<<" ; "<<i<<" "<<j<<"\n";
        
		if(i==destI && j==destJ)	{
		  //  vis[i][j] = 5;
		    cout<<"YES\n";
			cout<<dis;
			cout<<"\n";
			
// 			for(int i=0; i<n; i++)  {
//         	    cout<<"\n";
//         	    for(int j=0; j<m; j++)  { 
//         	        cout<< vis[i][j] <<" ";
//         	    }
//         	}
			
			pathTraceDFS(i,j,vis);
			
			return;
		}

		for(int ki=0; ki<4; ki++)	{
			int di = i + drow[ki];
			int dj = j + dcol[ki];

			if(di>=0 && di<n && dj>=0 && dj<m)	{
				if(vis[di][dj] == -1 && arr[di][dj] != -1)	{
					vis[di][dj] = ki + 1;
					q.push({dis+1, {di,dj}});
				}
			}
		}
	}
    
    cout<<"NO";
	return;
}

 
void solve(int i )	{
 	int n, m;
 	cin >> n >> m;

	vector<vector<int>> arr (n, vector<int> (m));
	int srci, srcj, destI, destJ;

 	for(int i=0; i<n; i++)	{
 		for(int j=0; j<m; j++)	{
 			char ch ;
 			cin >> ch;

 			if(ch=='.')	{
 				arr[i][j] = 0;
 			}
 			else if(ch=='#'){
 				arr[i][j] = -1;
 			}
 			else if(ch=='A')	{
 				srci = i;
 				srcj = j;
 				arr[i][j] = -2;
 			}
 			else if(ch=='B')	{
 				destI = i;
 				destJ = j;
 				arr[i][j] = -3;
 			}
 		}
 	}
 	
 	bfs(srci,srcj,destI,destJ,n,m,arr);

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