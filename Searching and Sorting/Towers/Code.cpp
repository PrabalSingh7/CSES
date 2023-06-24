#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
 
 
int main() {
    int n ;
    cin>>n;
 
    multiset<int> mltset;
 
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        
        auto it = mltset.upper_bound(x);
 
        if(it == mltset.end())  {
            mltset.insert(x);
        }
        else {
            mltset.erase(it);
            mltset.insert(x);
        }
    }
    
    cout<<mltset.size();
 
    return 0;
}