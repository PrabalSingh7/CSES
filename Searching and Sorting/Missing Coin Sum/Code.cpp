#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
 
int main()	{
 
    ll n;
    cin>>n;
 
    vector<ll> vec;
    for(int i=1; i<=n; i++)	{
    	ll x;
    	cin>>x;
    	vec.push_back(x);
    }
 
    sort(vec.begin(),vec.end());
 
    ll ans = 1;
    for(int i=0; i<n; i++)  {
        if(vec[i] <= ans)   {
            ans  += vec[i];
        }
        else {
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
 
    return 0;
}