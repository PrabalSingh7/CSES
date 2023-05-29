#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
 
void fun(ll &res, int idx, vector<int> nums, ll g1, ll g2)	{
 
	if(idx==nums.size())	{
		res = min(res,abs(g1-g2));
		return;
	}
 
	fun(res,idx+1,nums,g1+nums[idx],g2);
	fun(res,idx+1,nums,g1,g2+nums[idx]);
 
	return;
}
 
 
int main()	{
 
	int n ;
	cin >> n ;
 
	vector<int> nums;
	for(int i=0; i<n; i++)	{
		int x;cin>>x;
		nums.push_back(x);
	}	
 
	ll res = 1e9;
	fun(res,0,nums,0,0);
 
	cout<<res;
 
	return 0;
}