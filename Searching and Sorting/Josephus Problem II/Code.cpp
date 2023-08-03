#include <bits/stdc++.h>
using namespace std;
 
// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
 
typedef long long ll;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ordered_set o_set;
    
    int si = 0;
    int n,k;
    cin >> n >> k;
    
    for(int ni=1; ni<=n; ni++)   
        o_set.insert(ni);
    
    for(int ni=1; ni<=n; ni++)  {
        int di = si + k;
        di %= o_set.size();
        si = di;
        
        int val = *(o_set.find_by_order(di));
        cout<<val<<" ";
        
        o_set.erase(o_set.find(val));
    }
 
    return 0;
}