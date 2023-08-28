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

void dfs (int i, int j, int n, int m, vector<vector<int>> &arr, int count)	{
	if(arr[i][j] == -1 || arr[i][j] > 0)	
		return;

	arr[i][j] = count;

	for(int k=0; k<4; k++)	{
		int di = i + drow[k];
		int dj = j + dcol[k];

		if(di>=0 && di<n && dj>=0 && dj<m && arr[di][dj]==0 )	{
			dfs(di,dj,n,m,arr,count);
		}
	}
	
	return;
} 

 
void solve(int i )	{
 	int n, m;
 	cin >> n >> m;

	vector<vector<int>> arr (n, vector<int> (m,-2));

 	for(int i=0; i<n; i++)	{
 		for(int j=0; j<m; j++)	{
 			char ch ;
 			cin >> ch;

 			if(ch=='.')	{
 				arr[i][j] = 0;
 			}else {
 				arr[i][j] = -1;
 			}
 		}
 	}
 	
 	int count = 0;

 	for(int i=0; i<n; i++)	{
 		for(int j=0; j<m; j++)	{  
 			if(arr[i][j] == 0)	{
 				count += 1;
 				dfs(i,j,n,m,arr,count);
 			}
 		} 
 	}

 	cout<< count;

	return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	// ll T;
	// cin>>T;
 
	for(int ti=0; ti<1; ti++)	{ 
 
		solve(ti);
		cout<<"\n";
	}
 
	return 0; 
}