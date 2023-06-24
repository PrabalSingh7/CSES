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
 
    if(n%2!=0)  {
        int m1 = (n/2)-1;
        int m2 = (n/2);
        ll mv1 = vec[m1];
        ll mv2 = vec[m2];
 
        ll s1 = 0;
        for(int i=0; i<n; i++)  {
            s1 += (ll)abs(vec[i]-mv1);
        }
        ll s2 = 0;
        for(int i=0; i<n; i++)  {
            s2 += (ll)abs(vec[i]-mv2);
        }
 
        cout<<min(s1,s2);
        return 0;
    }
    else {
        int m1 = (n/2)-1;
        ll mv1 = vec[m1];
 
        ll s1 = 0;
        for(int i=0; i<n; i++)  {
            s1 += (ll)abs(vec[i]-mv1);
        }
 
        cout<<s1;
        return 0;
    }
 
    return 0;
}