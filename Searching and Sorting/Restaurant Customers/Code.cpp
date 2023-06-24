#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
 
 
int main()	{
 
    int n;
    cin>>n;
 
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    for(int i=0; i<n; i++)	{
    	int a,b;
    	cin>>a>>b;
    	pq.push({a,+1});
    	pq.push({b,-1});
    }
 
    int cnt = 0;
    int res = 0;
 
    while(!pq.empty())	{
    	auto it = pq.top();
    	pq.pop();
 
    	cnt += it.second;
    	res = max(res,cnt);
    }
 
    cout<<res;
 
    return 0;
}