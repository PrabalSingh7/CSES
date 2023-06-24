#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
 
 
int main() {
    int x,n;
    cin>>x>>n;
 
    multiset<int> distances;
    distances.insert(x-0);
 
    set<int> positions;
    positions.insert(0);
    positions.insert(x);
 
    for(int i=0; i<n; i++) {
        int p;
        cin>>p;
        
        positions.insert(p);
        auto it = positions.find(p);
        int prevVal = *prev(it);
        int nextVal = *next(it);
 
        int ol = nextVal - prevVal;
        distances.erase(distances.find(ol));
        distances.insert(p-prevVal);
        distances.insert(nextVal-p);
 
        cout<<*distances.rbegin()<<" ";
    }
 
    return 0;
}