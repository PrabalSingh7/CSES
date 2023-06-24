#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
 
 
ll maxSubArraySum(vector<ll> a, ll size)	{
    ll max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
 
int main()	{
 
    ll n;
    cin>>n;
 
    vector<ll> vec;
    for(int i=1; i<=n; i++)	{
    	ll x;
    	cin>>x;
    	vec.push_back(x);
    }
 
    cout<<maxSubArraySum(vec,n);
 
    return 0;
}