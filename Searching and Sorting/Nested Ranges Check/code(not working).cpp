#include <bits/stdc++.h>
using namespace std;
 
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
 
typedef long long ll;
typedef pair<ll,ll> pl;
 
#define ordered_set tree<pl, null_type,less<pl>, rb_tree_tag,tree_order_statistics_node_update>
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ordered_set o_set1, o_set2;
        
    ll n;
    cin >> n;
    ll arr[n][2];
    
    for(int i=0; i<n; i++)  {
        ll l,u;
        cin>>l>>u;
        arr[i][0] = l;
        arr[i][1] = u;
    }
    
    vector<pair<ll,pl>> vec;
    for(int i=0; i<n; i++)  {
        ll l = arr[i][0];
        ll r = arr[i][1];
        vec.push_back({l,{r,i}});        
    }
    
    sort(vec.begin(), vec.end());
    
    // for(auto it : vec)
    //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
        
    vector<int> containing (n,0), contained (n,0);
    
    for(int i=0; i<n; i++)  {
        ll idx = vec[i].second.second;
        ll right = vec[i].second.first;
        
        o_set1.insert({right,(-1*i)});
        ll val = o_set1.size() - ( o_set1.order_of_key({right,(-1*i)}) )- 1 ;
        
        contained[idx] = val;
    }
    
    for(int i=n-1; i>=0; i--)  {
        ll idx = vec[i].second.second;
        ll right = vec[i].second.first;
        
        o_set2.insert({right,(-1*i)});
        ll val = o_set2.order_of_key({right,(-1*i)});
        
        containing[idx] = val;
    }
    
    for (int i = 0; i < n; i++)	{
		if(containing[i] >=1 ) 
			cout <<"1 ";
		else 
			cout<<"0 ";
    }cout<<"\n";

    for (int i = 0; i < n; i++)	{
		if(contained[i] >=1 ) 
			cout <<"1 ";
		else 
			cout<<"0 ";
    }

    // for(auto it : containing)
    //     cout<<it<<" ";
    // cout<<"\n";
    // for(auto it : contained)
    //     cout<<it<<" ";
     
 
    return 0;
}